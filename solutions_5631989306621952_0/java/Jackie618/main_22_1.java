import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;


public class main_22_1 {
	public String lastword(String str){
		if(str == null || str.length() == 0){
			return "";
		}
		
		String ans = new String();
		for(int i = 0; i < str.length(); i++){
			char c = str.charAt(i);
			if(i == 0){
				ans = ans + c;
			} else {
				if(c >= ans.charAt(0)){
					ans = c + ans;
				} else {
					ans = ans + c;
				}
			}
		}
		
		return ans;
	}
	
	public static void main(String[] args) {
		main_22_1 m = new main_22_1();
//		System.out.println(m.lastword("ABAAB"));
		
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt(); // Scanner has functions to read ints, longs,
								// strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			String n = in.next();
			System.out.println("Case #" + i + ": " + m.lastword(n));
		}
	}
}
