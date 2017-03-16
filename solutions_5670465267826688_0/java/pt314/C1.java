import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class C1 {

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			boolean ijk = ijk(in);
			out.println("Case #" + t + ": " + (ijk ? "YES" : "NO"));
		}
		out.close();
	}
	
	private static boolean ijk(BufferedReader in) throws Exception {
		
		String[] data = in.readLine().split(" ");
		int L = Integer.parseInt(data[0]);
		int X = Integer.parseInt(data[1]);
		String line = in.readLine();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < X; i++)
			sb.append(line);
		line = sb.toString();
		
		int si = 1;
		for (int i = 0; i < line.length() - 2; i++) {
			si = mult(si, line.charAt(i));
			if (si != 'i')
				continue;
			
			int sjk = 1;
			boolean bj = false;
			for (int j = i + 1; j < line.length(); j++) {
				sjk = mult(sjk, line.charAt(j));
				if (sjk == 'j')
					bj = true;
			}
			
			if (bj && sjk == 'i')
				return true;
		}
		return false;
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

}
