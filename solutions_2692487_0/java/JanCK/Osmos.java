package janck.codejam.cj2013.round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class Osmos {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		String filenameInput = "A-small-attempt0.in";
		String filenameOutput = "A-small-attempt0.out";
		Class currentClass = Osmos.class;
		try {

			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(
					path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			System.out.println("Number of Testcases: " + numOfTestcases);
			for (int i = 0; i < numOfTestcases; i++) {
				//System.out.println("  ++++++   ");
				//System.out.println("  ++++++   ");
				int neededmoves = -1;
				String[] lineone = input.readLine().split(" ");
				int arminStartSize = Integer.parseInt(lineone[0]);
				int numberOfOtherMotes = Integer.parseInt(lineone[1]);
				int[] values = new int[numberOfOtherMotes];
				String[] secondinputline = input.readLine().split(" ");
				
				for(int j=0;j<numberOfOtherMotes;j++){
					values[j] = Integer.parseInt(secondinputline[j]);
				}
				Arrays.sort(values);
				System.out.println("Armin's start size "+arminStartSize+" values: "+Arrays.toString(values));
				if(arminStartSize == 1) {
					neededmoves = numberOfOtherMotes;
				}else{
					int currentSizeOfArminsMote = arminStartSize;
					int optimalNumberOfMoves = numberOfOtherMotes;
					int addedMotes = 0;
					int currentMoteIndex = 0;
					while(addedMotes < optimalNumberOfMoves && currentMoteIndex <numberOfOtherMotes){
						//System.out.println("currentSizeOfArminsMote: " + currentSizeOfArminsMote + "  - currentMoteIndex: " + currentMoteIndex + "values[currentMoteIndex]" + values[currentMoteIndex]);

						if(currentSizeOfArminsMote > values[currentMoteIndex]){
							currentSizeOfArminsMote += values[currentMoteIndex];
							//System.out.println("Eat mote. so size becomes " + currentSizeOfArminsMote);
							currentMoteIndex++;
							if(currentMoteIndex == numberOfOtherMotes){
								optimalNumberOfMoves = addedMotes;
							}
							//System.out.println("number of added motes stays " + addedMotes);
							//System.out.println("number of motes left " + (numberOfOtherMotes-currentMoteIndex) + " if they were to be cleared, the number of steps were: " + (addedMotes + (numberOfOtherMotes-currentMoteIndex)));
							
							if(optimalNumberOfMoves > addedMotes + (numberOfOtherMotes-currentMoteIndex)){
								optimalNumberOfMoves = addedMotes + (numberOfOtherMotes-currentMoteIndex);
								//System.out.println("new optimum " + optimalNumberOfMoves);
							}
							
						}else{
							//add a mote of size currentSizeOfArminsMote-1
							currentSizeOfArminsMote = 2*currentSizeOfArminsMote-1;
							//System.out.println("add a mote of optimal size and eat it, so size becomes");
							addedMotes++;
							//System.out.println("number of added motes is now " + addedMotes);
							//System.out.println("number of motes left " + (numberOfOtherMotes-currentMoteIndex) + " if they were to be cleared, the number of steps were: " + (addedMotes + (numberOfOtherMotes-currentMoteIndex)));
							if(optimalNumberOfMoves > addedMotes + (numberOfOtherMotes-currentMoteIndex)){
								optimalNumberOfMoves = addedMotes + (numberOfOtherMotes-currentMoteIndex);
								//System.out.println("new optimum " + optimalNumberOfMoves);
							}
						}
						//cap armins size
						if(currentSizeOfArminsMote > 500000000){
							currentSizeOfArminsMote = 500000000;
						}
						
						//System.out.println("while " +addedMotes +" < "+optimalNumberOfMoves +"&& "+currentMoteIndex +"<"+numberOfOtherMotes);
					}
					neededmoves = optimalNumberOfMoves;
					
					
				}
				
				
				

				
				String outputString = "Case #" + (i + 1) + ": " + neededmoves;
				System.out.println(outputString);
				if (i + 1 != numOfTestcases) {
					outputString += "\n";
				}
				output.write(outputString);
			}

			output.flush();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
