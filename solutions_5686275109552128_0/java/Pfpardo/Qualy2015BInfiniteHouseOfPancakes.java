import java.io.*;

public class Qualy2015BInfiniteHouseOfPancakes {

	enum ProblemType{SAMPLE,SMALL,LARGE};
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String roundPrefix = "Qualy2015";
		String problem = "B";
		ProblemType activeFile = ProblemType.SMALL;
		File file, outFile;
		String activeFileName;
		switch (activeFile) {
			case SAMPLE :
				activeFileName="sample";
				break;
			case SMALL:
				activeFileName="small-attempt2";
				break;
			case LARGE:
				activeFileName="large";
				break;
			default:
				throw new RuntimeException("Problem type not supported");
		}
		 file = new File(String.format("files/%s/%s-%s.in",roundPrefix,problem,activeFileName));
		 outFile = new File(String.format("files/%s/%s-%s.out",roundPrefix,problem,activeFileName));
		

		 BufferedReader br = new BufferedReader(new FileReader(file));
		 BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
		 int testCases = Integer.parseInt(br.readLine());
		 
		 //Specific for the problem
		 int dNonEmptyPlateDiners;
		 String[] pancakePerPlateStr;
		 long result;
		 initializeMagicArray();
		 for(int t=1;t<=testCases;t++){
			 dNonEmptyPlateDiners =  Integer.parseInt( br.readLine());
			 pancakePerPlateStr =br.readLine().split(" "); 
			 result = solveTestCase(dNonEmptyPlateDiners,pancakePerPlateStr);
			 StringBuilder caso = new StringBuilder();
			 caso.append("Case #");
			 caso.append(t);
			 caso.append(": ");
			 caso.append(result);
			 caso.append("\n");
			 bw.write(caso.toString());
		 }
		 br.close();
		 bw.close();

	}

	
private static long solveTestCase(int initialDNonEmptyPlateDiners, String []initialPancakesPerPlateStr){
		
		int [] dinersWithIPancakes = new int[1001] ;
		int p,numOfDiners,maxPancakesPerDiner;
		long totalAmountOfPancakes = 0;
		maxPancakesPerDiner = 0;
		numOfDiners = initialDNonEmptyPlateDiners;
		
	
		for (int i=0; i<initialDNonEmptyPlateDiners;i++) {
			p = Integer.parseInt(initialPancakesPerPlateStr[i]);
			dinersWithIPancakes[p]+=1;
			totalAmountOfPancakes += p; 
			if (p>maxPancakesPerDiner) {
				maxPancakesPerDiner = p;
			}
		}
		

		long minimumTime = maxPancakesPerDiner;
		long movesWithNNormalMoves;

		for (int numOfNormalMoves = 1; numOfNormalMoves < maxPancakesPerDiner ;numOfNormalMoves ++) {
			movesWithNNormalMoves = numOfNormalMoves;			
			for (int numOfPancakes=1 ; numOfPancakes<=maxPancakesPerDiner;numOfPancakes++){
				movesWithNNormalMoves += dinersWithIPancakes[numOfPancakes]*numSpecialMovesWithIPancakesAndJNormalMoves[numOfPancakes][numOfNormalMoves];
			}
			if(movesWithNNormalMoves < minimumTime) {
				minimumTime = movesWithNNormalMoves;
			}			
		}
		return minimumTime;
	}

	private static int[][]numSpecialMovesWithIPancakesAndJNormalMoves = new int[1001][1001];

	private static void initializeMagicArray() {
		int minimumSpecMoves,specMoves; 
		numSpecialMovesWithIPancakesAndJNormalMoves[2][1]=1;
		for (int numPancakes = 3; numPancakes <=1000; numPancakes++) {
			for (int numNormalMoves = 1; numNormalMoves <= 1000; numNormalMoves++) {
				if (numPancakes <= numNormalMoves) {
					minimumSpecMoves = 0;
				} else {
					minimumSpecMoves = numPancakes;
					for (int movedPancakes = 1; movedPancakes <= numPancakes/2;movedPancakes++) {
						specMoves = 1 
								+ numSpecialMovesWithIPancakesAndJNormalMoves[movedPancakes][numNormalMoves]
								+ numSpecialMovesWithIPancakesAndJNormalMoves[numPancakes-movedPancakes][numNormalMoves];
						if (minimumSpecMoves > specMoves) {
							minimumSpecMoves = specMoves;
						}
					}
				}
				numSpecialMovesWithIPancakesAndJNormalMoves[numPancakes][numNormalMoves] = minimumSpecMoves;
			}
		}
	}	
	
	
	
private static long solveTestCaseTry2(int initialDNonEmptyPlateDiners, String []initialPancakesPerPlateStr){
		
		int [] dinersWithIPancakes = new int[1001] ;
		int p,numOfDiners,maxPancakesPerDiner;
		long totalAmountOfPancakes = 0;
		maxPancakesPerDiner = 0;
		numOfDiners = initialDNonEmptyPlateDiners;
		
	
		for (int i=0; i<initialDNonEmptyPlateDiners;i++) {
			p = Integer.parseInt(initialPancakesPerPlateStr[i]);
			dinersWithIPancakes[p]+=1;
			totalAmountOfPancakes += p; 
			if (p>maxPancakesPerDiner) {
				maxPancakesPerDiner = p;
			}
		}

		long minimumTime = maxPancakesPerDiner;

		for (int numOfMovs = 1; numOfMovs < minimumTime && maxPancakesPerDiner > 2;numOfMovs +=1) {
			//SpecialMinute
			dinersWithIPancakes[maxPancakesPerDiner]-= 1;
			dinersWithIPancakes[maxPancakesPerDiner/2]+=1;
			dinersWithIPancakes[maxPancakesPerDiner -( maxPancakesPerDiner/2)]+=1;
			numOfDiners +=1;
			//Recalculate maxPancakes
			for (int i = maxPancakesPerDiner; i >= 0 && dinersWithIPancakes[i]==0; i--) {
				maxPancakesPerDiner = i-1;
			}
			if((numOfMovs+maxPancakesPerDiner) < minimumTime) {
				minimumTime = numOfMovs+maxPancakesPerDiner;
			}			
		}
//		while (totalAmountOfPancakes > 0) {
//			if (numOfDiners < (maxPancakesPerDiner -1)) {
//				//Special minute
//			} else {
//				//normalMinute
//				for (int i = 1; i<=maxPancakesPerDiner ;i++){
//					totalAmountOfPancakes -= dinersWithIPancakes [i];
//					if (i==1) {
//						numOfDiners -= dinersWithIPancakes[i];
//					}
//					dinersWithIPancakes [i] = dinersWithIPancakes[i+1];
//				}
//			}
//		}
//		if (totalAmountOfPancakes != 0) {
//			throw new RuntimeException("Error, no 0 al finalizar");
//		}
		return minimumTime;
	}

	
	private static long solveTestCaseBad(int initialDNonEmptyPlateDiners, String []initialPancakesPerPlateStr){
		
		int [] dinersWithIPancakes = new int[1001] ;
		int p,numOfDiners,maxPancakesPerDiner;
		long totalAmountOfPancakes = 0;
		maxPancakesPerDiner = 0;
		numOfDiners = initialDNonEmptyPlateDiners;
		
	
		for (int i=0; i<initialDNonEmptyPlateDiners;i++) {
			p = Integer.parseInt(initialPancakesPerPlateStr[i]);
			dinersWithIPancakes[p]+=1;
			totalAmountOfPancakes += p; 
			if (p>maxPancakesPerDiner) {
				maxPancakesPerDiner = p;
			}
		}
		
		//Empieza a correr el tiempo
		// Normal minute -> numOfDiners pancake eaten
		// Special minute -> (pancakes moved - 1) minutes saved at maximum
		long time = 0;
		while (totalAmountOfPancakes > 0) {
			if (numOfDiners < (maxPancakesPerDiner -1)) {
				//Special minute
				dinersWithIPancakes[maxPancakesPerDiner]-= 1;
				dinersWithIPancakes[maxPancakesPerDiner/2]+=1;
				dinersWithIPancakes[maxPancakesPerDiner -( maxPancakesPerDiner/2)]+=1;
				numOfDiners +=1;
			} else {
				//normalMinute
				for (int i = 1; i<=maxPancakesPerDiner ;i++){
					totalAmountOfPancakes -= dinersWithIPancakes [i];
					if (i==1) {
						numOfDiners -= dinersWithIPancakes[i];
					}
					dinersWithIPancakes [i] = dinersWithIPancakes[i+1];
				}
			}
			//Recalculate maxPancakes
			for (int i = maxPancakesPerDiner; i >= 0 && dinersWithIPancakes[i]==0; i--) {
				maxPancakesPerDiner = i-1;
			}
			time +=1;
		}
		if (totalAmountOfPancakes != 0) {
			throw new RuntimeException("Error, no 0 al finalizar");
		}
		return time;
	}

}
