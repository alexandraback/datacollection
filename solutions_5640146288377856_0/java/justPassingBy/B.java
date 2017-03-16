import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;


public class B {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		B main = new B();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(new File("A-small-attempt1.in"));
		//Scanner scan = new Scanner(System.in);
		int T = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("Asmall.out", "UTF-8");
		for(int cas=1; cas<=T; cas++){			
			String[] s = scan.nextLine().split(" ");
			int R = Integer.parseInt(s[0]);
			int C = Integer.parseInt(s[1]);
			int W = Integer.parseInt(s[2]);
			
			int nBlanks = C/W-1;
			int over = C%W;
			
			int nPerRow = 0;
			if(over==0){
				nPerRow = nBlanks + W;
			}else{
				nPerRow = nBlanks + W + 1;
			}		
			
			int answer = (C/W)*(R-1) + nPerRow;
			writer.println("Case #"+cas+": "+answer);
			System.out.println("Case #"+cas+": "+answer);
				
		}		
		writer.close();
	}
	
	
}
