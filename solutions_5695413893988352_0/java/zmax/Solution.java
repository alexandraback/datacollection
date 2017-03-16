package match;

import java.util.*;

public class Solution {

	public static ArrayList<String> getScore(String cScore, String jScore){
	
		int length = cScore.length();
		/*
		boolean[] cIndicator = new boolean[length];
		boolean[] jIndicator = new boolean[length];
		for(int i=0;i<length;i++){
			if(cScore.charAt(i) != '?'){
				cIndicator[i] = true;
			}
			else{
				cIndicator[i] = false;
			}
		}
		*/
		int maxValue = 0;
		for(int i=0;i<length;i++){
			maxValue = maxValue*10+9;
		}
		
		int minDiff = Integer.MAX_VALUE;
		String cTarget = "";
		String jTarget = "";
		
		for(int cValue = 0; cValue<=maxValue;cValue++){
			String cStr = String.valueOf(cValue);
			if(cStr.length()<length){
				int cdiff = length - cStr.length();
				for(int j=0;j<cdiff;j++){
					cStr = "0" + cStr;
				}
			}
			boolean cmatch = true;
			for(int i=0;i<length;i++){
				if(cScore.charAt(i) != '?' && cScore.charAt(i) != cStr.charAt(i)){
					cmatch = false;
					break;
				}
			}
			if(!cmatch){
				continue;
			}
			//cValue is matched
			
			for(int jValue = 0; jValue<=maxValue;jValue++){
				String jStr = String.valueOf(jValue);
				if(jStr.length()<length){
					int jdiff = length - jStr.length();
					for(int j=0;j<jdiff;j++){
						jStr = "0" + jStr;
					}
				}
				boolean jmatch = true;
				for(int i=0;i<length;i++){
					if(jScore.charAt(i) != '?' && jScore.charAt(i) != jStr.charAt(i)){
						jmatch = false;
						break;
					}
				}
				if(!jmatch){
					continue;
				}
				//jValue is matched
				
				int valueDiff = Math.abs(cValue - jValue);
				if(minDiff > valueDiff){
					minDiff = valueDiff;
					cTarget = cStr;
					jTarget = jStr;
				}
				
				
			}
			
		}
		
		ArrayList<String> list = new ArrayList<String>();
		list.add(cTarget);
		list.add(jTarget);
		
		return list;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			String cScore = scan.next();
			String jScore = scan.next();
			ArrayList<String> list = Solution.getScore(cScore, jScore);
			System.out.printf("Case #%d: %s %s\n", i, list.get(0), list.get(1));
		}
		scan.close();
	}

}
