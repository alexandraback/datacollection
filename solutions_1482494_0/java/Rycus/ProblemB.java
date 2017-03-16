import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemB {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new File("B-small.in"))) {
			try (BufferedWriter writer = new BufferedWriter(new FileWriter("B-small.out"))) {
				int numCases = scanner.nextInt();
						
				StringBuilder builder = new StringBuilder();
				for(int caseIdx = 0; caseIdx < numCases; caseIdx++) {
					builder.setLength(0);
	
					scanner.nextLine();
					int levels = scanner.nextInt();
					
					scanner.nextLine();
					int[] st1 = new int[levels]; // req for 1 star
					int[] st2 = new int[levels]; // req for 2 star
					
					for(int idx = 0; idx < levels; idx++) {
						st1[idx] = scanner.nextInt();
						st2[idx] = scanner.nextInt();
					}

					int required = levels * 2;
					int score = 0;
					
					int games = 0;
					int[] stars = new int[levels];
					
					while(score < required) {
						try {
							boolean completed = false;
							games++;
							
							int st1to2max = 0;
							
							int st1idx = -1;
							for(int idx = 0; idx < levels; idx++) {
								if(stars[idx] == 2) continue; // already completed
								if(st2[idx] <= score) { // can complete with 2 stars
									if(stars[idx] == 0) {
										stars[idx] = 2;
										score += 2;
										completed = true;
										break;
									} else {
//										st1idx = idx; // possible next
										if(st1to2max < st2[idx] - st1[idx]) {
											st1idx = idx; // possible next
											st1to2max = st2[idx] - st1[idx];
										}
									}
								} else if(st1[idx] <= score && stars[idx] == 0) { // can complete with 1 stars
									if(st1to2max < st2[idx] - st1[idx]) {
										st1idx = idx; // possible next
										st1to2max = st2[idx] - st1[idx];
									}
								}
							}
							
							if(!completed) {
								if(st1idx > -1) {
									stars[st1idx] = 1;
									score += 1;
								} else break;
							}
						} finally {
							System.out.println("Score: " + score + "/" + required 
									+ " | Stars: " + Arrays.toString(stars)
									+ " | St1: " + Arrays.toString(st1)
									+ " | St2: " + Arrays.toString(st2));
						}
					}
					
					if(score >= required) builder.append(games);
					else builder.append("Too Bad");
					
					String caseOutput = String.format("Case #%d: %s", caseIdx + 1, builder.toString());
					
					System.out.println(caseOutput);
					writer.append(caseOutput);
					writer.newLine();
				}
			}
		} catch(Throwable scannerEx) {
			scannerEx.printStackTrace();
		}
	}

}
