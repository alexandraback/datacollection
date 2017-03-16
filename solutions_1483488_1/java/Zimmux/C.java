import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

//javac C.java && java C x.in x.out
public class C {
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
		int A = in.nextInt();
		int B = in.nextInt();
		int ans = 0;
		
		int mod = 1;
		int a = A;
		int digs = 0;
		while(a>0) {
			a/=10;
			mod*=10;
			digs++;
		}

		HashSet<Integer> found = new HashSet<Integer>();
		for(int n = A; n <= B; n++) {
			found.clear();
			int nn=n;
			for(int i = 0; i < digs; i++) {
				nn=(nn+mod*(nn%10))/10;
				found.add(nn);
			}
			for(int mm : found)
				if(mm>n&&mm<=B)
					ans++;
		}
		out.println(ans);
	}
}