import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */

	static Scanner in;
	static int n;
	static Game[] game;
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		
		
		in = new Scanner(new File("C:/Users/JiaKY/Desktop/B-small-attempt1.in"));
		//in = new Scanner(System.in);
		System.setOut(new PrintStream("C:/Users/JiaKY/Desktop/B-small-attempt1.out"));
		int testcase = in.nextInt();

		for(int ii=1;ii<=testcase;ii++){
			n = in.nextInt();
			game = new Game[n+1];
			for(int i=1;i<=n;i++){
				game[i] = new Game();
				game[i].one = in.nextInt();
				game[i].two = in.nextInt();
			}
			int done = 0;
			int cost = 0;
			int have = 0;
			while(true){
				boolean flag = false;
				for(int i=1;i<=n;i++){
					Game g = game[i];
					if(!g.secondDone){
						if(have >= g.two){
							cost++;
							done++;
							flag = true;
							g.secondDone = true;
							if(!g.firstDone){
								have += 2;
							}
							else
								have ++;
						}
					}
				}
				
				if (!flag) {
					int max=-1;
					int maxi = 0;
					for (int i=1;i<=n;i++) {
						Game g = game[i];
						if (!g.firstDone && !g.secondDone) {
							if (have >= g.one) {
								flag = true;
								if(max < g.two){
									max = g.two;
									maxi = i;
								}
							}
						}
					}
					if(flag){
						cost++;
						have++;
						game[maxi].firstDone = true;
					}
					else
						break;
				}
				if(!flag || done == n)
					break;
			}
			
			if(done < n)
				System.out.printf("Case #%d: %s\n",ii,"Too Bad");
			else
				System.out.printf("Case #%d: %d\n",ii,cost);
		}
	}

}

class Game{
	public int one;
	public int two;
	boolean firstDone = false;
	boolean secondDone = false;
}