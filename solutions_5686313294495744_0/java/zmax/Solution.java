package technobabble;

import java.util.*;

public class Solution {

	public static int fakeNum(ArrayList<String> words1, ArrayList<String> words2){
		HashMap<String, Integer> map1 = new HashMap<String, Integer>();
		HashMap<String, Integer> map2 = new HashMap<String, Integer>();
		
		
		
		int length = words1.size();
		
		String word1 = "";
		String word2 = "";
		for(int i=0;i<length;i++){
			word1 = words1.get(i);
			word2 = words2.get(i);
			if(!map1.containsKey(word1)){
				map1.put(word1, 1);
			}
			else{
				map1.put(word1, map1.get(word1)+1);
			}
			if(!map2.containsKey(word2)){
				map2.put(word2, 1);
			}
			else{
				map2.put(word2, map2.get(word2)+1);
			}
		}
		
		//System.out.println(map1.toString());
		//System.out.println(map2.toString());
		
		HashMap<String, Integer> map11 = new HashMap<String, Integer>(map1);
		HashMap<String, Integer> map22 = new HashMap<String, Integer>(map2);
		
		int fakeNum1 = 0;
		for(int i=0;i<length;i++){
			word1 = words1.get(i);
			word2 = words2.get(i);
			if(map1.get(word1)>1 && map2.get(word2)>1){
				//System.out.println(word1 + " " + word2);
				fakeNum1++;
				map1.put(word1, map1.get(word1)-1);
				map2.put(word2, map2.get(word2)-1);
			}
		}
		
		int fakeNum2 = 0;
		for(int i=0;i<length;i++){
			word1 = words1.get(i);
			word2 = words2.get(i);
			if(map11.get(word1)>1 && map22.get(word2)>1){
				//System.out.println(word1 + " " + word2);
				fakeNum2++;
				map11.put(word1, map11.get(word1)-1);
				map22.put(word2, map22.get(word2)-1);
			}
		}
		
		return Math.max(fakeNum1, fakeNum2);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			int numTopics = scan.nextInt();
			ArrayList<String> words1 = new ArrayList<String>();
			ArrayList<String> words2 = new ArrayList<String>();
			for(int j=0;j<numTopics;j++){
				words1.add(scan.next());
				words2.add(scan.next());
			}
			int fakeNum = Solution.fakeNum(words1, words2);
			System.out.printf("Case #%d: %d\n", i, fakeNum);
		}
		scan.close();
	}

}
