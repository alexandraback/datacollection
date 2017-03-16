import java.util.Scanner;


public class TTT {

	public static int probe(char[][] mat, int sx, int sy, int dx, int dy)	{
		int[] count = new int[256];
		int total = 0;
		for(int i = sx, j = sy; i < 4 && j < 4 && i >= 0 && j >= 0; i+=dx, j+=dy)	{
				count[mat[i][j]]++;
				total++;
			}
		if(count['.'] != 0)
			return 3;
		if(total!=4)
			return 2;
		if(count['X'] == 0)
			return 1;
		if(count['O'] == 0)
			return 0;
		return 2;
	}
	public static void main(String[] args) {
		Scanner c = new Scanner(System.in);
		int t = c.nextInt();
		for(int i = 1; i <= t; ++i)	{
			System.out.print("Case #"+i+": ");
			char mat[][] = new char[4][4];
			for(int j = 0; j < 4; ++j)
				mat[j] = c.next().toCharArray();
			int count[] = new int[4];
			big:
				for(int j = 0; j < 4; ++j)
					for(int k = 0; k < 4; ++k)
					{
						count[probe(mat,j,k,0,1)]++;
						count[probe(mat,j,k,1,0)]++;
						count[probe(mat,j,k,1,1)]++;
						count[probe(mat,j,k,1,-1)]++;
					}
			if(count[0] > 0)
				System.out.println("X won");
			else if(count[1] > 0)
				System.out.println("O won");
			else if(count[3] > 0)
				System.out.println("Game has not completed");
			else
				System.out.println("Draw");				
			
		}

	}

}
