import java.io.*;
import java.util.*;
import java.math.*;

public class C
{
	public static void main(String[] args) throws Throwable
	{
		Scanner sc = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-large.out")));
		int t = sc.nextInt();
		
		int[][] mult = {{0, 1, 2, 3, 4, 5, 6, 7},
						{1, 4, 3, 6, 5, 0, 7, 2},
						{2, 7, 4, 1, 6, 3, 0, 5},
						{3, 2, 5, 4, 7, 6, 1, 0},
						{4, 5, 6, 7, 0, 1, 2, 3},
						{5, 0, 7, 2, 1, 4, 3, 6},
						{6, 3, 0, 5, 2, 7, 4, 1},
						{7, 6, 1, 0, 3, 2, 5, 4}};
		
		for(int caseno = 1; caseno <= t; caseno++)
		{
			// if total product != 1, it's never gonna work
			// if the total product = 1 then it is
			// sufficient to just find and i and a j
			// in the head... the k will then sort out itself.
			// moreover, wlog we can just use the first i
			// that we find.
			//nb we represent 1 -> 0, i -> 1, j -> 2, k -> 3;
			//              -1 -> 4, -i -> 5,-j -> 6, -k -> 7;
			int L = sc.nextInt();
			long X = sc.nextLong();
			String chars = sc.next();
			int[] arr = new int[L];
			for(int i = 0; i < L; i++){
				arr[i] = chars.charAt(i) - 104;
			}
			int prod = 0, totalprod = 0;
			for(int i = 0; i < L; i++){
				prod = mult[prod][arr[i]];
			}
			
			for(int i = 0; i < (X % 4); i++){
				totalprod = mult[totalprod][prod];
			}
			//System.out.println("totalprod: " + totalprod);
			if(totalprod != 4){
				out.println("Case #" + caseno + ": NO");
			}
			else{
				//wlog only neeed to look in 8 copies of L
				int[] suff = new int[(int) (L * Math.min(8, X))];
				for(int i = 0; i < L; i++){
					for(int j = 0; j < Math.min(8, X); j++){
						suff[i + j*L] = arr[i];
					}
				}
				
				boolean foundi = false;
				boolean foundj = false;
				prod = 0;
				for(int i = 0; i < suff.length; i++){
					prod = mult[prod][suff[i]];
					if(!foundi && prod == 1){
						foundi = true;
						prod = 0;
					}
					if(foundi && prod == 2){
						foundj = true;
						break;
					}
				}
				if(foundj){
					out.println("Case #" + caseno + ": YES");
				}
				else{
					out.println("Case #" + caseno + ": NO");
				}
			}
		}
		out.close();
		System.exit(0);
	}
}