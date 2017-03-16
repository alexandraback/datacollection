package gcj1012;

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

	int T;

	char[] code;

	public static void main(String[] args) throws Exception {
		new A().run();
	}

	void run() throws Exception {
		Scanner in = new Scanner(System.in);
		in = new Scanner(new FileInputStream("A-large.in"));
		PrintStream out = System.out;
		out = new PrintStream("A-large.out");
		T = in.nextInt();
		for (int C = 1; C <= T; C++) {
			int N = in.nextInt();
			double s[] = new double[N];
			for (int i = 0; i < N; i++)
				s[i] = in.nextDouble();
			double X = 0;
			for (double d : s)
				X += d;
			double r[] = new double[N];
			for (int i = 0; i < N; i++)
				r[i] = 2.0 / N - s[i] / X;
			double S=0;
			int n2=0;
			for (int i = 0; i < N; i++)
				if(r[i]<=0) r[i] = 0;
				else {
					S += s[i];
					n2++;
				}
			for (int i = 0; i < N; i++)
				if(r[i]!=0) r[i] = (S/X+1)/n2 - s[i]/X;
			out.printf("Case #%d:", C);
			for (double d : r)
				out.print(" "+100*d);
			out.println("");
		}

	}

}
