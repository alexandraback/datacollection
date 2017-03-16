import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {

	public static void main(String[] args) throws IOException {
		
		BufferedReader input = new BufferedReader(new FileReader("C:\\Users\\Wenjuan\\Desktop\\B.txt"));
		PrintWriter output = new PrintWriter(new FileWriter("C:\\Users\\Wenjuan\\Desktop\\answer.txt"));
		
		int T = Integer.parseInt(input.readLine());
		
		for (int t = 1; t <= T; t++) {
			System.out.println(t);
			String[] nextLine = input.readLine().split(" ");
			
			int min = Integer.MAX_VALUE;
			String c = "";
			String j = "";
			
			for (int C = 0; C <= 999; C++) {
				
				for (int J = 0; J <= 999; J++) {
					
					if (isMatch(nextLine[0], C) && isMatch(nextLine[1], J)) {
						
						if (Math.abs(J - C) < min) {
							
							String cc = String.valueOf(C);
							
							while (cc.length() < nextLine[0].length()) {
								
								cc = "0" + cc;
								
							}
							
							c = cc;
							
							String jj = String.valueOf(J);
							
							while (jj.length() < nextLine[1].length()) {
								
								jj = "0" + jj;
								
							}
							
							j = jj;
							min = Math.abs(J - C);
							
						}
						
					}
					
				}
				
			}
			
			output.println("Case #" + t + ": " + c + " " + j);
			
		}
		
		input.close();
		output.close();
		
	}
	
	public static boolean isMatch(String expression, int number) {
		
		String num = String.valueOf(number);
		
		while (num.length() < expression.length()) {
			
			num = "0" + num;
			
		}
		
		if (num.length() > expression.length()) {
			
			return false;
			
		}else{
			
			for (int i = 0; i < num.length(); i++) {
				
				if (expression.substring(i, i + 1).equals("?") || expression.substring(i, i + 1).equals(num.substring(i, i + 1))) {					
					
				}else{
					
					return false;
					
				}
				
			}
			
		}
		
		return true;
		
	}
	
}