import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Bsmall {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException, IOException {
		try (Scanner scan = new Scanner(System.in);
				FileOutputStream os = new FileOutputStream("b.txt");
				PrintStream ps = new PrintStream(os)) {
			
			int T = scan.nextInt();
			for (int t=0; t<T; t++) {
				int D = scan.nextInt();
				List<Integer> P = new ArrayList<>();
				for (int d=0; d<D; d++)
					P.add( scan.nextInt());
				Collections.sort(P);
				int largest = P.get(P.size()-1); 
				int result = largest;
				int counter = 0;
				while (largest > 3) {
					int toSplit;
					if ((P.size() > 1 && largest >7 && P.get(P.size()-2) <= 3 )
							|| (P.size() == 1 && largest > 7))
						toSplit = largest / 3;
					else
						toSplit = largest / 2;
					P.set(P.size()-1, largest - toSplit);
					P.add(toSplit);
					Collections.sort(P);
					largest = P.get(P.size()-1);
					counter++;
					result = Math.min(result, largest + counter);
				}
				
				ps.format("Case #%d: %d\n", t+1, result);
			}
		}
	}

}
