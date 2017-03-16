import java.util.*;

public class codeJam2B
{
	static double[][][] percentage;
	static int	diamonds[][], oX, oY, size;
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		generate();
		for(int caseNo = 1; caseNo <= testCase; caseNo++)
		{
			int num = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			//print(percentage);
			double ans = 0;
			if(Math.abs(x) < size/2 && Math.abs(y) < size/2)
			{
				for(int i = 1; i <= num; i++)
				{
					ans += percentage[oX+x][oY+y][i];
				}
				System.out.printf("Case #%d: %f\n", caseNo, ans);
			}
			else
			{
				System.out.printf("Case #%d: %f\n", caseNo, ans);
			}
		}
	}
	public static void generate()
	{
		size = 40;
		percentage = new double[size][size][21];
		diamonds = new int[size][size];
		oX = size/2;
		oY = size/2;
		diamonds[oX][oY] = 1;
		percentage[size/2][size/2][1] = 1;
		recurse(diamonds, 2, 1, size/2, size-2);
	}
	public static void recurse(int[][] a, int no, double percent, int x, int y)
	{
		if(no > size/2)
			return;
		while(x == size/2 && a[x][y-2] == 0 && y != size/2){y-=2;}
		//print(a);
		if(a[x-1][y-1] == 1 && a[x+1][y-1] == 1)
		{
			//System.out.println("MID");
			percentage[x][y][no] += percent;
			int[][] b = copy(a);
			b[x][y] = 1;
			recurse(b, no+1, percent, size/2, size-2);
		}
		else if(a[x-1][y-1] == 1)
		{
			while(a[x+1][y-1] != 1 && y != size/2){x++; y--;}
			percentage[x][y][no] += percent;
			//System.out.println("RIGHT");
			int[][] b = copy(a);
			b[x][y] = 1;
			recurse(b, no+1, percent, size/2, size-2);
		}
		else if(a[x+1][y-1] == 1)
		{
			while(a[x-1][y-1] != 1 && y != size/2){x--; y--;}
			percentage[x][y][no] += percent;
			//System.out.println("LEFT");
			int[][] b = copy(a);
			b[x][y] = 1;
			recurse(b, no+1, percent, size/2, size-2);
		}
		else
		{
			int[][] b = copy(a);
			//System.out.println("SPLIT");
			recurse(b, no, percent/2, x+1, y-1);
			recurse(b, no, percent/2, x-1, y-1);
		}
	}
	public static int[][] copy(int[][] a)
	{
		int[][] copyOf = new int[size][size];
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				copyOf[i][j] = a[i][j];
			}
		}
		return copyOf;
	}
	public static void print(double[][][] a)
	{
		for(int i = 0; i < 40; i++)
		{
			for(int j = 0; j < 40; j++)
			{
				System.out.print(a[i][j][size/2]+ " ");
			}
			
		System.out.println();
		}
		System.out.println();
	}
}