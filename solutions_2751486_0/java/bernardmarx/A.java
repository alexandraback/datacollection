import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class A {

	static char[] name; 
	static int n;
	 
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("A.in"));
		StringBuffer buf = new StringBuffer();
	    int T = Integer.parseInt(reader.readLine());
	    StringTokenizer st;
	    for (int t = 1; t <= T; t++) {
	    	st = new StringTokenizer(reader.readLine());
	    	name = st.nextToken().toCharArray();	
	    	n = Integer.parseInt(st.nextToken());
	    	buf.append("Case #"+t+": "+solve()+"\n");
		}
	    System.setOut(new PrintStream("A.out"));
	    System.out.print(buf.toString());
	}
	
	static long solve(){
		long res = 0;
		int l = name.length;
		int[] C = new int[l];
		if (isConsonant(name[0])) C[0]=1;
		for (int i = 1; i < C.length; i++) {
			if (isConsonant(name[i])) C[i]=C[i-1]+1;
		}
		for (int i = 0; i < C.length; i++) {
			if (C[i]>=n) res+=i-n+2;				
		}
		int last = -1;
		for (int i = 0; i < C.length; i++) {
			if (C[i]<n){
				if (last!=-1){
					res+=last-n+2;
				}
			}else{
				last=i;
			}
		}
		return res;
	}
	
	static boolean isConsonant(char c){
		return ( c!='a' && c!='e' && c!='i' && c!='o' && c!='u');  
	}
	
	
}
