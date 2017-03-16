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
		for(int i=0;i<from.length;i++)
			map.put(from[i],to[i]);
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
		char[] str = in.nextLine().toCharArray();
		for(int i = 0; i < str.length; i++)
			out.print(map.get(str[i]));
		out.println();
	}

	HashMap<Character,Character> map = new HashMap<Character,Character>();
	char[] from = "qz ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv".toCharArray(),
	to = "zq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up".toCharArray();
}