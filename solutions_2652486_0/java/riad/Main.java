import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author RiaD
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Reader in = new Reader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		GoodLuck1 solver = new GoodLuck1();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class GoodLuck1 {
    HashMap<String, HashSet<Long>> map = new HashMap<String, HashSet<Long>>();

    {
        int[] a = new int[3];
        for (a[0] = 2; a[0] <= 5; ++a[0]) {
            for (a[1] = 2; a[1] <= 5; ++a[1]) {
                for (a[2] = 2; a[2] <= 5; ++a[2]) {
                    String s = "" + a[0] + a[1] + a[2];
                    HashSet<Long> set = new HashSet<Long>();

                    for (int i = 0; i < 8; ++i) {
                        long product = 1;
                        for (int j = 0; j < 3; ++j) {
                            if (((1 << j) & i) > 0) {
                                product *= a[j];
                            }

                        }
                        set.add(product);
                    }

                    map.put(s, set);
                }
            }
        }
    }

    Random rnd = new Random();

    public void solve(int testNumber, Reader in, OutputWriter out) {
        int r = in.nextInt();
        in.nextInt();
        in.nextInt();
        in.nextInt();
        
        out.println("Case #1:");

        for (int z = 0;z < r; ++z) {
            HashSet<Long> set = new HashSet<Long>();

            for (int i = 0; i < 7; ++i) {
                set.add(in.nextLong());
            }

            List<String> good = new ArrayList<String>();


            for (Map.Entry<String, HashSet<Long>> entry : map.entrySet()) {
                boolean ok = true;
                for(long product: set) {
                    if(!entry.getValue().contains(product)){
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    good.add(entry.getKey());
            }

            out.println(good.get(rnd.nextInt(good.size())));

        }
    }
}

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Reader(BufferedReader reader) {
        this.reader = reader;
    }

    public Reader(InputStream stream) {
        this(new BufferedReader(new InputStreamReader(stream)));
    }

    public String nextString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public long nextLong() {
        return Long.parseLong(nextString());
    }

    public String next() {
        return nextString();
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class OutputWriter extends PrintWriter {

	public OutputWriter(OutputStream out) {
		super(out);
	}

	public OutputWriter(java.io.Writer writer){
		super(writer);
	}

	}

