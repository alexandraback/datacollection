import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.ObjectOutputStream.PutField;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.TreeMap;



public class B12014C {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new B12014C();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			int n = nextInt();
			int  m = nextInt();
			int [] zip = new int[n];
			for (int i = 0; i < zip.length; i++) {
				zip[i] = nextInt();
			}
			boolean [][] graph = new boolean [n][n];
			
			for (int i = 0; i < m; i++) {
				int a = nextInt()-1;
				int b = nextInt()-1;
				graph[a][b] = graph[b][a] = true;
			}
			
			TreeMap<Integer, Integer> mapper = new TreeMap<Integer, Integer>();
			int mincod = zip[0];
			int index = 0;
			for (int i = 1; i < zip.length; i++) {
				if(zip[i] < mincod){
					mincod = zip[i];
					index = i;
				}
			}
			String ret = "";
			mapper.put(mincod, index);
			HashSet<Integer> used = new HashSet<Integer>();
			while(used.size()!= n){
				int node = mapper.pollFirstEntry().getValue();
				ret += zip[node];
				used.add(node);
				for (int i = 0; i < graph.length; i++) {
					if(graph[node][i] && !used.contains(i)){
						mapper.put(zip[i], i);
					}
				}
			}
			writeln("Case #"+counter+": "+ret);
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	static boolean [] used ;
	static int [] zip;
	
	static String play(int node,int parent){
		
		String ret = used[node]?"":""+zip[node];
		
		return ret;
	}
	
	public B12014C() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("Template.in"));
		out = new PrintWriter("B12014C.out");
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
