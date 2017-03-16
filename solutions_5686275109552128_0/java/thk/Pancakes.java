import java.util.*;


public class Pancakes {

	public static void main(String args[]){

		try{
			
			//Read inputs
			Scanner s = new Scanner(System.in);
			int T = s.nextInt();//no of test cases
			
			int testCaseNum = 0;
			int[] D = new int[T];
			ArrayList<int[]> P = new ArrayList<int[]>();
			
			while(testCaseNum < T){
				
				int numDiners = s.nextInt();//no of diners with non empty plates
				D[testCaseNum] = numDiners;//
				int[] tempP = new int[numDiners];
				for(int index = 0 ;index < numDiners ;index++){
					tempP[index] = s.nextInt();
				}
				P.add(tempP);
				testCaseNum++;
			}
			testCaseNum = 0;
			
			while(testCaseNum<T){
				System.out.println("Case #"+(testCaseNum+1)+": "+findOptimumTime(D[testCaseNum],P.get(testCaseNum)));
				testCaseNum++;
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}	
	private static int findOptimumTime(int D,int[] P){
		
		int optimumTime = getMaximumCakes(P);//get maximum pan cakes in a plate
		
		if(optimumTime<=2) return optimumTime;
		else{
			int timeIndex = 2;
			
			while(timeIndex < optimumTime){
				optimumTime = getOptimumTime(optimumTime,timeIndex,P);
				timeIndex++;
			}
		
			return optimumTime;
		}
		
	}
	private static int getOptimumTime(int optimumTime,int timeIndex,int[] P){
		
		int sumOfTime = 0;
		for(int index=0;index<P.length;index++){
			sumOfTime+=(P[index] - 1 )/timeIndex;
		}
		if(sumOfTime + timeIndex < optimumTime)
			return sumOfTime + timeIndex; 
		else return optimumTime; 
		
	}
	private static int getMaximumCakes(int[] P){
		int maxPanCakes = 0;
		for(int index=0;index<P.length;index++){
			if(maxPanCakes<P[index])
				maxPanCakes = P[index];
		}
		return maxPanCakes;
	}
	
}

