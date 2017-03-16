import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Scanner;

//javac A.java && java A x.in x.out
public class A {
	public static void main(String[] args) throws FileNotFoundException {
		InputStream in = System.in;
		if(args.length>0)
			in = new FileInputStream(args[0]);
		PrintStream out = System.out;
		if(args.length>1)
			out = new PrintStream(args[1]);

		Solver s = new Solver(new Scanner(in),out);
		//Multiple case input
		s.cases();
		//Single case input
		//s.go();
	}
}

class Solver {
	Scanner in;
	PrintStream out;
	public Solver(Scanner scanner, PrintStream printStream) {
		in = scanner;
		out = printStream;
	}

	public void cases() {
		int numCases = in.nextInt();
		in.nextLine();
		for(int i=0;i<numCases;i++) {
			out.print("Case #"+(i+1)+": ");
			go();
		}
	}
	
	int N,X;
	int[] s;
	public void go() {
		N = in.nextInt();
		s = new int[N];
		int[] m = new int[N];
		X = 0;
		for(int i=0;i<N;i++) {
			s[i] = in.nextInt();
			X+=s[i];
		}
		
		for(int i = 0; i < N; i++) {
			out.format("%.8f",M(i));
			out.print(" ");
		}
		out.println();
	}

	double e = 1e-9;
	
	private double M(int ign) {
		double lo = 0;
		double hi = 2;
		double y;
		while(lo+e<hi) {
			y = (lo + hi) / 2;
			double left=1-y;
			double need = s[ign]+X*y;
			for(int i=0;i<N;i++)
				if(i!=ign)
					left-=(need-s[i])/X;
			if(left>0)
				lo=y;
			else
				hi=y;
		}
		return lo;
	}
}