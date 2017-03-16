/*
 * https://code.google.com/codejam/contest/2270488/dashboard#s=p2
 */

package qual.problemc;

import java.util.ArrayList;

public class Solution {
	public int upper = 100000;
	public boolean[] quali = new boolean[upper+1];
	
	public Solution(int upper){
		this.upper = upper;
	}
	
	public Solution() {}
	
	public int getRange(int s, int e){
		int res = 0;
		for(int i = s; i <= e; i++){
			if(quali[i]) res++;
		}
		return res;
	}
	
	public void getResUndThou(){
		int sqt = (int) Math.sqrt(upper);
		quali[1] = true;
		quali[4] = true;
		quali[9] = true;
		for(int i = 4; i <= sqt; i++){
			if(isPanlindrome(i) && isPanlindrome(i * i))
				quali[i*i] = true;
		}
	}
	
	public boolean isPanlindrome(int num){
		if(num <= upper && quali[num]) return true;
		ArrayList<Integer> bits = new ArrayList<Integer>();
		
		while(num > 0){
			bits.add(num % 10);
			num /= 10;
		}
		
		for(int i = 0; i < bits.size() / 2; i++){
			if(bits.get(i) != bits.get(bits.size() - 1 - i)) 
				return false;
		}
		return true;
	}
}
