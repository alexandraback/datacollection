import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
 
public class Main {
 
	public static void main(String[] args) {
 
		BufferedReader br = null;
 
		try {
 
			br = new BufferedReader(new FileReader("D-large.in"));
			
			int t = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < t; i++) {
				int n = Integer.parseInt(br.readLine());
				
				double[] naomi = new double[n];
				double[] ken = new double[n];
				boolean[] kUsed = new boolean[n];
				String[] line1 = br.readLine().split(" ");
				String[] line2 = br.readLine().split(" ");
				
				for (int j = 0; j < n; j++) {
					naomi[j] = Double.parseDouble(line1[j]);
					ken[j] = Double.parseDouble(line2[j]);
					
					for (int k = j-1; k >= 0; k--) {
						if (naomi[k] < naomi[k+1]) {
							double temp = naomi[k];
							naomi[k] = naomi[k+1];
							naomi[k+1] = temp;
						}
						else
							break;
					}
					for (int k = j-1; k >= 0; k--) {
						if (ken[k] < ken[k+1]) {
							double temp = ken[k];
							ken[k] = ken[k+1];
							ken[k+1] = temp;
						}
						else
							break;
					}
					
					kUsed[j] = false;
				}
				
				

				int war = 0;
				int kMinIndex = n-1;
				for (int j = 0; j < n; j++) {
					boolean found = false;
					for (int k = kMinIndex; k >= 0; k--) {
						if (!kUsed[k]) {
							if (ken[k] > naomi[j]) {
								found = true;
								kUsed[k] = true;
								if (k == kMinIndex)
									kMinIndex--;
								break;
							}
						}
					}
					if (!found) {
						for (int k = kMinIndex; k >= 0; k--) {
							if (!kUsed[k]) {
								kUsed[k] = true;
								kMinIndex = k - 1;
								break;
							}
						}
						war++;
					}
				}
				
				
				for (int j = 0; j < n; j++) {
					kUsed[j] = false;
				}
				
				int dWar = n;
				int kMaxIndex = 0;
				for (int j = n-1; j >= 0; j--) {
					boolean found = false;
					for (int k = kMaxIndex; k < n; k++) {
						if (!kUsed[k]) {
							if (ken[k] < naomi[j]) {
								found = true;
								kUsed[k] = true;
								if (k == kMaxIndex)
									kMaxIndex++;
								break;
							}
						}
					}
					if (!found) {
						for (int k = kMaxIndex; k < n; k++) {
							if (!kUsed[k]) {
								kUsed[k] = true;
								kMaxIndex = k + 1;
								break;
							}
						}
						dWar--;
					}
				}
				
				
//				for (int j = 0; j < n; j++) {
//					System.out.print(naomi[j] + " ");
//				}
//				System.out.println();
//				for (int j = 0; j < n; j++) {
//					System.out.print(ken[j] + " ");
//				}
//				System.out.println();
				System.out.println("Case #" + (i+1) + ": " + dWar + " " + war);
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}