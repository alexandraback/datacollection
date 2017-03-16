import java.io.*;
import java.util.*;

public class Testing {


	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("C:\\Users\\JeffreyChan\\Downloads\\A-large.in"));
		int cases = scan.nextInt();

		for (int i = 0; i < cases; i++) {
			long orig = scan.nextLong();
			long current = orig;
			long num = orig;
			int k = 1;
			Set<Long> mySet = new HashSet<>();
			for (long j = 0; j < 10; j++) {
				mySet.add(j);
			}

			while (!mySet.isEmpty()) {
				while (num > 0) {
					mySet.remove(num % 10);
					num /= 10;
				}

				if (!mySet.isEmpty()) {
					k++;
					current = orig * k;
					num = current;
				}

				if (current <= 0) {
					break;
				}
			}

			if (mySet.isEmpty())
				System.out.println("Case #" + (i + 1) + ": " + current);
			else
				System.out.println("Case #" + (i + 1) + ": " + "INSOMNIA");

		}

		scan.close();
    }


}