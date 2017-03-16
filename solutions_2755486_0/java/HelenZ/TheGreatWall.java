import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Vector;

public class TheGreatWall {
	
	private static class attack implements Comparable<attack>{
		int b, e, d;
		long s;
		public attack(int b, int e, long s, int d){
			this.b = b;
			this.e = e;
			this.s = s;
			this.d = d;
		}
		public int compareTo(attack a){
			if (d < a.d)return -1;
			if (d > a.d)return 1;
			if (s > a.s)return 1;
			if (s < a.s)return -1;
			return 0;
		}
	}
	
	public static void main(String [] args) throws IOException{
		Scanner cin = new Scanner(new FileReader("input.txt"));
		PrintWriter cout = new PrintWriter(new FileWriter("output.txt"));
		int T = cin.nextInt();
		Vector<attack> v = new Vector<attack>();
		for (int t=0;t<T;++t){
			int N = cin.nextInt();
			for (int ii=0;ii<N;++ii){
			int d = cin.nextInt(), n = cin.nextInt(), b = cin.nextInt(), e = cin.nextInt(), s = cin.nextInt();
			int dd = cin.nextInt(), dp = cin.nextInt(), ds = cin.nextInt();
			for (int i=0;i<n;++i){
				v.add(new attack(b, e, s, d));
				d += dd;
				e += dp; b += dp;
				s += (long)ds;
			}
			}
			attack []a = new attack[v.size()];
			v.toArray(a);
			Arrays.sort(a);
			//for (int i=0;i<a.length;++i)cout.println(a[i].b+" "+a[i].e+" "+a[i].s+" "+a[i].d);
			//cout.flush();
			int MAX = 10000, za = 5000, cnt = 0;
			N = a.length;
			long []x = new long[MAX];
			for (int i=0;i<N;++i){
				int b = a[i].b, e = a[i].e;
				boolean succeed = false;
				for (int j=b+za;j<e+za;++j)if (x[j] < a[i].s){succeed = true; x[j] = a[i].s;}
				if (succeed)cnt++;
			}
			cout.println("Case #"+(t+1)+": "+cnt);
			v.clear();
		}
		cout.flush();
	}

}