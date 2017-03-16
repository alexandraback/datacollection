import java.math.BigInteger;
import java.util.Scanner;


public class Task_A {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		
		for (int i = 1; i <= t; i++) {
			solve(i, scan);
		}
		
		scan.close();

	}
	

	
	public static void solve(int number, Scanner sc) {
		String c = sc.next();
		int index = c.indexOf("/");
		Long p = Long.parseLong( (String) c.subSequence(0, index));
		Long q = Long.parseLong( (String) c.subSequence(index + 1, c.length()));
		Long z = (long) Math.pow(2,40);
		BigInteger a = new BigInteger(p.toString());
		a = a.multiply(new BigInteger(z.toString()));
		if (a.remainder(new BigInteger(q.toString())).equals(BigInteger.ZERO)) {
			long w = 1;
			p *= 2;
			while (p < q) {
				p*=2;
				w++;
			}
			if (w <= 40) {
				System.out.println("Case #" + number + ": " + w);
			}
			else {
				System.out.println("Case #" + number + ": impossible");
			}
		} else {
			//System.out.println(p +" " + z +" "+ q + " " + a +" "+ a.remainder(new BigInteger(q.toString())));
			System.out.println("Case #" + number + ": impossible");
		}
	}
	
}