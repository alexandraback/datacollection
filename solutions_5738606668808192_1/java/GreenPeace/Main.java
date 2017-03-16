import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new FileInputStream("input.txt"))){
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				out.write("Case #" + (i + 1) + ":\n");
				int n = scanner.nextInt();
				int j = scanner.nextInt();
				int leftDigit = (int)Math.pow(2, n/2-1);
				StringBuffer sb = new StringBuffer();
                if (j > Math.pow(2, n/2-2)) {
                	throw new IllegalStateException();
                }
				for (int base = 2; base < 11; base++) {
					sb.append(" ");
					BigInteger bigBase = new BigInteger("" +base);
					sb.append(bigBase.pow(n/2).add(BigInteger.ONE).toString());
				}
				for (int count = 0; count < j; count++) {
					String str = Integer.toBinaryString(leftDigit+2*count+1);
					out.write(str);
					out.write(str);
					out.write(sb.toString());
					out.write("\n");
				}
				out.write("");
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}