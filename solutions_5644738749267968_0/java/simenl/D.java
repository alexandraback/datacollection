import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class D {
	public static void main(String[] args) throws Exception{
		int t = readInt();
		for(int i = 1; i <= t; i++){
			int n = readInt();
			double[] naomi = new double[n];
			double[] ken = new double[n];
			for(int j = 0; j < n; j++){
				naomi[j] = readDouble();
			}
			for(int j = 0; j < n; j++){
				ken[j] = readDouble();
			}
			Arrays.sort(naomi);
			Arrays.sort(ken);
			int a = 0;
			int b = 0;
			int deceit = 0;
			int pure = 0;
			while(a < n && b < n){
				if(naomi[a] > ken[b]){
					deceit++;
					a++;
					b++;
				}
				else{
					a++;
				}
			}
			a = n-1;
			b = n-1;
			while(a >= 0 && b >= 0){
				if(ken[b] > naomi[a]){
					a--;
					b--;
				}
				else{
					a--;
					pure++;
				}
			}
			System.out.println("Case #" + i + ": " + deceit + " " + pure);
		}
	}
	
	static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer(" ");
	static String readString() throws Exception{
		while(!st.hasMoreTokens()){
			st = new StringTokenizer(stdin.readLine());
		}
		return st.nextToken();
	}
	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}
	static double readDouble() throws Exception {
		return Double.parseDouble(readString());
	}
	static long readLong() throws Exception {
		return Long.parseLong(readString());
	}
}
