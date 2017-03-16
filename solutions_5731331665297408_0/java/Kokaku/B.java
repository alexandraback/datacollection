import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


public class B {

	public static void main(String[] args) {
		try {
			setInputFile("input.in");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		try {
			setOutputFile("output.out");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		
		for (int i = 0; i < testCase; i++) {
			System.out.print("Case #"+(i+1)+": ");
			int cities[] = new int[sc.nextInt()];
			boolean explored[] = new boolean[cities.length];
			for (int j = 0; j < explored.length; j++) {
				explored[j] = false;
			}
			Map<Integer, Set<Integer>> flight = new HashMap<>();
			int flightNbr = sc.nextInt();
			for (int j = 0; j < cities.length; j++) {
				cities[j] = sc.nextInt();
			}
			for (int j = 0; j < flightNbr; j++) {
				int cityA = sc.nextInt() - 1;
				int cityB = sc.nextInt() - 1;
				addToMap(flight, cityA, cityB);
				addToMap(flight, cityB, cityA);
			}

			int min = cities[0];
			int index = 0;
			for (int j = 0; j < cities.length; j++) {
				if(cities[j] < min) {
					min = cities[j];
					index = j;
				}
			}
			LinkedList<Integer> path = new LinkedList<>();
			explore(cities, explored, flight, index, path);
			System.out.println();
		}
		
		sc.close();
	}
	
	private static void explore(int cities[], boolean explored[], Map<Integer, Set<Integer>> flight, int index, LinkedList<Integer> path) {
		explored[index] = true;
		System.out.print(cities[index]);
		
		while(true) {

			if(flight.get(index) == null) {
				return;
			}
			

			int max = 0;
			for (Integer value : flight.get(index)) {
				if((!explored[value]) && max < cities[value]) {
					max = cities[value];
				}
			}
			LinkedList<Integer> pathCopy = new LinkedList<>(path);
			if(areAllReachable(explored, flight, index, path) &&
					isOk(cities, explored, flight, index, pathCopy, max)) {
				return;
			}
			
			
			int min = Integer.MAX_VALUE;
			int newIndex = -1;
			for (Integer value : flight.get(index)) {
				if((!explored[value]) && min > cities[value]) {
					min = cities[value];
					newIndex = value;
				}
			}
			if(newIndex < 0) {
				return;
			}

			path.addLast(index);
			explore(cities, explored, flight, newIndex, path);
			path.removeLast();
		}
		
		
	}
	
	private static boolean areAllReachable(boolean explored[], Map<Integer, Set<Integer>> flight, int index, LinkedList<Integer> path) {
		boolean allReachable = true;
		for (Integer destination : flight.get(index)) {
			if(explored[destination])
				continue;
			boolean reachable = false;
			Set<Integer> starts = flight.get(destination);

			for (int value : path) {
				if(starts.contains(value)) {
					reachable = true;
					break;
				}
			}
			if(!reachable) {
				allReachable = false;
				break;
			}
		}
		
		return allReachable;
	}
	
	private static boolean isOk(int cities[], boolean explored[], Map<Integer, Set<Integer>> flight, int index, LinkedList<Integer> path, int otherValue) {
		if(path.size() == 0) return true;
		int newIndex = path.removeLast();
		boolean reachable = areAllReachable(explored, flight, newIndex, path);
		if(reachable)
			return isOk(cities, explored, flight, newIndex, path, otherValue);
		
		int min = Integer.MAX_VALUE;
		for (Integer value : flight.get(newIndex)) {
			if((!explored[value]) && min > cities[value]) {
				min = cities[value];
			}
		}
		
		return min < otherValue;
	}
	
	private static void addToMap(Map<Integer, Set<Integer>> flight, int cityA, int cityB) {
		Set<Integer> setA = flight.get(cityA);
		if(setA == null) {
			setA = new HashSet<Integer>();
			flight.put(cityA, setA);
		}
		setA.add(cityB);
	}

	private static void setInputFile(String path) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File(path)));
	}

	private static void setOutputFile(String path) throws FileNotFoundException {
		System.setOut(new PrintStream(new File(path)));
	}
}
