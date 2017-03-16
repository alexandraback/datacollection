package codejam.q1c2015;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class ProblemA {

    public static void main(String[] args) throws Exception {
		
		Scanner sc = new Scanner(new File("ProblemA.txt.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("ProblemA.txt.out")));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for(int i=0;i<T;i++) {
        
		    int R = sc.nextInt();
		    int C = sc.nextInt();
		    int W = sc.nextInt();
		    int count = W + R * (C /W) - 1;
		    if(C%W != 0 && W > 1) count ++;
		    
		    bw.write("Case #" + (i+1) +": "+ count + "\n");
		}
		bw.close();
        sc.close();
	}
}