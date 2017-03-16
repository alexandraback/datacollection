import java.io.*;
import java.math.*;
import java.util.*;

public class A{
	public static double prob(double[] p, int start, int end){
		double res = 1;
		for(int i = start; i < end; i++){
			res *= p[i];
		}

		return res;
	}

	public static void main(String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("Ain.txt"));
		PrintWriter fout = new PrintWriter(new FileWriter("Aout.txt"));

		String in = fin.readLine();
		int tt = Integer.parseInt(in);

		int t = 1;

		while(t <= tt){
			in = fin.readLine();
			String[] sp = in.split(" ");
			int a = Integer.parseInt(sp[0]);
			int b = Integer.parseInt(sp[1]);

			in = fin.readLine();
			sp = in.split(" ");
			double[] p = new double[a];
			for(int i = 0; i < a; i++){
				p[i] = Double.parseDouble(sp[i]);
			}

			double min = Double.MAX_VALUE;

			min = b + 2;
			
			double tmp = prob(p, 0, a) * (b - a + 1) + (1 - prob(p, 0, a))*(2 * b - a + 2);

			if(tmp < min)
				min = tmp;

			for(int i = 1; i <= a; i++){
				tmp = prob(p, 0, a-i) * (i + i + b - a + 1) + (1 - prob(p, 0, a-i))*(i + i + b - a + 1 + b + 1);
				if(tmp < min)
					min = tmp;
			}




			fout.println("Case #" + t + ": " +    min  );
			fout.flush();
			t++;
		}
	}
}