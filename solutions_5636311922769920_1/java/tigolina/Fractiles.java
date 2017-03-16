import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Fractiles {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int testCount = in.nextInt();
		
		for (int test = 0; test < testCount; test++) {
			int K = in.nextInt();
			int C = in.nextInt();
			int S = in.nextInt();
			
			solveCase(test, K, C, S);
		}
		
		in.close();
	}
	
	private static void solveCase(int test, int K, int C, int S) {
		List<Long> steps = new ArrayList<>();
		int range = Math.min(C, K) - 1;
		
		int start = 1;
		while (start <= K) {
			int end = Math.min(start + range, K);
			long step = getPosition(start, end, K, C);
			steps.add(step);
			start = end + 1;
		}
		
		if (steps.size() > S) {
			System.out.println("Case #" + (test + 1) + ": " + "IMPOSSIBLE");
		} else {
			System.out.println("Case #" + (test + 1) + ": " + printList(steps));
		}
	}
	
	private static long getPosition(int start, int end, int K, int C) {
		long position = 1;
		int depth = 1;
		while (depth <= C) {
			position = (position - 1) * K + start;
			if (start < end) {
				start++;
			}
			depth++;
		}
		
		return position;
	}
	
	private static String printList(List<Long> list) {
		String s = "";
		for (long l : list) {
			s = s + l + " ";
		}
		return s.trim();
	}
}
