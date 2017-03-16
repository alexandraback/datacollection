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



public class Qual2013B {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new Qual2013B();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			int m = nextInt();
			int state [][] = new int [n][m];
			for (int i = 0; i < state.length; i++) 
				for (int j = 0; j < state[i].length; j++) 
					state[i][j]=nextInt();
			
			boolean can = true;
			for (int i = 0; i < state.length; i++) 
				for (int j = 0; j < state[i].length; j++) 
					can &= check(state,i,j);
			writeln("Case #"+counter+": "+(can?"YES":"NO"));
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static boolean check(int[][] state, int i, int j) {
		// TODO Auto-generated method stub
		if(state[i][j]>100)return false;
		boolean ret = true;
		for (int k = 0; k < state[i].length; k++) {
			if(state[i][k]>state[i][j])ret = false;
		}
		if(ret) return true;
		ret = true;
		for (int k = 0; k < state.length; k++) {
			if(state[k][j]>state[i][j])ret = false;
		}
		return ret;
	}

	public Qual2013B() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Qual2013B.in"));
		out = new PrintWriter("Qual2013B.in");
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
