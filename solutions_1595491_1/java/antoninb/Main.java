package googlers;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	
	public static int calcWIS(int n){
		if(n - 2 < 0)
			return 0;
		return ((n - 2) / 3) + 2;
	}
	
	public static int calcWOS(int n){
		if(n - 1 < 0)
			return 0;
		return ((n - 1) / 3) + 1;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//String fileName = args[0];
		String fileName = "googlers/B-large.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int T = sC.nextInt();
		int N, S, p;
		int[] tab, wiS, woS;
		for(int i = 0; i < T; i++){
			N = sC.nextInt();
			S = sC.nextInt();
			p = sC.nextInt();
			tab = new int[N];
			wiS = new int[N];
			woS = new int[N];
			
			for(int j = 0; j < N; j++){
				tab[j] = sC.nextInt();
				wiS[j] = calcWIS(tab[j]);
				woS[j] = calcWOS(tab[j]);
				//System.out.println(tab[j] + " " + wiS[j] + " " + woS[j]);
			}
			
			int count = 0;
			
			for(int j = 0; j < N; j++){
				if(woS[j] >= p){
					count++;
				}
				if(woS[j] < p && wiS[j] >= p && S > 0){
					count++;
					S--;
				}
			}
			
			System.out.println("Case #" + (i + 1) + ": " + count);
			
		}

	}

}
