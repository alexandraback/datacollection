import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Fractiles {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("C:\\Users\\JeffreyChan\\Downloads\\D-small-attempt1.in"));
		//		Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine());

		for (int i = 0; i < cases; i++) {
			int k_tiles = scan.nextInt();
			int complexity = scan.nextInt();
			int students = scan.nextInt();
			ArrayList<Long> list = new ArrayList<>();
			
			long j = 0;
			while (j < k_tiles){
				if (j != k_tiles - 1) list.add(j + 1);
				else {
					if (2L * k_tiles > (long) Math.pow(k_tiles, complexity)) {
						list.add((long) Math.pow(k_tiles, complexity));
					} else {
						list.add(2L * k_tiles);
					}
				}

				j++;
			}
			System.out.print("Case #" + (i + 1) + ":");
			for (long k : list) {
				System.out.print(" " + k);
			}
			System.out.println();
		}
	}
}
