package round12016;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class A {
	
	static String trans(String s){
		String res=""+s.charAt(0);
		for(int i=1;i<s.length();i++){
			if(s.charAt(i)>=res.charAt(0))
				res = s.charAt(i)+res;
			else
				res = res+s.charAt(i);
		}
		return res;
	}
	
	public static void main(String[] args) throws Exception {
//		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
//        PrintWriter pw = new PrintWriter(new File("A-small.out"));
        BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter pw = new PrintWriter(new File("A-large.out"));
        int T = Integer.parseInt(br.readLine());
        for(int i=1;i<=T;i++){
        	String s = br.readLine();
        	pw.println("Case #"+i+": "+trans(s));
        }
        pw.close();
        br.close();
	}
}
