import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + t + ":");
			for (int i = 1; i <= s; i++)
				sb.append(" " + i);
			pw.println(sb);
		}
		pw.close();
	}
}
