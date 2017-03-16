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
	Person [] d;
	ArrayList<String> permu = new ArrayList<String>();
	
	static class Person{
		int ID;
		int BFF;
		
		public Person(int BFF, int ID){
			this.BFF = BFF;	
			this.ID = ID;
		}	
	}
	
	public static void main (String [] args){
		new Main();
	}
	
	boolean isLegal(String s){
		if (s.length() < 2)
			return true;
		
		for(int y = 0; y < s.length(); y++){
			if (y == 0){
				int right =s.charAt(y+1) - '0';
				int left = s.charAt(s.length()-1) - '0';
				int now = s.charAt(y) - '0';
				if (!((d[now].BFF == right || d[now].BFF == left))){
					//System.out.println(left + " " + now + " " + right + " " + d[left].BFF + " " + d[now].BFF + " " + d[right].BFF);
					return false;
				}
			}	
			else if (y == s.length()-1){
				int right = s.charAt(0) - '0';
				int left = s.charAt(y-1) - '0';
				int now = s.charAt(y) - '0';
				if (!((d[now].BFF == right || d[now].BFF == left))){
					//System.out.println("WRONG2");
					return false;
				}
			}
			else{
				int right = s.charAt(y+1) - '0';
				int left = s.charAt(y-1) - '0';
				int now = s.charAt(y) - '0';
				if (!((d[now].BFF == right|| d[now].BFF == left))){
					//System.out.println("WRONG3");
					return false;
				}	
			}
		}	
		return true;
	}
	
	private void permutation(String prefix, String str) {
		if (prefix.length() > 5 && !isLegal(prefix.substring(1, prefix.length()-2))){
			//System.out.println("Illegal");
			return;
		}
		else if (prefix.length() > 2){
			permu.add((prefix));
		}
		//System.out.println("Legal");
		int n = str.length();
		//if (n >= 3) 
			//permu.add((prefix));
		//else {
			for (int i = 0; i < n; i++)
				permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
		//}
	}
	

	public Main(){
		try{
			in = new BufferedReader(new FileReader("problemC-small8.in"));
			PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
			int T = nextInt();
			for(int q = 0; q < T; q++){
				permu = new ArrayList<String>();
				int N = nextInt();
				//System.out.println(N);
				d = new Person[N]; //N
				for(int x = 0; x < N; x++){
					int num = nextInt() - 1;
					d[x] = new Person(num, x);
					//System.out.println(num);
				}
				
				if (N <= 1){
					out.println("Case #" + (q+1) + ": " + 0);
					continue;	
				}
				if (N == 2){
					out.println("Case #" + (q+1) + ": " + 2);	
					continue;
				}
				
				//System.out.println(isLegal("0123"));
				//if (1 == 1)continue;
				
				/* Now try all combinations! */
				String str = "";
				for(int x = 0; x < N; x++){
					str += x + "";	
				}
				permutation("", str); 
				//Collections.sort(permu);
				//System.out.println(permu.size());
				int best = 0;
				String bestS = "";
				
				for(int x = permu.size()-1; x>= 0; x--){
					//now see if it's legal
					if (permu.get(x).length() < 3)
						continue;
						
					if (isLegal(permu.get(x)) && permu.get(x).length() > best){
						bestS = (permu.get(x));
						best = permu.get(x).length();
					}
					
				}
				out.println("Case #" + (q+1) + ": " + best);
				//System.out.println(bestS);
				//System.out.println("DONE");
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