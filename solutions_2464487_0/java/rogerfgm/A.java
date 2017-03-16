

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class A {
	static Scanner sc = null;
	static PrintWriter out = null;
	
	int INF = Integer.MAX_VALUE / 10;
	double DF = 0.0000000001;
	
	public void solve() throws Exception{
		long r = sc.nextLong();
		double t = sc.nextDouble();
		
		long ans = 0;
		while(t >= 0-DF){
			double men = (r+1)*(r+1)  - (r)*(r);
			t -= men;
			r+=2;
			if(t >= 0-DF){
				ans++;
			}
			else{
				break;
			}
		}
		out.println(ans);
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		File file = new File("A-small-attempt0.in");
		if(file.exists()){
			System.setIn(new BufferedInputStream(new FileInputStream(file)));
		}
		sc =  new Scanner(System.in);
		out = new PrintWriter(new FileWriter(new File("output.txt")));
		
		A b = new A();
		int T = sc.nextInt();
		int t = 1;
		while(t <= T){
			out.print("Case #" + t + ": ");
			b.solve();
			t++;
		}
		out.close();
	}
}
