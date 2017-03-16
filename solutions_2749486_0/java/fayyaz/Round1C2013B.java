import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;



public class Round1C2013B {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	private static int[] dx = {1,-1,0,0};
	private static int[] dy = {0,0,1,-1};
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new Round1C2013B();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int x = nextInt(),y=nextInt();
			Queue<state> waiting = new LinkedList<Round1C2013B.state>();
			TreeSet<state> vis = new TreeSet<Round1C2013B.state>();
			state ss = new state(0, 0, 1, null);
			vis.add(ss);
			waiting.add(ss);
			state end = null;
			while(!waiting.isEmpty()){
				state c = waiting.poll();
				if(Math.abs(c.x)>100 || Math.abs(c.y)>100)continue;
				if(c.x==x && c.y==y){end = c;break;}
				for (int i = 0; i < dx.length; i++) {
					state sss = new state(c.x+dx[i]*c.n, c.y+dy[i]*c.n, c.n+1, c);
					if(!vis.contains(sss)){
						waiting.add(sss);
						vis.add(sss);
					}
				}
			}
			
			writeln("Case #"+counter+": "+buildpath(end));
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static String buildpath(state end) {
		// TODO Auto-generated method stub
		String ret = "";
		while(end.parent!=null){
			if(end.x > end.parent.x){
				ret = "E"+ret;
			}else if(end.x < end.parent.x){
				ret = "W"+ret;
			}else if(end.y > end.parent.y){
				ret = "N"+ret;
			}else if(end.y < end.parent.y){
				ret = "S"+ret;
			}
			end = end.parent;
		}
		return ret;
	}

	public Round1C2013B() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Round1C2013B.in"));
		out = new PrintWriter("Round1C2013B.out");
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

	
	static class state implements Comparable<state>{
		
		static int goalx;
		static int goaly;
		
		int x;
		int y;
		
		int n;
		
		state parent;

		public state(int x, int y, int n, state parent) {
			super();
			this.x = x;
			this.y = y;
			this.n = n;
			this.parent = parent;
		}

		@Override
		public int compareTo(state o) {
			// TODO Auto-generated method stub
			if(n==o.n){
				if(x==o.x){
					return y-o.y;
				}else
					return x-o.x;
			}else
				return n-o.n;
		}
		
	}
	
}

