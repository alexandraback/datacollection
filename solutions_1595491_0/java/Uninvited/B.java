import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class B {

	public static void main(String[] args) {
		
		try {
			Scanner in = new Scanner(new File("smallB.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File("smallB.out")));
			
			int T = in.nextInt();
			in.nextLine();
			
			for (int i=0; i<T; i++) {
				
				int N = in.nextInt();
				int S = in.nextInt();
				int p = in.nextInt();
				
				int[] array = new int[N];
				
				for (int j=0; j<N; j++) { 
					array[j] = in.nextInt();
				}
				
				int res = 0;
				
				//if (p > 0) {
				
				Arrays.sort(array);
				
				for (int j=N-1; j>=0; j--) {
					if ((3*p - 2) <= array[j]) {
						res++;
					}
					else if ((3*p-4 <= array[j]) && (S > 0) && !(p==1 && array[j] == 0)) {
						res++;
						S--;
					}
				}
				
				//}
				
				writer.append("Case #" + (i+1) + ": " + res + "\n");
			}
			
			writer.close();
			
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
