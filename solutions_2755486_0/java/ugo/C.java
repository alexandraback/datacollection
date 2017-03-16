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

public class C {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/R1C/";
		String READ_FILE = null;
		String WRITE_FILE = null;

				READ_FILE = "csmall.in";
				WRITE_FILE = "csmall.out";
//		READ_FILE = "csmall.in";
//		WRITE_FILE = "csmall.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new C().run();
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
	
	void solve(){
		int n = sc.nextInt();
		HashMap<Integer, Integer> wall = new HashMap<Integer, Integer>();
		int[] ds = new int[n];
		int[] ns = new int[n];
		int[] wis = new int[n];
		int[] eis = new int[n];
		int[] ss = new int[n];
		int[] dds = new int[n];
		int[] dps = new int[n];
		int[] dss = new int[n];
		for(int i = 0 ; i < n ; i++){
			ds[i] = sc.nextInt();
			ns[i] = sc.nextInt();
			wis[i] = sc.nextInt();
			eis[i] = sc.nextInt();
			ss[i] = sc.nextInt();
			dds[i] = sc.nextInt();
			dps[i] = sc.nextInt();
			dss[i] = sc.nextInt();
		}
		
		int total = 0;
		for(int day = 0 ; day < 700 * 1000 ; day++){
			
			HashMap<Integer, Integer> tobe = new HashMap<Integer, Integer>();
			for(int t = 0 ; t < n ; t++){
				if(day >= ds[t] && (day - ds[t]) % dds[t] == 0){
					int times = (day - ds[t]) / dds[t];
					if(times >= ns[t]) continue;
					int w = wis[t] + times * dps[t];
					int e = eis[t] + times * dps[t];
					int str = ss[t] + times * dss[t];
					
					boolean suc = false;
					for(int pos = w ; pos < e ; pos++){
						if(get(wall, pos) < str){
							suc = true;
							if(get(tobe, pos) < str){
								tobe.put(pos, str);
							}
						}
					}
					if(suc){
//						debug(tobe);
//						debug(day, t);
						total++;
					}
				}
					
			}
			
			for(Integer i : tobe.keySet()){
				if(get(wall, i) < get(tobe, i)){
					wall.put(i, get(tobe, i));
				}
			}
			
			
		}
		System.out.println(total);
	}

	public int get(HashMap<Integer, Integer> map, int p){
		return map.get(p) == null ? 0 : map.get(p);
	}
}

/*
 * 
 * 
Input 
 	
Output 
 
2
2
0 3 0 2 10 2 3 -2
10 3 2 3 8 7 2 0
3
1 2 0 5 10 2 8 0
0 3 0 1 7 1 2 2
3 3 0 5 1 1 4 0
Case #1: 5
Case #2: 6


 */
