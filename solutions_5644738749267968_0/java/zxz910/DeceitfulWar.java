import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;


public class DeceitfulWar {
	public static void main(String[] args) {
		
		//read in input
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		int n = scanner.nextInt();
		
		for (int i = 0; i < n; i++) {
			System.out.print("Case #" + (i+1)+ ": ");
			int size = scanner.nextInt();
			double [] nBlocks = new double[size];
			double [] kBlocks = new double[size];
			for (int j = 0; j < size; j++) {
				nBlocks[j] = scanner.nextDouble();
			}
			for (int j = 0; j < size; j++) {
				kBlocks[j] = scanner.nextDouble();
			}
			Arrays.sort(nBlocks);
			Arrays.sort(kBlocks);
			
			int count = 0;
			int ktop = size-1;
			int kbottom = 0;
			
			//System.out.println(Arrays.toString(nBlocks));
			//System.out.println(Arrays.toString(kBlocks));
			for (int j = 0; j < size; j++) {
				if (nBlocks[j] < kBlocks[kbottom]) {
					ktop--;
				}
				else {
					count++;
					kbottom++;
				}
			}
			
			int cur = 0;
			ktop = size - 1;
			kbottom = 0;
			
			for (int j = size - 1; j >= 0; j--) {
				if (nBlocks[j] > kBlocks[ktop]) {
					cur++;
					kbottom++;
				}
				else {
					ktop--;
				}
			}
			
			System.out.println(count + " " + cur);
			
			
			
		}
	}
}
