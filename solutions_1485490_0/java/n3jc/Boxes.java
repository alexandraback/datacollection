import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;


public class Boxes {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path path = Paths.get(args[0]);
		Path file = Paths.get("boxes.txt");
		int numberOfCases;
		try (Scanner scanner = new Scanner(Files.newInputStream(path), "UTF-8");
				OutputStreamWriter output = new OutputStreamWriter(Files.newOutputStream(file), "UTF-8")) {
			Formatter f = new Formatter(output);
			numberOfCases = scanner.nextInt();
			for (int i = 1; i <= numberOfCases; i++) {
				int numberOfBoxes = scanner.nextInt();
				int numberOfToys = scanner.nextInt();
				List<Long[]> boxes = new LinkedList<>();
				List<Long[]> toys = new LinkedList<>();
				for (int j = 0; j < numberOfBoxes; j++) {
					boxes.add(new Long[]{scanner.nextLong(), scanner.nextLong()});
				}
				for (int j = 0; j < numberOfToys; j++) {
					toys.add(new Long[]{scanner.nextLong(), scanner.nextLong()});
				}
				int result = solve(boxes, toys);
				f.format("Case #%d: %d\n", i, result);
			}
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static int solve(List<Long[]> boxes, List<Long[]> toys) {
		List<Assembly> boxesList = new LinkedList<>();
		List<Assembly> toysList = new LinkedList<>();
		for (Long[] box : boxes) {
			boxesList.add(new Assembly(box[0], box[1]));
		}
		for (Long[] toy : toys) {
			toysList.add(new Assembly(toy[0], toy[1]));
		}
		
		Queue<CurrentUnit> queue = new LinkedList<>();
		queue.add(new CurrentUnit(boxesList, toysList, 0));
		int max = 0;
		while (!queue.isEmpty()) {
			CurrentUnit u = queue.poll();
			if (u.boxes.isEmpty() || u.toys.isEmpty()) {
				if (u.numberOfUnits > max) {
					max = u.numberOfUnits;
				}
			} else if (u.boxes.get(0).unitType == u.toys.get(0).unitType) {
				if (u.boxes.get(0).numberOfUnits > u.toys.get(0).numberOfUnits) {
					u.numberOfUnits+=u.toys.get(0).numberOfUnits;
					u.boxes.set(0, new Assembly(u.boxes.get(0).numberOfUnits - u.toys.get(0).numberOfUnits, u.boxes.get(0).unitType));
					u.toys.remove(0);
				} else if (u.boxes.get(0).numberOfUnits < u.toys.get(0).numberOfUnits) {
					u.numberOfUnits+=u.boxes.get(0).numberOfUnits;
					u.toys.set(0, new Assembly(u.toys.get(0).numberOfUnits - u.boxes.get(0).numberOfUnits, u.boxes.get(0).unitType));
					u.boxes.remove(0);
				} else {
					u.numberOfUnits+=u.boxes.get(0).numberOfUnits;
					u.boxes.remove(0);
					u.toys.remove(0);
				}
				queue.add(u);
			} else {
				Assembly ta = u.toys.get(0);
				Assembly ba = u.boxes.get(0);
				if (!containsType(u.boxes, ta.unitType)) {
					u.toys.remove(0);
					queue.add(u);
				} else if (!containsType(u.toys, ba.unitType)){
					u.boxes.remove(0);
					queue.add(u);
				} else {
					List<Assembly> newBList = new LinkedList<>(u.boxes);
					newBList.remove(0);
					List<Assembly> newTList = new LinkedList<>(u.toys);
					queue.add(new CurrentUnit(newBList, newTList, u.numberOfUnits));
					u.toys.remove(0);
					queue.add(u);
				}
			}
		}
		return max;
	}
	
	private static boolean containsType(List<Assembly> list, long type) {
		for (Assembly a : list) {
			if (a.unitType == type) {
				return true;
			}
		}
		return false;
	}
	
	private static class Assembly {
		final long numberOfUnits;
		final long unitType;
		
		public Assembly (long number, long type) {
			this.numberOfUnits = number;
			this.unitType = type;
		}

		@Override
		public String toString() {
			return "Assembly [numberOfUnits=" + numberOfUnits + ", unitType=" + unitType + "]";
		}
		
		
	}
	
	private static class CurrentUnit {
		List<Assembly> boxes;
		List<Assembly> toys;
		int numberOfUnits;
		
		public CurrentUnit(List<Assembly> boxes, List<Assembly> toys, int number) {
			this.boxes = boxes;
			this.toys = toys;
			this.numberOfUnits = number;
		}

		@Override
		public String toString() {
			return "CurrentUnit [boxes=" + boxes + ", toys=" + toys + ", numberOfUnits="
					+ numberOfUnits + "]";
		}
		
		
	}
}
