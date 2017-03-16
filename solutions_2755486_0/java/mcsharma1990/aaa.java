import java.util.Scanner;
import java.util.List;
import java.io.IOException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("greatwall.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("greatwall.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		GreatWall solver = new GreatWall();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class GreatWall {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        out.print("Case #" + testNumber + ": ");
        
        int N = in.nextInt();
        int[] day = new int[N];
        int[] nAttacks = new int[N];
        int[] left = new int[N];
        int[] right = new int[N];
        int[] strength = new int[N];
        int[] delD = new int[N];
        int[] delP = new int[N];
        int[] delS = new int[N];
        
        List<Attack> attacks = new ArrayList<Attack>();
        for (int i = 0; i < N; ++i) {
            day[i] = in.nextInt();
            nAttacks[i] = in.nextInt();
            left[i] = in.nextInt() + 300;
            right[i] = in.nextInt() + 300;
            strength[i] = in.nextInt();
            delD[i] = in.nextInt();
            delP[i] = in.nextInt();
            delS[i] = in.nextInt();
            for (int j = 0; j < nAttacks[i]; ++j) {
                attacks.add(new Attack(
                                       day[i] + delD[i] * j,
                                       left[i] + delP[i] * j,
                                       right[i] + delP[i] * j,
                                       strength[i] + delS[i] * j
                                       ));
            }
        }
        
        long[] wall = new long[600];
        long[] nh = new long[600];
        
        Collections.sort(attacks);
        int d = attacks.get(0).day;
        int res = 0;
        for (Attack a : attacks) {
            if (a.day != d) {
                d = a.day;
                System.arraycopy(nh, 0, wall, 0, 600);
            }
            boolean success = false;
            for (int i = a.left; i < a.right; ++i) {
                if (wall[i] < a.strength) {
                    success = true;
                    nh[i] = Math.max(nh[i], a.strength);
                }
            }
            if (success) ++res;
        }
        
        out.println(res);
    }
    
    class Attack implements Comparable<Attack> {
        int day, left, right, strength;
        public Attack(int day, int left, int right, int strength) {
            this.day = day;
            this.left = left;
            this.right = right;
            this.strength = strength;
        }
        public int compareTo(Attack other) {
            return day - other.day;
        }
    }
}