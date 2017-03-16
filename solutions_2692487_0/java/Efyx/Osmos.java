package gcj2013.round1b.A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
		
		int T = scanner.nextInt();
		for(int t=0; t<T; t++) {
			int A = scanner.nextInt();
			int N = scanner.nextInt();
			int motes[] = new int[N];
			for(int i=0; i<N; i++) {
				motes[i] = scanner.nextInt();
			}
			Arrays.sort(motes);
			
			if(A == 1) {
				// Cannot absorb any mote, must remove all of them
				System.out.println("Case #" + (t+1) + ": " + N);
				continue;
			}
			
			int result = N;
			int insert = 0; // number of total inserted motes
			for(int i=0; i < N; i++) {
				while(A <= motes[i]) {
					// insert one mote, the biggest I can absorb
					A += A-1;
					insert++;
				}
				A += motes[i];
				
				// Result if I remove all remaining motes
				result = Math.min(result, insert+N-i-1);
			}
			
			System.out.println("Case #" + (t+1) + ": " + result);
		}
	}

}
