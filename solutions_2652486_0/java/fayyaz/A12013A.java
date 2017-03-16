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



public class A12013A {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new A12013A();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int r = nextInt();
			int n = nextInt();
			m = nextInt();
			int k = nextInt();
			cards = new int[n];
			stored = new int[n];
			writeln("Case #"+counter+":");
			while(r-->0){
				v = new int[k];
				for (int i = 0; i < v.length; i++) {
					v[i]=nextInt();
				}
				dfs(0, 2);
				for (int i = 0; i < stored.length; i++) {
					write(""+stored[i]);
				}
				writeln("");
			}
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	static int m;
	static int [] cards ;
	static int [] v;
	static int [] stored;
	public static void dfs(int index,int last) {
		if(index == cards.length){
			// valid set :)
			muls = new boolean[126];
			mul(0,1);
			for (int i = 0; i < v.length; i++) {
				if(!muls[v[i]])return;
			}
			for (int i = 0; i < cards.length; i++) {
				stored[i]=cards[i];
			}
			return;
		}
		for (int i = last; i <= m; i++) {
			cards[index]=i;
			dfs(index+1,i);
		}
	}
	static boolean [] muls;
	public static void mul(int index,int m) {
		muls[m]=true;
		if(index == cards.length)return;
		mul(index+1,m);
		mul(index+1,m*cards[index]);
	}
	
	public A12013A() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("A12013A.out");
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
