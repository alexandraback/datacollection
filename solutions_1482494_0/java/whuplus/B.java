package round1;

import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {
	public static Scanner in;
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("in.txt"));
		out = new PrintStream(new File("out.txt"));

		int T = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			solve();
			out.println();
		}
	}

	public static void solve() {
		int N;
		N = in.nextInt();

		final int[][] ab = new int[N][2];
		for (int i = 0; i < N; i++) {
			ab[i][0] = in.nextInt();
			ab[i][1] = in.nextInt();
		}

		Integer[] levels = new Integer[N];
		for (int i = 0; i < N; i++) {
			levels[i] = i;
		}
		Arrays.sort(levels, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return ab[o1][1] - ab[o2][1];
			}
		});

		System.out.println(Arrays.toString(levels));

		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < N; i++) {
			set.add(i);
		}

		boolean[][] played = new boolean[N][2];
		int stars = 0;
		int times = 0;
		
		
		while(set.size() > 0) {
			int x = -1, y = -1;
			
			for (int i = 0; i < N; i++) {
				if (played[i][0] == false && played[i][1] == false && stars >= ab[i][1]) {
					x = i;
					y = 1;
					break;
				}
			}
			
			if (x == -1) {
				for (int i = 0; i < N; i++) {
					if (played[i][0] == true && played[i][1] == false && stars >= ab[i][1]) {
						x = i;
						y = 1;
						break;
					}
				}
			}
			
			if (x == -1) {
				for (int i = 0; i < N; i++) {
					if ( played[i][0] == false && played[i][1] == false && stars >= ab[i][0]) {
						x = i;
						y = 0;
						break;
					}
				}
			}
			
			if (x == -1) {
				System.out.println("Too Bad");
				out.print("Too Bad");
				return;
			}
			
			System.out.println("--(" + x + " " + y + ") " + stars);
			
			if (y == 1) {
				if (played[x][0]) {
					stars += 1;
				} else {
					stars += 2;
				}
				played[x][1] = true;
				set.remove(x);
			} else {
				stars += 1;
				played[x][0] = true;
			}
			
			times++;
		}
		 
		System.out.println(times);
		out.print(times);
	}
}
