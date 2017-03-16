package gcj2013.R1A;

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

public class B2 {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/R1A/";
		String READ_FILE = null;
		String WRITE_FILE = null;

//				READ_FILE = "bsmall.in";
//				WRITE_FILE = "bsmall.out";
		READ_FILE = "blarge.in";
		WRITE_FILE = "blarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new B2().run();
	}

	Scanner sc;
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

	int[] jobs;
	long E, R;
	int n;
	void solve(){
		E = sc.nextInt();
		R = sc.nextInt();
		n = sc.nextInt();
		jobs = new int[n];
		for(int i = 0 ; i < n ; i++) jobs[i] = sc.nextInt();
		System.out.println(doit(0, n-1, E, 0));
	}
	long doit(int start, int end, long es, long ef){
//		System.out.println(start + " " + end + " " + es + " " + ef);
		long total = 0;
		long e = es;
		for(int pos = start ; pos <= end ; pos++){
			long usable = Math.max(0, e - ef);
			int maxI = findMaxI(pos, end+1);
			if(maxI == pos){
				total += jobs[pos] * usable;
				e -= usable;
			}else{
				int intMaxI = findMaxI(pos, maxI);
				long newef = (E - ef) - (maxI - intMaxI) * R;
				if(newef < 0) newef = 0;
				total += doit(pos, intMaxI, e, newef);
				e = newef;
				pos = intMaxI;
			}
			e += R;
		}
		return total;
	}
	int findMaxI(int pos, int posE){
		int maxV = jobs[pos];
		int maxI = pos;
		for(int i = pos + 1 ; i < posE ; i++){
			if(jobs[i] > maxV){
				maxV = jobs[i];
				maxI = i;
			}
		}
		return maxI;
	}
	void debug(Object... o){
		System.out.println(deepToString(o));
	}
}

/*
Input 
 	
Output 
 
3
5 2 2
2 1
5 2 2
1 2
3 3 4
4 1 3 5
Case #1: 12
Case #2: 12
Case #3: 39



*/