import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("D-small-attempt0.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("D-small.out"));
		StringTokenizer st;
		int cases = Integer.parseInt(br.readLine().trim()), X, R, C;
		for (int c = 1; c <= cases; c++) {
			st = new StringTokenizer(br.readLine());
			X = Integer.parseInt(st.nextToken());
			R = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			if((R >= X-1 && C >= X-1) && (R*C%X==0))
				out.println("Case #" + c + ": GABRIEL");
			else
				out.println("Case #" + c + ": RICHARD");
		}
		out.close();
	}
}