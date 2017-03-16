import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class DancingWithTheGooglersLarge {

	public static void main(String[] args) {

		File file = new File("/Users/NoK/Desktop/B-large.in");
		int counter = 1;

		try {
			Scanner sc = new Scanner(file);

			int numOfCases = sc.nextInt();

			sc.nextLine();

			for (int i = 0; i < numOfCases; i++) {
				int numOfGooglers = sc.nextInt();
				int numOfSupTrip = sc.nextInt();
				int bestScores = sc.nextInt();
				int maxBestGooglers = 0;

				for (int j = 0; j < numOfGooglers; j++) {
					int googlerPoint = sc.nextInt();
					if (googlerPoint == 0) {
						if (bestScores == 0) {
							maxBestGooglers++;
						}
						continue;
					} else if (googlerPoint == 1) {
						if ((bestScores == 0) || (bestScores == 1)) {
							maxBestGooglers++;
						}
						continue;
					} else if (googlerPoint == 2) {
						if ((bestScores == 0) || (bestScores == 1)) {
							maxBestGooglers++;
						} else if (bestScores == 2) {
							if (numOfSupTrip > 0) {
								maxBestGooglers++;
								numOfSupTrip--;
							}
						}
						continue;
					}
					if (googlerPoint % 3 == 0) {
						if (googlerPoint / 3 >= bestScores) {
							maxBestGooglers++;
						} else {
							if (numOfSupTrip > 0) {
								if ((googlerPoint/3)+1 == bestScores) {
									maxBestGooglers++;
									numOfSupTrip--;
								}
							}
						}
					} else if (googlerPoint % 3 == 1) {
						if ((googlerPoint/3)+1 >= bestScores) {
							maxBestGooglers++;
						}
					} else if (googlerPoint % 3 == 2) {
						if ((googlerPoint/3)+1 >= bestScores) {
							maxBestGooglers++;
						} else {
							if (numOfSupTrip > 0) {
								if ((googlerPoint/3)+2 == bestScores) {
									maxBestGooglers++;
									numOfSupTrip--;
								}
							}
						}
					}
				}

				try { 
					FileWriter fw = new FileWriter("/Users/NoK/Desktop/B-large.out", true);
					BufferedWriter bw = new BufferedWriter(fw);
					System.out.println("Case #" + counter + ": " + maxBestGooglers);
					bw.write("Case #" + counter + ": " + maxBestGooglers);
					bw.newLine();
					bw.close();
					counter++;
				} catch (Exception e){
					System.err.println("Error: " + e.getMessage());
				}

			}

		} catch (FileNotFoundException e ) {
			e.printStackTrace();
		}

	}

}