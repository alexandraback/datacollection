import java.io.*;
import java.util.*;
import java.math.*;

public class D
{
	public static void main(String[] args) throws Throwable
	{
		Scanner sc = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D-large.out")));
		int t = sc.nextInt();
		
		/*int[][][] om1 = {{{1}}};
		int[][][] om2 = {{{1,1},{0,0}}};
		int[][][] om3 = {{{1,1,1},{0,0,0},{0,0,0}}, {{1,1,0},{1,0,0},{0,0,0}}};
		int[][][] om4 = {{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
						 {{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
						 {{1,1,1,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}},
						 {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
						 {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}};
		int[][][] om5 = {{{1,1,1,1,1},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,1,1,1,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,1,1,1,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,1,1,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,1,1,0,0},{1,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,1,1,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,1,1,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,1,1,0,0},{0,0,1,1,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{0,1,1,0,0},{1,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,0,0,0,0},{1,1,1,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{1,0,0,0,0},{1,1,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0}},
						 {{0,1,0,0,0},{1,1,1,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},};*/
		/*int[][][] om6 = {{{1,1,1,1,1,1},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}}
						};
		
		*/
		for(int caseno = 1; caseno <= t; caseno++)
		{
			int X = sc.nextInt();
			int R = sc.nextInt();
			int C = sc.nextInt();
			
			if(R > C){ // wlog make C >= R
				int temp = R;
				R = C;
				C = temp;
			}
			
			
			if(X == 1){
				out.println("Case #" + caseno + ": GABRIEL");
			}
			else if(X == 2){
				if((R * C) % 2 != 0){
					out.println("Case #" + caseno + ": RICHARD");
				}
				else{
					out.println("Case #" + caseno + ": GABRIEL");
				}
			}
			else if(X == 3){
				if((R * C) % 3 != 0 || R == 1){
					out.println("Case #" + caseno + ": RICHARD");
				}
				else{
					out.println("Case #" + caseno + ": GABRIEL");
				}
			}
			else if(X == 4){
				if((R * C) % 4 != 0 || R <= 2){
					out.println("Case #" + caseno + ": RICHARD");
				}
				else{
					out.println("Case #" + caseno + ": GABRIEL");
				}
			}
			else if(X == 5){
				if((R * C) % 5 != 0 || R <= 2 || (R == 3 && C == 5)){
					out.println("Case #" + caseno + ": RICHARD");
				}
				else{
					out.println("Case #" + caseno + ": GABRIEL");
				}
			}
			else if(X == 6){
				if((R * C) % 6 != 0 || R <= 3){
					out.println("Case #" + caseno + ": RICHARD");
				}
				else{
					out.println("Case #" + caseno + ": GABRIEL");
				}
			}
			else{ // we can make a polyomino with a hole, so Richard wins
				out.println("Case #" + caseno + ": RICHARD");
			}
			
		}
		out.close();
		System.exit(0);
	}
}