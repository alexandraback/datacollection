package round1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

public class A {
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();sc.nextLine();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			StringBuilder sb = new StringBuilder();
			System.out.println(caseNum);
			
			int N = sc.nextInt();
			Tree[] stock = new Tree[N];
			
			for(int i=0;i<N;i++) {
				int M = sc.nextInt();
				LinkedList<Integer> part = new LinkedList<Integer>();
				for(int j=0;j<M;j++) {
					part.add(sc.nextInt()-1);
				}
				stock[i] = new Tree(part);
			}
			
			for(int i=0;i<N;i++) {
				if(explore(i, stock)) {
					sb.append("Yes");
					break;
				} else {
					for(int j=0;j<N;j++)
						stock[j].vu=false;
				}
			}
			if(sb.length()==0)
				sb.append("No");
			
			
			pw.println("Case #" + caseNum + ": " + sb.toString());
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	static boolean explore(int n, Tree[] stock) {
		LinkedList<Integer> queue = new LinkedList<Integer>();
		for(int i : stock[n].parents)
			queue.add(i);
		while(!queue.isEmpty()) {
			int i =queue.poll();
			if(stock[i].vu)
				return true;
			else {
				stock[i].vu=true;
				for(int j : stock[i].parents)
					queue.add(j);
			}
		}
		return false;
	}
}

class Tree {
	boolean vu = false;
	LinkedList<Integer> parents;
	Tree(LinkedList<Integer> p) {
		this.parents = p;
	}
}
