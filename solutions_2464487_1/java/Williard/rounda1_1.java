import java.io.*;
import java.math.BigDecimal;

public class rounda1_1 {
	public static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		int T;
		long r, t;
		double n;
		String[] input;
		
		T = Integer.parseInt(br.readLine());
		
		for (int ctr = 1; ctr <= T; ctr++) {
			input = br.readLine().split(" ");
			r = Long.parseLong(input[0]);
			t = Long.parseLong(input[1]);
			
			
			n = Math.floor(((1.000001-2.0*r + Math.sqrt(4.0*(double)r*(double)r - 4.0*r + 8.0*t + 1.0)) / 4.0));
			if (r > 10e9) {
				BigDecimal rbd = new BigDecimal(r);
				BigDecimal tbd = new BigDecimal(t);
				BigDecimal result = new BigDecimal(1);
				result.multiply(rbd);
				rbd.multiply(BigDecimal.valueOf(4));
				result.multiply(rbd);
				result.subtract(rbd);
				tbd.multiply(BigDecimal.valueOf(8));
				result.add(tbd);
				result.add(BigDecimal.valueOf(1));
				rbd.divide(BigDecimal.valueOf(2));
				rbd.subtract(BigDecimal.valueOf(1));
				if (result.compareTo(BigDecimal.valueOf(2.0*r-1.000001)) == -1) {
					if (n != 0)
						n--;
				}
			}
			out.printf("Case #%d: %.0f\n", ctr, n);
		}
		out.flush();
	}
	
}
