import java.io.File;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;


public class Culture {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-small-attempt0.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			long target = Integer.parseInt(s.nextLine());
			System.out.println("Case #" + currentCase + ": " + solve(target));
		}
	}
	public static int solve(long n) {
		LinkedList<NumberInstance> queue = new LinkedList<NumberInstance>();
		NumberInstance start = new NumberInstance(1,1);
		queue.add(start);
		HashSet<Long> seen = new HashSet<Long>();
		seen.add(1L);
		while(!queue.isEmpty()) {
			NumberInstance next = queue.removeFirst();
			if(next.x==n) {
				return next.numSteps;
			}
			if(!seen.contains(next.x+1)) {
				seen.add(next.x+1);
				queue.add(new NumberInstance(next.x+1,next.numSteps+1));
			}
			long reversed = reverse(next.x);
			if(!seen.contains(reversed)) {
				seen.add(reversed);
				queue.add(new NumberInstance(reversed,next.numSteps+1));
			}
		}
		return -1;
	}
	public static long reverse(long n) {
		return Long.parseLong(new StringBuilder(Long.toString(n)).reverse().toString());
	}
}
class NumberInstance {
	long x;
	int numSteps;
	public NumberInstance(long x, int n) {
		this.x = x;
		numSteps = n;
	}
}
