import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Problem2 {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintStream output = new PrintStream(new FileOutputStream(new File("output.txt")));
		
		int T = input.nextInt();
		input.nextLine();
		
		for(int i=1; i <= T; ++i) {
			int N = input.nextInt();
			input.nextLine();
			ArrayList<Integer> firstStar = new ArrayList<Integer>();
			ArrayList<Integer> secondStar = new ArrayList<Integer>();

			for(int j=0; j<N; ++j) {
				Scanner line = new Scanner(input.nextLine());
				firstStar.add(line.nextInt());
				secondStar.add(line.nextInt());
			}
			//System.out.printf("Case:%d, T:%d, N:%d \n",i, T,N);
			
			int nstars = 0;
			int toGo = N;
			int steps = 0;
			int toBad = 0;
			
			while(toGo > 0) {
				if (Collections.min(secondStar) > nstars) {
					if (Collections.min(firstStar) > nstars) {
						System.out.printf("Case #%d: ",i);
						System.out.println("Too Bad");
						output.printf("Case #%d: ",i);
						output.println("Too Bad");
						toGo = 0;
						toBad =1;
					}
					else {
						int argmin = firstStar.indexOf(Collections.min(firstStar));
						firstStar.set(argmin, 4000);
						nstars++;
						steps++;
					}
				}
				else {
					int argmin = secondStar.indexOf(Collections.min(secondStar));
					secondStar.set(argmin, 4000);
					nstars++;
					if(firstStar.get(argmin) != 4000) {
						nstars++;
						firstStar.set(argmin, 4000);
					}
					steps++;
					toGo--;
				}
			}
			if(toBad!=1) {
				System.out.printf("Case #%d: %d\n",i, steps);
				output.printf("Case #%d: %d\n",i, steps);
			}
		}
	}
}
