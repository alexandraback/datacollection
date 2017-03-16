package leetcode;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BratBrother {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner=new Scanner(new File("/Users/zhuangli/Downloads/A-small-attempt2.in"));
		int caseNum=scanner.nextInt();
		for (int i = 0; i < caseNum; i++) {
			int R=scanner.nextInt();
			int C=scanner.nextInt();
			int W=scanner.nextInt();
			int amout=(R-1)*(C/W);
			if(C%W==0){
				amout=amout+(C/W+W-1);
			}else{
				amout=amout+(C/W+W);
				
			}
			System.out.println("Case #"+(i+1)+": "+amout);
		}
		scanner.close();
	}
}
