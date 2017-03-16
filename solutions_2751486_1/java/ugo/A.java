package gcj2013.R1C;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.deepToString;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.*;

public class A {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/R1C/";
		String READ_FILE = null;
		String WRITE_FILE = null;

//				READ_FILE = "asmall.in";
//				WRITE_FILE = "asmall.out";
		READ_FILE = "alarge.in";
		WRITE_FILE = "alarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new A().run();
	}

	Scanner sc;

	void debug(Object... o){
		System.out.println(deepToString(o));
	}

	
	static void precalc(){}

	void run(){
		sc = new Scanner(System.in);
		int caseCnt = sc.nextInt();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");
			solve();
			System.out.flush();
		}
	}
	
	String s;
	int n;
	void solve(){
		s = sc.next();
		n = sc.nextInt();
		int len = s.length();
		doit();
		
		long total = 0;
		for(int i = 0 ; i < len ; i++){
			int index = -1;
			for(int cand : list){
				if(cand < i){
					continue;
				}else if(cand - i + 1 < n){
					continue;
				}
				
				if(conseq[cand] - conseq[i] == cand - i && conseq[i] > 0) {
					index = i + n - 1;
				}else{
					index = cand - conseq[cand] + n;
				}
				break;
			}
//			debug(i, index);
			
			if(index < 0){
				continue;
			}else {
				total += len - index;
			}
		}
		System.out.println(total);
		
	}

	LinkedList<Integer> list;
	int[] conseq;
	void doit(){
		conseq = new int[s.length()];
		list = new LinkedList<Integer>();
		int seq = 0;
		for(int i = 0 ; i < s.length(); i ++){
			switch (s.charAt(i)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				seq = 0;
				conseq[i] = 0;
				break;
			default:
				seq++;
				conseq[i] = seq;
				break;
			}
		}
//		debug(conseq);
		for(int i = 0 ; i < conseq.length ; i++){
			if(i == conseq.length-1){
				if(conseq[i] >= n){
					list.add(i);
				}
			}else{
				if(conseq[i] > conseq[i+1] && conseq[i] >= n){
					list.add(i);
				}
			}
		}
//		debug(list);
	}
	
}

/*

Input 
 	
Output 
 
4
quartz 3
straight 3
gcj 2
tsetse 2
Case #1: 4
Case #2: 11
Case #3: 3
Case #4: 11


*/