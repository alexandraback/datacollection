import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class QC {

	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("C-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			pw.println("Case #" + caseNum + ":");
			System.out.println(caseNum);
			
			int R = sc.nextInt();
			int N = sc.nextInt();
			int M = sc.nextInt();
			int K = sc.nextInt();
			for(int set = 0;set<R;set++) {
				int[] results = new int[K];
				for(int k=0;k<K;k++) {
					results[k] = sc.nextInt();
				}
				int[][] proba = new int[K][10];
				for(int i =0;i<K;i++) {
					for(int j=0;j<10;j++) {
						proba[i][j] = 0;
					}
				}
				for(int k=0;k<K;k++) {
					for(int i =2;i<10;i++) {
						int resultInter = results[k];
						while(resultInter%i==0) {
							resultInter = resultInter/i;
							proba[k][i]++;
						}
					}
				}
				
				double[] agre = new double[10];
				for(int i = 0;i<K;i++) {
					for(int j=0;j<9;j++) {
						agre[j] += proba[i][j];
					}
				}
				String resulta = "";
				int other=0;
				if(agre[5]!=0) {
					resulta = resulta + 5;
					other++;
					agre[5] -= K/3;
				}
				if(agre[7]!=0) {
					resulta = resulta + 7;
					other++;
					agre[5] -= K/3;
				}
				if(agre[3]!=0 && agre[6]==0) {
					resulta = resulta + 3;
					other++;
					agre[3] -= K/3;
				}
				if(agre[8]!=0) {
					resulta = resulta + 8;
					other++;
					agre[8] -= K/3;
				}
				if(agre[9]!=0) {
					resulta = resulta + 3;
					other++;
					agre[3] -= K/3;
				}
				if(agre[2]!=0 && agre[6]==0 && agre[4]==0&& agre[8]==0) {
					resulta = resulta + 2;
					other++;
					agre[2] -= K/2;
				}
				for(int i =0;i<N-other;i++) {
					int thisResult = 2;
					int random = (int) (Math.random()*(M-2)+2);
					
					resulta = resulta + random;
				}
				pw.println(resulta);
			}

		}

		pw.flush();
		pw.close();
		sc.close();
	}
}
