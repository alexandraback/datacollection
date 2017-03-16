import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();

        char[] a = s.toCharArray();
        int sol = 0;

        int right = a.length-1;

        while (right >=0){

            while (right >=0 && a[right] == '+'){
                right--;
            }

            int i = 0;
            while (i <= right && a[i] == '+'){
                i++;
            }

            if (i > 0){
                sol++;
                reverse(a, 0, i-1);
            }

            i =0;
            while (i <= right && a[i] == '-'){
                i++;
            }

            if (i > 0) {
                sol++;
                reverse(a, 0, i-1);
            }
        }

        out.println(String.format("Case #%d: %s", testNumber, Integer.toString(sol)));
    }

    private void reverse(char[] a, int start, int end) {
        int len = end-start+1;
        for (int i=0; i<len /2; i++){
            char c1 = a[start+i];
            char c2 = a[end-i];

            a[start+i] = negate(c2);
            a[end-i] = negate(c1);
        }

        if (len%2 == 1){
            a[start+len/2] = negate(a[start+len/2]);
        }
    }

    private char negate(char c2) {
        if (c2 == '+')
            return '-';

        return '+';
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;


    public InputReader(InputStream stream){
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String next(){
        while (tokenizer == null || !tokenizer.hasMoreTokens()){
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException("FATAL ERROR", e);
            }
        }

        return tokenizer.nextToken();
    }

}

