package janck.codejam.cj2013.round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;

public class FallingDiamonds {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		String filenameInput = "B-small-attempt0.in";
		String filenameOutput = "B-small-attempt0.out";
		Class currentClass = FallingDiamonds.class;
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
				double probability = -1.0;
				int numberOfDiamonds = Integer.parseInt(lineone[0]);
				int posX = Integer.parseInt(lineone[1]);
				int posY = Integer.parseInt(lineone[2]);
				System.out.println("numberOfDiamonds " + numberOfDiamonds + "  posX " + posX + "  posY " + posY);
				posX = Math.abs(posX); 
				int hittingHorizontalAxisAt = posX + posY;
				if(hittingHorizontalAxisAt == 0){
					probability = 1.0;
					
				}else{
				int diamondlengthOfInnerPyramid = hittingHorizontalAxisAt - 1;
				System.out.println("inner ground size " + diamondlengthOfInnerPyramid);
				int diamondsInInnerPyramid = (diamondlengthOfInnerPyramid* diamondlengthOfInnerPyramid+ diamondlengthOfInnerPyramid)/2;
				System.out.println("inner areasize = "+ diamondsInInnerPyramid);
				int diamondsInOuterPyramid = ((diamondlengthOfInnerPyramid+2)* (diamondlengthOfInnerPyramid+2)+ (diamondlengthOfInnerPyramid+2))/2;
				System.out.println("outer areasize = "+ diamondsInOuterPyramid);
				if(numberOfDiamonds <= diamondsInInnerPyramid){
					probability = 0.0;
				}else{
					System.out.println("check "+numberOfDiamonds + ">= " + (diamondsInInnerPyramid + diamondlengthOfInnerPyramid +1 + posY +1));
					if(numberOfDiamonds >= diamondsInInnerPyramid + diamondlengthOfInnerPyramid +1 + posY +1 ){
						probability = 1.0;
					}else{
						int diamondsFallingAfterInnerPyramid = numberOfDiamonds - diamondsInInnerPyramid;
						// 0 < diamondsFallingAfterInnerPyramid < diamondlengthOfInnerPyramid +1 + posY +1
						System.out.println("diamondsFallingAfterInnerPyramid  " + diamondsFallingAfterInnerPyramid );
						int upperIndex = diamondsFallingAfterInnerPyramid - (posY+1);
						if(posX ==0){
							System.out.println("at top");
							if(numberOfDiamonds ==diamondsInOuterPyramid ){
								probability = 1.0;
							}else{
								probability = 0.0;
							}
							
						}else{
						BigInteger pTimesHalfToNumFalling= BigInteger.ZERO;
						BigInteger mChoosek = BigInteger.ONE;
						System.out.println("if at most " + upperIndex + " fall to the other side, all is good"); 
						for(int k=0;k<=upperIndex;k++){
							System.out.println(k+" elements to the left has this many options: " + mChoosek);
							System.out.println("At most "+k+" elements to the left has this many options: " +  pTimesHalfToNumFalling);
							
							pTimesHalfToNumFalling =  pTimesHalfToNumFalling.add(mChoosek);
							//calculate next mChooseK with
							//m = diamondsFallingAfterInnerPyramid;
							mChoosek = mChoosek.multiply(BigInteger.valueOf(diamondsFallingAfterInnerPyramid-k))
					                 .divide(BigInteger.valueOf(k+1));
							
						}
						BigInteger two = BigInteger.ONE.add(BigInteger.ONE);
						
						BigInteger twoToThem = two.pow(diamondsFallingAfterInnerPyramid);
						
						probability  = pTimesHalfToNumFalling.doubleValue() / twoToThem.doubleValue();
						
					}
					}
					
				}
				}
				
								
				

				
				String outputString = "Case #" + (i + 1) + ": " + probability;
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
