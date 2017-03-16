import java.io.FileNotFoundException;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeMap;
import java.util.ArrayList;
import java.util.Set;
import java.io.FileInputStream;
import java.util.TreeSet;
import java.util.StringTokenizer;
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
		GoodLuck2 solver = new GoodLuck2();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class GoodLuck2 {
    HashMap<int[], Counter<Long>> map = new HashMap<int[], Counter<Long>>();

    {
        int[] a = new int[9];
        int[] b = new int[9];
        for(a[0] = 0; a[0] <= 0; ++a[0])
        for(a[1] = 0; a[0] + a[1] <= 0; ++ a[1])
        for(a[2] = 0; a[0] + a[1] + a[2]<= 12; ++ a[2])
        for(a[3] = 0; a[0] + a[1] + a[2] + a[3] <= 12; ++ a[3])
        for(a[4] = 0; a[0] + a[1] + a[2] + a[3] + a[4] <= 12; ++ a[4])
        for(a[5] = 0; a[0] + a[1] + a[2] + a[3] + a[4] + a[5]<= 12; ++ a[5])
        for(a[6] = 0; a[0] + a[1] + a[2] + a[3] + a[4] + a[5] +a[6]<= 12; ++ a[6])
        for(a[7] = 0; a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] <= 12; ++ a[7])
        {

            a[8] = 12 - a[0] - a[1] - a[2] - a[3] - a[4] - a[5] - a[6] - a[7];

            Counter<Long> set = new Counter<Long>();


            for(b[0] = 0; b[0] <= a[0]; ++b[0])
            for(b[1] = 0; b[1] <= a[1]; ++ b[1])
            for(b[2] = 0; b[2] <= a[2]; ++ b[2])
            for(b[3] = 0; b[3] <= a[3]; ++ b[3])
            for(b[4] = 0; b[4] <= a[4]; ++ b[4])
            for(b[5] = 0; b[5] <= a[5]; ++ b[5])
            for(b[6] = 0; b[6] <= a[6]; ++ b[6])
            for(b[7] = 0; b[7] <= a[7]; ++ b[7])
            for(b[8] = 0; b[8] <= a[8]; ++ b[8]) {

                long product = 1;
                for(int i = 2; i <= 8; ++i){
                    product *= IntegerUtils.power(i, b[i]);
                }
                set.add(product);

            }
            map.put(a.clone(), set);
        }
    }

    Random rnd = new Random();

    public void solve(int testNumber, Reader in, OutputWriter out) {
        try {
            in = new Reader(new FileInputStream("/home/riad/Downloads/C-small-2-attempt4.in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        in.nextInt();
        int r = in.nextInt();
        in.nextInt();
        in.nextInt();
        in.nextInt();

        out.println("Case #1:");

        for (int z = 0; z < r; ++z) {
            TreeSet<Long> set = new TreeSet<Long>();

            for (int i = 0; i < 12; ++i) {
                set.add(in.nextLong());
            }

            List<int[]> good = new ArrayList<int[]>();

            int best = -1;

            for (Map.Entry<int[], Counter<Long>> entry : map.entrySet()) {
                boolean ok = true;
                int sum = 0;
                for(long product: set) {
                    int s = entry.getValue().get(product);
                    if(s == 0){
                        ok = false;
                        break;
                    }
                    sum *= s;

                }
                if(!ok)
                    continue;
                if (sum > best) {
                    good = new ArrayList<int[]>();
                    best = sum;
                }

                if(sum == best)
                    good.add(entry.getKey());



            }

            if(best == -1)
                throw new AssertionError("1 " + z);

            if(good.isEmpty())
                throw new AssertionError("2 " + z );

            int[] a = good.get(rnd.nextInt(good.size()));
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i <= 8; ++i)
                for(int j = 0; j < a[i]; ++j){
                    sb.append((char)(i + '0'));
                }

            out.println(sb.toString());

        }
    }
}

class Counter<T> extends TreeMap<T, Integer> {
    public void add(T key) {
        add(key, 1);
    }

    public void add(T key, int value) {
        put(key, get(key) + value);
    }

    public Integer get(Object key) {
        return containsKey(key) ? super.get(key) : 0;
    }

}

class IntegerUtils {

	public static long power(long base, long power) {
		long result = 1;
		while (power > 0) {
			if (power % 2 == 1)
				result *= base;
			base *= base;
			power >>= 1;
		}
		return result;

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

