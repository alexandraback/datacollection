import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class B {
	public static void main(String ... args) throws Exception{
		Scanner in = new Scanner(new File("B-large.in"));
		PrintStream out = new PrintStream(new File("B-large.out"));
				
		int[] max1 = new int[31];
		int[] max2 = new int[31];
		max1[0] = 0;
		max2[0] = 0;
		
		max1[1] = 1;
		max2[1] = 1;
		
		max1[2] = 1;
		max2[2] = 2;
		
		max1[3] = 1;
		max2[3] = 2;
		
		max1[4] = 2;
		max2[4] = 2;
		
		max1[5] = 2;
		max2[5] = 3;
		
		max1[6] = 2;
		max2[6] = 3;
		
		max1[7] = 3;
		max2[7] = 3;
		
		max1[8] = 3;
		max2[8] = 4;
		
		max1[9] = 3;
		max2[9] = 4;
		
		max1[10] = 4;
		max2[10] = 4;
		
		max1[11] = 4;
		max2[11] = 5;
		
		max1[12] = 4;
		max2[12] = 5;
		
		max1[13] = 5;
		max2[13] = 5;
		
		max1[14] = 5;
		max2[14] = 6;
		
		max1[15] = 5;
		max2[15] = 6;
		
		max1[16] = 6;
		max2[16] = 6;
		
		max1[17] = 6;
		max2[17] = 7;
		
		max1[18] = 6;
		max2[18] = 7;
		
		max1[19] = 7;
		max2[19] = 7;
		
		max1[20] = 7;
		max2[20] = 8;
		
		max1[21] = 7;
		max2[21] = 8;
		
		max1[22] = 8;
		max2[22] = 8;
		
		max1[23] = 8;
		max2[23] = 9;
		
		max1[24] = 8;
		max2[24] = 9;
		
		max1[25] = 9;
		max2[25] = 9;
		
		max1[26] = 9;
		max2[26] = 10;
		
		max1[27] = 9;
		max2[27] = 10;
		
		max1[28] = 10;
		max2[28] = 10;
		
		max1[29] = 10;
		max2[29] = 10;
		
		max1[30] = 10;
		max2[30] = 10;
		
		int T = in.nextInt();
		in.nextLine();
		
		for(int t=0;t<T;t++){
			int N=in.nextInt();
			int S=in.nextInt();
			int p=in.nextInt();
			int cnt1 = 0;
			int cnt2 = 0;
			for(int n=0;n<N;n++){
				int num = in.nextInt();
				cnt1+= max1[num]>=p?1:0;
				cnt2+= max2[num]>=p?1:0;
			}
			cnt1 += Math.min(cnt2-cnt1, S);
			out.println("Case #" + (t+1) + ": " + cnt1);
		}
		
		
	}
}
