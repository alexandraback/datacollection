import java.io.*;
import java.util.*;


public class third {
	public static void main(String[] args) throws Exception {
		FastScanner sc = new FastScanner(new File("C.in"));
		PrintWriter out = new PrintWriter(new File("C.out"));
		int I = sc.nextInt();
		jump: for(int i=1;i<=I;i++){
			int N = sc.nextInt();
			out.println("Case #"+i+":");
			int[] array = new int[N];
			int sum = 0;
			for(int a=0;a<N;a++){
				array[a]=sc.nextInt();
				sum+=array[a];
			}
			int[] from1 = new int[sum+1];
			Arrays.fill(from1,-1);
			from1[0]=0;
			for(int a=0;a<N;a++){
				for(int b=sum-array[a];b>=0;b--){
					if(from1[b]!=-1){
						//for(int ad=0;ad<5;ad++)System.out.print(" "+from1[ad]);
						//System.out.println();
						if(from1[b+array[a]]==-1)
						from1[b+array[a]]=array[a];
						
						else{
							//System.out.println(b+" "+array[a]+" "+a);
							String one = array[a]+" "+recurse(b,from1);
							String two = recurse(b+array[a],from1);
							if(!compared(one,two)){
								out.println(one);
								out.println(two);
								continue jump;
							}
							
						}
					}
				}
				
			}
			
			
			
			out.println("Impossible");
			

		}
		
		out.close();
	}
	
	
	private static boolean compared(String one, String two) {
		Scanner s1 = new Scanner(one);

		HashSet<Integer> HS = new HashSet<Integer>();
		while(s1.hasNext()){
			int t = s1.nextInt();
			if(HS.contains(t))return true;
			HS.add(t);
		}
		s1 = new Scanner(two);
		while(s1.hasNext()){
			int t = s1.nextInt();
			if(HS.contains(t))return true;
			HS.add(t);
		}
		return false;
	}


	private static String recurse(int b, int[] from1) {
		if(b==0)return "";
		else return from1[b]+" "+recurse(b-from1[b],from1);
	}


	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		
		public FastScanner(File file) throws Exception{
			br = new BufferedReader(new FileReader(file));
			st = new StringTokenizer(br.readLine().trim());
		}
		public int numTokens() throws Exception {
			if(!st.hasMoreTokens()){
				st = new StringTokenizer(br.readLine().trim());
				return numTokens();
			}
			return st.countTokens();
		}
		public String next() throws Exception {
			if(!st.hasMoreTokens()){
				st = new StringTokenizer(br.readLine().trim());
				return next();
			}
			return st.nextToken();
		}
		public double nextDouble() throws Exception{
			return Double.parseDouble(next());
		}
		public float nextFloat() throws Exception{
			return Float.parseFloat(next());
		}
		public long nextLong() throws Exception{
			return Long.parseLong(next());
		}
		public int nextInt() throws Exception{
			return Integer.parseInt(next());
		}
		public String nextLine() throws Exception{
			return br.readLine().trim();
		}
	}

}
