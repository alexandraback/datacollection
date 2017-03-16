package janck.codejam.cj2013.round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class Bullseye {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		

		String filenameInput = "A-small-attempt0.in";
		String filenameOutput = "A-small-attempt0.out";
		Class currentClass = Bullseye.class;
		try {
			
			
			/*BigInteger sumEven = BigInteger.ZERO;
			BigInteger sumOdd = BigInteger.ZERO;
			BigInteger index = BigInteger.valueOf(1);
			BigInteger max = BigInteger.valueOf(10l).pow(9);
			
			boolean indexIsEven = false;
			while(index.compareTo(max)<0){
				if(indexIsEven){
				sumEven = sumEven.add(index.pow(2));
				//System.out.println("current index: " + index.toString() + " current sum Even: "+sumEven.toString());
				}
				else{
						sumOdd = sumOdd.add(index.pow(2));
						//System.out.println("current index: " + index.toString() + " current sum Even: "+sumEven.toString());
						}
				index = index.add(BigInteger.ONE);
				indexIsEven = !indexIsEven;
			}*/
			/*System.out.println("done");*/
			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(
					path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			System.out.println("Number of Testcases: " + numOfTestcases);
			for (int i = 0; i < numOfTestcases; i++) {
				boolean possible = true;
				String[] rAndT = input.readLine().split(" ");
				BigInteger r = new BigInteger(rAndT[0]);
				BigInteger t = new BigInteger(rAndT[1]);
				boolean rIsEven = !r.testBit(0);
				//System.out.println("r: " + r.toString() + " t: " + t.toString() + " is r even: " + rIsEven);
				BigInteger paintNotUsedInMiddleForThisr = paintNotUsedInMiddle(r);
				BigInteger jBig = BigInteger.ZERO;
				/*for(int j=1;j<20;j++){
					jBig = jBig.add(BigInteger.ONE);
					System.out.println("jBig : " + jBig.toString() +  "sumofsquares: " + sumofsq(jBig).toString() 
							+ " paintNotUsed " + paintNotUsedInMiddle(jBig)
							
							);
					
				}*/
				BigInteger availPaintWithMiddle = paintNotUsedInMiddleForThisr.add(t);
				BigInteger maxPaintable = getMaxPaintable(availPaintWithMiddle);
				//System.out.println("availPaintWithMiddle" + availPaintWithMiddle);
				//System.out.println("maxPaintable" + maxPaintable);
				//System.out.println("paintNotUsedInMiddleForThisr" + paintNotUsedInMiddleForThisr);

				
				//System.out.println("maxPaintable.subtract(r)" + maxPaintable.subtract(r));
				BigInteger numberOfDrawableCircles = maxPaintable.subtract(r).add(BigInteger.ONE).divide(new BigInteger("2"));
				//System.out.println("numberOfDrawableCircles" + numberOfDrawableCircles);
				
			
				String outputString = "Case #" + (i + 1)+": "+numberOfDrawableCircles.toString();
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

	private static BigInteger getMaxPaintable(BigInteger availPaintWithMiddle) {
		BigInteger lowerBound = BigInteger.ZERO;
		BigInteger upperBound = new BigInteger("10").pow(20);
		while(lowerBound.compareTo(upperBound) != 0){
			//System.out.println("lower: " + lowerBound.toString());
			//System.out.println("upper: " + upperBound.toString());
			BigInteger middle =  lowerBound.add(upperBound).divide(new BigInteger("2"));
			//System.out.println("middle: " + middle.toString());
			//System.out.println("paintForOuterRingEndInR(middle)" + paintForOuterRingEndInR(middle).toString());
			//System.out.println("availPaintWithMiddle" + availPaintWithMiddle.toString());
			
			if(paintForOuterRingEndInR(middle).compareTo(availPaintWithMiddle)<=0) {
				lowerBound = middle;
				
				
			}else{
				upperBound = middle;
			}
			if(lowerBound.add(BigInteger.ONE).compareTo(upperBound) == 0){
				if(paintForOuterRingEndInR(lowerBound).compareTo(availPaintWithMiddle)<=0
						)
					upperBound = lowerBound;
				else
					lowerBound = upperBound;
			}
		}
		
		
		return lowerBound;
	}
	private static BigInteger paintForOuterRingEndInR(BigInteger r){
		return paintNotUsedInMiddle(r.add(BigInteger.ONE));
	}

	private static BigInteger paintNotUsedInMiddle(BigInteger r) {
		boolean rIsEven = !r.testBit(0);
		BigInteger rMinusOne = r.subtract(BigInteger.ONE);
		BigInteger paintInMilliliter = null;
		if(rIsEven){
			/*System.out.println("rMinusOne" + rMinusOne.toString());
			System.out.println("sumofsq(rMinusOne)" + sumofsq(rMinusOne).toString());
			System.out.println("sumofsq(rMinusOne.subtract(BigInteger.ONE).divide(new BigInteger(2))).multiply(new BigInteger(8))" 
			+ sumofsq(rMinusOne.subtract(BigInteger.ONE).divide(new BigInteger("2"))).multiply(new BigInteger("8")));
			*/
			paintInMilliliter = sumofsq(rMinusOne).subtract(
					
					sumofsq(rMinusOne.subtract(BigInteger.ONE).divide(new BigInteger("2"))).multiply(new BigInteger("8"))
					
					);
					
					
					
					
			
		}else{
			//2 * 2^2 * sumofsq((r-1)/2) - 1*sumofsq(r-1)
			paintInMilliliter = sumofsq(
					
					rMinusOne.divide(new BigInteger("2"))
					
					).multiply(new BigInteger("8")).subtract(sumofsq(rMinusOne ))
					;
		}
		
		return paintInMilliliter;
	}

	private static BigInteger sumofsq(BigInteger b) {
		return b.multiply(b.add(BigInteger.ONE)).multiply(b.multiply(new BigInteger("2")).add(BigInteger.ONE)).divide(new BigInteger("6"));
		
	}

}
