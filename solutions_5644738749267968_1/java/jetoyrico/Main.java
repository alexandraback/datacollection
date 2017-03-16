import java.util.Scanner;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tc/D-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tc/output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		D solver = new D();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class D {

	public void solve(int testNumber, Scanner in, PrintWriter out) {
	    int n = in.nextInt();
	    ArrayList<Double> naomi = new ArrayList<Double>();
	    ArrayList<Double> ken = new ArrayList<Double>();
	    for (int i = 0; i < n; ++i) naomi.add(in.nextDouble());
	    for (int i = 0; i < n; ++i) ken.add(in.nextDouble());
	    Collections.sort(naomi);
	    Collections.sort(ken);

	    ArrayList<Double> n1 = new ArrayList<>(naomi);
	    ArrayList<Double> k1 = new ArrayList<>(ken);
	    int res1 = 0;
	    for (int loop = 0; loop < n; ++loop) {
		    int sz = n1.size();
		    if (n1.get(0) < k1.get(0)) {
			    n1.remove(0);
			    k1.remove(sz - 1);
		    } else {
			    n1.remove(0);
			    k1.remove(0);
			    res1++;
		    }
	    }

	    ArrayList<Double> n2 = new ArrayList<>(naomi);
	    ArrayList<Double> k2 = new ArrayList<>(ken);
	    int res2 = 0;
	    for (int loop = 0; loop < n; ++loop) {
		    double nao = n2.get(0);
		    double delta = Double.POSITIVE_INFINITY;
		    int index = -1;
		    for (int j = 0; j < k2.size(); ++j) {
			    double ke = k2.get(j);
			    if (ke > nao && Math.abs(ke - nao) < delta) {
				    delta = Math.abs(ke - nao);
				    index = j;
			    }
		    }
		    if (index >= 0) {
			    k2.remove(index);
			    n2.remove(0);
		    }
		    else break;
	    }
	    res2 = n2.size();

	    out.print(String.format("Case #%d: %d %d\n", testNumber, res1, res2));
    }

}

