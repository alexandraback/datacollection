package codejam2012_1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class P1 {
	//static File inFile = new File("in1Asmall.txt");
	//static File outFile = new File("out1Asmall.txt");
	static File inFile = new File("inAlarge.txt");
	static File outFile = new File("outAlarge.txt");

	//inQBlarge.txt
	static BufferedReader in;
	static BufferedWriter out;
	static Scanner sc;

	static int T = 0;
	
	
	public static void solve() throws IOException{

		T = sc.nextInt();
		for (int i=0;i<T;i++) {						

			int A = sc.nextInt();
			int B = sc.nextInt();
			
			double[] p = new double[A];
			for (int j=0;j<A;j++) {
				p[j] = sc.nextDouble();
			}
			
			double expmin = Double.MAX_VALUE;
			double exp = 0;
			double prod = 1;
			for (int back=A;back>=0;back--) {
				int ind = A-back;
				if (back==A) {
					exp=B+1+back;
					if (exp<expmin) expmin=exp;
				} else {
					prod*=p[ind-1];
					exp=prod*(back+back+B-A+1) + (1-prod)*(back+back+B-A+1+B+1);
					if (expmin>exp) expmin=exp;
				}
			  
			}
			
			exp = (1+B+1);
			if (exp<expmin) expmin=exp;
			
			//System.out.println(sb.toString());
			out.write("Case #"+(i+1)+": "+expmin+"\n");
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

