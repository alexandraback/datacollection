import java.util.*;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			in.nextLine();
			int[] array = new int[N];
			for (int b=0; b<N; b++) {
				array[b] = in.nextInt();
			}
			if (a!=cases-1) {
				in.nextLine();
			}
			int gain = recursion(E, E, R, N, array, 0, 0);
			System.out.println("Case #" + (a+1) + ": " + gain);
		}
	}
	private static int recursion(int E, int current, int R, int N, int[] array, int place, int gain) {
		int newG;
		int max = gain;
		for (int i=0; i<=current; i++) {
			newG = gain + i*array[place];
			int x = current - i + R;
			if (x>E) {
				x=E;
			}
			if (place!=N-1) {
				newG = recursion(E, x, R, N, array, place+1, newG);
			}
			if (newG>max) {
				max = newG;
			}
		}
		return max;
	}

}
