import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.ArrayList;
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
 * @author phantom11
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("b.out");
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
    List<String> set = new ArrayList<String>();
    char characters[];
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        set.clear();

        int k = in.nextInt(), l = in.nextInt(), s = in.nextInt();
        String K = in.next();
        String L = in.next();
        characters = K.toCharArray();
        //DebugUtils.print("making" + characters);
        permute(0, s, "");
        //DebugUtils.print("made");
        int prefixTable[] = generatePrefixTable(L, l);
        long ans = 0;
        long max = 0;
        //DebugUtils.print(set.size());
        //if(testNumber == 4) DebugUtils.print(set);
        for(String s1 : set) {
            long p = KMP(s1, L, prefixTable);
            ans += p;
            max = Math.max(p, max);
        }
        double d = (double)ans;
        d /= set.size();
        double res = max - d;
        //DebugUtils.print(d, max, set.size());
        out.printLine("Case #" + testNumber + ": " + res);
    }
    public void permute(int i,int n, String made)
    {
        if(i == n) {
            set.add(made);
            return;
        }
        if(i >= n) return;
        for(Character c : characters) {
            permute(i + 1, n , made + c);
        }

    }
    public int[] generatePrefixTable(String pattern, int length) {
        int i = 1,j = 0;
        int prefixTable[] = new int[length];
        prefixTable[0] = 0;
        while (i < length) {
            if(pattern.charAt(i) == pattern.charAt(j)) {
                prefixTable[i] = j + 1;
                i++;
                j++;
            }
            else {
                if(j > 0) {
                    j = prefixTable[j-1];
                }
                else {
                    prefixTable[i] = 0;
                    i++;
                }
            }
        }
        return prefixTable;
    }
    public static int KMP(String text, String pattern, int prefixTable[]) {
        int n = text.length(), m = pattern.length(), i = 0;
        int count = 0;
        int start = 0;
        while (start + i < n) {
            if(text.charAt(start+ i) == pattern.charAt(i)) {
                if(i == m-1){
                    count++;
                    i = -1;
                    start++;
                }
                i++;
            }
            else if(i > 0) {
                start += i - prefixTable[i-1];
                i = prefixTable[i-1];
            }
            else start++;
        }
        return count;
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

