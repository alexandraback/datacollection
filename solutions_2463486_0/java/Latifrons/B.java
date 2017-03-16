import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {
	static String pre = "1s";
	static String in = pre + ".in";
	static String out = pre + ".out";

	static Scanner s;
	static FileWriter fw;

	private static String handle() {
		long a = s.nextLong();
		long b = s.nextLong();
		long ar = (long) Math.ceil(Math.sqrt(a));
		long br = (long) Math.floor(Math.sqrt(b));
		long count = 0;
		for (long i = ar; i <= br; i++) {
			long ii = (long) Math.pow(i, 2);
			long mod = ii % 10;
			if (mod == 0 || mod == 2 || mod == 3 || mod == 7 || mod == 8) {
				continue;
			}
			if (isp(i) && isp(ii)) {
				count++;
				System.out.println(ii);
			}
		}
		return Long.toString(count);
	}

	private static boolean isp(long ii) {
		long rev = 0;
		long iii = ii;
		while (iii != 0) {
			rev = rev * 10 + iii % 10;
			iii /= 10;
		}
		return rev == ii;
	}

	public static void main(String[] args) throws IOException {
		s = new Scanner(new FileInputStream(in));
		fw = new FileWriter(out);

		// init();

		int lines = s.nextInt();
		for (int i = 1; i <= lines; i++) {
			long start = System.currentTimeMillis();
			String result = handle();
			String output = String.format("Case #%d: %s\n", i, result);
			fw.write(output);
			System.out.printf("%3d %s",
					(System.currentTimeMillis() - start) / 1000, output);
		}

		fw.close();
		System.out.println("Done");
	}

}
