import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class QA {

	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			
			int mySize = sc.nextInt();
			int N = sc.nextInt();
			int[] moteSize = new int[N];
			
			for(int i = 0;i<N;i++) {
				moteSize[i] = sc.nextInt();
			}
			
			Arrays.sort(moteSize);
			int maxSize = moteSize[N-1];
			int result = 0;
			if(mySize == 1) {
				result = N;
			} else if(mySize <= maxSize) {
				int[] moteNeeded = new  int[N];
				for(int i =0;i<N;i++) {
					if(i>0) {
						moteNeeded[i] = moteNeeded[i-1];
					}
					while(mySize <= moteSize[i]) {
						mySize = mySize*2 - 1;
						moteNeeded[i]++;
					}
					mySize += moteSize[i];
				}
				result = N;
				for(int i =0;i<N;i++) {
					result = Math.min(result, moteNeeded[i] + (N-i-1));
				}
			}
			
			
			pw.println("Case #" + caseNum + ": " + result);
		}

		pw.flush();
		pw.close();
		sc.close();
	}
	
	
	
	
}
