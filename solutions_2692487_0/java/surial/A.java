import java.util.Arrays;
import java.util.Scanner;


public class A {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %d\n", i + 1, exec());
	}
	
	private static int[] o;
	private static int n;
	public static int exec() {
		int a = sc.nextInt();
		n = sc.nextInt();
		o = new int[n];
		for (int i = 0; i < n; i++) o[i] = sc.nextInt();
		Arrays.sort(o);
		
		return recurse(0, 0, a, Integer.MAX_VALUE);
	}
	
	public static int recurse(int opsDoneSoFar, int indexIntoO, int a, int limit) {
		if (a == 1) return n - indexIntoO;
		if (opsDoneSoFar >= limit) return limit;
		for (int i = indexIntoO; ; i++) {
			if (i == n) return opsDoneSoFar;
			if (o[i] < a) {
				a += o[i];
				continue;
			}
			// We can't eat the smallest mote. We have two choices. Option A is to remove all remaining motes:
			int answerByRemoving = opsDoneSoFar + (n - i);
			// The other option is to see what happens if we add the largest mote we can and carry on:
			int answerByAdding = recurse(opsDoneSoFar + 1, i, a + a - 1, answerByRemoving);
			return Math.min(answerByRemoving, answerByAdding);
		}
	}
}
