package prac;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class PartElf {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		File input = new File("src/prac/input.in");
//		File input = new File("src/prac/example.in");
		File output = new File("src/prac/output.in");
    	Scanner sc = new Scanner(input);
    	PrintWriter pw = new PrintWriter(output);
    	int case_count = sc.nextInt();
    	sc.nextLine();
    	for(int i=0; i<case_count; i++){
    		new PartElf().solve(sc, pw, i+1);
    		pw.flush();
    	}
        pw.close();
        sc.close();
	}
	
	void solve(Scanner sc, PrintWriter pw, int caseNo){		
		String str[] = sc.next().split("/");
		double nom = Integer.valueOf(str[0]);
		double denom = Integer.valueOf(str[1]);
		double val = nom/denom;
		int gen = -1;
		for(int i=0; i<41; i++){
			if(val>=Math.pow ( 0.5,i )){
				val -= Math.pow ( 0.5,i );
				if(gen == -1){
					gen = i;
				}
			}
			if(val == 0){
				System.out.println("Case #"+caseNo+": "+gen);
				pw.println("Case #"+caseNo+": "+gen);
				return;
			}
		}
		System.out.println("Case #"+caseNo+": "+"impossible");
		pw.println("Case #"+caseNo+": "+"impossible");
	}
	
}
