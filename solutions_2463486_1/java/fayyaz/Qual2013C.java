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



public class Qual2013C {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	static long [] nums = {1l,
		4l,
		9l,
		121l,
		484l,
		10201l,
		12321l,
		14641l,
		40804l,
		44944l,
		1002001l,
		1234321l,
		4008004l,
		100020001l,
		102030201l,
		104060401l,
		121242121l,
		123454321l,
		125686521l,
		400080004l,
		404090404l,
		10000200001l,
		10221412201l,
		12102420121l,
		12345654321l,
		40000800004l,
		1000002000001l,
		1002003002001l,
		1004006004001l,
		1020304030201l,
		1022325232201l,
		1024348434201l,
		1210024200121l,
		1212225222121l,
		1214428244121l,
		1232346432321l,
		1234567654321l,
		4000008000004l,
		4004009004004l};
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new Qual2013C();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			long a = nextLong();
			long b = nextLong();
			
			int c = 0;
			for (int i = 0; i < nums.length; i++) {
				if(nums[i]>=a && nums[i]<=b)c++;
			}
			
			writeln("Case #"+counter+": "+c);
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	
	private static boolean pl(long i) {
		char[] s = (""+i).toCharArray();
		for (int j = 0; j < s.length; j++) {
			if(s[j]!=s[s.length-1-j])return false;
		}
		return true;
	}
	

	public Qual2013C() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Qual2013C.in"));
		out = new PrintWriter("Qual2013C.out");
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
