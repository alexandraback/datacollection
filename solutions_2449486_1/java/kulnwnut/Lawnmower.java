import java.util.Scanner;


public class Lawnmower {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Lawnmower().run();
	}
	
	Scanner sc = new Scanner(System.in);
	int count = 1;
	public void run()
	{
		int n = sc.nextInt();
		sc.nextLine();
		for( count = 1; count <= n; count++){
			solve();
		}
	}
	
	
	int N,M;
	int [][] lawn;
	
	boolean [][] left;
	boolean [][] right;
	boolean [][] up;
	boolean [][] down;
	
	public void solve()
	{
		N = sc.nextInt();
		M = sc.nextInt();
		sc.nextLine();
		
		lawn = new int [N][M];
		left = new boolean [N][M];
		right = new boolean [N][M];
		up = new boolean [N][M];
		down = new boolean [N][M];
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				lawn[i][j] = sc.nextInt();
			sc.nextLine();
		}
		
		checkLeft();
		checkRight();
		checkUp();
		checkDown();
		
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				if( ! (  (left[i][j] && right[i][j]) || (up[i][j] && down[i][j])  ))
				{
					System.out.println("Case #" + count + ": " + "NO");
					return;
				}
			}
		System.out.println("Case #" + count + ": " + "YES");
	}
	private void checkUp()
	{
		for(int j=0;j<M;j++)
		{
			int max = lawn[0][j];
			for(int i=0;i<N;i++)
			{
				if( lawn[i][j] >= max )
				{
					max = lawn[i][j];
					up[i][j] = true;
				}
			}
		}
	}
	private void checkDown()
	{
		for(int j=0;j<M;j++)
		{
			int max = lawn[N-1][j];
			for(int i=N-1;i>=0;i--)
			{
				if( lawn[i][j] >= max )
				{
					max = lawn[i][j];
					down[i][j] = true;
				}
			}
		}
	}
	
	private void checkLeft()
	{
		for(int i=0;i<N;i++){
			int max = lawn[i][0];
			for(int j=0;j<M;j++)
			{
				if( lawn[i][j] >= max )
				{
					max = lawn[i][j];
					left[i][j] = true;
				}
			}
		}
	}
	private void checkRight()
	{
		for(int i=0;i<N;i++){
			int max = lawn[i][M-1];
			for(int j=M-1;j>=0;j--)
			{
				if( lawn[i][j] >= max )
				{
					max = lawn[i][j];
					right[i][j] = true;
				}
			}
		}
	}
}




