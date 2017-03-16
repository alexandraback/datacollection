
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		InputStream in = System.in;
		PrintStream out = System.out;
		if (args.length > 0) {
			try {
				in = new FileInputStream(args[0]);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner scanner = new Scanner(in);
		int cases = scanner.nextInt();
		for (int c = 1; c <= cases; ++c) {
			
			int op = 0;
			int opmin;
			long an;
			int a = scanner.nextInt();
			int n = scanner.nextInt();
			int sizes[] = new int[n];
			int ops[] = new int[n];
			for (int i = 0; i < sizes.length; ++i) {
				sizes[i] = scanner.nextInt();
			}
			Arrays.sort(sizes);
			an = a;
			opmin = n;
			for (int i = 0; i < sizes.length; ++i) {
				if (an > 1) {
					while (an <= sizes[i]) {
						an += an - 1;
						op++;
					}
					an += sizes[i];
				} else {
					op++;
				}
				ops[i] = op;
			}
			
			for (int i = 0; i < ops.length; ++i) {
				if (ops[ops.length - i - 1] + i < opmin) {
					opmin = ops[ops.length - i - 1] + i;
				}
			}
			
			out.format("Case #%d: ",c);
			out.println(opmin);
		}
	}
}
