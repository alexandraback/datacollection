package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Scanner;

public class A {

	private String solve(Scanner in) {
		int N = in.nextInt();
		

		System.out.println(N);
		int[][] M = new int[N+1][];
		
//		boolean[] isChild = new boolean[N+1];
		cList = new HashSet[N+1];
		for (int i=1; i<N+1; i++) cList[i] = new HashSet<Integer>();
		
		
		for (int i=1; i<N+1; i++) {
			int noOfParents = in.nextInt();
			M[i] = new int[noOfParents];
			for (int p=0; p<noOfParents; p++) {
				M[i][p] = in.nextInt();
				cList[M[i][p]].add(i);
			}
		}
		
			
/*		for (int i=1; i<N+1; i++) {
			for (Integer cc: cList[i]) {
				System.out.print("cc " + cc + " ");
			}
			System.out.println();
		}
	*/	
		
		//for (int i=1; i<N+1; i++) System.out.println(isParent[i]);
		
		inhList = new HashSet[N+1];
		for (int i=1; i<N+1; i++) inhList[i] = new HashSet<Integer>();
		
		for (int i=1; i<N+1; i++) {
			//if (M[i].length == 0) // no parents
				if (checkFor(i) == null) return "Yes";
		}
		return "No";//sb.toString();
	}
	HashSet<Integer>[] inhList;
	HashSet<Integer>[] cList;
	
	HashSet<Integer> checkFor(int index){
/*		System.out.println(index);
		for (int i=1; i<inhList.length; i++){
			for (Integer aa:inhList[i]) System.out.print(aa);
			System.out.println();
		}*/
		if (inhList[index].size() > 0 || cList[index].size() == 0) return inhList[index];
		
		for (Integer c : cList[index]) {
		//	System.out.println("c: " + c);
			HashSet<Integer> tmp = checkFor(c);
			
			if (tmp == null) return null;
			
			if (inhList[index].contains(c)) return null;
			else inhList[index].add(c);
			for (Integer tt : tmp) {
				if (inhList[index].contains(tt)) return null;
				else inhList[index].add(tt);
			}
		}
		
		
		return inhList[index];
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args)  throws FileNotFoundException{
	    Scanner in = new Scanner(new File("C:\\Users\\User\\Desktop\\dane\\data.in"));//input.txt"));//data.in"));
	    PrintWriter out = new PrintWriter("C:\\Users\\User\\Desktop\\dane\\output");//output.txt");//output");
		
	    in.useLocale(Locale.US);
	    int T = in.nextInt();
	    in.nextLine();
	    System.out.println("T "+T);
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
	}

}
