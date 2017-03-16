package round1c.pa;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class Solution {
	public static void main(String[] args) {
		try{
			BufferedReader reader = new BufferedReader(new FileReader(new File("in.txt")));
			PrintWriter writer = new PrintWriter(new File("out.txt"));
			String s = reader.readLine();
			int total = Integer.parseInt(s.trim());
		
			vow.add('a');
			vow.add('e');
			vow.add('i');
			vow.add('o');
			vow.add('u');

			for(int i = 0; i < total; i++){
				String str = reader.readLine();
				String[] strs = str.split(" ");
				int res = cal('a' + strs[0] + 'a', Integer.parseInt(strs[1].trim()));
//				System.out.println("Case #" + (i+1) + ": " + res);
				writer.println("Case #" + (i+1) + ": " + res);
			}
			
			writer.close();
		} catch(Exception e){
			e.printStackTrace();
		}
	}
	
	private static Set<Character> vow = new HashSet<Character>();
	
	// a e i o u
	public static int cal(String s, int l){
		int preVow = 0, ans = 0, base = 0;
		boolean found = false;
		for(int i = 1; i < s.length(); i++){
			char ch = s.charAt(i);

			if(vow.contains(ch)){
				int temp = i - preVow - l;
				if(temp > 0) {
					found = true;
					base = preVow + temp;
					ans += base;
				}
				preVow = i;
			}
			if(found && i != s.length() - 1 && i - preVow < l) ans += base; 
			if(!found && preVow == 0 && i > l) ans += 1;
		}
		
		int tempAns = 0;
		for(int i = 1; i < s.length(); i++)
			for(int j = i + 1; j < s.length(); j++){
				String str = s.substring(i, j);
				int temp = 0;
				for(int t = 0; t < str.length(); t++){
					if(vow.contains(str.charAt(t))){
						temp = 0;
					} else {
						temp ++;
						if(temp >= l){
							tempAns++;
							break;
						}
					}
				}
			}
		
		if(tempAns != ans){
			System.out.println(s + ":" + l + ":" + ans + ":" + tempAns);
		}
		return tempAns;
	}
}
