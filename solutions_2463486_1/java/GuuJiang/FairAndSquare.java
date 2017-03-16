import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class FairAndSquare {
	private final static BigInteger[] fairAndSquares = { new BigInteger("1"),
			new BigInteger("4"), new BigInteger("9"), new BigInteger("121"),
			new BigInteger("484"), new BigInteger("10201"),
			new BigInteger("12321"), new BigInteger("14641"),
			new BigInteger("40804"), new BigInteger("44944"),
			new BigInteger("1002001"), new BigInteger("1234321"),
			new BigInteger("4008004"), new BigInteger("100020001"),
			new BigInteger("102030201"), new BigInteger("104060401"),
			new BigInteger("121242121"), new BigInteger("123454321"),
			new BigInteger("125686521"), new BigInteger("400080004"),
			new BigInteger("404090404"), new BigInteger("10000200001"),
			new BigInteger("10221412201"), new BigInteger("12102420121"),
			new BigInteger("12345654321"), new BigInteger("40000800004"),
			new BigInteger("1000002000001"), new BigInteger("1002003002001"),
			new BigInteger("1004006004001"), new BigInteger("1020304030201"),
			new BigInteger("1022325232201"), new BigInteger("1024348434201"),
			new BigInteger("1210024200121"), new BigInteger("1212225222121"),
			new BigInteger("1214428244121"), new BigInteger("1232346432321"),
			new BigInteger("1234567654321"), new BigInteger("4000008000004"),
			new BigInteger("4004009004004") };

	private Scanner cin;
	private PrintStream cout;

	/**
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception {
		Scanner cin = new Scanner(System.in);
		PrintStream cout = System.out;
		new FairAndSquare().solve();
	}

	public void solve() throws Exception {
		cin = new Scanner(System.in);
		cout = System.out;
		int no = cin.nextInt();
		for (int i = 1; i <= no; ++i) {
			cout.printf("Case #%d: %d\n", i, solveCase(i));
		}
	}

	private int solveCase(int no) throws Exception {
		BigInteger a = new BigInteger(cin.next("[0-9]+"));
		BigInteger b = new BigInteger(cin.next("[0-9]+"));
		int count = 0;
		int i = 0;
		while (i < fairAndSquares.length && fairAndSquares[i].compareTo(a) < 0) {
			++i;
		}
		while (i < fairAndSquares.length && fairAndSquares[i].compareTo(b) <= 0) {
			++i;
			++count;
		}
		return count;
	}
}
