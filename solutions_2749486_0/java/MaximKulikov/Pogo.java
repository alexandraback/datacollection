import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Pogo {
	
	public Pogo() {
	}
	
	public String solve(int x, int y) {
		String res = "";
		if (x > 0) {
			res += strmul("WE", x);
		} else if (x < 0) {
			res += strmul("EW", -x);
		}
		if (y > 0) {
			res += strmul("SN", y);
		} else if (y < 0) {
			res += strmul("NS", -y);
		}
		return res;
	}

	private String strmul(String step, int n) {
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < n; ++i)
			builder.append(step);
		return builder.toString();
	}

	public static void main(String[] args) {
		String inputFileName = args[0];
		String outputFileName = args[1];
			
		try {
			BufferedReader in = null;
			PrintWriter out = null;
			try {
				in = new BufferedReader(new FileReader(inputFileName));
				out = new PrintWriter(outputFileName);
				
				StringTokenizer tokenizer = new StringTokenizer(in.readLine());
				int tests = Integer.parseInt(tokenizer.nextToken());
				
				Pogo solver = new Pogo();
				
				for (int i = 1; i <= tests; ++i) {
					tokenizer = new StringTokenizer(in.readLine());
					int x = Integer.parseInt(tokenizer.nextToken()),
						y = Integer.parseInt(tokenizer.nextToken());
					
					out.printf("Case #%d: %s\n", i, solver.solve(x, y));
				}
			}
			finally {
				if (in != null)
					in.close();
				if (out != null)
					out.close();
			}
		} catch (IOException e)
		{
			e.printStackTrace();
		}
	}

}
