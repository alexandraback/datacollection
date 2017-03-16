import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Round1AProblemC {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int R = sc.nextInt();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int K = sc.nextInt();
		int Case = 1;
		PrintStream out;
		out = new PrintStream(new FileOutputStream("1AoutputC.txt"));
		out.println("Case #1:");
		while(R > 0){
			int[] k = new int[7];
			k[0] = sc.nextInt();
			k[1] = sc.nextInt();
			k[2] = sc.nextInt();
			k[3] = sc.nextInt();
			k[4] = sc.nextInt();
			k[5] = sc.nextInt();
			k[6] = sc.nextInt();
			int max = k[0];
			for(int i = 1; i<7; i++){
				if(max < k[i]) max = k[i];
			}
			if(max == 125) out.println(555);
			else if(max == 100) out.println(554);
			else if(max == 80) out.println(544);
			else if(max == 75) out.println(553);
			else if(max == 64) out.println(444);
			else if(max == 60) out.println(354);
			else if(max == 50) out.println(552);
			else if(max == 48) out.println(443);
			else if(max == 45) out.println(533);
			else if(max == 40) out.println(245);
			else if(max == 36) out.println(334);
			else if(max == 32) out.println(442);
			else if(max == 30) out.println(235);
			else if(max == 27) out.println(333);
			else if(max == 24) out.println(234);
			else if(max == 18) out.println(332);
			else if(max == 20) out.println(445);
			else if(max == 25) out.println(555);
			else if(max == 16) out.println(444);
			else if(max == 9) out.println(333);
			else if(max == 8) out.println(222);
			else if(max == 1) out.println(111);
			else if(max == 2) out.println(122);
			else if(max == 3) out.println(133);
			else if(max == 4) out.println(144);
			else if(max == 5) out.println(155);
			else if(max == 6) out.println(233);
			else if(max == 8) out.println(244);
			else if(max == 10) out.println(552);
			else if(max == 12) out.println(344);
			else if(max == 15) out.println(553);
			
			R--;
		}
		System.setOut(out);
	}

}
