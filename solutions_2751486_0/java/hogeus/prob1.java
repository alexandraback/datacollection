
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;
import java.math.*;

public class Problem {
	
	boolean containsVowel(String sub) {
		if(sub.length() > limit) {
			sub = sub.substring(sub.length()-limit, sub.length());
		}
		if(sub.contains("a") || 
				sub.contains("e") ||
				sub.contains("i") ||
				sub.contains("o") ||
				sub.contains("u"))
			return true;
		return false;
	}

	int limit = 1000;
	public void doStuff() throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int caseNum = 1;
		br.readLine();
		while(br.ready()) {
			String s = br.readLine();
			String word = s.split(" ")[0];
			limit= Integer.valueOf(s.split(" ")[1]);
			
			int count = 0;
			for(int i=0; (i+limit)<=word.length(); i++) {
				
				for(int j=(i+limit); j<=word.length(); j++) {
					String sub = word.substring(i,j);
					
					if(containsVowel(sub)) {
						int min = 0; 
						for(int k=j-1; k>=i; k--) {
							String sub2 = word.substring(k, j);
							if(containsVowel(sub2))
								break;
							min++;
						}
						if((limit - min) > 1) {
							j = j + (limit-min)-1;
						}
						
					}
					else {
						count += word.length() - j + 1;
						break;
					}
				}
			}
			
			System.out.println("Case #" + caseNum + ": " + count);
			caseNum++;
		}

	}
	public static void main(String [] args) throws Exception{
		Problem A = new Problem();
		A.doStuff();
	}
}
