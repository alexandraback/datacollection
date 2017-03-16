import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;


public class sub {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	public static String next() throws Exception {
		while (true) {
			if (st.hasMoreTokens())
				return st.nextToken();
			String s = br.readLine();
			if (s == null)
				return null;
			st = new StringTokenizer(s);
		}
	}
	public static int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	public static void main(String[] args) throws Exception {
		 int T = nextInt();
		 for(int it = 1 ; it <= T; it++){
			 
			 int n = nextInt();
			 
			 int [] num = new int[n];
			 for(int i = 0 ; i < n; i++){
				 num[i] = nextInt();
			 }
			 int sum[] = new int[(int)Math.pow(2, n)];
			 HashMap<Integer, Integer> map = new HashMap<Integer,Integer>();
			 int curI = -1;
			 int curI2 = -1;
			 for(int i = 0 ; i < sum.length ; i ++){
				 
				 for(int j = 0 ; j < n ; j++){
					 if( (i & (1 << j)) != 0){
						 sum[i] += num[j]; 
					 }
				 }
				if(map.containsKey(sum[i])){
					curI2 = map.get(sum[i]);
					curI = i;
					break;
				}else
				map.put(sum[i], i);
			 }
			 System.out.println("Case #"+it + ":");
			 if(curI == -1)
				 System.out.println("IMPOSSIBLE");
			 else{
				 String s1 = "";
				 for(int j = 0 ; j < n ; j++){
					 if( (curI & (1 << j)) != 0){
						 s1 += (num[j] + " "); 
					 }
				 }
				 System.out.println(s1.trim());
				 s1 = "";
				 for(int j = 0 ; j < n ; j++){
					 if( (curI2 & (1 << j)) != 0){
						 s1 += num[j]+ " "; 
					 }
				 }
				 System.out.println(s1.trim());
			 }
		 }
		 
		 
	}
}
