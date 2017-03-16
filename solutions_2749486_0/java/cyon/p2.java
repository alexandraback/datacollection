import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p2 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}

	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		StringBuilder sb = new StringBuilder("");
		if(x > 0) {
			for(int i=0;i<x;i++)
				sb.append("WE");
		}
		else if(x < 0) {
			for(int i=0;i<Math.abs(x);i++)
				sb.append("EW");
		}
		if(y > 0) {
			for(int i=0;i<y;i++)
				sb.append("SN");
		}
		else if(y < 0) {
			for(int i=0;i<Math.abs(y);i++)
				sb.append("NS");
		}
		return sb.toString();
	}

	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
}
