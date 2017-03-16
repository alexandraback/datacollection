import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class ProblemB {	

	private static BufferedWriter writer;
	private static Scanner scanner;
	
	private static List<Integer> input;
	
	private static TreeSet<Integer> result;
	
	private static void processCase(int i) throws IOException {
		readInput();
		solve();
		outputResults(i);
	}

	private static void solve() {
		result = new TreeSet<>();
		input.stream().forEach(i -> {
			
			if (result.contains(i)) {
				result.remove(i);
			} else {
				result.add(i);
			}
			
		});
	}
	
	private static void outputResults(int testCase) throws IOException {		
		String out = String.format("Case #%d: %s", testCase + 1, result.stream().map(String::valueOf).collect(Collectors.joining(" ")));
		System.err.println(out);
		writer.write(out);
		writer.newLine();
	}
	

	private static void readInput() {
		int n = scanner.nextInt();
		input = new ArrayList<>((2*n-1)*n);
		for(int i = 0; i <  (2*n-1)*n; i++) {
			input.add(scanner.nextInt());
		}
	}

	public static void main(String[] args) throws IOException {
		Path input = Paths.get("input.in");
		Path output = Paths.get("output.txt");
		scanner = new Scanner(input);
		writer = Files.newBufferedWriter(output);
		int testCases = scanner.nextInt();
		scanner.nextLine();
		for (int i = 0; i < testCases; i++) {
			processCase(i);
		}
		writer.close();

	}
	

}
