package gcj2015.qual;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {

	final boolean DEBUG = false;
	final boolean isSmall = false;
	final String PACKAGE = "gcj2015/qual";
	final String PROBLEM = "B";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small-attempt1.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out1.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i=0;i<n;i++) a[i]=sc.nextInt();
			int L = 0, R = 1024;
			while(R-L>1){
				int m = (L+R)/2;
				if (check(m, a)) R = m;
				else L=m;
			}
			System.out.println("Case #"+CASE+": "+R);
//			for(int t=1;t<=1024;t++)if(check(t, a)){
//				System.out.println("Case #"+CASE+": "+t);
//				break;
//			}
		}
	}
	
	boolean check(int turn, int[] a){
		for(int i=0;i<turn;i++)if(check2(turn, i, a))return true;
		return false;
	}
	
	boolean check2(int turn, int stop, int[] a){
		PriorityQueue<Integer> q = new PriorityQueue<Integer>(a.length, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return o2 - o1;
			}
		});
		int d = turn-stop;
		for(int i=0;i<a.length;i++)if(d < a[i])q.add(a[i]);
		while(0 < stop){
			if (q.isEmpty()) return true;
			int x = q.poll();
			if (d < x-d) q.add(x-d);
			stop--;
		}
		return q.isEmpty();
		
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
