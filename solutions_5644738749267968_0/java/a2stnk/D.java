package cj2014.q;
import java.io.*;
import java.util.*;

public class D {
	Scanner sc;
	PrintWriter pw;
	int N;
	double[][] w;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"D-small-attempt0";

		try {
			new D().run(filePrefix);
		} catch(Exception e) {
//			System.err.println("file read error");
			System.err.println(e);
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		N = sc.nextInt();
		w = new double[2][N];
		for(int i=0; i<N; i++)
			w[0][i] = sc.nextDouble();
		for(int i=0; i<N; i++)
			w[1][i] = sc.nextDouble();
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	public void solve() {
		Arrays.sort(w[0]);
		Arrays.sort(w[1]);
		
		println(cnt(w[0],w[1]) + " " + (N-cnt(w[1],w[0])));
	}
	
	public int cnt(double[] me, double[] you) {
		int a=0,b=0;
		int cnt=0;
		while(a<N && b<N) {
			if(me[a]>you[b]) {
				cnt++;
				a++;
				b++;
			} else {
				a++;
			}
		}
		return cnt;
	}
}
