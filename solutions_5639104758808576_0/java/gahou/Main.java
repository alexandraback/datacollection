import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
 
class Main
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(new InputStreamReader(System.in));
	 
	public static void main (String[] args) throws java.lang.Exception {
		int T = Integer.parseInt(br.readLine());
		for (int i=0; i<T; i++) {
			solve(i);
		}
	}
 
	public static void solve(int num) throws IOException{
		StringTokenizer data = new StringTokenizer(br.readLine(), " ");
		int L = Integer.parseInt(data.nextToken());
		String str = data.nextToken();
		int length = str.length();
		int total = 0;
		int friend = 0;
		
		for (int i=0; i<length; i++){
			if (i > total){
				friend += i - total;
				total = i;
			}
		total += Integer.parseInt("" + str.charAt(i));
		}

		System.out.println("Case #" + (num+1) + ": " + friend);
	}
}
