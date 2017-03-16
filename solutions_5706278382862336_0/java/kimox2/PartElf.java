import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PartElf {

	public static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		String outfile = "out.txt";
		BufferedReader reader = new BufferedReader(new FileReader("test.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outfile));
		int x = Integer.parseInt(reader.readLine());
		for (int cas = 1; cas <= x; cas++) {
			String st[] = reader.readLine().split("/");
			long nom = Long.parseLong(st[0]);
			long denom = Long.parseLong(st[1]);
			long gcd = gcd(nom, denom);
			nom /= gcd;
			denom /= gcd;
			writer.write("Case #" + cas + ": ");
			int count = 1;
			if ((denom & 1) != 0) {
				writer.write("impossible");
				writer.newLine();
			} else {
				double d = (nom * 1.0) / (denom * 1.0);
				while (d != 0.5) {
					System.out.println(d);
					d *= 2;
					count++;
					if (d > 1)
						d -= 1.0;
				}
				if (count > 40) {
					writer.write("impossible");
					writer.newLine();
					continue;
				} else {
					count = 0;
					while ((nom / denom) < 1) {
						nom *= 2;
						count++;
					}
					writer.write(count + "");
					writer.newLine();
				}
				
			}
		}
		writer.close();
	}

}
