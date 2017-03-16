import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
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
		found.clear();
		found.put(0l, 0l);
		int N = in.nextInt();
		long[] inX = new long[N];
		for(int i=0;i<N;i++)
			inX[i]=in.nextInt();
		for(int i=0;i<N;i++) {
			long x=inX[i];
			add.clear();
			for(Map.Entry<Long,Long> y:found.entrySet()){
				long z = y.getKey()+x;
				if(found.containsKey(z)) {
					out.println();
					output(z);
					out.print(x+" ");output(z-x);
					return;
				}
				add.add(z);
			}
			for(long z:add)
				found.put(z,x);
		}
		out.println("Impossible");
	}

	private void output(long z) {
		long y = found.get(z);
		if(y==0) {
			out.println();
			return;
		}
		out.print(y+" ");
		output(z-y);
	}

	HashMap<Long,Long> found = new HashMap<Long,Long>();
	HashSet<Long> add = new HashSet<Long>();
}