import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class C2 {

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			boolean ijk = ijk(in);
			//System.err.println(t);
			out.println("Case #" + t + ": " + (ijk ? "YES" : "NO"));
		}
		out.close();
	}
	
	private static boolean ijk(BufferedReader in) throws Exception {
		
		int maxLineCount = 14;
		
		String[] data = in.readLine().split(" ");
		//int L = Integer.parseInt(data[0]);
		long X = Long.parseLong(data[1]);
		String line = in.readLine();
		
		int lineCount = (int) (X % 4);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < lineCount; i++)
			sb.append(line);
		if (ijk(sb.toString()))
			return true;
		
		while (lineCount < Math.min(X, maxLineCount)) {
			for (int i = 0; i < 4; i++)
				sb.append(line);
			lineCount += 4;
			if (ijk(sb.toString()))
				return true;
		}
		return false;
	}

	private static boolean ijk(String line) throws Exception {
		int i = 0;
		int si_ = 1;
		for (; i < line.length(); i++) {
			si_ = mult(si_, line.charAt(i));
			if (si_ == 'i')
				break;
		}
		if (si_ != 'i')
			return false;
		
		int k = line.length() - 1;
		int sk_ = 1;
		for (; k > i + 1; k--) {
			sk_ = mult(line.charAt(k), sk_);
			if (sk_ == 'k')
				break;
		}
		if (sk_ != 'k')
			return false;

		if (i > k - 2)
			return false;
		
		int sj_ = 1;
		for (int j = i + 1; j < k; j++)
			sj_ = mult(sj_, line.charAt(j));
		
		return sj_ == 'j';
	}

	private static int[][] M = {{  -1,  'k', -'j'},
	                            {-'k',   -1,  'i'},
	                            { 'j', -'i',   -1}};

	private static int mult(int a, int b) {
		boolean na = a < 0;
		boolean nb = b < 0;
		if (na) a = -a;
		if (nb)	b = -b;
		boolean neg = na ^ nb;
		
		int res = 0;
		if (a == 1 || b == 1)
			res = Math.max(a, b);
		else
			res = M[a - 'i'][b - 'i'];
		
		return neg ? -res : res;
	}

	private static int multB(int a, int ab) {
		if (Math.abs(a) == 1 || Math.abs(ab) == 1)
			return a * ab;
		else
			return -mult(ab, a);
	}
	
}
