import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
		
	Scanner in;
	PrintWriter out;
	
	void run() throws FileNotFoundException {
		in = new Scanner(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		//out = new PrintWriter(System.out);
		int testNum = in.nextInt();
		for (int testCount = 0; testCount < testNum; testCount++) {
			BigInteger r = in.nextBigInteger().add(BigInteger.ONE);
			BigInteger t = in.nextBigInteger();
			long left = 1, right = 1000000000000L;
			while (left < right) {
				long mid = (left + right) / 2 + 1;
				BigInteger d = r.add(r.add(BigInteger.valueOf(mid * 2 - 2)))
						.multiply(BigInteger.valueOf(mid)).subtract(BigInteger.valueOf(mid));
				if (d.compareTo(t) <= 0)
					left = mid;
				else
					right = mid - 1;
			}
			out.println(String.format("Case #%d: %d", testCount + 1, left));
		}
		out.flush();
	}
	
	

}
