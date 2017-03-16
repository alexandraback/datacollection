import java.awt.Image;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.swing.text.html.MinimalHTMLWriter;


public class Q1 {

	public static void main(String[] args) {
		try {
			String input="d:\\A-small-attempt0.in";
		    String output="d:\\output.out";
		    
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);
            
            int n = sc.nextInt();
            sc.nextLine();
            for (int c=0; c<n; c++) {
                pw.print("Case #" + (c+1) + ": ");
                test(sc, pw);
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            
        }

	}

	
	private static void test(Scanner sc, PrintWriter pw) {
		
		String x = sc.nextLine();
		if(x.isEmpty())
			pw.println(x);
		
		char start = x.charAt(0);
		StringBuilder sb = new StringBuilder();
		sb.append(start);
		for(int i = 1;i<x.length();i++){
			char c = x.charAt(i);
			if(c < start){
				sb.append(c);
			} else {
				start = c;
				sb.insert(0,c);
			}
		}
		pw.println(sb.toString());
		
			
			
			
		
		
	}
	

}
