import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Template {

	public static void main(String[] args) throws FileNotFoundException{
		Scanner scanner = new Scanner(new File("A-small-attempt0.in"));
		int numTests = Integer.parseInt(scanner.nextLine());
		PrintWriter writer = new PrintWriter("A-small-attempt0.out");
		
		for(int testNum = 1; testNum <= numTests; testNum++){
			long P;
			long Q;
			String[] line = scanner.nextLine().split("/");
			P = Integer.parseInt(line[0]);
			Q = Integer.parseInt(line[1]);
			
			boolean isPossible = false;
			double PoverQ = P/Q;
			int generationAgo = 0;
			int possiblePos = 0;
			boolean first = false;
			while (generationAgo < 40){
				P *= 2;
				PoverQ = ((double)P)/Q;
				generationAgo++;
				if (PoverQ == 1.0){
					isPossible = true;
					break;
				}	
				if (PoverQ > 1.0){
					P = P - Q;
					if (!first){
						possiblePos = generationAgo;
						first = true;
					}
				}
								
			}
			
			if (first)
				generationAgo = possiblePos;
			
			if (isPossible)
				writer.write("Case #" + testNum + ": " + generationAgo + "\n");
			else
				writer.write("Case #" + testNum + ": " + "impossible" + "\n");
		}
		writer.close();	
		scanner.close();
	}

}
