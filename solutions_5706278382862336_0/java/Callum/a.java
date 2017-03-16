import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;

public class a {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter("A-small.out", "UTF-8");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= t; test++) {
			String[] line = br.readLine().split("/");
			
			int num = Integer.parseInt(line[0]);
			int denom = Integer.parseInt(line[1]);
			
			int gcd = BigInteger.valueOf(num).gcd(BigInteger.valueOf(denom)).intValue();
			
			num = (int)(num / gcd);
			denom = (int)(denom / gcd);
			
			boolean found = false;
			
			if (powerTwo(denom)) {
				for (int i = 1; i <= 40; i++) {
					int n = 1;
					int d = (int) Math.pow(2, i);
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
	
	public static boolean powerTwo(int n) {
        if ((n & -n) == n) {
            return true;
        }
        return false;
    }
}