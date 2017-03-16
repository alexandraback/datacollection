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
import java.util.StringTokenizer;



public class C {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new C();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			int [] s = new int [n] ;
			for(int i = 0 ; i < n ; i++)s[i]=nextInt();
			boolean f = false;
			HashMap<Integer, Integer> sumtoindex = new HashMap<Integer, Integer>();
			for (int i = 1; i < (1<<n); i++) {
				int sum = ss(i,s);
				if(sumtoindex.containsKey(sum)){
					writeln("Case #"+counter+":");
					print(sumtoindex.get(sum),i,s);
					f = true;
					break;
				}
				sumtoindex.put(sum, i);
			}
			if(!f)
			writeln("Case #"+counter+": Impossible");
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static void print(int j, int i, int[] s) {
		// TODO Auto-generated method stub
		boolean a = false;
		for (int k = 0; k < s.length; k++) {
			if((j&1<<k)!=0){
				if(a)write(" "+s[k]);
				else write(""+s[k]);
				a=true;
			}
		}
		writeln("");
		a = false;
		for (int k = 0; k < s.length; k++) {
			if((i&1<<k)!=0){
				if(a)write(" "+s[k]);
				else write(""+s[k]);
				a=true;
			}
		}
		writeln("");
	}

	private static int ss(int i, int[] s) {
		// TODO Auto-generated method stub
		int ss = 0;
		for (int j = 0; j < s.length; j++) {
			if((i&1<<j)!=0)ss+=s[j];
		}
		return ss;
	}

	public C() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("C.in"));
		out = new PrintWriter("C.txt");
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
