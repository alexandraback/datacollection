import java.util.ArrayList;
import java.util.Scanner;


public class ProblemB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int numTestCases = sc.nextInt(); // T
		
		for(int i = 0; i < numTestCases; i++){
			runTest(sc, i + 1);
		}
	}
	
	public static void runTest(Scanner sc, int testNum){
		int numLevels = sc.nextInt(); // N
		
		ArrayList<Integer[]> starVals = new ArrayList<Integer[]>();
		
		for(int i = 0; i < numLevels; i++){
			Integer[] vals = new Integer[3];
			
			vals[0] = sc.nextInt();
			vals[1] = sc.nextInt();
			vals[2] = 0; // not taken a star
			
			starVals.add(vals);
		}
		
		int moves = moves(starVals);
		
		if(moves == -1){
			print("Case #" + testNum + ": Too Bad");
		} else {
			print("Case #" + testNum + ": " + moves);
		}
		
		//int[][][] starPerms = genPerms(starVals);
		
		// print("" + starPerms);
	}
	
	public static int moves(ArrayList<Integer[]> starVals){
		int moves = 0;
		
		int currentStars = 0;
		
		while(moves >= 0 && !starVals.isEmpty()){
			boolean found2 = false;
			// 2-pass
			for(int i = 0; i < starVals.size(); i++){
				Integer[] vals = starVals.get(i);
				if(vals[2] == 0 && vals[1] <= currentStars){
					currentStars += 2;
					starVals.remove(i);
					found2 = true;
					moves++;
					break;
				}
			}
			
			if(!found2){
				for(int i = 0; i < starVals.size(); i++){
					Integer[] vals = starVals.get(i);
					if(vals[2] == 1 && vals[1] <= currentStars){
						currentStars += 1;
						starVals.remove(i);
						found2 = true;
						moves++;
						break;
					}
				}
			}
			
			if(!found2){
				for(int i = 0; i < starVals.size(); i++){
					Integer[] vals = starVals.get(i);
					if(vals[2] == 0 && vals[0] <= currentStars){
						currentStars += 1;
						vals[2] = 1;
						//starVals.remove(i);
						//starVals.add(vals);
						found2 = true;
						moves++;
						break;
					}
				}
			}
			
			if(!found2){
				moves = -1;
			}
		}
		
		return moves;
	}
	
	

	public static void print(String str){
		System.out.println(str);
	}
}
