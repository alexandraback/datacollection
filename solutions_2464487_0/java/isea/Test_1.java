import java.io.*;
import java.math.*;
import java.util.*;

public class Test_1 {
	static BigInteger B(int x) {
		return BigInteger.valueOf(x);
	}
	public static void main(String[] args) {
		try {
			Scanner cin = new Scanner(new File("D:/VIM/A.in"));
			PrintWriter cout = new PrintWriter(new FileWriter("D:/VIM/A.out"), true);
			int caseNum = cin.nextInt();
			for (int Case = 1; Case <= caseNum; ++Case) {
				BigInteger ri, tp;
				ri = cin.nextBigInteger();
				tp = cin.nextBigInteger();
				BigInteger l = B(0), r = tp.multiply(B(1000));
				while (l.compareTo(r) <= 0) {
					BigInteger mid = (l.add(r)).shiftRight(1);
					BigInteger p = mid.multiply(ri.multiply(B(2)).
							add(mid.multiply(B(2))).subtract(B(1)));
					if (tp.compareTo(p) >= 0) {
						l = mid.add(B(1));
					} else {
						r = mid.subtract(B(1));
					}
				}
				cout.println("Case #" + Case + ": " + l.subtract(B(1)));
			}
		}catch(IOException ioe) {
		}
	}
}
