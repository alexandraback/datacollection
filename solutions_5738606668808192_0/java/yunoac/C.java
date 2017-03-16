package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Random;
import java.util.Scanner;

public class C {

	private static Scanner reader;
	private static PrintWriter writer;
	
	public static void main(String[] args) throws IOException {
		System.out.println(Arrays.toString(findDivisors(55)));
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			int N = reader.nextInt();
			int J = reader.nextInt();
			HashMap<Long, long[]> jamcoins = new HashMap<>();
			Random rnd = new Random();
			while(jamcoins.size() < J) {
				long x = (1 << (N - 1)) + 1;
				for(int i = 1; i < N - 1; i++) {
					if(rnd.nextBoolean()) {
						x |= (1 << i);
					}
				}
				if(!jamcoins.containsKey(x)) {
					long[] div = findDivisors(x);
					if(div != null) {
						jamcoins.put(x, div);
					}
				}
			}
			writer.println("Case #" + tc + ":");
			for(Entry<Long, long[]> e : jamcoins.entrySet()) {
				String div = Arrays.toString(e.getValue());
				div = div.substring(1, div.length() - 1);
				div = div.replace(",", "");
				writer.println(Long.toBinaryString(e.getKey()) + " " + div);
			}
		}
		reader.close();
		writer.close();
	}
	
	static long[] findDivisors(long x) {
		long[] BB = new long[9];
		long[] div = new long[9];
		for(int b = 2; b <= 10; b++) {
			long B = new BigInteger(Long.toBinaryString(x), b).longValue();
			BB[b - 2] = B;
			for(long d = 2; d * d <= B; d++) {
				if(B % d == 0) {
					div[b - 2] = d;
					break;
				}
			}
			if(div[b - 2] == 0) {
				return null;
			}
		}
		for(int i = 0; i < 9; i++) {
			System.out.print(BB[i] % div[i] + " ");
		}
		System.out.println();
		return div;
	}
	
}
