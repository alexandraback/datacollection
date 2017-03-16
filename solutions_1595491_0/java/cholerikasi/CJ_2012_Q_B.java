import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class CJ_2012_Q_B {
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("cj_files/in"));
		FileWriter w = new FileWriter(new File("cj_files/out"));
		
		int cases = in.nextInt();
		int numDancers, numSurprises, p, cSurprises, cRegular, score;
		for(int i = 1; i <= cases; i++) {
			numDancers = in.nextInt();
			numSurprises = in.nextInt();
			p = in.nextInt();
			cRegular = 0;
			cSurprises = 0;
			
			for(int j = 0; j < numDancers; j++) {
				score = in.nextInt();
				score -= p;
				if(score < 0) {
					continue;
				}
				
				score /= 2;
				if(p - score <= 1) {
					cRegular++;
				} else if (p - score == 2) {
					cSurprises++;
				}
			}
			
			w.append(String.format("Case #%d: %d\n", i, (cRegular + Math.min(cSurprises, numSurprises))));
		}
		
		w.close();
	}
}
