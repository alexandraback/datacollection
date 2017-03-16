import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("C.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C.out"));
		out.write("Case #1:");
		out.newLine();
		
		in.nextInt();
		int R = in.nextInt();
		int N = in.nextInt();
		int M = in.nextInt();
		int K = in.nextInt();
		for (int i =0; i <R; i++){
			long[] product = new long[K];
			int[] factors = new int[M+1];
			for(int j=0; j<K; j++) {
				product[j] = in.nextLong();
				long temp = product[j];
				int fa = 0;
				while (temp % 5 == 0) {
					temp = temp/5;
					fa++;
				}
				if (fa>factors[5])
					factors[5] = fa;
				
				fa=0;
				temp = product[j];
				while (temp % 3 == 0) {
					temp = temp/3;
					fa++;
				}
				if (fa>factors[3])
					factors[3] = fa;
				
				fa=0;
				temp = product[j];
				while (temp % 4 == 0) {
					temp = temp/4;
					fa++;
				}
				if (fa>factors[4])
					factors[4] = fa;
												
			}
			//Arrays.sort(product);
			int n = N;
			for(int j =0; j< factors[5]; j++){
				n--;
				out.write("5");
			}
			for(int j =0; j< factors[3]; j++){
				n--;
				out.write("3");
			}
			for(int j =0; j< factors[4]; j++){
				n--;
				out.write("4");
				if (n==0)
					break;
			}
			while(n>0){
				n--;
				out.write("2");
			}
			
			out.newLine();
			
		}
		
		
		//out.write("Case #" + i + ": " + n);
		out.newLine();

		in.close();
		out.close();

	}

}
