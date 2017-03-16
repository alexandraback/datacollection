import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

//javac D.java && java D x.in x.out
public class D {
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
		int H = in.nextInt()-2;
		int W = in.nextInt()-2;
		int D = in.nextInt();

		in.nextLine();
		in.nextLine();
		int x=0;
		int y=0;
		for(int row = 0; row<H; row++) {
			char[] line = in.nextLine().toCharArray();
			for(int col = 0; col<W; col++) {
				if(line[col+1]=='X') {
					x=2*col+1;
					y=2*row+1;
				}
			}
		}
		in.nextLine();
		H*=2;
		W*=2;
		D*=2;
		//Note: all is twice as big

		HashSet<Node> found = new HashSet<Node>();
		int ans = 0;
		int rx = D/W+1;
		int ry = D/H+1;
		for(int dx=-rx;dx<=rx;dx++) {
			int xx = (dx&1)==0?dx*W:(dx*W+W-2*x);
			for(int dy=-ry;dy<=ry;dy++) {
				if(dx==0&&dy==0)
					continue;
				int yy = (dy&1)==0?dy*H:(dy*H+H-2*y);
				if(xx*xx+yy*yy<=D*D) {
					found.add(new Node(xx,yy));
				}
			}
		}

		out.println(found.size());
	}
}

class Node {
	int x, y;

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (!(o instanceof Node)) return false;

		Node node = (Node) o;

		if (x != node.x) return false;
		if (y != node.y) return false;

		return true;
	}

	@Override
	public int hashCode() {
		int result = x;
		result = 31 * result + y;
		return result;
	}

	public Node(int xx, int yy) {
		int d = gcd(xx,yy);
		x=xx/d;
		y=yy/d;
	}

	public int gcd(int a, int b) {
		a=a<0?-a:a;b=b<0?-b:b;
		return a==0?b:gcd(b%a,a);
	}
}