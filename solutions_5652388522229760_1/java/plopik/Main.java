import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {
	public static void addDigits(boolean[] seen, int nb) {
		while (nb > 0) {
			seen[nb % 10] = true;
			nb /= 10;
		}
	}

	public static boolean testSeen(boolean[] seen) {
		boolean toReturn = true;
		for (boolean b : seen)
			toReturn &= b;
		return toReturn;
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("input.txt"));
		File write = new File("output.txt");
		FileWriter fWriter = new FileWriter(write);

		int nb = sc.nextInt();

		for (int i = 0; i < nb; i++) {
			int test = sc.nextInt();
			System.out.println(test);
			boolean[] seen = new boolean[10];
			
			for (int j = 0; j < seen.length; j++) {
				seen[j] = false;
			}
			int nbToAdd = 0;
			if (test == 0) {
				fWriter.write("Case #" + (i + 1) + ": INSOMNIA\n");
			} else {
				while (!testSeen(seen)) {
					nbToAdd += test;
					addDigits(seen, nbToAdd);
				}
				fWriter.write("Case #" + (i + 1) + ": " + nbToAdd + "\n");
			}
		}
		fWriter.flush();
		fWriter.close();
		sc.close();
	}
}
