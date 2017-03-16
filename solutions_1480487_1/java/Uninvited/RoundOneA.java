import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class RoundOneA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		try {
			Scanner in = new Scanner(new File("inputA.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File("outputA.out")));
			
			int T = in.nextInt();
			in.nextLine();
			
			for (int i=0; i<T; i++) {
				int N = in.nextInt();
				
				int[] S = new int[N];
				int sum = 0;
				
				for (int j=0; j<N; j++){
					S[j] = in.nextInt();
					sum += S[j];
				}
				
				writer.append("Case #" + (i+1) + ": ");
				
				boolean fin = false;
				double ratio = 0;
				double newRatio = ((double)2 * sum) / N;
				int newNum = N;
				int num = 0;
				int totalSum = 0;
				int newTotalSum = 2*sum;
				
				while (!fin) {
					ratio = newRatio;
					totalSum = newTotalSum;
					num = newNum;
					
					for (int j=0; j<N; j++) {
						if (S[j] > ratio) {
							totalSum -= S[j];
							num--;
						}
					}
					newNum = num;
					newTotalSum = totalSum;
					newRatio = ((double) totalSum) / num;
					
					if (num == newNum)
						fin = true;
				}

				for (int j=0; j<N; j++) {
					
					double score = 0;
					
					if (S[j] <= newRatio) {
						score = ((double)(newRatio - S[j])) / sum * 100;
					}
					
					// System.out.println(ratio + " " + score);
					
					writer.append("" + score + " ");
				}
				
				writer.append("\n");
			}
			
			writer.close();
			
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
