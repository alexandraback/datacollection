import java.util.LinkedList;
import java.util.Scanner;

public class PartElf { 
	public static void main(String[] arguments) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		sc.nextLine();

		for (int i = 0; i < t; i++) {
			String[] line = sc.nextLine().split("/");

			int p = Integer.parseInt(line[0]);
			int q = Integer.parseInt(line[1]);

			// Assuming p/q is in simplest form.
			if ((q & (q - 1)) != 0) {
				System.out.printf("Case #%d: impossible\n", i + 1);
				continue;
			}

			int j;
			for (j = 0; p < q; j++) {
				q /= 2;
			}

			System.out.printf("Case #%d: %d\n", i + 1, j);
		}		
	}
}