import java.util.*;
public class StandingOvation {

	
	public static void main(String args[]){
		try{
			
			Scanner s = new Scanner(System.in);
			int T = Integer.parseInt(s.next());//# of test cases
			String[][] tempInputs = new String[T][2];
			int testCaseNum = 0;
			
			//Read each test case
			while(testCaseNum < T){
				
				tempInputs[testCaseNum][0] = s.next();
				tempInputs[testCaseNum][1] = s.next();
				testCaseNum++;
				
			}
			
			testCaseNum = 0;
			while(testCaseNum < T){
				int Smax = Integer.parseInt(tempInputs[testCaseNum][0]);//max shyness level
				int[] audienceCount = toIntegerArray(tempInputs[testCaseNum][1]);//shyness indexed number of members
				
				System.out.println("Case #"+(testCaseNum+1)+": "+computeY(Smax,audienceCount));
				
				testCaseNum++;
			
			}
			
			
			
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	private static int computeY(int Smax,int[] audienceCount){
		int y = 0;
		
		if(Smax <= 0){
			return y;
		}else{
			int audienceTotalCount = audienceCount[0];
			
			for(int s=1;s<=Smax;s++){
				
				if(audienceTotalCount + y < s){
					y += s - (audienceTotalCount + y);
				}
				audienceTotalCount += audienceCount[s];
			}
			
		}
		
		return y;
	}
	
	private static int[] toIntegerArray(String inputstring){
		int[] outputArr = new int[inputstring.length()];
		for(int index=0;index<inputstring.length();index++){
		
			outputArr[index] = Character.getNumericValue(inputstring.charAt(index));
		}
		return outputArr;
	}
}
