import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Lokesh Khandelwal
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("B-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output_comp.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    long dp[][][][] = new long[31][2][2][2];
    int dA[] = new int[30], dB[] = new int[30], dC[] = new int[30];
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int a = in.nextInt() - 1, b = in.nextInt() - 1, k = in.nextInt() - 1;
        int i, j, l;
        for(i=0;i<=30;i++) {
            for(j=0;j<2;j++) {
                for(l=0;l<2;l++) {
                    Arrays.fill(dp[i][j][l], -1);
                }
            }
        }
        digitA(a);
        digitB(b);
        digitC(k);
        //DebugUtils.print(dA, dB, dC);
        long c = rec(30, true, true, true);
        out.printLine("Case #"+testNumber+": "+c);
        DebugUtils.print(testNumber);
    }
    public void digitA(int x) {
        for (int i = 0; i < 30; i++) {
            dA[i] = ( (x & (1<<i)) != 0) ? 1 : 0;
        }
    }
    public void digitB(int x) {
        for (int i = 0; i < 30; i++) {
            dB[i] = ( (x & (1<<i)) != 0) ? 1 : 0;
        }
    }
    public void digitC(int x) {
        for (int i = 0; i < 30; i++) {
            dC[i] = ( (x & (1<<i)) != 0) ? 1 : 0;
        }
    }
    public long rec(int t, boolean eqA, boolean eqB, boolean eqC)
    {
        long res = dp[t][eqA ? 1 : 0][eqB ? 1 : 0][eqC ? 1 : 0];
        if (res == -1) {
            res = 0;
            if (t == 0) {
                res = 1;
            } else {
                res = 0;
                // pick the two bits x, y:
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        int z = x & y; //find z
                        // If valid
                        if (    (!eqA || (x <= dA[t-1]) )
                                && (!eqB || (y <= dB[t-1]) )
                                && (!eqC || (z <= dC[t-1]) )
                                ) {
                            // procceed:
                            res += rec(
                                    t-1,
                                    eqA && (x == dA[t-1] ),
                                    eqB && (y == dB[t-1] ),
                                    eqC && (z == dC[t-1] )
                            );
                        }
                    }
                }
            }
        }
        dp[t][eqA ? 1 : 0][eqB ? 1 : 0][eqC ? 1 : 0] = res;
        return res;
    }
}

class InputReader
{
    BufferedReader in;
    StringTokenizer tokenizer=null;

    public InputReader(InputStream inputStream)
    {
        in=new BufferedReader(new InputStreamReader(inputStream));
    }
    public String next()
    {
        try{
            while (tokenizer==null||!tokenizer.hasMoreTokens())
            {
                tokenizer=new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }
        catch (IOException e)
        {
            return null;
        }
    }
    public int nextInt()
    {
        return Integer.parseInt(next());
    }
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}
}

class DebugUtils {
    public static void print(Object... a)
    {
        boolean oj=System.getProperty("ONLINE_JUDGE")!=null;
        if(!oj)
            System.out.println(Arrays.deepToString(a));
    }
}

