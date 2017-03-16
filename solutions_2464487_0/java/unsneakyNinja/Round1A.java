import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class Round1A {

	public static void main(String[] args) {
		try {
			Scanner fileReader = new Scanner(new File("A-small-attempt0.in"));
			FileWriter fileWriter = new FileWriter(new File("output.txt"));

			int numTestCases = fileReader.nextInt();
			for (int i=0; i<numTestCases; ++i) {
				long startingRadius = fileReader.nextLong();
				long amountOfPaint = fileReader.nextLong();
				
				long innerWhiteCircleSize = startingRadius*startingRadius;
				long firstBlackCircleSize = (startingRadius+1)*(startingRadius+1);
				long nextCirclePaint = firstBlackCircleSize - innerWhiteCircleSize;
				int numCircles = 0;
				long paintLeft = amountOfPaint;
				while (paintLeft >= nextCirclePaint) {
					paintLeft -= nextCirclePaint;
					nextCirclePaint += 4;
					numCircles++;
				}
				
				
				
			
				
				
				fileWriter.write("Case #" + (i+1) + ": " + /* output goes here */ numCircles + "\n");
			}
			fileWriter.flush();
			fileWriter.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}
