package codejam2012_1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {
	static File inFile = new File("inAsmall.txt");
	static File outFile = new File("outAsmall.txt");
	//static File inFile = new File("inAlarge.txt");
	//static File outFile = new File("outAlarge.txt");

	static BufferedReader in;
	static BufferedWriter out;
	static Scanner sc;

	static int T = 0;
	
	
	public static void solve() throws IOException{
		T = sc.nextInt();
		for (int i=0;i<T;i++) {						
			String res = "";

			out.write("Case #"+(i+1)+": "+res+"\n");
		}
	}
	
	public static void main(String[] args) throws IOException {
		try {
			in = new BufferedReader(new FileReader(inFile));
			out = new BufferedWriter(new FileWriter(outFile));
			sc = new Scanner(in);
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			in.close();
			out.close();		
		}		

	}
}


