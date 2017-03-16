package gcj2015.qual;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

	final boolean DEBUG = false;
	final boolean isSmall = false;
	final String PACKAGE = "gcj2015/qual";
	final String PROBLEM = "A";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int n = sc.nextInt();
			char[] s = sc.next().toCharArray();
			int res = 0;
			int standup = 0;
			for(int i=0;i<s.length;i++){
				int x = s[i]-'0';
				if (0 < x && i > standup) {
					res += Math.max(0, i-standup);
					standup += i - standup;
				}
				standup+=x;
			}
			System.out.println("Case #"+CASE+": "+res);
		}
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
