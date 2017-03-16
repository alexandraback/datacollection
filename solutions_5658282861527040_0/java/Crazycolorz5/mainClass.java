import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class mainClass {

	public static void main(String[] args) {
		File f = new File("B-small-attempt1.in");
		File out = new File("newLotteryGame.out");
		FileInputStream fin;
		Scanner sin = null;
		try {
			fin = new FileInputStream(f);
			FileWriter fout = new FileWriter(out);
			try {
				sin = new Scanner(fin);
				int numOfCases = sin.nextInt();
				for(int casenum = 0; casenum<numOfCases; casenum++)
				{
					int A = sin.nextInt();
					int B = sin.nextInt();
					int K = sin.nextInt();
					
					long numWays = 0;
					/*int numBitsK = log2(K)+1;
					int numBitsA = log2(A)+1;
					int numBitsB = log2(B)+1;
					if(!(numBitsK>numBitsA||numBitsK>numBitsB))
					{
						int numCombinationsofKWithSetBitButNoneBefore[] = new int[numBitsK];
						int numCombinationsofAWithSetBitButNoneBefore[] = new int[numBitsA];
						int numCombinationsofBWithSetBitButNoneBefore[] = new int[numBitsB];
						//numCombinationsofKWithSetBit[i] = 
						//0th bit -> (K-2)/2+K%2 = (K-2)/2+K%2
						//1st bit -> (K-4)/2+(K-2)%3
						//
						//int beforeCurrentPattern = (K-bitPlacePlusOneValue)/2;
						//int inCurrentPattern = 0;
						//if(K%bitPlacePlusOneValue!=K%bitPlaceValue)
						//{
						//	inCurrentPattern = K%bitPlacePlusOneValue-K%bitPlaceValue;
						//}
						
						//numCombinationsofKWithSetBit[i] = beforeCurrentPattern+inCurrentPattern;
						for(int i=0; i<numBitsK; i++)
						{
							int bitPlacePlusOneValue = (int)Math.pow(2, i+1);
							int bitPlaceValue = (int)Math.pow(2, i);
							numCombinationsofKWithSetBitButNoneBefore[i] = (K+bitPlaceValue)/bitPlacePlusOneValue;
						}
						//repeat for A, B
						for(int i=0; i<numBitsA; i++)
						{
							int bitPlacePlusOneValue = (int)Math.pow(2, i+1);
							int bitPlaceValue = (int)Math.pow(2, i);
							numCombinationsofAWithSetBitButNoneBefore[i] = (A+bitPlaceValue)/bitPlacePlusOneValue;
						}					
						for(int i=0; i<numBitsB; i++)
						{
							int bitPlacePlusOneValue = (int)Math.pow(2, i+1);
							int bitPlaceValue = (int)Math.pow(2, i);
							numCombinationsofBWithSetBitButNoneBefore[i] = (B+bitPlaceValue)/bitPlacePlusOneValue;
						}
						//int[] totalNumCombinationsWithSetBit = new int[numBitsK];
						for(int i=0; i<numBitsK; i++)
						{
							numWays+=numCombinationsofAWithSetBitButNoneBefore[i]*numCombinationsofBWithSetBitButNoneBefore[i]*numCombinationsofKWithSetBitButNoneBefore[i];
							//note ways are counted multiple times.
						}
						//now, account for 0
						int numCombinationsofAWithoutSetBitAndNoneBefore[] = new int[numBitsA];
						int numCombinationsofBWithoutSetBitButNoneBefore[] = new int[numBitsB];
						int largerBitsSansLO = 0, smallerBitsSansLO = 0;
						if(numBitsA<numBitsB)
						{
							smallerBitsSansLO = numBitsA-1;
							largerBitsSansLO = numBitsB-1;
						}
						else
						{
							largerBitsSansLO = numBitsA-1;
							smallerBitsSansLO = numBitsB-1;
						}
						//Break up into the cases without and with the largest order bit
						//Firstly, I have smallerBitsSansLO to distribute among A and B
						//This is 2^(smallerBitsSansLO+1)-1 possibilities, since it could be less than that many bits
						//Not, WLOG, suppose A<B
						//I can try this process again with pretending A doesn't have its LO bit.
						//So, A-2^(NumBitsA-1)
						
						for(int x=0; x<numBitsA; x++)
						{
							for(int y=0; y<numBitsB; y++)
							{
								
							}
						}
					}*/
					
					//inelegant brute forcer
					for(int i=0; i<A; i++)
					{
						for(int j=0; j<B; j++)
						{
							if((i&j)<K)
								numWays++;				
						}
					}					
					
					
					try {
						fout.write("Case #" + (casenum+1) + ": ");
						fout.write(Long.toString(numWays));
						fout.write("\n");
						fout.flush();
					} catch (IOException e1) {e1.printStackTrace();}
				}
			} finally {
				sin.close();
				fout.close();
			}
		}
		catch(IOException e)
		{}
	}
	
	//code from http://stackoverflow.com/questions/3305059/how-do-you-calculate-log-base-2-in-java-for-integers
	public static int log2(int n){
	    if(n <= 0) throw new IllegalArgumentException();
	    return 31 - Integer.numberOfLeadingZeros(n);
	}
}