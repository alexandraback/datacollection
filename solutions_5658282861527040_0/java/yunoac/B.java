package R1B_2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner reader = new Scanner(new FileReader("in"));
		int nt = reader.nextInt();
		for (int t = 1; t <= nt; t++) {
			System.out.print("Case #" + t + ": ");
			int A = reader.nextInt();
			int B = reader.nextInt();
			int K = reader.nextInt();
			int cnt = 0;
			for(int x = 0; x < A; x++) {
				for(int y = 0; y < B; y++) {
					if((x & y) < K) {
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		}
	}
	
	
}
