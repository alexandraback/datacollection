package digits;

import java.util.*;

public class Solution {

	public static String getDigits(String s){
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		int length = s.length();
		for(int i=0;i<length;i++){
			char c = s.charAt(i);
			if(!map.containsKey(c)){
				map.put(c, 1);
			}
			else{
				map.put(c, map.get(c)+1);
			}
		}
		
		//System.out.println(map.toString());
		
		HashMap<Integer, Integer> digitMap = new HashMap<Integer, Integer>();
		
		if(map.containsKey('Z') && map.get('Z')>0){
			int numZERO = map.get('Z');
			digitMap.put(0, numZERO);
			map.put('Z', map.get('Z')-numZERO);
			map.put('E', map.get('E')-numZERO);
			map.put('R', map.get('R')-numZERO);
			map.put('O', map.get('O')-numZERO);
			
		}
		
		if(map.containsKey('X') && map.get('X')>0){
			int numSIX = map.get('X');
			digitMap.put(6, numSIX);
			map.put('S', map.get('S')-numSIX);
			map.put('I', map.get('I')-numSIX);
			map.put('X', map.get('X')-numSIX);
			
		}
		
		if(map.containsKey('S') && map.get('S')>0){
			int numSEVEN = map.get('S');
			digitMap.put(7, numSEVEN);
			map.put('S', map.get('S')-numSEVEN);
			map.put('E', map.get('E')-numSEVEN*2);
			map.put('V', map.get('V')-numSEVEN);
			map.put('N', map.get('N')-numSEVEN);
		}
		
		if(map.containsKey('V') && map.get('V')>0){
			int numFIVE = map.get('V');
			digitMap.put(5, numFIVE);
			map.put('F', map.get('F')-numFIVE);
			map.put('I', map.get('I')-numFIVE);
			map.put('E', map.get('E')-numFIVE);
			map.put('V', map.get('V')-numFIVE);
		}
		
		if(map.containsKey('F') && map.get('F')>0){
			int numFOUR = map.get('F');
			digitMap.put(4, numFOUR);
			map.put('F', map.get('F')-numFOUR);
			map.put('O', map.get('O')-numFOUR);
			map.put('U', map.get('U')-numFOUR);
			map.put('R', map.get('R')-numFOUR);
		}
		
		if(map.containsKey('R') && map.get('R')>0){
			int numTHREE = map.get('R');
			digitMap.put(3, numTHREE);
			map.put('T', map.get('T')-numTHREE);
			map.put('H', map.get('H')-numTHREE);
			map.put('R', map.get('R')-numTHREE);
			map.put('E', map.get('E')-numTHREE*2);
		}
		
		if(map.containsKey('H') && map.get('H')>0){
			int numEIGHT = map.get('H');
			digitMap.put(8, numEIGHT);
			map.put('E', map.get('E')-numEIGHT);
			map.put('I', map.get('I')-numEIGHT);
			map.put('G', map.get('G')-numEIGHT);
			map.put('H', map.get('H')-numEIGHT);
			map.put('T', map.get('T')-numEIGHT);
		}
		
		if(map.containsKey('T') && map.get('T')>0){
			int numTWO = map.get('T');
			digitMap.put(2, numTWO);
			map.put('T', map.get('T')-numTWO);
			map.put('W', map.get('W')-numTWO);
			map.put('O', map.get('O')-numTWO);
		}
		
		if(map.containsKey('O') && map.get('O')>0){
			int numONE = map.get('O');
			digitMap.put(1, numONE);
			map.put('O', map.get('O')-numONE);
			map.put('N', map.get('N')-numONE);
			map.put('E', map.get('E')-numONE);
		}
		
		if(map.containsKey('E') && map.get('E')>0){
			int numNINE = map.get('E');
			digitMap.put(9, numNINE);
			map.put('N', map.get('N')-numNINE*2);
			map.put('I', map.get('I')-numNINE);
			map.put('E', map.get('E')-numNINE);
		}
		
		String digits = "";
		
		for(int i=0;i<10;i++){
			if(digitMap.containsKey(i)){
				int times = digitMap.get(i);
				for(int j=0;j<times;j++){
					digits += String.valueOf(i);
				}
			}
		}
		
		return digits;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for(int i=1;i<=testNum;i++){
			String s = scan.next();
			String digits = Solution.getDigits(s);
			System.out.printf("Case #%d: %s\n", i, digits);
		}
		scan.close();
	}

}
