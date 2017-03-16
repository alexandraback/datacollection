import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class RoundOneC {

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
				
				int MAX = 3000001;
				boolean[] sums = new boolean[MAX];
				int[] S = new int[50];
				
				for (int j=1; j<MAX; j++)
					sums[j] = false;
				
				sums[0] = true;
				
				
				int N = in.nextInt();
				
				boolean fin = false;
				
				writer.append("Case #" + (i+1) + ":\n");
				
				for (int idx=0; idx<N; idx++) {
					S[idx] = in.nextInt();

					if (fin)
						continue;
					
					for (int j=MAX-1-S[idx]; j>=0; j--) {
						if (sums[j]) {
							if (sums[j+S[idx]]) {
								writer.append("" + S[idx] + " ");
								
								int rem = j;
								
								boolean[] check = new boolean[idx];
								
								for (int k=0; k<idx; k++)
									check[k] = false;
								
								while (rem > 0) {
									for (int k=0; k<idx; k++) {
										if ((!check[k]) && (S[k] <= rem) && (sums[rem-S[k]])) {
											rem -= S[k];
											writer.append("" + S[k] + " ");
											check[k] = true;
											break;
										}
									}
								}
								
								rem = j + S[idx];
								writer.append("\n");
								
								for (int k=0; k<idx; k++)
									check[k] = false;
								
								while (rem > 0) {
									for (int k=0; k<idx; k++) {
										if ((!check[k]) && (S[k] <= rem) && (sums[rem-S[k]])) {
											rem -= S[k];
											writer.append("" + S[k] + " ");
											check[k] = true;
											break;
										}
									}
								}
								
								fin = true;
								break;
							}
							else {
								sums[j+S[idx]] = true;
							}
						}				
					}
				}
				
				if (!fin)
					writer.append("Impossible");
				
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
