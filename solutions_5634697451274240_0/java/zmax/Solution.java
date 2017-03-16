package revengePancakes;

import java.util.*;

public class Solution {

	public static int flipTimes(String s){
	
		int flipTimes = 0;
		boolean startPosition = true;
		//boolean negativeSequence = false;
		int length = s.length();
		
		int index = 0;
		while(index<length){
			char c = s.charAt(index);
			if(c == '-'){
				while(c == '-'){
					index++;
					if(index<length){
						c = s.charAt(index);
					}
					else{
						break;
					}
				}
				if(startPosition){
					flipTimes++;
				}
				else{
					flipTimes += 2;
				}
				startPosition = false;
			}
			else{
				//c == '+'
				index++;
				startPosition = false;
			}
		}
		
		return flipTimes;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			String s = scan.next();
			int flipTimes = Solution.flipTimes(s);
			System.out.printf("Case #%d: %d\n", i, flipTimes);
		}
		scan.close();

	}

}
