import java.util.*;
public class a {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.print("Case #"+(t+1)+": ");
		char[][] data = new char[4][4];
		boolean full = true, xrow = false, orow = false, xdiag = true, xdiag2 = true, odiag = true, odiag2 = true;
		boolean[] xcol = new boolean[4], ocol = new boolean[4];
		Arrays.fill(xcol, true);
		Arrays.fill(ocol,true);
		for(int i = 0; i<4; i++) 
		{
			int xcount = 0, ocount = 0;
			String s =input.next();
			for(int j = 0; j<4; j++) 
			{
				data[i][j] = s.charAt(j);
				if(data[i][j] == 'X') xcount++;
				else if(data[i][j] == 'O') ocount++;
				else if(data[i][j] == 'T') {xcount++; ocount++;}
				xcol[j] &= data[i][j] == 'X' || data[i][j] == 'T';
				ocol[j] &= data[i][j] == 'O' || data[i][j] == 'T';
			}
			full &= s.indexOf('.') == -1;
			xdiag &= s.charAt(i) == 'X' || s.charAt(i) == 'T';
			odiag &= s.charAt(i) == 'O' || s.charAt(i) == 'T';
			xdiag2 &= s.charAt(3-i) == 'X' || s.charAt(3-i) == 'T';
			odiag2 &= s.charAt(3-i) == 'O' || s.charAt(3-i) == 'T';
			orow |= ocount == 4;
			xrow |= xcount == 4;
		}
		boolean xwon = xrow || xdiag || xdiag2;
		boolean owon = orow || odiag || odiag2;
		for(int i = 0; i<4; i++)
		{
			xwon |= xcol[i];
			owon |= ocol[i];
		}
		if(xwon && owon) System.out.println("Draw");
		else if(xwon) System.out.println("X won");
		else if(owon) System.out.println("O won");
		else if(!full) System.out.println("Game has not completed");
		else System.out.println("Draw");
	}
}
}
