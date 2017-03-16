/*
 * https://code.google.com/codejam/contest/2270488/dashboard#s=p2
 */

package qual.problemc;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;

public class Solution {
	public int upper;
	public boolean[] quali;
	public ArrayList<Long> ans;
	
	public Solution(int upper){
		this.upper = upper;
		quali = new boolean[upper+1];
	}
	
	public Solution() {
		this.upper = 100000;
		quali = new boolean[upper+1];
	}
	
	public int getRange(int s, int e){
		int res = 0;
		for(int i = s; i <= e; i++){
			if(quali[i]) res++;
		}
		return res;
	}
	
	public void getResUndThou(){
		long sqt = (long) Math.sqrt(1e14);
		quali[1] = true;
		quali[4] = true;
		quali[9] = true;
		isPanlindrome(sqt * sqt);
		for(long i = 4; i <= sqt; i++){
			if(isPanlindrome(i) && isPanlindrome(i * i)){
				if(i*i <= upper) quali[(int) (i*i)] = true;
				System.out.println(i*i + " " + i);
			}
		}
	}
	
	public boolean isPanlindrome(long num){
		if(num <= upper && quali[(int) num]) return true;
		ArrayList<Long> bits = new ArrayList<Long>();
		
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
	
	public void printAll(){
		for(int i = 0; i <= upper; i++){
			if(quali[i]) System.out.println(i + " " + (int) Math.sqrt(i));
		}
	}
	
	public void readAns(){
		try{
			BufferedReader reader = new BufferedReader(new FileReader(new File("interesting.txt")));
			ans = new ArrayList<Long>();
			String s;
			
			while((s = reader.readLine()) != null){
				String[] strs = s.trim().split(" ");
				ans.add(Long.parseLong(strs[0].trim()));
			}
			reader.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public int getRangeFromAns(long s, long t){
		int total = 0;
		for(int i = 0; i < ans.size(); i++){
			if(ans.get(i) >= s && ans.get(i) <= t)
				total++;
		}
			
		return total;
	}
}


/*
 * for first large test 
1 1
4 2
9 3
121 11
484 22
10201 101
12321 111
14641 121
40804 202
44944 212
1002001 1001
1234321 1111
4008004 2002
100020001 10001
102030201 10101
104060401 10201
121242121 11011
123454321 11111
125686521 11211
400080004 20002
404090404 20102
10000200001 100001
10221412201 101101
12102420121 110011
12345654321 111111
40000800004 200002
1000002000001 1000001
1002003002001 1001001
1004006004001 1002001
1020304030201 1010101
1022325232201 1011101
1024348434201 1012101
1210024200121 1100011
1212225222121 1101011
1214428244121 1102011
1232346432321 1110111
1234567654321 1111111
4000008000004 2000002
4004009004004 2001002
*/

