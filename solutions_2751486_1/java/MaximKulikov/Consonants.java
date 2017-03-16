import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Consonants {
	
	public Consonants() {
	}
	
	public long solve(char[] name, int n) {
		int i, j;
		long res = 0;
		j = forward(name, n, 0);
		for (i = 0; i < name.length - n + 1; ++i) {
			if (j - i < n) j = forward(name, n, j);
			res += name.length + 1 - j;
		}
		return res;
	}

	private int forward(char[] name, int n, int j) {
		int l = (j == 0) ? 0 : n-1;
		for (; j < name.length && l < n; ++j) {
			if (name[j] == 'a' || name[j] == 'e' || name[j] == 'i' || name[j] == 'o' || name[j] == 'u')
				l = 0;
			else
				++l;
		}
		if (l < n) return j+1;
		return j;
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
				
				Consonants solver = new Consonants();
				
				for (int i = 1; i <= tests; ++i) {
					tokenizer = new StringTokenizer(in.readLine());
					char[] name = tokenizer.nextToken().toCharArray();
					int n = Integer.parseInt(tokenizer.nextToken());
					
					out.printf("Case #%d: %d\n", i, solver.solve(name, n));
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
