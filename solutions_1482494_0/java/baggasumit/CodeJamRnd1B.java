import java.io.*;
import java.util.*;

public class CodeJamRnd1B {
	
	public void permute(int[] str, int d) {
		  if (d == str.length) {
			  //decideWinner(str);
			  for(int k : str)
				  System.out.print(k + " " );
			  System.out.println(".");
		  }
		  else
		    for (int i = d; i < str.length; i++) {//i <- d to length(str)
		      swap(str, d, i);//(str[d] <-> str[i]) // swap the characters for permutation
		      permute(str, d + 1);
		      swap(str, d, i); //str[d] <-> str[i]) // undo the swapping for parent call
		    }
		}
	public void swap(int[] A, int i, int j) {
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
	public static void main(String[] args) throws IOException {
		CodeJamRnd1B sh = new CodeJamRnd1B();
		int i, j, k;
		long startTime = System.currentTimeMillis();
		File inFile = new File("B-small-attempt0.in"); // File to read from
		File outFile = new File("Rnd1B-small.out");

		BufferedReader reader = new BufferedReader(new FileReader(inFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));

		String line = null;
		line = reader.readLine();
		int cases = Integer.parseInt(line);
		int counter = 1;
		int[] arr = {0,1,2,3};
		//sh.permute(arr, 0);

		while ((line = reader.readLine()) != null) {
			int tries = 0;
			int stars = 0;
			int N = Integer.parseInt(line);
			int[] level1 = new int[N];
			int[] level2 = new int[N];
			for(i = 0; i < N; i++) {
				line = reader.readLine();			
				String[] node = line.split(" ");
				level1[i] = Integer.parseInt(node[0]);				
				level2[i] = Integer.parseInt(node[1]);
				//System.out.println(level1[i] + " " + level2[i]);				
			}
			boolean[] lev1 = new boolean[N];
			boolean[] lev2 = new boolean[N];
			Arrays.fill(lev1, false);
			Arrays.fill(lev2, false);
			boolean alltrue = false;
			boolean bad = false;
			while(!alltrue) {
				boolean found = false;
			
				for(i = 0; i < N; i++) {
					if(!lev2[i] && level2[i] <= stars) {
						lev2[i] = true;
						found = true;
						stars += lev1[i] ? 1 : 2;
						tries++;
						break;					
					}
				}		
				if(!found) {
					for(i = 0; i < N; i++) {
						if(!lev1[i] && level1[i] <= stars) {
							lev1[i] = true;
							found = true;
							stars++;
							tries++;
							break;					
						}
					}		
				}
				if(!found) {
					//System.out.println("Too Bad");
					bad = true;					
					writer.write("Case #"+counter+": Too Bad");
					writer.newLine();
					break;
				}
				int count = 0;
				for(i = 0; i < N; i++) {
					if(lev2[i])
						count++;
				}
				if(count == N)
					alltrue = true;
			}
			if(!bad) {
				//System.out.println(tries);
			
				writer.write("Case #"+counter+": "+tries);
				writer.newLine();
			}
			counter++;
		}		
		writer.close();
		long endTime = System.currentTimeMillis();
		long totalTime = endTime - startTime;
		System.out.println("Total Time: " + totalTime);
	}
}
