package qualifs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Scanner;

public class Treasure {
	
	public static int numPoss = 1 << 20;
	public static boolean[] dp = new boolean[numPoss];
	public static int[] keys_available = new int[201];
	public static LinkedList<Integer> pathF = new LinkedList<Integer>();
	
	public static boolean open(int[] keys_needed, int[][] keys_inside, int path, int N){
		//System.out.println(Integer.toBinaryString(path));
		if(path == (1 << N) - 1) return true;
		for(int i = 0; i < N; i++){
			if((path & (1 << i)) != 0) continue;
			int nPath = path | (1 << i);
			if(dp[nPath] && keys_available[keys_needed[i]] > 0){
				//we can follow this path, we have consumed one key, but maybe earned some more!
				keys_available[keys_needed[i]]--;
				for(int k: keys_inside[i]){
					keys_available[k]++;
				}
				boolean res = open(keys_needed, keys_inside, nPath, N);
				if(res){
					pathF.add(i + 1);
					return true;
				}
				else{
					//we need to clean up
					for(int k: keys_inside[i]){
						keys_available[k]--;
					}
					keys_available[keys_needed[i]]++;
				}
			}
		}
		dp[path] = false;
		return false;
	}
	
	public static void printPath(){
		Integer c = pathF.pollLast();
		if(c == null) System.out.println();
		else{
			System.out.print(" " + c);
			printPath();
		}
		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String fileName = "../D-small-attempt0.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		sC.useLocale(Locale.US);
		
		int T = sC.nextInt();
		int K, N, nK;
		
		for(int t = 0; t < T; t++){
			for(int i = 0; i < numPoss; i++) dp[i] = true;
			for(int i = 0; i < 201; i++) keys_available[i] = 0;
			pathF.clear();
			
			K = sC.nextInt();
			N = sC.nextInt();
			
			for(int i = 0; i < K; i++){
				keys_available[sC.nextInt()] += 1;;
			}
			
			int[] keys_needed = new int[N];
			int[][] keys_inside = new int[N][];
			for(int n = 0; n < N; n++){
				keys_needed[n] = sC.nextInt();
				nK = sC.nextInt();
				keys_inside[n] = new int[nK];
				for(int i = 0; i < nK; i++) keys_inside[n][i] = sC.nextInt();
			}
			
			boolean result = open(keys_needed, keys_inside, 0, N);
			System.out.print("Case #" + (t + 1) + ":");
			if(result)
				printPath();
			else
				System.out.println(" IMPOSSIBLE");
		}

	}

}
