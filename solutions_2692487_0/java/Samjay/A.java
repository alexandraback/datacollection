package con2013R1B;

import java.io.*;
import java.util.*;

public class A {

	//private static final String islarge = "-large";
	private static final String fileName = "results/con2013R1B/"+A.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	private void solve() {
		int A = in.nextInt(),
			N = in.nextInt();
		int[]ns = new int[N];
		for(int i=0;i<N;i++){
			ns[i]=in.nextInt();
		}
		Arrays.sort(ns);
		int total = 0,
			best = N;
		for(int i=0;i<N;i++){
			if(A <= ns[i]){
				if(A==1){
					total=N;
					break;
				}
				best = Math.min(best, total+(N-i));
				A += (A-1);
				total++;
				i--;
			}else{
				A+=ns[i];
			}
		}
		best = Math.min(best, total);
		System.out.println(best);
		out.println(best);
	}

	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
