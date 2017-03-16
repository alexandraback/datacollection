import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class R2B {

	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new File("D:\\Downloads\\B-small-attempt0 (1).in"));
			FileWriter out = new FileWriter("D:\\Downloads\\B.out");

			int t = in.nextInt();

			for (int i = 0; i < t; i++) {
				int a = in.nextInt();
				int b = in.nextInt();
				int c = in.nextInt();

				int count = 0;
				for (int j = 0; j < a; j++) {
					for (int k = 0; k < b; k++) {
						if ((j & k) < c) {
							count++;
						}
					}
				}

				String resultString = "Case #" + (i + 1) + ": " + count;
				out.write(resultString + "\n");
			}
			out.close();
			in.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
