import java.io.FileReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;


public class C {

	static int N;
	static int M;
	
	static class I {
		long q;
		long t;
		I(long q, long t) {
			this.q = q;
			this.t = t;
		}
	}
	static LinkedList<I> b;
	static LinkedList<I> g;
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("src/C.in"));
		PrintWriter output = new PrintWriter("src/C.out");
		long T = input.nextLong();
		for(long t = 1; t <= T; t++) {
			String o = "Case #" + t + ": ";
			N = input.nextInt();
			M = input.nextInt();
			b = new LinkedList<I>();
			g = new LinkedList<I>();
			for(long i = 0; i < N; i++) {
				b.add(new I(input.nextLong(), input.nextLong()));
			}
			for(long i = 0; i < M; i++) {
				g.add(new I(input.nextLong(), input.nextLong()));
			}	
			
			o += solve(0);
			output.println(o);
			System.out.println(o);
		}
		input.close();
		output.close();
	}

	static long solve(long result) {
		if(b.isEmpty() || g.isEmpty()) {
			return result;
		}

		I box = b.get(0); long bq = box.q;
		I toy = g.get(0); long tq = toy.q;

		long max = 0;
		long min = 0;
		if(box.t == toy.t) {
			min = Math.min(box.q, toy.q);
			if(box.q == min) {
				b.remove(0);
			}
			else
				box.q = box.q - min;
			if(toy.q == min) {
				g.remove(0);
			}
			else
				toy.q = toy.q - min;
			max = Math.max(max,solve(result+min));
			if(bq == min) {
				b.add(0, box);
			}
			else
				box.q = box.q + min;
			if(tq == min) {
				g.add(0, toy);
			}
			else
				toy.q = toy.q + min;
			return max;
		}

		b.remove(0);
		max = Math.max(max,solve(result));

		b.add(0, box);
		g.remove(0);
		max = Math.max(max,solve(result));
		
		g.add(0, toy);

		return max;
	}
}