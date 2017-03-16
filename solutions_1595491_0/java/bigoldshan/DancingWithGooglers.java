import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;


public class DancingWithGooglers {
	
	public static void main(String[] argv) throws Exception {
//		Scanner s = new Scanner(System.in);
		Scanner s = new Scanner(new FileInputStream("DancingWithGooglers/B-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileOutputStream("DancingWithGooglers/B-small-attempt1.out"));
//		PrintWriter pw = new PrintWriter(System.out);
		
		int T = s.nextInt();
		for(int i=1;i<=T;i++) {
			int N = s.nextInt();
			int S = s.nextInt();
			int p = s.nextInt();
			int[] scores  = new int[N];
			for(int j=0;j<N;j++) {
				scores[j] = s.nextInt();
			}
			
			int num = 0;
			for(int j=0;j<N;j++) {
				if(scores[j] < p) continue;
				int min = (scores[j]-p)/2;				
				if(p - min == 2) {
					if(S>0) {
						S--;
						num++;
					}
				} else if(p- min < 2){
					num ++;
				}
			}
			
			pw.println("Case #" + i +": " + num);
			System.out.println("Case #" + i +":" +num);
		}
		pw.flush();
		pw.close();
	}

}
