import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Scanner;

//javac B.java && java B x.in x.out
public class B {
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

	public void go() {
		int N = in.nextInt();
		int S = in.nextInt();
		int p = in.nextInt();
		//Surprise x-2,x-2,x || x-2,x-1,x || x-2,x,x
		//Non-surp x,x,x || x-1,x,x || x-1,x-1,x
		int tS = p*3-4;
		int tN = p*3-2;
		if(p==0) {
			tS=0;
			tN=0;
		}
		if(p==1) {
			tS=p*3-2;
			tN=p*3-2;
		}
		int[] t = new int[N];
		for(int i=0;i<N;i++)
			t[i]=in.nextInt();

		int ans = 0;
		for(int i=0;i<N;i++) {
			if(t[i]>=tN)
				ans++;
			else if(S>0 && t[i]>=tS) {
				ans++;
				S--;
			}
		}

		out.println(ans);
	}
}