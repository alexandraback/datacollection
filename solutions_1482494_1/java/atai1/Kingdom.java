import java.io.*;
import java.util.*;

public class Kingdom {
	public static void main(String[] args) throws IOException {		
		BufferedReader br = new BufferedReader(new FileReader(new File("/Users/atai/Play/Codejam/input.txt")));
		PrintWriter prn = new PrintWriter(new FileWriter("output.txt"));
		
		int numTests = Integer.parseInt(br.readLine().trim());
		for (int i = 0; i < numTests; i++) {
			int numLevels = Integer.parseInt(br.readLine().trim());
			int[] level1 = new int[numLevels];
			int[] level2 = new int[numLevels];
			boolean[] level1Done = new boolean[numLevels];
			boolean[] level2Done = new boolean[numLevels];
			for (int j = 0; j < numLevels; j++) {
				String[] arg = br.readLine().trim().split(" ");
				level1[j] = Integer.parseInt(arg[0]);
				level2[j] = Integer.parseInt(arg[1]);
				level1Done[j] = false;
				level2Done[j] = false;
			}
			boolean done = false;
			int numStars = 0;
			int times = 0;
			while(!done) {
				System.out.println(numStars);
				int j = 0;
				// doe the maximum possible
				int index = -1;
				int max = -1;
				for (j = 0; j < numLevels; j++) {
					if ((level2[j] <= numStars) && (!level2Done[j])) {
						/*if (level1Done[j])
							numStars +=1;
						else
							numStars +=2;
						times++;
						level2Done[j] = true;
						level1Done[j] = true;
						break;*/
						if (level2[j] > max) {
							max = level2[j];
							index = j;
						}							            
					}						
				}
				if (index != -1) {
					if (level1Done[index])
						numStars +=1;
					else numStars +=2;
					level2Done[index] = true;
					level1Done[index] = true;
					times++;
				}
				//System.out.println(index);
				int indexsecond = -1;
				int maxsecond = -1;
				if (index == -1) {
				for (j = 0; j < numLevels; j++) {
					if ((level1[j] <= numStars) && (!level2Done[j]) && (!level1Done[j])) {
						/*numStars +=1;
						times++;
						level1Done[j] = true;
						System.out.println(j);
						break;*/
						if (level2[j] > maxsecond) {
							maxsecond = level2[j];
							indexsecond = j;
						}						
					}
				}
				if (indexsecond != -1) {
					numStars +=1;
					times++;
					level1Done[indexsecond] = true;
				}
				} else {
					done = true;
					for (j = 0 ;j < numLevels; j++) {
						done = done && level2Done[j];
					}
					continue;
				}

				//System.out.println(indexsecond);
				if (indexsecond == -1) {
					break;
				} else {
					done = true;
					for (j = 0 ;j < numLevels; j++) {
						done = done && level2Done[j];
					}					
				}
			}			
			if(!done) {
				if (numStars == 2*numLevels)
					System.out.println("a;lskdfja;lskdfj");
					prn.printf("Case #%d: Too Bad\n", i+1);
			}
			else {
				if (numStars != 2*numLevels)
					System.out.println("OHS;DLAKFJSDF");
				prn.printf("Case #%d: %d\n", i+1, times);
			}
		}
		
		prn.close();
	}
}
