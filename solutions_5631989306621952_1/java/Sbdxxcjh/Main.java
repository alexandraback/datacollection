import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(System.in);
		PrintWriter writer = new PrintWriter("output", "UTF-8");
		
		int T = input.nextInt();
		for(int i = 1; i <= T; i++){
			String s = input.next();
			String re = "";
			for(int j = 0; j < s.length(); j++){
				if(j == 0) re = String.valueOf(s.charAt(j));
				else{
					char c = s.charAt(j);
					if(c >= re.charAt(0)){
						re = c + re;
					}else{
						re = re + c;
					}
				}
			}
			writer.println(String.format("Case #%d: %s", i, re));
			
		}
		writer.close();
		input.close();
	}
}
