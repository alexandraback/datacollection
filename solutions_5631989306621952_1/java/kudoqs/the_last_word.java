//revenge_of_the_pancakes
import java.util.*;
import java.io.*;
public class the_last_word {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int num = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
		
		for (int i = 1 ; i<= num; i++){
			String cur = in.next();
			
			String rst = "";
			rst += cur.charAt(0);
			char pre = cur.charAt(0);
			for (int j=1; j<cur.length(); j++){
				if (cur.charAt(j)>=pre){
					pre = cur.charAt(j);
					rst = cur.charAt(j)+rst;
				}
				else {
					rst = rst + cur.charAt(j);
				}
			}
			System.out.println("Case #" + i + ": " + rst);		
		}
	}
}