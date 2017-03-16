import java.io.*;
import java.util.InputMismatchException;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Roberto Sales
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
		FastInput in = new FastInput(inputStream);
		FastOutput out = new FastOutput(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastInput in, FastOutput out) {
        int n = in.readInt();
        String s = in.read();

        int cnt = 0, ans = 0;
        for(int i = 0; i <= n; i++){
            int val = s.charAt(i)-'0';
            if(i > cnt){
                ans += i-cnt;
                cnt = i;
            }
            cnt += val;
        }

        out.print(GCJ.getCase(testNumber));
        out.printLine(ans);

    }
}

class FastInput{
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public FastInput(InputStream in){
        reader = new BufferedReader(new InputStreamReader(in), 1<<16);
        tokenizer = null;
    }

    public String read(){
        while(tokenizer == null || !tokenizer.hasMoreTokens()){
            try{
                tokenizer = new StringTokenizer(reader.readLine());
            }catch(Exception ex){
                throw new InputMismatchException();
            }
        }
        return tokenizer.nextToken();
    }

    public int readInt(){
        return Integer.parseInt(read());
    }

    public String next(){
        return read();
    }
}

class FastOutput {
    private PrintWriter writer;

    public FastOutput(OutputStream out){
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(out)));
    }

    public void print(Object...args){
        for(int i = 0; i < args.length; i++){
            if(i > 0) writer.print(' ');
            writer.print(args[i]);
        }
    }

    public void printLine(Object...args){
        print(args);
        writer.println();
    }

    public void close(){
        writer.close();
    }
}

class GCJ {
    public static String getCase(int x){
        return "Case #" + x + ": ";
    }
}

