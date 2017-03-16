import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class B implements Comparable<B> {
	int pos;
	int v;
	public int compareTo(B b) {
		return Integer.compare(v, b.v) != 0 ? Integer.compare(v, b.v) : Integer.compare(b.pos, pos);
	}
	public B(int p, int vv) {
		pos = p;
		v = vv;
	}
	public static void main(String[] args) throws IOException {
		String name = "B-small-attempt1";
		Scanner sc = new Scanner(new File(name + ".in"));
		//Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter(name + ".out"));
		int n = sc.nextInt();
		for (int c = 1; c <= n; c++) {
			int E = sc.nextInt(), R = sc.nextInt(), N = sc.nextInt();
			int[] v = new int[N];
			B[] bs = new B[N];
			for(int i = 0; i < N; i++) {
				v[i] = sc.nextInt();
				bs[i] = new B(i, v[i]);
			}
			Arrays.sort(bs);
			long gain = 0;
			TreeSet<Integer> poss = new TreeSet<Integer>();
			for(int i = N-1; i >= 0; i--) {
				int dist;
				int pos = bs[i].pos;
				if(poss.higher(pos) == null) {
					if(poss.lower(pos) == null) {
						dist = 0;
					} else {
						dist = pos - poss.lower(pos);
					}
				} else {
					if(poss.lower(pos) == null) {
						dist = poss.higher(pos) - pos;
					} else {
						dist = Math.min(poss.higher(pos) - pos, pos -poss.lower(pos));
					}
				}
				long energy = dist;
				energy *= R;
				energy = dist == 0 ? E : Math.min(energy, E);
				gain += energy * bs[i].v;
				//System.out.println(gain);
				poss.add(bs[i].pos);
			}
			out.println("Case #" + c + ": " + gain);
			System.out.println("Case #" + c + ": " + gain);
		}
		out.close();
		sc.close();
	}

}
