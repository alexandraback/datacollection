package gcj2013.Pre;

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

public class B {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/Pre/";
		String READ_FILE = null;
		String WRITE_FILE = null;

				READ_FILE = "bsmall.in";
				WRITE_FILE = "bsmall.out";
//		READ_FILE = "blarge.in";
//		WRITE_FILE = "blarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new B().run();
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
	
	int[][] arr;
	int[][] grass;
	void solve(){
		int n = sc.nextInt();
		int m = sc.nextInt();
		arr = new int[n][m];
		grass = new int[n][m];
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				arr[i][j] = sc.nextInt();
		for(int[] aa : grass){
			Arrays.fill(aa, 100);
		}
		int max;
		for(int i = 0 ; i < n ; i++){
			max = 0;
			for(int j = 0 ; j < m ; j++){
				max = max(max, arr[i][j]);
			}
			for(int j = 0 ; j < m ; j++){
				grass[i][j] = min(grass[i][j], max);
			}
		}
		
		for(int j = 0 ; j < m ; j++){
			max = 0;
			for(int i = 0 ; i < n ; i++){
				max = max(max, arr[i][j]);
			}
			for(int i = 0 ; i < n ; i++){
				grass[i][j] = min(grass[i][j], max);
			}
		}
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(arr[i][j] != grass[i][j]){
					System.out.println("NO");
					return;
				}
			}
		}
		System.out.println("YES");

	}
	void debug(Object... o){
		System.out.println(deepToString(o));
	}
}

/*

Input 
 	
Output 
 
3
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
1 3
1 2 1
Case #1: YES
Case #2: NO
Case #3: YES


 *
 */