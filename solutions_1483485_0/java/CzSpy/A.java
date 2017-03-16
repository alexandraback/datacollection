package codejam20120413;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class A {
	
	void run()throws IOException{
		BufferedReader bf = new BufferedReader(new FileReader("A.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A.out"));
		
		String key = "yhesocvxduiglbkrztnwjpfmaq";
		
		int cases = Integer.parseInt(bf.readLine());
		for (int i=0; i<cases; i++) {
			String[] s = bf.readLine().split(" ");
			pw.write("Case #"+ (i+1) + ":");
			for(int j=0; j<s.length; j++) {
				String out="";
				for (int k=0; k<s[j].length(); k++) {
					out+=key.charAt(s[j].charAt(k)-'a');
					
				}
				pw.write(" " + out);
			}
			pw.write("\n");
			
		}
		pw.close();
	}
		
	public static void main(String[] args)throws IOException {
		new A().run();
	}
	
	
}
