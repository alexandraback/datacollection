import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;



public class B12013 {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new B12013();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int a = nextInt();
			int n = nextInt();
			
			ns = new int[n];
			remove = new boolean[n];
			for (int i = 0; i < ns.length; i++) ns[i]=nextInt();
			Arrays.sort(ns);
			min = 10000000;
			limit = n;
			for (int i = ns.length; i >=0; i--) {
				limit = i;
				solve(0,a,ns.length-i);
			}
			
			writeln("Case #"+counter+": "+min);
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	private static void max() {
		int max = -1; int index = 0;
		for (int i = 0; i < ns.length; i++) {
			if(remove[i])continue;
			if(ns[i]>max){
				max= ns[i];
				index=i;
			}
		}
		remove[index]=true;
	}
	static int min;
	static int [] ns;
	static boolean [] remove;
	private static void solve(int i, int a, int j) {
		if(i==limit){ min= Math.min(min, j);return;}
		if(remove[i])solve(i+1, a, j);
		if(ns[i]<a)
			solve(i+1,a+ns[i],j);
		else
			if(a==1)
				return;
			else		
				solve(i,2*a-1,j+1);
		
	}
	static int limit;
	
	
	public B12013() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("1BA.in");
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
	
}
