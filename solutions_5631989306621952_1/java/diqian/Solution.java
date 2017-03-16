

import java.util.*;

public class Solution {
	
	public static String produceAllPossibleString(char[] arr){
		
		LinkedList<String> list = new LinkedList<String>();
		
		list.offer( Character.toString(arr[0]) );
		int i = 1;
		while( i < arr.length){
			int j = 0;
			int size = list.size();
			while(j < size){
				String s = list.poll();
				String s1 = s+arr[i];
				String s2 = arr[i]+s;
				list.add(s1);
				list.add(s2);
				j++;
			}
			i++;
		}
		
		Collections.sort(list);
		return list.getLast();
		
	}
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		char[] arr;
		for(int i = 1; i <= T; i++){
			
			arr = sc.next().toCharArray();
			System.out.println("Case #"+i+": "+ produceAllPossibleString(arr));
			
		}
		
	}
}
