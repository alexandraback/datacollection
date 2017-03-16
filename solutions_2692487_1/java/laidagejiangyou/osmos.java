import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class osmos {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileWriter fw = new FileWriter("out.txt");
		Scanner sn = new Scanner(System.in);
		int testCase = sn.nextInt();
		for(int t=1; t<=testCase; ++t) {
			fw.write("Case #" + t + ": ");
			int a, n;
			a = sn.nextInt();
			n = sn.nextInt();
			int size[] = new int[n];
			for(int i=0; i<n; ++i) {
				size[i] = sn.nextInt();
			}
			
			// consider a is one, no absorb
			if(a == 1) {
				fw.write("" + n + "\n");
				continue;
			}
			Arrays.sort(size);
			int optimal = n;
			for(int i=0, op = 0; i < n; ++i) {
				while(a <= size[i]) {
					a += a - 1;
					++op;
				}
				a += size[i];
				optimal = Math.min(optimal, op + n - i - 1);
				
			}
			fw.write("" + optimal + "\n");
		}
		
		fw.close();
	}
	

}
