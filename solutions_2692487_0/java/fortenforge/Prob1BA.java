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
		int T = Integer.parseInt(f.readLine());
		for(int n = 0; n < T; n++){
			String[] str = (f.readLine()).split(" ");
			int A = Integer.parseInt(str[0]);
			int N = Integer.parseInt(str[1]);
			String[] str2 = (f.readLine()).split(" ");
			ArrayList<Integer> motes = new ArrayList<Integer>();
			for(int i = 0; i < N; i++){
				motes.add(Integer.parseInt(str2[i]));
			}
			Collections.sort(motes);
			int ans = solve(A, motes);
			System.out.println("Case #" + (n+1) + ": " + ans);
		}
		//long end = System.currentTimeMillis();
		//System.out.println(end - start);
		out.close();
	}
	
	public static int solve(int A, ArrayList<Integer> motes){
		if(motes.size() == 0)
			return 0;
		while(A > motes.get(0)){
			A += motes.get(0);
			motes.remove(0);
			if(motes.size() == 0)
				return 0;
		}
		//System.out.println(motes);
		if(A == 1)
			return motes.size();
		int x = motes.size();
		return Math.min(solve(2*A - 1, motes) + 1, x);
	}
	

}