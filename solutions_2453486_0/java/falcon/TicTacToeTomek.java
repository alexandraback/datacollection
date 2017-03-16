package gcj2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class TicTacToeTomek
{
	private final String xwon="X won";
	private final String owon="O won";
	private final String draw="Draw";
	private final String incomplete="Game has not completed";
	
	private boolean check(String[] inp, char ch)
	{
		for(int i=0;i<4;++i)
		{
			boolean zero=(inp[i].charAt(0)==ch ||inp[i].charAt(0)=='T');
			boolean one=(inp[i].charAt(1)==ch ||inp[i].charAt(1)=='T');
			boolean two=(inp[i].charAt(2)==ch ||inp[i].charAt(2)=='T');
			boolean three=(inp[i].charAt(3)==ch ||inp[i].charAt(3)=='T');
			
			if(zero && one && two && three)
			{
				return true;					
			}			
		}
			
		for(int i=0;i<4; ++i)
		{
			boolean zero=(inp[0].charAt(i)==ch ||inp[0].charAt(i)=='T');
			boolean one=(inp[1].charAt(i)==ch ||inp[1].charAt(i)=='T');
			boolean two=(inp[2].charAt(i)==ch ||inp[2].charAt(i)=='T');
			boolean three=(inp[3].charAt(i)==ch ||inp[3].charAt(i)=='T');
			
			if(zero && one && two && three)
			{
				return true;					
			}			
		}
		
		boolean diag=true;
		for(int i=0;i<4;++i)
		{
			diag&=(inp[i].charAt(i)==ch ||inp[i].charAt(i)=='T');
		}
		if(diag)
			return true;
		
		diag=true;
		for(int r=0,c=3;r<4;++r,--c)
		{
			diag&=(inp[r].charAt(c)==ch ||inp[r].charAt(c)=='T');
		}
		if(diag)
			return true;
		
		return false;
	}
	public String getStatus(String[] inp)
	{
		if(check(inp, 'X'))
			return xwon;
		if(check(inp,'O'))
			return owon;
		
		int numDots=0;
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j)
			{
				if(inp[i].charAt(j)=='.')
					++numDots;
			}
		}
		if(numDots==0)
			return draw;
		return incomplete;
	}

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		TicTacToeTomek obj=new TicTacToeTomek();
		for(int t=1;t<=T;++t)
		{
			String[] inp=new String[4];
			for(int i=0;i<4;++i)
				inp[i]=br.readLine();
			br.readLine();
			String ret=obj.getStatus(inp);
			System.out.println("Case #"+t+": "+ret);
			
		}
		br.close();
	}

}
