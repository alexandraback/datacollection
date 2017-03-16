import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class C12014B {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new C12014B();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			train  = new String[n];
			for (int i = 0; i < train.length; i++) {
				train[i] = nextString();
			}
			prem = new int[n];
			used = new boolean[n];
			
			writeln("Case #"+counter+": "+ans(0));
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	static String [] train;
	static int [] prem;
	static boolean [] used;
	static int mod = 1000000007;
	static long ans(int index){
		if(index == prem.length){
			return check();
		}
		long ret = 0;
		for (int i = 0; i < used.length; i++) {
			if(used[i]) continue;
			used[i] = true;
			prem[index] = i;
			ret += ans(index+1);
			ret %= mod;
			prem[index] = 0;
			used[i] = false;
		}
		return ret;
	}
	private static long check() {
		boolean [] before = new boolean [30] ;
		before[train[prem[0]].charAt(0)-'a'] = true;
		char last = train[prem[0]].charAt(0);
		for (int i = 0; i < prem.length; i++) {
			for (int j = 0; j < train[prem[i]].length(); j++) {
				char x = train[prem[i]].charAt(j);
				if(last == x)continue;
				if(before[x-'a']) return 0;
				before[x-'a'] = true;
				last = x;
			}
		}
		return 1;
	}
	public C12014B() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("C12014B.out");
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
