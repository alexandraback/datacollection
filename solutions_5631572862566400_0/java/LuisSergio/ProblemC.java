import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.AllPermission;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Scanner;
import java.util.Set;

public class ProblemC {	

	private static BufferedWriter writer;
	private static Scanner scanner;
	
	private static Map<Integer, Integer> input;
	
	private static Integer result;
	
	private static void processCase(int i) throws IOException {
		readInput();
		solve();
		outputResults(i);
	}

	private static void solve() {
		result = 0;
		int[] A = new int[input.size()];
		for(int i =0; i < A.length; i++) {
			A[i] = i + 1;
		}
		
		for(int i = input.size(); i >= 3; i--) {
			List<List<Integer>> sets = new ArrayList<>();
			AllSubSetOfSizeK.subset(A, i, 0, 0, new boolean[A.length], sets);
			Optional<Integer> p = sets.parallelStream()
					.map(AllPerms::allPerms)
					.flatMap(l -> l.stream())
					.filter(ProblemC::validCircle)
					.parallel()
					.findAny()
					.map(l -> l.size());

			
				if (p.isPresent()){
					result = p.get();
					return;					
				}
		}
		
	}
	

	private static boolean validCircle(List<Integer> perm) {
		for(int i = 0; i < perm.size(); i++) {
			int bff = input.get(perm.get(i));
			if (i == 0) {
				if (perm.get(1) == bff || perm.get(perm.size() - 1) == bff) {
					continue;
				}
				return false;
			} else if (i == perm.size() - 1) {
				if (perm.get(0) == bff || perm.get(perm.size() - 2) == bff) {
					continue;
				}
				return false;				
			} else {
				if (perm.get(i - 1) == bff || perm.get(i + 1) == bff) {
					continue;
				}
				return false;
			}
		}
		return true;
	}

	private static void outputResults(int testCase) throws IOException {		
		String out = String.format("Case #%d: %s", testCase + 1, result);
		System.err.println(out);
		writer.write(out);
		writer.newLine();
	}
	

	private static void readInput() {
		int n = scanner.nextInt();
		input = new HashMap<>(n);
		for(int i = 1; i <= n; i++) {
			input.put(i, scanner.nextInt());
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
