import java.util.*;
import java.io.*;

public class C  {
	public static void main (String [] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("C-small-0.in"));
			PrintWriter pw = new PrintWriter("C-small-0.out");
			int inputNo;
			inputNo = Integer.parseInt(br.readLine());

			for (int i = 1; i <= inputNo; i++) {
				// get one input here
				LinkedList<Pair> first = new LinkedList<Pair>();
				LinkedList<Pair> second = new LinkedList<Pair>();
				Scanner sc = new Scanner(br.readLine());
				int N = sc.nextInt();
				int M = sc.nextInt();
				sc = new Scanner(br.readLine());
				for (int j = 1; j <= N; j++) {
					long a = sc.nextLong();
					int A = sc.nextInt();
					Pair pair = new Pair(a, A);
					first.add(pair);
				}
				sc = new Scanner(br.readLine());
				for (int j = 1; j <= M; j++) {
					long b = sc.nextLong();
					int B = sc.nextInt();
					Pair pair = new Pair(b, B);
					second.add(pair);
				}
				pw.println("Case #" + i + ": " + processInput(first, second));
			}

			br.close();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static long processInput(LinkedList<Pair> first, LinkedList<Pair> second) {
		if (first.size() == 1) {
			Pair fp = first.getFirst();
			long sb = 0;
			for (Pair p: second) {
				if (p.A == fp.A) sb += p.a;
			}
			return Math.min(sb,fp.a);
		} else if (second.size() == 1) {
			Pair fp = second.getFirst();
			long sb = 0;
			for (Pair p: first) {
				if (p.A == fp.A) sb += p.a;
			}
			return Math.min(sb,fp.a);
		} else {
			Pair fp1 = first.getFirst();
			Pair fp2 = second.getFirst();
			if (fp1.A == fp2.A) {
				if (fp1.a > fp2.a) {
					LinkedList<Pair> nFirst = new LinkedList<Pair>(first);
					LinkedList<Pair> nSecond = new LinkedList<Pair>(second);
					nSecond.removeFirst();
					Pair nFp1 = new Pair(fp1.a - fp2.a, fp1.A);
					nFirst.removeFirst();
					nFirst.addFirst(nFp1);
					return fp2.a + processInput(nFirst, nSecond);
				} else if (fp1.a < fp2.a) {
					LinkedList<Pair> nFirst = new LinkedList<Pair>(first);
					LinkedList<Pair> nSecond = new LinkedList<Pair>(second);
					nFirst.removeFirst();
					Pair nFp2 = new Pair(fp2.a - fp1.a, fp2.A);
					nSecond.removeFirst();
					nSecond.addFirst(nFp2);
					return fp1.a + processInput(nFirst, nSecond);
				} else {
					LinkedList<Pair> nFirst = new LinkedList<Pair>(first);
					LinkedList<Pair> nSecond = new LinkedList<Pair>(second);
					nFirst.removeFirst();
					nSecond.removeFirst();
					return fp1.a + processInput(nFirst, nSecond);
				}
			} else {
				LinkedList<Pair> nFirst = new LinkedList<Pair>(first);
				nFirst.removeFirst();
				long r1 = processInput(nFirst, second);
				LinkedList<Pair> nSecond = new LinkedList<Pair>(second);
				nSecond.removeFirst();
				long r2 = processInput(first, nSecond);
				return Math.max(r1, r2);
			}
		}
	}
}
