import java.util.Scanner;



public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		for(int x = 1; x <= t; ++x){
			String str = scanner.next();
			String result = str.charAt(0) + "";
			for(int i = 1; i < str.length(); ++i){
				if(str.charAt(i) >= result.charAt(0))
					result = str.charAt(i) + result;
				else
					result = result + str.charAt(i);
			}
			System.out.println("Case #" + x + ": " + result);
		}
	}
}
