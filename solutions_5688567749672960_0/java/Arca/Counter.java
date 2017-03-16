import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Counter {

	private static Scanner scanner = new Scanner(System.in);
	private static PrintWriter sortie;

	private static Map<Long, Long> REVERSE = new HashMap<>();

	public static void main(String[] args) {
		start();

	    int T = scanner.nextInt();

	    for (int i = 0; i < T; i++) {
	    	long n = scanner.nextLong();

			sortie.println("Case #" + (i + 1) + ": " + counter(n));
		}

	    end();
	}

	private static long counter(long n) {
		long count = 0, i = n;

		while (i > 0) {
			long modulo = getModulo(i);
			if (i > 20 && i % modulo == 1) {
				long reverse = reverse(i);

				if (reverse < i) {
					i = reverse;
				} else {
					i--;
				}
			} else {
				i--;
			}

			count++;
		}

		return count;
	}

	private static long getModulo(long n) {
		if (n < 100) {
			return 10;
		} else if (n < 10000) {
			return 100;
		} else if (n < 1000000) {
			return 1000;
		} else if (n < 100000000) {
			return 10000;
		} else if (n < 10000000000L) {
			return 100000;
		} else if (n < 1000000000000L) {
			return 1000000;
		} else if (n < 100000000000000L) {
			return 10000000;
		} else {
			return 100000000;
		}
	}





	//////////// UTILITIES

	private static long reverse(long i) {
		if (!REVERSE.containsKey(i)) {
			REVERSE.put(i, Long.parseLong(new StringBuilder().append(String.valueOf(i)).reverse().toString()));
		}

		return REVERSE.get(i);
	}

	private static void end() {
	    sortie.close();
	    try {
		    InputStream ips=new FileInputStream("C:\\Users\\Thomas\\Desktop\\output.txt");
			InputStreamReader ipsr=new InputStreamReader(ips);
			BufferedReader br=new BufferedReader(ipsr);
			String ligne;
			while ((ligne=br.readLine())!=null) System.out.println(ligne);
			br.close();
	    } catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void start() {
		try {
			sortie =  new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Thomas\\Desktop\\output.txt")));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
