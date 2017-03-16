import java.io.*;
import java.math.*;
import java.util.*;

public class C{
	public static void main(String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("Cin.txt"));
		PrintWriter fout = new PrintWriter(new FileWriter("Cout.txt"));

		String in = fin.readLine();
		int tt = Integer.parseInt(in);

		int t = 1;

		while(t <= tt){
			//System.out.println("asdf");
			in = fin.readLine();
			String[] sp = in.split(" ");
			double d = Double.parseDouble(sp[0]);
			int n = Integer.parseInt(sp[1]);
			int A = Integer.parseInt(sp[2]);

			double[] ti = new double[n];
			double[] xi = new double[n];
			for(int i = 0; i < n; i++){
				in = fin.readLine();
				sp = in.split(" ");
				ti[i] = Double.parseDouble(sp[0]);
				xi[i] = Double.parseDouble(sp[1]);
			}
			double[] ai = new double[A];
			in = fin.readLine();
			sp = in.split(" ");
			for(int i = 0; i < A; i++){
				ai[i] = Double.parseDouble(sp[i]);
			}

			double[] res = new double[A];
			for(int i = 0; i< A; i++){
				if(n == 1){
					res[i] = Math.max(ti[0], Math.pow(2.0 * d / ai[i], .5));
				} else{
					double v = (xi[1] - xi[0]) / (ti[1] - ti[0]);
					double tempt = (d - xi[0]) / v;
					double tempt2 = Math.pow(2.0 * d / ai[i], .5);
					res[i] = Math.max(tempt, tempt2);
				}
			}





			fout.println("Case #" + t + ":");
			for(int i = 0; i < A; i++){
				fout.println(res[i]);
			}
			fout.flush();
			t++;
		}
	}
}