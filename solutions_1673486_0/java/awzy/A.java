import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws IOException {
		String filename = "A-small-attempt0";
		String inname = filename + ".in";
		String outname = filename + ".out";
		//Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File(inname));
		int N = sc.nextInt();
		sc.nextLine();
		PrintWriter out = new PrintWriter(new FileWriter(outname)); 
		for(int n = 1; n <= N; n++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			double[] p = new double[a];
			double[] pc = new double[a];
			double[] e = new double[a];
			double mine = Double.MAX_VALUE;
			for(int i = 0; i < a; i++) {
				p[i] = sc.nextDouble();
				pc[i] = p[i];
				if(i > 0) pc[i] *= pc[i-1];
				e[i] = pc[i]*(b-i-1+a-i-1+1)+(1.0-pc[i])*(b-i-1+a-i-1+1+b+1);
				mine = Math.min(e[i], mine);
			}
			mine = Math.min(mine, b+2);
			DecimalFormat df = new DecimalFormat("#.000000");
			out.println("Case #" + n + ": " + df.format(mine));
			System.out.println("Case #" + n + ": " + df.format(mine));
		}
		out.close();
	}
}
