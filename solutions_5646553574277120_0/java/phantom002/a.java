import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "A-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int c=in.nextInt();
        int d=in.nextInt();
        ArrayList<Integer> den=new ArrayList<Integer>();
        int v=in.nextInt();
        for(int i=0;i<d;i++){
            den.add(in.nextInt());
        }
        int cou=0;
        boolean st=true;
        while (st) {
            st=false;
            int hash[] = new int[v + 1];
            Arrays.fill(hash, 0);
            for (int mask = 0; mask < (1 << den.size()); mask++) {
                int val = 0;
                for (int i = 0; i < den.size(); i++) {

                    if ((mask & (1 << i)) > 0) {
                        val += den.get(i);
                    }
                }
                if (val <= v)
                    hash[val] = 1;
            }
            int firstThere = 0;
            for (int i = 1; i <= v; i++) {
                if (hash[i] == 0) {
                    //System.out.println(i);
                    if (!den.contains(i)) {
                        den.add(i);

                        cou++;
                        st=true;
                        break;
                    }
                } //else firstThere = i;
            }
        }
        System.out.println("Case #" + testNumber + ": " + cou);
    }
}

class InputReader {
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

    public void close() {
            writer.close();
        }
}

