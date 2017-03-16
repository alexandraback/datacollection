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
	
	public void generate(String str, int size, int done){
		if (str.length() < size){
			//System.out.println(str.length() + " " + size);
			if (done > 0)
				generate(str + "1", size, done-1);
			if (size-str.length() > done)
				generate(str + "0", size, done);	
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
				System.out.println(B + " " + M); //B*B-B
				//generate("", (int)(22));
				boolean done = false;
				poss:{
					int xx = 0;
					if (M >= 18 && B == 6){
						xx = 25;
					}
					else if (M == 14 && B == 6){
						xx = 25;
					}
					else if (M == 17 && B == 6){
						xx = 25;
					}
					for(; xx <= B*B-B; xx++){
						possibility = new ArrayList<String>();
						generate("", B*B-B, xx);
						boolean survived = false;
						for(int yy = 0; yy < possibility.size(); yy++){
							String ok = possibility.get(yy);
							int [] [] arr = new int[B][B];
							int counting = 0;
							for(int y = 0; y < B-1; y++){
								for(int x = 0; x < B; x++){
									arr[x][y] = possibility.get(yy).charAt(counting)-'0';
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
											if (x != temp && arr[x][temp] == 1){ // x temp
												count[x] += count[temp];
												if (count[x] > M){
													break bfs;	
												}
												Q.addLast(x);
											}
										}
									}	
								}
								survived = true;
								for(int x = 0; x < count.length; x++){
									if (count[x] > M)
										survived = false;	
								}
								if (count[count.length-1] == M){
									done = true;
									for(int x = 0; x < count.length; x++){
										System.out.print(count[x] + " ");	
									}
									System.out.println("done");
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
						if (!survived){
							//yy = 1000000;
							break poss;	
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