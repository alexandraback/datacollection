package gcj2015.qual;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class D {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2015/qual";
	final String PROBLEM = "D";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small-attempt2.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out2.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int X = sc.nextInt(), R = sc.nextInt(), C = sc.nextInt();
			if (C < R){
				int t = C; C = R; R = t;
			}
			boolean exists = true;
			
			if ((R*C)%X != 0) {
				exists = false;
			} else if (C < X) {
				exists = false;
			} else if ((1+R)*2 - 1 <= X) {
				exists = false;
			} else if (3 <= R) {
				if (7 <= X) {
					exists = false;
				} else if (X==6) {
					exists = false;
				}
			} else if (2 == R) {
				if (5 <= X) {
					exists = false;
				} else if (X==4){
					exists = false;
				}
			}
			
			System.out.println("Case #"+CASE+": "+(!exists?"RICHARD":"GABRIEL"));
		}
	}
	
	public static void main(String[] args) {
		new D().run();
	}
}
