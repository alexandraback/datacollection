import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;

public class a {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter("A-large.out", "UTF-8");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= t; test++) {
			String[] line = br.readLine().split("/");
			
			long num = Long.parseLong(line[0]);
			long denom = Long.parseLong(line[1]);
			
			long gcd = BigInteger.valueOf(num).gcd(BigInteger.valueOf(denom)).longValue();
			
			num = (long)(num / gcd);
			denom = (long)(denom / gcd);
			
			boolean found = false;
			
			if (powerTwo(denom)) {
				for (int i = 1; i <= 40; i++) {
					long n = 1;
					long d = (long) Math.pow(2, i);
					if (num * d >= n * denom) {
						pw.printf("Case #%d: %d%n", test, i);
						found = true;
						break;
					}
				}
			}
			if (!found) {
				pw.printf("Case #%d: impossible%n", test);
			}
		}
		
		br.close();
		pw.close();
	}
	
	public static boolean powerTwo(long n) {
        if ((n & -n) == n) {
            return true;
        }
        return false;
    }
}