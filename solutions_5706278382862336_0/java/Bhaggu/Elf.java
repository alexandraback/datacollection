import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Elf {

	public static long GCD(long a, long b) {
		   if (b==0) return a;
		   return GCD(b,a%b);
		}
	
	public static long calc(long p, long q) {
		double qLog2 = Math.log(q) / Math.log(2);
		long qLog2Round = Math.round(qLog2);
		if (Math.pow(2, qLog2Round) != q) {
			return -1;
		}
		String pString = Long.toBinaryString(p);
		String qString = Long.toBinaryString(q);
		return qString.length() - pString.length();		
	}

	public static void main(String[] args) {
		try {
			BufferedReader bufferRead = new BufferedReader(
					new InputStreamReader(System.in));
			String s = bufferRead.readLine();
			int numCases = Integer.parseInt(s);
			for (int i = 1; i <= numCases; i++) {
				String line = bufferRead.readLine();
				String[] lineSplit = line.split("/");
				long p = Long.parseLong(lineSplit[0]);
				long q = Long.parseLong(lineSplit[1]);
				long gcd = GCD(p,q);
				long output = calc(p/gcd, q/gcd);
				System.out.print("Case #" + i + ": ");
				if(output == -1){
					System.out.println("impossible");
				}
				else{
					System.out.println(output);
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
