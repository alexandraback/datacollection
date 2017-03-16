package round1A_Problem1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Set;
import java.util.TreeSet;

public class LastWord {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("/Users/alexpeptan/Desktop/Eclipse Workspace/Google Code Jam 2016/src/round1A_Problem1/1A1.in"));
		PrintWriter writer = new PrintWriter("/Users/alexpeptan/Desktop/Eclipse Workspace/Google Code Jam 2016/src/round1A_Problem1/1A1.out", "UTF-8");
		
		long t = Long.valueOf(br.readLine());
		for(int i=0; i<t; i++){
			String s = br.readLine();
			String res = "" + s.charAt(0);
			for(int j=1; j<s.length(); j++){
				if(("" + s.charAt(j) + res).compareTo(res + s.charAt(j)) <= 0){
					res = res + s.charAt(j);
				} else {
					res = "" + s.charAt(j) + res;
				}
			}
			
			writer.println("Case #" + (i+1) + ": " + res);
		}
		writer.close();
	}
}
