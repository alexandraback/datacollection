package codeJam.competition2014.round1B;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class B {

	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("B-small-attempt0.in"));
//		System.setIn(new FileInputStream("B.in"));
		
		System.setOut(new PrintStream(new FileOutputStream("B-small-attempt0.out")));
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));

		int noCases = Integer.parseInt(bfr.readLine());
		
		String [] splitedLine;
		
		Cases:
		for (int i = 1; i <= noCases; i++) {
			
			int result = 0;
			
			splitedLine = bfr.readLine().split(" ");
			
			int A = Integer.parseInt(splitedLine[0]);
			int B = Integer.parseInt(splitedLine[1]);
			int K = Integer.parseInt(splitedLine[2]);
			
			
			for (int j = 0; j < A; j++) {
				for (int j2 = 0; j2 < B; j2++) {
					if ((j & j2) < K){
						result++;
					}
				}
			}
			
			System.out.println("Case #" + i + ": "+ result);
		}
		
		bfr.close();
	}

}
