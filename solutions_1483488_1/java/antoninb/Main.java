package recycling;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	
	public static int lint(int n){
		if(n == 0)
			return 0;
		return 1 + lint(n / 10);
	}
	
	public static void permut(int[] tab){
		int l = tab.length;
		int temp = tab[l - 1];
		for(int i = l - 1; i > 0; i--){
			tab[i] = tab[i - 1];
		}
		tab[0] = temp;
	}
	
	public static int toInt(int[] tab){
		int res = 0;
		int m = 1;
		for(int i = tab.length - 1; i >= 0; i--){
			res += m * tab[i];
			m *= 10;
		}
		return res;
	}
	
	public static int[] toTab(int n){
		int[] res = new int[lint(n)];
		int temp = n;
		for(int i = res.length - 1; i >= 0; i--){
			res[i] = temp % 10;
			temp /= 10;
		}
		return res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//String fileName = args[0];
		String fileName = "recycling/C-large.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int T = sC.nextInt();
		int A, B, l;
		
		HashSet<Integer> set = new HashSet<Integer>();
		
		for(int i = 0; i < T; i++){
			A = sC.nextInt();
			B = sC.nextInt();
			
			l = lint(A);
			
			int[] tab;
			
			int temp;
			
			int count = 0;
			
			for(int j = A; j < B; j++){
				set.clear();
				tab = toTab(j);
				for(int k = 0; k < l - 1; k++){
					permut(tab);
					temp = toInt(tab);
					//System.out.println(j + " " + temp);
					if(temp > j && temp <= B){
						set.add(temp);
						//System.out.println(j + " " + temp);
					}
				}
				count += set.size();
			}
			
			System.out.println("Case #" + (i + 1) + ": " + count);
		}

	}

}
