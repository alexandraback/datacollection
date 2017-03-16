package jam2015.round1c;

import java.awt.List;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	public void solve(Scanner sc, PrintWriter pw) {
		int K, L, S;
		K = sc.nextInt();
		L = sc.nextInt();
		S = sc.nextInt();
		String kStr, lStr;
		char []k = new char [K];
		char []l = new char [L];
		int []kcount = new int [L];
		
		kStr = sc.next();
		lStr = sc.next();
		
//		System.out.println(K + " " + L + " " + S);
//		System.out.println(kStr);
//		System.out.println(lStr);
		
		int overlap = 0;
		double wordp = 1;
		boolean allsame = true;
		
		for(int i = 0; i < L; i++) {
			if(kStr.indexOf(lStr.charAt(i)) == -1) {
				System.out.print("0.0");
				pw.print("0.0");
				return;
			}
			int count = 0;
			for(int j = 0; j < K; j++) {
				if(kStr.charAt(j) == lStr.charAt(i)) {
					count++;
				}
			}
			kcount[i] = count;
			wordp *= count / (double) K;
			if(wordp < 0.000001)
				wordp = 0;
		}
		for(int i = 1; i < L && allsame; i++) {
			if(lStr.charAt(0) != lStr.charAt(i)) {
				allsame = false;
				break;
			}
		}
		
		for(int i = 1; i < L; i++) {
			String end = lStr.substring(L - i, L);
			String head = lStr.substring(0, i);
			if(!end.equalsIgnoreCase(head)) {
				break;
			}
			overlap++;
//			System.out.println(i + " " + head + " " + end);
		}
		
//		if(allsame && L > 1) {
//			overlap = L;
//		}
//		System.out.println(overlap);
		
		int maxB = (S - L) / (L - overlap) + 1;
		
//		System.out.println(maxB);
		
		System.out.print(maxB * (1-wordp));
		pw.print(maxB * (1-wordp));
		
	}

	public static void main(String[] args) throws Exception {
//        Scanner sc = new Scanner(new FileReader("data/sample"));
        Scanner sc = new Scanner(new FileReader("data/B-small-attempt1.in"));
//        Scanner sc = new Scanner(new FileReader("data/A-large.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("data/out"));
        int caseCount = sc.nextInt();
        for(int caseNum = 0; caseNum < caseCount; caseNum++) {
        	pw.print("Case #" + (caseNum + 1) + ": ");
        	System.out.print("Case #" + (caseNum + 1) + ": ");

        	B template = new B();
        	template.solve(sc, pw);
        	
        	System.out.println();
        	pw.println();
        }
        
        pw.flush();
        pw.close();
        sc.close();
	}

}
