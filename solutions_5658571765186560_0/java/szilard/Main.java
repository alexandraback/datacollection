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
			final String regex = "D-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("d.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int x = in.nextInt();
        int r = in.nextInt();
        int c = in.nextInt();

        if (canPlace(x,r,c)){
            out.println(String.format("Case #%d: RICHARD", testNumber));
        } else {
            out.println(String.format("Case #%d: GABRIEL", testNumber));
        }

    }

    private boolean canPlace(int x, int r, int c) {
        int rem = r*c - x;

        if (rem < 0 || (rem % x) != 0){
            return true;
        }

        if (x == 1 || x == 2){
            return false;
        }


        if (x == 3){
            if (possible31(r,c)){
                return true;
            }

            if (possible32(r, c)){
                return true;
            }

            return false;
        }

        if (possible41(r, c) || possible42(r,c) || possible43(r,c) || possible44(r, c) || possible45(r, c)){
            return true;
        }

        return false;
    }

    private boolean possible45(int r, int c) {
        if (r>=4 || c>=4){
            return false;
        }

        return true;
    }

    private boolean possible44(int r, int c) {
        if (r >=3 && c>=4 || r>=4 && c>=3){
            return false;
        }

        return false;
    }

    private boolean possible43(int r, int c) {
        if (r>=3 && c>=3){
            return false;
        }

        return true;
    }

    private boolean possible42(int r, int c) {
        // **
        // *
        // *

        if (r>=3 && c>=2 || r>=2 && c>=3){
            return false;
        }

        return true;
    }

    private boolean possible41(int r, int c) {
        // **
        // **

        return possible32(r, c);
    }

    private boolean possible32(int r, int c) {
        // **
        // *

        if (r<2 || c <2){
            return true;
        }

        return false;
    }

    private boolean possible31(int r, int c) {
        // ***

        if (r >= 3 || c >= 3){
            return false;
        }

        return true;
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

    public int nextInt(){
        return Integer.valueOf(next());
    }

}

