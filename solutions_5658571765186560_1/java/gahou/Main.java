import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
 
class Main
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(new InputStreamReader(System.in));
	 
	public static void main (String[] args) throws java.lang.Exception {
		int T = Integer.parseInt(br.readLine());
		for (int i=0; i<T; i++) {
			solve(i);
		}
	}

	public static void solve(int num) throws IOException{
		StringTokenizer data = new StringTokenizer(br.readLine(), " ");
		int X = Integer.parseInt(data.nextToken());
		int R = Integer.parseInt(data.nextToken());
		int C = Integer.parseInt(data.nextToken());

		if (R * C % X != 0){
			System.out.println("Case #" + (num+1) + ": RICHARD");
			return;
		}
		
		if (X > 6){
			System.out.println("Case #" + (num+1) + ": RICHARD");
		}else if (X < 4){
			if (X == 3 && (R == 1 || C == 1)){
				System.out.println("Case #" + (num+1) + ": RICHARD");
			}else{
				System.out.println("Case #" + (num+1) + ": GABRIEL");
			}
		}else if(X == 4){
			if (R <= 2 || C <= 2){
				System.out.println("Case #" + (num+1) + ": RICHARD");
			}else{
				System.out.println("Case #" + (num+1) + ": GABRIEL");
			}
		}else if(X == 5){
			if (R <= 2 || C <= 2){
				System.out.println("Case #" + (num+1) + ": RICHARD");
			}else if (R == 3 && C == 5 || R == 5 && C == 3){
				System.out.println("Case #" + (num+1) + ": RICHARD");
			}else{
				System.out.println("Case #" + (num+1) + ": GABRIEL");
			}
		}else{
			// X = 6
			if (R <= 3 || C <= 3){
				System.out.println("Case #" + (num+1) + ": RICHARD");
			}else{
				System.out.println("Case #" + (num+1) + ": GABRIEL");
			}
		}

	}
}
