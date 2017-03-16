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
			in = new BufferedReader(new FileReader("aSmall2.in"));
			PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
			//System.out.println("Case #" + q + ": ");
			
			int T = nextInt();
			for(int q = 0; q < T; q++){
				String input = next();
				ArrayList<String> list = new ArrayList<String>();
				for(int x =0 ; x < input.length(); x++){
					list.add(input.charAt(x) + "");	
				}
				String [] rid = new String[10];
				HashMap<Integer, Integer> convert = new HashMap<Integer, Integer>();
				/*convert.put(1, 7);
				convert.put(7,1);
				convert.put(6, 3);
				convert.put(3, 6);*/
				
				
				
				rid[0] = "ZERO";
				
				rid[1] = "SIX";
				convert.put(1, 6);
				rid[2] = "TWO";
				
				rid[3] = "FOUR";
				convert.put(3, 4);
				rid[4] = "EIGHT";
				convert.put(4, 8);
				rid[5] = "FIVE";
				
				rid[6] = "THREE";
				convert.put(6, 3);
				rid[7] = "SEVEN";
				rid[8] = "NINE";
				convert.put(8, 9);
				rid[9] = "ONE";
				convert.put(9, 1);
				
				for(int x = 0; x < 10; x++){
					if (convert.get(x) == null)
						convert.put(x, x);
				}
				
				/*rid[1] = "SEVEN";
				rid[2] = "TWO";
				rid[3] = "SIX";
				rid[4] = "FOUR";
				rid[5] = "FIVE";
				rid[6] = "THREE"; //this
				rid[7] = "ONE";
				rid[8] = "EIGHT";
				rid[9] = "NINE";*/
				
				ArrayList<Integer> sol = new ArrayList<Integer>();
				for(int x = 0; x < rid.length; x++){
					boolean isFound = true;
					for(int y =0; y < rid[x].length(); y++){
						if (list.indexOf(rid[x].charAt(y)+"") != -1){
							list.remove(list.indexOf(rid[x].charAt(y)+""));
							
						}	
						else{
							for(int z = y-1; z >= 0; z--){
								list.add(rid[x].charAt(z) + "");
							}	
							isFound = false;
							break;
						}
					}	
					if (isFound){
						//System.out.println("FOUND: " + x);
						//System.out.println(rid[x]);
						//if (x == 1){
							//x = 7;	
						//}
					//	else if (x == 7){
						//	x = 1;
						//}	
						if (convert.get(x) != null){
							sol.add(convert.get(x));
							//System.out.println(convert.get(x));
						}
						else{
							sol.add(x);
							//System.out.println("NULL" + x);
						}
						x--;
					}
				}
				if (list.size() != 0){
					System.out.println(list.size() + "OH NO " + input);
				}
				Collections.sort(sol);
				String ans = "";
				for(int x = 0; x < sol.size(); x++)
					ans += sol.get(x);
				
				out.println("Case #" + (q+1) + ": " + ans);
					
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