import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.StringTokenizer;



public class Round1C2013C {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new Round1C2013C();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			PriorityQueue<attack> at = new PriorityQueue<Round1C2013C.attack>();
			while(n-->0){
				int day = nextInt();
				int numofatt = nextInt();
				int w = nextInt();int e = nextInt();
				int str = nextInt();
				int dd = nextInt();
				int dp = nextInt();
				int ds = nextInt();
				for (int i = 0; i < numofatt; i++) {
					at.add(new attack(day+dd*i, str+ds*i, w+dp*i, e+dp*i));
				}
			}
			int ans = 0;
			int lastday = 0;
			HashMap<Integer, Integer> wall = new HashMap<Integer, Integer>();
			HashMap<Integer, Integer> newwall = new HashMap<Integer, Integer>();
			while(!at.isEmpty()){
				attack a = at.poll();
				if(lastday<a.day){
					for (int i : newwall.keySet()) {
						wall.put(i, newwall.get(i));
					}
					newwall = new HashMap<Integer, Integer>();
					lastday = a.day;
				}
				
				
				boolean ss = false;
				for (int i = a.w; i < a.e; i++) {
					if(!wall.containsKey(i))wall.put(i, 0);
					if(wall.get(i)<a.str){
						ss=true;
						if(newwall.containsKey(i))
							newwall.put(i, Math.max(a.str, newwall.get(i)));
						else 
							newwall.put(i, a.str);
					}
				}
				if(ss)ans++;
			}
			
			
			
			writeln("Case #"+counter+": "+ans);
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	public Round1C2013C() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Round1C2013C.in"));
		out = new PrintWriter("Round1C2013C.out");
		//-------------------------------------------------------------------------
		//Initalize Stringtokenizer input
		input = new StringTokenizer(in.readLine());
	}

	private static int nextInt() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Integer.parseInt(input.nextToken());
	}
	private static long nextLong() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Long.parseLong(input.nextToken());
	}
	private static double nextDouble() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Double.parseDouble(input.nextToken());
	}
	private static String nextString() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return input.nextToken();
	}
	private static void write(String output){
		out.write(output);
		out.flush();
	}
	private static void writeln(String output){
		out.write(output+"\n");
		out.flush();
	}
	private static void end() throws IOException{
		in.close();
		out.close();
		System.exit(0);
	}
	
	static class attack implements Comparable<attack>{
		
		int day;
		int str;
		int w;
		int e;
		public attack(int day, int str, int w, int e) {
			super();
			this.day = day;
			this.str = str;
			this.w = w;
			this.e = e;
		}
		@Override
		public int compareTo(attack o) {
			if(day==o.day)
				if(w==o.w)
					return e-o.e;
				else return w-o.w;
			else
			return day-o.day;
		}
		
		
		
		
	}
	
	
}
