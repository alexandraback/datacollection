import java.io.*;
import java.util.*;

public class A implements Runnable{
	public void run(){
		try{
			Locale.setDefault(Locale.US);
			Scanner in = new Scanner(new File("A-small.in"));
			PrintWriter out = new PrintWriter("A-small.out");
			int t = in.nextInt(), k, i, a, b;
			double ans, c_prob, buf_prob, buf_ans;
			double[] prob = new double[100000];
			for (k = 1; k <= t; k++){
				a = in.nextInt();
				b = in.nextInt();
				c_prob = 1;
				for (i = 0; i < a; i++){
					prob[i] = in.nextDouble();
					c_prob *= prob[i];
				}
				ans = ((b - a + 1) * c_prob) + ((b - a + b + 2) * (1 - c_prob));
				ans = Math.min(ans, 2 + b);
				buf_prob = c_prob;
				for (i = 1; i <= a; i++){
				        buf_prob /= prob[a - i];
//				        buf_ans = (i + b - a + i + 1) * c_prob;
				        buf_ans = (i + b - a + i + 1) * buf_prob;
				        buf_ans += (i + b - a + i + 1 + b + 1) * (1 - buf_prob);
					ans = Math.min(ans, buf_ans);
				}
				out.print("Case #" + k + ": ");
				out.printf("%6f\n", ans);
			}
			out.close();
		}
		catch(Exception e){
//			System.out.println(e.toString());
		}
	}

	public static void main(String[] args){
		(new Thread(new A())).start();
	}
}