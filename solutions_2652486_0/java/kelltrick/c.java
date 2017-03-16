import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;


public class c {

	public static void main(String[] args) {
		genny();
		Scanner sc = new Scanner(System.in);
		int tn = sc.nextInt();
		int r = sc.nextInt();
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		System.out.printf("Case #1:\n");
		for(int i = 0; i < r; i++){
			int[] set = new int[k];
			for(int j = 0; j < k; j++){
				set[j] = sc.nextInt();;
			}
			int[] ans = getAns(r,n,m,k,set);
			String s = "";
			for(int j = 0; j < ans.length; j++){
				s += ans[j];
			}
			System.out.printf("%s\n",s);
		}
	}

	private static void genny() {
		setD = new int[126][];
		for(int i = 2; i <= 5; i++){
			for(int j = 2; j <= i; j++){
				for(int k = 2; k <= j; k++){
					int ans = i*j*k;
					if(setD[ans] == null)
						setD[ans] = new int[]{i,j,k};
					else
						setD[ans] = new int[]{0};
				}
			}
		}
	}

	static int[][] setD;
	
	private static int[] getAns(int r, int n, int m, int k, int[] set) {
		for(int i = 0; i < k; i++){
			if(setD[set[i]] != null && setD[set[i]].length > 1)
				return setD[set[i]];
		}
		
		boolean has5 = false;
		boolean has4 = false;
		boolean has3 = false;
		boolean has2 = false;
		
		for(int i = 0; i < k; i++){
			if(set[i] % 5 == 0)
				has5 = true;
			if(set[i] % 4 == 0)
				has4 = true;
			if(set[i] % 3 == 0)
				has3 = true;
			if(set[i] % 2 == 0)
				has2 = true;
			//System.out.println(set[i] + " " + has5 + " " + has4 + " " + has3 + " " + has2);
		}
		
		int ct = 0;
		int[] ret = new int[3];

		if(has5)
			ret[ct++] = 5;
		if(has3)
			ret[ct++] = 3;
		if(ct == 2 && has4)
			ret[ct++] = 4;
		if(ct <= 2 && has2)
			ret[ct++] = 2;
		if(ct <= 2 && has4)
			ret[ct++] = 4;
		
		
		Random rand = new Random();
		for(int i = ct; i < ret.length; i++){
			ret[i] = rand.nextInt(4) + 2;
		}
		return ret;
	}

}
