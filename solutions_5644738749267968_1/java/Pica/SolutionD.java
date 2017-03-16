import java.util.*;
import java.io.*;
import java.math.*;


// Author: Pica
// Google Code Jam 2014


public class SolutionD {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			int N = sc.nextInt();
                        double[] naomi = new double[N];
                        double[] ken = new double[N];
			
                        for (int i = 0; i < N; i++) {
                            naomi[i] = sc.nextDouble();
                        }
                        for (int i = 0; i < N; i++) {
                            ken[i] = sc.nextDouble();
                        }
                        Arrays.sort(naomi);
                        Arrays.sort(ken);
                        
                        int j = 0;
                        //caculate z
                        int z = 0;
                        for (int i = 0; i < N; i++) {
                            while (j< N && ken[j]<naomi[i])
                                j++;
                            if (j< N) {
                                z++;
                                j++;
                            }                       
                        }
                        z = N-z;
                        //caculate y
                        int k_start = 0;
                        j = 0;
                        int y = 0; 
                        for (int i = 0; i < N; i++) 
                            if (naomi[i]<ken[j])
                            {
                                //discard loose                   
                            }
                            else {
                                y++;
                                j++;
                            }

			pw.println("Case #" + caseNum + ": " + y + " " + z );
			
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new SolutionD()).doMain();
	}
}