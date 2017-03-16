import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Minesweeper_Master {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("ms.in"));
		FileWriter fw = new FileWriter(new File("ms.out"));
		
		int t =sc.nextInt();
		for(int i=0; i<t; i++)
		{
			fw.write("Case #"+(i+1)+":\n");
			int R=sc.nextInt(), C=sc.nextInt(), M=sc.nextInt();
			System.out.println("Case #"+(i+1)+": "+R+" "+C+" "+M);
			char[][] brd = new char[R][C];
			int L = R*C-M;
			if(L<=0 || M<0 || (R!=1 && C!=1 && (L==2 || L==3 || L==5 || L==7)) || ((R==2 || C==2) && (L!=1 && L%2==1)))
			{
				fw.write("Impossible\n");
				System.out.println("Impossible");
				continue;
			}
			for(int r=0; r<R; r++)
				for(int c=0; c<C; c++)
					brd[r][c]='.';
			brd[R-1][C-1]='c';
			
			int m=0;
			for(int r=0; r<R-2; r++)
				for(int c=0; c<C-2; c++)
				{
					if(m<M)
					{
						brd[r][c]='*';	
						++m;
					}
				}
			for(int r=0; r<R-3; r++)
			{
				if(m<M)
				{
					if(C>1)
					{
						brd[r][C-2]='*';
						++m;
					}
					brd[r][C-1]='*';
					++m;
				}
			}
			for(int c=0; c<C-3; c++)
			{
				if(m<M)
				{
					if(R>1)
					{
						brd[R-2][c]='*';
						++m;
					}
					brd[R-1][c]='*';
					++m;
				}
			}
			if(m>M)
				brd[R-3][C-3]='.';
			if(m<M && C>2)
			{
				if(R>1)
				{
					brd[R-2][C-3]='*';
					++m;
				}
				brd[R-1][C-3]='*';
				++m;
			}
			if(m<M && R>2)
			{
				if(C>1)
				{
					brd[R-3][C-2]='*';
					++m;
				}
				brd[R-3][C-1]='*';
				++m;
			}
			if(m<M)
			{
				if(R>1 && C>1)
					brd[R-2][C-2]='*';
				if(R>1)
					brd[R-2][C-1]='*';
				if(C>1)
					brd[R-1][C-2]='*';
			}
			
			for(int r=0; r<R; r++)
			{
				for(int c=0; c<C; c++)
					fw.write(brd[r][c]);
				fw.write("\n");
			}
			
			//verify
		}
		fw.flush();
		fw.close();
	}
}
