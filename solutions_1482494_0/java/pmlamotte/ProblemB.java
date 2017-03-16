import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


/**
 * @author Paul LaMotte
 *
 */
public class ProblemB {

	static int count = 0;

	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(new File("B-small-attempt1.in"));
						System.setOut(new PrintStream(new FileOutputStream(new File("probB.out"))));

			int num = Integer.parseInt(scan.nextLine());

			for (int l = 0; l < num; l++) {
				Scanner s = new Scanner(scan.nextLine());
				int levels = s.nextInt();

				boolean[][] complete = new boolean[levels][2];
				int[][] stars = new int[levels][2];

				for (int i = 0;  i < levels; i++) {
					s = new Scanner(scan.nextLine());
					stars[i][0] = s.nextInt();
					stars[i][1] = s.nextInt();
				}

				count = 0;

				int tried = 0;
				while (!finished(complete)) {
					boolean found = false;
					for (int i = 0; i < levels; i++) {
						if (complete[i][1]) {
							continue;
						}

						if (count >= stars[i][1]) {
							complete[i][1] = true;
							count += (complete[i][0]) ? 1 : 2;
							complete[i][0] = true;
							found = true;
							tried++;
							break;
						}
					}
					if (found) {
						continue;
					}
					
					int max = -1, ind = -1;
					for (int i = 0; i < levels; i++) {
						if (complete[i][0]) {
							continue;
						}
						
						if (stars[i][1] > max && count >= stars[i][0]) {
							max = stars[i][1];
							ind = i;
						}
					}

					if (ind != -1) {
						count += 1;
						tried++;
						complete[ind][0] = true;
						found = true;
					}
					
//					for (int i = 0; i < levels; i++) {
//						if (complete[i][0]) {
//							continue;
//						}
//
//						if (count >= stars[i][0]) {
//							count += 1;
//							tried++;
//							complete[i][0] = true;
//							found = true;
//							break;
//						}
//					}
					if (!found) {
						break;
					}
				}

				if (!finished(complete)) {
					System.out.printf("Case #%d: Too Bad\n", l + 1);
				} else {
					System.out.printf("Case #%d: %d\n", l + 1, tried);
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}
	
	public static boolean finished(boolean[][] complete) {
		for (int i = 0; i < complete.length; i++) {
			if (!complete[i][1]) {
				return false;
			}
		}
		return true;
	}
}
