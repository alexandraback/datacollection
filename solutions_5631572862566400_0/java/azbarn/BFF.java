import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/** https://code.google.com/codejam/contest/4304486/dashboard#s=p2 */

public class BFF {

	public static void main(String[] args) {
		
		if(args.length == 0) {
			
			System.out.println("No arguments provided");
			return;
			
		}
		
		try {
			
			File file = new File(args[0]);
			Scanner input = new Scanner(file);
			FileWriter fileOut = new FileWriter("output.txt");
			BufferedWriter writer = new BufferedWriter(fileOut);
						
			int numTests = input.nextInt();
			int i;
			
			for(i = 0; i < numTests; i++) {
				
				int numStudents = input.nextInt();
				int j;
				//Make an array of BFFs ignoring zero index for simplicity
				//i.e. student 1's best friend is stored at index 1.
				int[] bffs = new int[numStudents+1];
				
				//System.out.println("BFFS----------");
				
				//Read in each student's best friend
				for(j = 1; j <= numStudents; j++) {
		
					bffs[j] = input.nextInt();
					//System.out.print(bffs[j]);
					
				}
				
				
				//Find the length of the chain starting at each student
				int maxChainLength = 1;
				
				//System.out.println("\n----------");
				
				for(j = 1; j <= numStudents; j++) {
					
					int currChainLength = 0;
					int currentStudent = j;
					int prevStudent = -1;
					
					//Loop until you have reached a student you have already visited
					boolean[] visited = new boolean[numStudents+1];
					visited[currentStudent] = true;
					
					while(currChainLength < numStudents) {
						
						currChainLength++;
						//System.out.print(currentStudent + " ");
						prevStudent = currentStudent;
						currentStudent = bffs[currentStudent];
						visited[currentStudent] = true;
						
						if(currentStudent == j) {
							
							//System.out.print("#");
							
							//We have reached the start of the circle
							if(currChainLength > maxChainLength) {
								maxChainLength = currChainLength;	
							}
							
							break;
							
						} else if(bffs[currentStudent] == prevStudent) {
							
							//System.out.print("&");
							
							//For each non visited student see if there is a chain to current student
							int maxSecondChain = 0;

							int k;
							for(k = 1; k <= numStudents; k++) {
								
								if(!visited[k]) {
									
									int currSecondChainLength = 0;
									int currentSecondStudent = k;
									
									while(currSecondChainLength < numStudents) {
										
										currSecondChainLength++;
										currentSecondStudent = bffs[currentSecondStudent];
										
										if(currentSecondStudent == currentStudent) {
											
											//We have reached the end of the first chain
											if(currSecondChainLength > maxSecondChain) {
												maxSecondChain = currSecondChainLength;	
											}
											
											break;
										} else if(visited[currentSecondStudent]) {
											break;
										}
										
									}
									
								}
								
							}
							
							//System.out.print("~" + maxSecondChain);
							
							currChainLength += maxSecondChain + 1;
							
							if(currChainLength > maxChainLength) {
								maxChainLength = currChainLength;	
							}
							
							break;
								
						}	
						
					}
					
					//System.out.println();
					
				}
				
				//Print result
				writer.write("Case #" + (i+1) + ": " + maxChainLength + "\n");
								
			}
			
			writer.close();
			fileOut.close();
			input.close();
			
		} catch(FileNotFoundException e) {
			
			System.out.println("Error reading input file");
			
		} catch(IOException e) {
			
			System.out.println("Error writing output");
			
		}
		
	}

}
