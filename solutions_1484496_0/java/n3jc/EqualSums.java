import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;


public class EqualSums {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path path = Paths.get(args[0]);
		Path file = Paths.get("sums.txt");
		int numberOfCases;
		try (Scanner scanner = new Scanner(Files.newInputStream(path), "UTF-8");
				OutputStreamWriter output = new OutputStreamWriter(Files.newOutputStream(file), "UTF-8")) {
			Formatter f = new Formatter(output);
			numberOfCases = scanner.nextInt();
			for (int i = 1; i <= numberOfCases; i++) {
				Set<Long> numbers = new HashSet<>();
				int nOfNumbers = scanner.nextInt();
				for (int j = 0; j < nOfNumbers; j++) {
					numbers.add(scanner.nextLong());
				}
				
				List<Set<Long>> result = solve(numbers);
				f.format("Case #%d:\n", i);
				if (result == null) {
					f.format("Impossible\n");
				} else {
					for (Long l : result.get(0)) {
						f.format("%d ", l);
					}
					f.format("\n");
					for (Long l : result.get(1)) {
						f.format("%d ", l);
					}
					f.format("\n");
				}
			}
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static List<Set<Long>> solve(Set<Long> numbers) {
		Map<Long, Number> map = new TreeMap<>();
		for (Long n : numbers) {
			LinkedList<Number> tmp = new LinkedList<>(map.values());
			for (Number v : tmp) {	
				Number nwNumber = new Number(v, n);
				if (map.containsKey(nwNumber.sum)) {
					LinkedList<Set<Long>> l = new LinkedList<>();
					l.add(map.get(nwNumber.sum).numbers);
					l.add(nwNumber.numbers);
					return l;
				}
				map.put(nwNumber.sum, nwNumber);
			}
			Number nwNumber = new Number(n);
			if (map.containsKey(nwNumber.sum)) {
				LinkedList<Set<Long>> l = new LinkedList<>();
				l.add(map.get(nwNumber.sum).numbers);
				l.add(nwNumber.numbers);
				return l;
			}
			map.put(nwNumber.sum, nwNumber);
		}
		return null;
	}

	private static class Number {
		final long sum;
		final Set<Long> numbers;
		
		public Number (Number number, Long additional) {
			sum = number.sum + additional;
			numbers = new HashSet<>(number.numbers);
			numbers.add(additional);
		}
		
		public Number(Long n) {
			sum = n;
			numbers = new HashSet<>();
			numbers.add(n);
		}
	}
}
