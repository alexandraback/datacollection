package qualitfy;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Test {
	public static void main (String args[]) throws FileNotFoundException {
		Scanner in = new Scanner(new File ("src//qualitfy/input.in"));
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int N  = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();
			int count = 0;
			int n1=0,n2=0,n3=0;
			for (int j = 0; j < N; j++) {
				int no = in.nextInt();
				int div = no % 3;
				n1 = n2 = n3 = no/3;
				if (div==1)
					n3 = n3 + 1;
				if (div == 2)
					n2 = n3 = n3 + 1;
				
				if (n3 >= p)
					count++;
				else if (S != 0 && no >= 2) {
					if(n2 == n3) {
						n3 = n3 + 1;
						n2 = n2 - 1;
						if (n3 >= p) {
							count++;
							S--;
						}
					}						
				}
			}

			System.out.println("Case #" + (i + 1) + ": " + count);
		}
	}

}