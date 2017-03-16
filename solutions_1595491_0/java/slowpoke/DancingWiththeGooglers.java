import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class DancingWiththeGooglers {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B-small-attempt1.in"));
		PrintWriter pw = new PrintWriter("B-small.out");
		
		int tc = sc.nextInt();
		for(int i=1; i<=tc; i++){
			int N = sc.nextInt();
			int S = sc.nextInt();
			int P = sc.nextInt();
			int sum=0;
			for(int j=0; j<N; j++){
				int tot = sc.nextInt();
				int maxScore = (tot+2)/3;
				if(maxScore >= P){
					sum++;
				}else if(maxScore == P-1 && maxScore >0 && (tot%3)!=1){
					if(S>0){
						sum++;
						S--;
					}
				}
			}
			pw.println("Case #" + i + ": " + sum);
		}
		
		pw.close();
		sc.close();
	}

}
