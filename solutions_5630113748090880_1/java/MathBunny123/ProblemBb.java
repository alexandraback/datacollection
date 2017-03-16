/* Programming Competition - Template (Horatiu Lazu) */

import java.io.*;
import java.util.*;
import java.lang.*;
import java.awt.*;
import java.awt.geom.*;
import java.math.*;
import java.text.*;


class Main{
	BufferedReader in;
	StringTokenizer st;
	
	public static void main (String [] args){
		new Main();
	}

	public Main(){
		try{
			in = new BufferedReader(new FileReader("ProblemB-large.in"));
			PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
			int T = nextInt();
			for(int q = 0; q < T; q++){
				int N = nextInt();
				String input = "";
				int [] arr2 = new int[N*2-1];
				int [] arr = new int[2501];
				//let each number be one less and add at the end ;p
				for(int x = 0; x < N*2-1; x++){
					for(int y = 0; y < N; y++)
						arr[nextInt()]++;
				}
				String output = "";
				for(int x = 0; x < arr.length; x++){
					if (arr[x] % 2 == 1){
						output += x + " ";
					}
				}
				output = output.trim();
				out.println("Case #" + (q+1) + ": " + output);
			}
			out.close();
			
		}
		catch(IOException e){
			System.out.println("IO: General");
		}
	}
	
	String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
	   	 	st = new StringTokenizer(in.readLine().trim());
		return st.nextToken();
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	String nextLine() throws IOException {
		return in.readLine().trim();
	}
}