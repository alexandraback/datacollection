import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class B {
	public static void main(String[] args) throws Exception{
		int t = readInt();
		for(int i = 1; i <= t; i++){
			double c = readDouble();
			double f = readDouble();
			double x = readDouble();
			double curSpeed = 2.0;
			double time = 0.0;
			while(true){
				if(c/curSpeed + x/(curSpeed + f) < x/curSpeed){
					time += c/curSpeed;
					curSpeed = curSpeed + f;
				}
				else{
					time+= x/curSpeed;
					break;
				}
			}
			System.out.println("Case #" + i + ": " + time);
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
