/*
PROG: Prob1BA
LANG: JAVA
ID: sridhar4
*/

import java.io.*;
import java.util.*;

public class Prob1BA{

	public static void main(String [] args) throws IOException {
		//long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(new FileReader("Prob1BA.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Prob1BA.out")));
		long T = Long.parseLong(f.readLine());
		for(long n = 0; n < T; n++){
			String[] str = (f.readLine()).split(" ");
			long A = Long.parseLong(str[0]);
			long N = Long.parseLong(str[1]);
			String[] str2 = (f.readLine()).split(" ");
			ArrayList<Long> motes = new ArrayList<Long>();
			for(int i = 0; i < N; i++){
				motes.add(Long.parseLong(str2[i]));
			}
			Collections.sort(motes);
			long ans = solve(A, motes);
			out.println("Case #" + (n+1) + ": " + ans);
		}
		//long end = System.currentTimeMillis();
		//System.out.prlongln(end - start);
		out.close();
	}
	
	public static long solve(long A, ArrayList<Long> motes){
		if(motes.size() == 0)
			return 0;
		while(A > motes.get(0)){
			A += motes.get(0);
			motes.remove(0);
			if(motes.size() == 0)
				return 0;
		}
		//System.out.prlongln(motes);
		if(A == 1)
			return motes.size();
		long y = motes.size();
		if(motes.get(0) > 20*A){
			long x = (long)(Math.log10(((double)motes.get(0))/(A-1))/Math.log10(2));
			x -= 2;
			long z = (long) (Math.pow(2, x)*A - Math.pow(2, x) + 1);
			return Math.min(solve(z, motes) + x, y);
		}
		return Math.min(solve(2*A - 1, motes) + 1, y);
	}
	

}