import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Pavel Chuprikov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.print("Case #" + testNumber + ": ");
        int armones = in.nextInt();
        ArrayList<Integer> motes = new ArrayList<>();
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            motes.add(in.nextInt());
        }
        Collections.sort(motes);
        while (!motes.isEmpty() && motes.get(0) < armones) {
            armones += motes.get(0);
            motes.remove(0);
        }
        if (armones == 1) {
            out.println(motes.size());
        } else {
            int bestResult = motes.size();
            ArrayList<Integer> lifeNotes = new ArrayList<>();
            for (int i = 1; i <= motes.size(); i++) {
                lifeNotes.clear();
                for (int m : motes) {
                    if (lifeNotes.size() == i)
                        break;
                    lifeNotes.add(m);
                }
                int additions = 0;
                for (int newArmones = armones; additions < bestResult && !lifeNotes.isEmpty();) {
                    if (newArmones > lifeNotes.get(0)) {
                        newArmones += lifeNotes.get(0);
                        lifeNotes.remove(0);
                    } else {
                        newArmones += newArmones - 1;
                        additions++;
                    }
                }
                bestResult = Math.min(bestResult, additions + motes.size() - i);
            }
            out.println(bestResult);
        }
    }
}

class FastScanner {
    private BufferedReader br;
    private StringTokenizer st;

    public FastScanner(InputStream in) {
        this.br = new BufferedReader(new InputStreamReader(in));
    }

    public boolean hasNext() {
        try {
            while (st == null || !st.hasMoreTokens()) {
                final String nextLine = br.readLine();
                if (nextLine == null) {
                    return false;
                } else {
                    st = new StringTokenizer(nextLine);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        return true;
    }

    public String next() {
        return hasNext() ? st.nextToken() : null;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }

