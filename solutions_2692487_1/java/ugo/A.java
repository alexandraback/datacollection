package gcj2013.R1B;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.deepToString;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/R1B/";
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

	int A, n;
	int[] arr;
	void solve(){
		A = sc.nextInt();
		n = sc.nextInt();
		arr = new int[n];
		for(int i = 0 ; i < n ; i++){
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
	
		int cur = A;
		int min = 10000;
		int ret = 0;
		for(int i = 0 ; i < n ; i++){
			if(arr[i] < cur){
				cur += arr[i]; continue;
			}
			if(cur == 1){
				ret++;
				continue;
			}
//			debug(cnt, n-i);
			min = Math.min(min, ret + n - i);

			int tmp = cur;
			int cnt = 0;
			while(arr[i] >= tmp){
				tmp = tmp + tmp - 1;
				cnt++;
			}
			
			ret += cnt;
			cur = tmp + arr[i];

//			debug("fail", tmp, cur);
		}
		min = Math.min(min, ret);
		System.out.println(min);
//		System.out.println(doit(A, 0));
	}
	
	int doit(int cur, int pos) {
		if(pos == n){
			return 0;
		}
		int tmp = doit(cur, pos + 1) + 1;
		if(arr[pos] < cur) {
			cur += arr[pos];
			tmp = min(tmp, doit(cur + arr[pos], pos+1));
		} else {
			int cnt = 0;
			while(arr[pos] >= cur) {
				cur = cur + cur - 1;
				cnt++;
			}
			tmp = min(tmp, doit(cur + arr[pos], pos+1) + cnt);
			
		}
		return tmp;
	}

	void debug(Object... o){
		System.out.println(deepToString(o));
	}
}

/*


Input 
 	
Output 
 
4
2 2
2 1
2 4
2 1 1 6
10 4
25 20 9 100
1 4
1 1 1 1
Case #1: 0
Case #2: 1
Case #3: 2
Case #4: 4

*/