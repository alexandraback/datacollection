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
	
	static class Priority implements Comparable<Priority>{
		String a;
		String b;
		int p;
		
		public Priority(String a, String b, int p){
			this.a = a;
			this.b = b;
			this.p = p;	
		}
		
		public int compareTo(Priority o){
			return o.p - p;	
		}
		
	}

	public Main(){
		try{
			in = new BufferedReader(new FileReader("cSmall3.in"));
			PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
			
			int T = nextInt();
			for(int q = 0; q < T; q++){
				int N = nextInt();
				Priority[] arr = new Priority[N];
				HashMap<String, Boolean> usedA = new HashMap<String, Boolean>();
				HashMap<String, Boolean> usedB = new HashMap<String, Boolean>();
				HashMap<String, Boolean> ex = new HashMap<String, Boolean>();
				for(int qq = 0; qq < N; qq++){
					String a = next();
					String b = next();
					
					
					if (usedA.get(a) == null && usedB.get(b) == null){
						arr[qq] = new Priority(a, b, 0);
					}
					else{
						arr[qq] = new Priority(a, b, 0);	
					}
					usedA.put(a, true);
					usedB.put(b, true);
				}	
				for(int qq = 0; qq < N; qq++){
					if (usedA.get(arr[qq].a) != null && usedB.get(arr[qq].b)!=null){
						arr[qq].p=0;	
					}
					else if (usedA.get(arr[qq].a) != null ||  usedB.get(arr[qq].b)!=null){
						arr[qq].p=1;	
					}
				}	
				
				Arrays.sort(arr);
				int counter = 0;
				usedA = new HashMap<String, Boolean>();
				usedB = new HashMap<String, Boolean>();
				ex = new HashMap<String, Boolean>();
				for(int x = 0; x < arr.length; x++){
					Priority temp = arr[x];
					//System.out.println(temp.a + " " + temp.b);
					if (usedA.get(temp.a) != null && usedB.get(temp.b) != null && ex.get(temp.a + temp.b) == null){
						//if (!(usedA.get(temp.a) == null && usedB.get(temp.b) == null)){
							counter++;
							ex.put(temp.a + temp.b, true);
						//}	
					}
					usedA.put(temp.a, true);
					usedB.put(temp.b, true);
				}	
				out.println("Case #" + (q+1)+": " + counter);
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