import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author Sagar
 *
 */
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args){
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();
		for(int i = 1 ; i <= t; i++){
			String n = in.next();
			char []str = n.toCharArray();
			//char []ans = new char[str.length];
			char first = str[0];
			char last = str[0];
			String ans = "";
			ans += first; 
			for(int j = 1; j < str.length; j++){
				if(str[j] >= first){
					ans = str[j] + ans;
					first = str[j];
				} else {
					ans = ans + str[j];
					last = str[j];
				}
			}
			System.out.println("Case #" + i + ": " + ans);
		}
		in.close();
		
	}

}
