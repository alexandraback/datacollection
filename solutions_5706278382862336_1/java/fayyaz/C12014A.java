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




public class C12014A {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new C12014A();
		//-------------------------------------------------------------------------
		int testCases = Integer.parseInt(in.readLine());
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			String [] s = in.readLine().replace("/", " ").split(" ");
			long p = Long.parseLong(s[0]);
			long q = Long.parseLong(s[1]);
			long gcd = gcd(p,q);
			p/=gcd;q/=gcd;
			int twos = two(q);
			if(twos == -1) 
				out.println("Case #"+counter+": impossible");
			else {
				int level = 0;
				long now = p;
				while(true){
					if(now>=q)break;
					level ++;
					now*=2;
				}
				out.println("Case #"+counter+": "+level);
			}

		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static long gcd(long a, long b) {
		return b==0?a:gcd(b,a%b);
	}

	private static int two(long q) {
		if(q==1) return 0;
		if(q%2!=0) return -1;
		int ret = two(q/2);
		if(ret == -1) return -1;
		return 1+ ret;
	}

	
	public C12014A() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("C12014A2.out");
		//-------------------------------------------------------------------------
		//Initalize Stringtokenizer input
//		input = new StringTokenizer(in.readLine());
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
