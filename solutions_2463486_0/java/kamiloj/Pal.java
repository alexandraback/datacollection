import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Pal {

	Scanner s;
	ArrayList<Long> lista;

	public Pal() throws NumberFormatException, IOException {
		s = new Scanner(new File("C-small-attempt5.in"));
		lista = new ArrayList<Long>();
		prefill();
		int t = s.nextInt();
		for (int i = 1; i <= t; i++) {
			System.out.println("Case #" + i + ": " + solve());
		}
	}

	private void prefill() {
		for (long i = 1; i < 10000000; i++) {
			if (isPal(Long.toString(i)) && isPal(Long.toString(i * i))) {
				lista.add(i * i);
			}
		}
	}

	private boolean isPal(String string) {
		for (int i = 0, j = string.length() - 1; i < j; i++, j--) {
			if (string.charAt(i) != string.charAt(j))
				return false;
		}
		return true;
	}

	private int solve() {
		long a = s.nextLong();
		long b = s.nextLong();
		int total = 0;
		int i = 0;
		for (i = 0; true; i++) {
			if (a <= lista.get(i)) {
				total -= i;
				break;
			}
		}
		for (; true; i++) {
			if (b <= lista.get(i)) {
				total += i;
				if (b == lista.get(i))
					total++;
				break;
			}
		}
		return total;
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		FileOutputStream fdout = new FileOutputStream(new File("salida.out"));
		BufferedOutputStream bos = new BufferedOutputStream(fdout, 1024);
		PrintStream ps = new PrintStream(bos, false);
		System.setOut(ps);
		new Pal();
		ps.close();
	}
}
