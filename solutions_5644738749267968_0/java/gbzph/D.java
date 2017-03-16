import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class D {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in;
		try {
			in = new Scanner(new File("C:\\temp\\google\\D-small-attempt0.in"));
			int T = in.nextInt();
			for(int cas=1; cas<=T; cas++) {
				int B = in.nextInt();
				double[] ArrN = new double[B];
				double[] ArrK = new double[B];
				for(int i=0; i<B; i++)
					ArrN[i] = in.nextDouble();
				for(int i=0; i<B; i++)
					ArrK[i] = in.nextDouble();
				Arrays.sort(ArrN);
				Arrays.sort(ArrK);
				double ans = 0;
				
				//build link
				StringBuilder resultlistBuilder=new StringBuilder(B*2);
				int pK=0,pN=0;
				while  (pK<B) {
					while ((pN<B) &&(ArrN[pN]<ArrK[pK])){
						resultlistBuilder.insert(0, "N");
						pN++;
					}
					resultlistBuilder.insert(0, "K");
					pK++;
				}
				while (pN<B)
				{
					resultlistBuilder.insert(0, "N");
					pN++;
				}
						
				String resultlist=resultlistBuilder.toString();
				//System.out.printf(resultlist+"\n");
				
				while (resultlist.contains("KN"))
				{
					resultlist=resultlist.replace("KN", "");
					//System.out.printf(resultlist+"\n");
				}
				int r1=resultlist.length()/2;
				
				//System.out.printf("------next---\n");
				resultlist=resultlistBuilder.toString();
				while (resultlist.contains("NK"))
				{
					resultlist=resultlist.replace("NK", "");
					//System.out.printf(resultlist+"\n");
				}
				
				int r2=B-resultlist.length()/2;
				
				System.out.printf("Case #%d: %d %d\n", cas,r2,r1 );	
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
