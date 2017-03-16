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

	private static int numberOfFlipping(char[] str, int start, int length) {
		for(int i= length; i>=0; i--){
			if(i == 0 && str[i] == '+')
				return 0;
			if(str[i] == '+')
				continue;
			if(str[i] == '-' && str[0] == '-'){
				swap(str, i);
				return 1 + numberOfFlipping(str,0,i);
			}else if(str[i] == '-' && str[0] == '+'){
				int k = i;
				while(str[k] == '-'){
					k--;
				}
				swap(str, k);
				return 1 + numberOfFlipping(str,0,i);
			}
		}
		return 0;
	}

	private static void swap(char[] str, int i) {
		int k=0, j=i;
		while(j>=k){
			if(str[k] == '+'){
				str[k] = '-';
			}
			else if(str[k] == '-'){
				str[k] = '+';
			}
			if(j!=k){
				if(str[j] == '+'){
					str[j] = '-';
				}
				else if(str[j] == '-'){
					str[j] = '+';
				}
				char temp = str[k];
				str[k] = str[j];
				str[j] = temp;
			}
			k++;
			j--;
		}
	}
}
