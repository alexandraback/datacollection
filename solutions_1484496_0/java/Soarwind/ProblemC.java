package roundoneB;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;

public class ProblemC {

	/**
	 * @param args
	 */
	public static String input = "C-small-attempt0.in";

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		// Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new FileReader(input));
		 //PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new FileWriter(input + ".out"));
		int t = in.nextInt();
		for (int test = 0; test < t; test++) {
			int n = in.nextInt();
			int[] numbers = new int[n];
			for (int i = 0; i < n; i++) {
				numbers[i] = in.nextInt();
			}
			int max = 10000000;
			boolean done = false;
			boolean[] resultA = null;
			boolean[] resultB = null;
			while (!done) {
				HashMap<Long, boolean[]> bitMap = new HashMap<Long, boolean[]>();
				resultA = new boolean[n];
				resultB = new boolean[n];
				for (int i = 0; i < max; i++) {
					boolean[] checkA = new boolean[n];
					Random rand = new Random();
					long currentSum = 0;
					for (int j = 0; j < n; j++) {
						checkA[j] = rand.nextBoolean();
						if (checkA[j]) {
							currentSum += numbers[j];
						}
					}
					boolean[] checkB = bitMap.get(currentSum);
					if (checkB == null) {
						bitMap.put(currentSum, checkA);
					} else {
						for (int k = 0; k < n; k++) {
							if (checkA[k] != checkB[k]) {
								resultA[k] = checkA[k];
								resultB[k] = checkB[k];
							} else {
								resultA[k] = false;
								resultB[k] = false;
							}
						}
						boolean equal = true;
						for(int k = 0;k<n;k++){
							if(resultA[k]!=resultB[k]){
								equal = false;
								break;
							}
						}
						if(equal){
							
						}
						else {
							done = true;
							break;
						}
					}
				}
			}
			out.println("Case #" + (test + 1) + ":");
			for(int i = 0;i<n;i++){
				if(resultA[i]){
					out.print(numbers[i]+" ");
				}
			}
			out.println();
			for(int i = 0;i<n;i++){
				if(resultB[i]){
					out.print(numbers[i]+" ");
				}
			}
			out.println();
			
		}
		out.close();
	}

}
