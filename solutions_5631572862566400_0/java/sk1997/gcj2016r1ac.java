import java.util.*;
import java.io.*;

public class gcj2016r1ac {
	
	private static Scanner sc;
	private static PrintStream ps;
	
	private static void oneCase() {
		int n = sc.nextInt();
		int[] bff = new int[n];
		for (int i = 0; i < n; i++)
			bff[i] = sc.nextInt() - 1;
		//
		Set<Integer> used = new HashSet<>();
		LinkedList<Integer> circle = new LinkedList<>();
		circle.add(0);
		boolean didAdd = true;
		while (didAdd) {
			didAdd = false;
			for (int i = 1; i < n; i++) {
				if (used.contains(i))
					continue;
				if (bff[i] == circle.getLast() || bff[circle.getLast()] == i) {
					circle.addLast(i);
					used.add(i);
					didAdd = true;
				} else if (bff[i] == circle.getFirst() || bff[circle.getFirst()] == i) {
					circle.addFirst(i);
					used.add(i);
					didAdd = true;
				}
			}
		}
		ps.println(circle.size());
	}

	public static void main(String[] args) throws IOException {
		sc = new Scanner(new File("infile.txt"));
		ps = new PrintStream(new FileOutputStream(new File("outfile.txt")));
		//
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			ps.format("Case #%d: ", t);
			//
			oneCase();
		}
	}
	
	private static int[][] multBySelf(int[][] mat) {
		int m = mat.length;
		int[][] res = new int[m][m];
		for (int r = 0; r < m; r++) {
			for (int c = 0; c < m; c++) {
				
			}
		}
		
		return null;
	}

}
