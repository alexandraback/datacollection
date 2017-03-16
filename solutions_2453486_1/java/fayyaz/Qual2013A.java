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



public class Qual2013A {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new Qual2013A();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int [][] state = new int[4][4];
			for (int i = 0; i < state.length; i++) {
				char [] s = nextString().toCharArray();
				for (int j = 0; j < s.length; j++) {
					if(s[j]=='X')state[i][j]=1;
					if(s[j]=='O')state[i][j]=2;
					if(s[j]=='T')state[i][j]=3;
				}
			}
			if(check(state,1)){
				writeln("Case #"+counter+": X won");
			}else if(check(state,2)){
				writeln("Case #"+counter+": O won");
			}else if(move(state)){
				writeln("Case #"+counter+": Game has not completed");
			}else{
				writeln("Case #"+counter+": Draw");	
			}
			
			
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	static boolean move(int[][] state){
		for (int i = 0; i < state.length; i++) {
			for (int j = 0; j < state[i].length; j++) {
				if(state[i][j]==0)return true;
			}
		}
		return false;
	}
	private static boolean check(int[][] state,int p) {	
	// TODO Auto-generated method stub
		boolean ret = false;
		for (int i = 0; i < state.length; i++) {
			ret |= row(state,p,i);
			ret |= col(state,p,i);
			ret |= dig(state,p);
			ret |= idig(state,p);
		}
		return ret;
	}

	static boolean row(int [][]state,int p,int r){
		for (int i = 0; i < state.length; i++) {
			if(state[r][i]==p || state[r][i]==3)continue;
			return false;
		}
		return true;
	}
	
	static boolean col(int [][]state,int p,int c){
		for (int i = 0; i < state.length; i++) {
			if(state[i][c]==p || state[i][c]==3)continue;
			return false;
		}
		return true;
	}
	
	static boolean dig(int [][]state,int p){
		for (int i = 0; i < state.length; i++) {
			if(state[i][i]==p || state[i][i]==3)continue;
			return false;
		}
		return true;
	}
	static boolean idig(int [][]state,int p){
		for (int i = 0; i < state.length; i++) {
			if(state[3-i][i]==p || state[3-i][i]==3)continue;
			return false;
		}
		return true;
	}
	public Qual2013A() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Qual2013A.in"));
		out = new PrintWriter("Qual2013A.out");
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
		if (!input.hasMoreTokens()){input=new StringTokenizer(in.readLine());return nextString();}
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
