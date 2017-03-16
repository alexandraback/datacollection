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
	ArrayList<String> possibility = new ArrayList<String>();
	
	
	public static void main (String [] args){
		new Main();
	}
	
	static class Node{
		int ID;
		long count;
		
	}
	
	public void generate(String str, int size){
		if (str.length() < size){
			//System.out.println(str.length() + " " + size);
			generate(str + "1", size);
			generate(str + "0", size);	
		}
		else{
			possibility.add(str);
			return;
		}
	}

	public Main(){
		try{
			in = new BufferedReader(new FileReader("input.txt"));
			PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
			//generate("", 30);
			//System.out.println("Case #" + q + ": ");
			int T = nextInt();
			//T = 0;
			for(int q = 0; q < T; q++){
				possibility = new ArrayList<String>();
				int B = nextInt();
				int M = nextInt();
				generate("", B*B-B);
				boolean done = false;
				poss:{
					for(int xx = 0; xx < possibility.size(); xx++){
						String ok = possibility.get(xx);
						int [] [] arr = new int[B][B];
						int counting = 0;
						for(int y = 0; y < B-1; y++){
							for(int x = 0; x < B; x++){
								arr[x][y] = possibility.get(xx).charAt(counting)-'0';
								counting++;
							}
						}
						
						int [] count = new int[B];
						for(int x = 0; x < count.length; x++){
							count[x] = 0;
						}
						ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
						Q.addLast(0);
						count[0] = 1;
						bfs:{
							while(!Q.isEmpty()){
								int size = Q.size();
								for(int qq = 0; qq < size; qq++){
									int temp = Q.removeFirst();
									for(int x = 0; x < B; x++){
										if (x != temp && arr[x][temp] == 1){
											count[x] += count[temp];
											if (count[x] > M){
												break bfs;	
											}
											Q.addLast(x);
										}
									}
								}	
							}
							if (count[count.length-1] == M){
								done = true;
								out.println("Case #" + (q+1) + ": POSSIBLE");
								for(int y = 0; y < B; y++){
									for(int x = 0; x < B; x++){
										out.print(arr[x][y]);	
									}
									out.println();
								}	
								break poss;
							}
						}
						
					}
				}
				if (!done){
					out.println("Case #" + (q+1) + ": IMPOSSIBLE");
				}
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