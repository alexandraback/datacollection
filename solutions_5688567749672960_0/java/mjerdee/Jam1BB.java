import java.io.*;
import java.util.*;
public class Jam1BB{
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader( new FileReader("g.in"));
		PrintWriter out = new PrintWriter( new BufferedWriter( new FileWriter("gJamout.txt")));
		//Scanner f = new Scanner(System.in);	
		int t = i(f.readLine());
		for(int iii = 1; iii <= t; iii++){
			String[] cur = f.readLine().split(" ");	
			int n = i(cur[0]);
			out.println("Case #" + iii + ": " + (int) ans(n));
		}
		out.close();
		System.exit(0);
	}
	public static int swi(int i){
		int res = 0;
		while(i > 0){
			res *= 10;
			res += (i % 10);
			i /= 10;
		}
		return res;
	}
	public static double ans(double n){
		if(n <= 19){
			return n;
		}else{
			int dig = (int) Math.floor(Math.log(n)/Math.log(10)) + 1; int targ;
			int mid = (int) Math.pow(10, (dig + 1)/2);
			//System.out.println(n + " " + dig + " " + ((int) n / mid) + " " + ((int) Math.pow(10, dig - 1)/mid));
			if((int) n / mid != (int) Math.pow(10, dig - 1)/mid){
				targ = 1 + mid*(((int) n)/mid);
			}else{
				targ = (int) Math.pow(10, dig - 1) - 9;
			}
			//System.out.println(targ);
			return ans(swi((int) targ)) + 1 + (n - targ);
		}
	}
	public static int i(String s){ return Integer.parseInt(s); }
	public static int[][] fill(int[][] input, int val){
		int[][] res = new int[input.length][input[0].length];
		for(int i = 0; i < input.length; i++){
			for(int j = 0; j < input[0].length; j++){
				res[i][j] = val;
			}
		}
		return res;
	}
}