import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.math.BigInteger;
import java.util.TreeMap;

public class CLarge1 {
	public static final java.util.Scanner in = new java.util.Scanner(System.in);
	public static final java.io.PrintStream out = System.out;
	public static final String squaresFile = "squares.bin";
	public static TreeMap<BigInteger, BigInteger> squares;
	public static final BigInteger limit = new BigInteger("10000000");

	public static void main(String[] args) {
		preCalc();

		final int n = in.nextInt();

		for (int i = 0; i < n; ++i) {
			String a = in.next();
			String b = in.next();

			int count = squares.subMap(new BigInteger(a), new BigInteger(b).add(BigInteger.valueOf(1))).size();

			out.print("Case #");
			out.print(i + 1);
			out.print(": ");
			out.println(count);
		}
	}

	public static void preCalc() {
		if (readMap()) {
			return;
		}

		squares = new TreeMap<BigInteger, BigInteger>();

		for (BigInteger bi = BigInteger.valueOf(0); bi.compareTo(limit) <= 0; bi = bi
				.add(BigInteger.valueOf(1))) {
			if (isPalindrom(bi.toString())) {
				BigInteger bs = bi.multiply(bi);

				if (isPalindrom(bs.toString())) {
					squares.put(bs, bi);
				}
			}
		}

		storeMap();
	}

	@SuppressWarnings("unchecked")
	public static boolean readMap() {
		File file = new File(squaresFile);
		if (!file.canRead()) {
			return false;
		}

		ObjectInputStream is = null;

		try {
			is = new ObjectInputStream(new FileInputStream(file));

			squares = (TreeMap<BigInteger, BigInteger>) is.readObject();

			return true;
		} catch (IOException ex) {
			throw new AssertionError(ex);
		} catch (ClassNotFoundException ex) {
			throw new AssertionError(ex);
		} finally {
			try {
				if (is != null) {
					is.close();
				}
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}

	public static void storeMap() {
		ObjectOutputStream os = null;

		try {
			os = new ObjectOutputStream(new FileOutputStream(squaresFile));
			os.writeObject(squares);
		} catch (IOException ex) {
			throw new AssertionError(ex);
		} finally {
			try {
				if (os != null) {
					os.close();
				}
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}

	public static boolean isPalindrom(String s) {
		int length = s.length();
		int count = length / 2;
		for (int i = 0; i < count; ++i) {
			if (s.charAt(i) != s.charAt(length - i - 1)) {
				return false;
			}
		}

		return true;
	}
}
