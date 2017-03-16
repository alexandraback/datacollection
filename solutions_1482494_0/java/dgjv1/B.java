import java.util.*;
import java.io.*;

public class B{
	
	public static void main(String[] args) throws IOException{
		Scanner inp = new Scanner(new File("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("b-small.out"));
		
		int numCases = inp.nextInt();
		
		for (int cas = 0; cas < numCases; cas++){
			pw.print("Case #" + (cas+1) + ": ");
			
			/* case input */
			
			int N = inp.nextInt();
			Pair[] pairs = new Pair[N];
			int[] a = new int[N];
			int[] b = new int[N];
			
			for (int i = 0; i < N; i++){
				a[i] = inp.nextInt();
				b[i] = inp.nextInt();
				pairs[i] = new Pair(a[i], b[i]);
			}
			
			/* end case input */
			
			for (int i = 0; i < N-1; i++){
				for (int j = i+1; j < N; j++){
					if (pairs[j].less(pairs[i])){
						// swap
						Pair tmp = pairs[i];
						pairs[i] = pairs[j];
						pairs[j] = tmp;
					}
				}
			}
			
			for (int i = 0; i < N; i++){
				System.out.println(pairs[i].a + " " + pairs[i].b);
			}
			
			boolean[] completedB = new boolean[N];
			boolean[] completedA = new boolean[N];
			
			Arrays.fill(completedB, false);
			Arrays.fill(completedA, false);
			
			boolean notSoBad = true;
			int ctr = 0;
			int starsEarned = 0;
			int start = 0;

			System.out.println("===");
			whileloop:
			while (notSoBad){
				int doneB = 0;
				int doneA = 0;
				for (int i = start; i < N; i++){
					if (!completedB[i]){
						if (pairs[i].b <= starsEarned){
							if (completedA[i]){
								starsEarned+=1;
							}
							else{
								starsEarned+=2;
							}
							//starsEarned += 2;
							doneB++;
							ctr++;
							completedB[i] = true;
							start++;
							System.out.println("b done, " + ctr + " " + starsEarned);
						}
					}
				}
				/*
				if (doneThisTime > 0){
					continue whileloop;
				}
				*/
				
				if (checkFinish(completedB)){
					break;
				}
				
				for (int i = N - 1; i >= start; i--){
					if (!completedB[i] && !completedA[i]){
						if (pairs[i].a <= starsEarned){
							starsEarned+=1;
							completedA[i] = true;
							doneA++;
							ctr++;
							System.out.println("a done, " + ctr + " " + starsEarned);
							break;
						}
					}
				}
				
				
				if (doneA == 0){
					notSoBad = false;
					break;
				}
			}
			
			
			/* end main logic */
			
			
			if (notSoBad){
				pw.println(ctr);
			}
			else{
				pw.println("Too Bad");
			}
			
			//pw.println(ans);
		}
		pw.close();
	}
	
	public static boolean checkFinish(boolean b[]){
		//boolean ans = true;
		for (int i = 0; i < b.length; i++){
			if (!b[i]){
				return false;
			}
		}
		return true;
	}
}


class Pair{
	
	int a;
	int b;
	
	public Pair(int x, int y){
		a = x;
		b = y;
	}
	
	public boolean less(Pair another){
		if (this.b < another.b){
			return true;
		}
		else if(this.b == another.b){
			return this.a < another.a;
		}
		else{
			return false;
		}
	}
}
