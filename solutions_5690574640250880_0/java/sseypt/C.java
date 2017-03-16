package gcj2014.global_qr;

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.BufferedWriter;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

import java.text.NumberFormat;
import java.text.DecimalFormat;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.util.*;

public class C
{
	private static int debugCC = -1;
	
	private static int cc;
	
	private static int R;
	private static int C;
	private static int M;
	
	private static char[][] field;
	private static boolean possible = false;
	
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			possible = false;
			
			R = INT();
			C = INT();
			M = INT();
			
//			println(R+" "+C+" "+M);

			field = new char[R][C]; 
			if ((R==1 || C==1) || (M==0 || M==R*C-1)) possible = true;
			
			if (!possible) possible = solveField(R,C,M); 
				
							println("Case #"+cc+":");
			if (possible) 	printField();
			else			println("Impossible");
		}
	}
	
	public static void generateField() throws IOException
	{
		// 1 row/col case
		if (R==1 || C==1)
		{
			field = new char[Math.max(R, C)][1]; 
			for(int i=0; i<M; i++) 					field[i][0] = '*';
			for(int i=M; i<Math.max(R, C)-1; i++)	field[i][0] = '.';
		}
		// ---end
		// 0 or R*C-1 mines
		else if (M==0 || M==R*C-1)
		{
			for(int x=0; x<C; x++) for(int y=0; y<R; y++) field[y][x] = M==0?'.':'*';
		}
		// ---end
		else
		{
			int yLeft = R;
			int xLeft = C;
			int mLeft = M;
			
			boolean filled = false;
			while(yLeft*xLeft>9 && !filled)
			{
				// specials
				if (yLeft==2 || xLeft==2)
				{
					if (yLeft==2 && mLeft>=yLeft)
					{
						for(int y=R-yLeft; y<R-yLeft+2; y++) field[y][C-xLeft] = '*';
						mLeft-=yLeft; xLeft--;
					}
					else if (xLeft==2 && mLeft>=xLeft)
					{
						for(int x=C-xLeft; x<C-xLeft+2; x++) field[R-yLeft][x] = '*';
						mLeft-=xLeft; yLeft--;
					}
					else
					{
						filled = true;
					}
				}
				// ---end
				else
				{
					if (yLeft>xLeft && mLeft>=xLeft)
					{
						for(int x=C-xLeft; x<C; x++) field[R-yLeft][x] = '*';
						mLeft-=xLeft; yLeft--;
					}
					else if (mLeft>=yLeft)
					{
						for(int y=R-yLeft; y<R; y++) field[y][C-xLeft] = '*';
						mLeft-=yLeft; xLeft--;
					}
					else
					{
						filled = true;
					}
				}
			}
			
			boolean error = false;
			debugln("fill leftovers for "+yLeft+"x"+xLeft+" "+mLeft);
			while (mLeft>0 && !error)
			{
				// specials
				if (yLeft*xLeft==9)
				{
					for(int y=R-yLeft; y<R&&mLeft>0; y++)
					{
						field[y][C-xLeft] = '*';
						mLeft--;
					}
					xLeft--;
					for(int x=C-xLeft; x<C&&mLeft>0; x++)
					{
						field[R-yLeft][x] = '*';
						mLeft--;
					}
					yLeft--;
				}
				if (yLeft*xLeft==8 || yLeft*xLeft==6)
				{
					if (yLeft==2)
					{
						for(int y=R-yLeft; y<R&&mLeft>0; y++)
						{
							field[y][C-xLeft] = '*';
							mLeft--;
						}
						xLeft--;
					}
					if (xLeft==2)
					{
						for(int x=C-xLeft; x<C&&mLeft>0; x++)
						{
							field[R-yLeft][x] = '*';
							mLeft--;
						}
						yLeft--;
					}
				}

				// ---end
				
				if (yLeft>=xLeft && yLeft-2<R)
				{
					for(int y=R-yLeft; y<R-2&&mLeft>0; y++)
					{
						field[y][C-xLeft] = '*';
						mLeft--;
					}
					xLeft--;
				}
				else if (xLeft-2<C)
				{
					for(int x=C-xLeft; x<C-2&&mLeft>0; x++)
					{
						field[R-yLeft][x] = '*';
						mLeft--;
					}
					yLeft--;
				}
				else
				{
					error = true;
				}
				debugln("fill leftovers for "+yLeft+"x"+xLeft+" "+mLeft);
			}
			
			if (error) System.out.println("FILL ERROR!!!!");
			if (error) System.err.println("FILL ERROR!!!!");
		}
	}
	
	public static int[] reduceProblem (int y, int x, int m) throws IOException
	{
		debugln("reduce from "+y+"x"+x+" "+m);
		
		// specials
		if (y==2 && m>=y)
		{
			m-=y;
			x--;
		}
		if (x==2 && m>=x)
		{
			m-=x;
			y--;
		}
		// ---end
		
		if (y>x && m>=x)
		{
			m-=x;
			y--;
		}
		else if (m>=y)
		{
			m-=y;
			x--;
		}
		else
		{
			debugln("cant reduce");
			return new int[] {-1};
		}
		
		debugln("reduce to "+y+"x"+x+" "+m);
		
		return new int[] {y,x,m};
	}
	
	public static boolean solveField(int y, int x, int m) throws IOException
	{
		// shortcuts
		switch (y*x)
		{
			case 4: if (m>0)					return false; break;
			case 6: if (m!=0 && m!=2)			return false; break;
			case 8: if (m==1||m==3||m==5||m==6)	return false; break;
			case 9: if (m==2||m==4||m>=6)		return false; break;
		}
		if ((y==2 || x==2) && (m%2==1)) return false;
		if (y*x<=9) return true;
		//---
		
		int[] yxm = reduceProblem(y, x, m);
		
		if (yxm[0]==-1) return true;
		y = yxm[0]; x = yxm[1]; m = yxm[2];
		
		return solveField(y, x, m);
	}
	
	public static void printField() throws IOException
	{
		generateField();
		
		boolean rotate = field[0].length!=C;
		
		// .
		for(int y=0; y<R; y++)
		{
			for(int x=0; x<C; x++)
			{
				if (rotate) {	if (field[x][y]!='*')	field[x][y] = '.';	}
				else			if (field[y][x]!='*')	field[y][x] = '.';
			}
		}
		
		// c
		field[field.length-1][field[0].length-1] = 'c';
		
		// count * . c
		int cs = 0;
		int cd = 0;
		int cc = 0;
		
		for(int y=0; y<R; y++)
		{
			for(int x=0; x<C; x++)
			{
				if (rotate)
				{
					if (field[x][y]=='*') cs++;
					if (field[x][y]=='.') cd++;
					if (field[x][y]=='c') cc++;
				}
				else
				{
					if (field[y][x]=='*') cs++;
					if (field[y][x]=='.') cd++;
					if (field[y][x]=='c') cc++;
				}
			}
		}
		if (cs!=M || cc!=1 || cs+cd+cc != R*C)
		{
			System.out.println("ERROR!!!!");
			System.err.println("ERROR!!!!");
		}
		// ---end
		
		for(int y=0; y<R; y++)
		{
			for(int x=0; x<C; x++)
			{
				if (rotate)	print(""+field[x][y]);
				else		print(""+field[y][x]);
			}	
			println("");
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 02:29 - 02:44 / 06:35 - 07:19 / 08:00 - 
//		String problemFile = "test";
//		String problemFile = "%s-small-practice";
		
		String problemFile = "%s-small-attempt0";
//		String problemFile = "%s-large";
		
		try
		{
			String problem = new Object(){}.getClass().getEnclosingClass().getSimpleName();
			String folder = "_"+new Object(){}.getClass().getPackage().getName();
			
			init(folder+"/"+String.format(problemFile, problem));
			putput(); 
			done();
		}
		catch (Throwable e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}

	private static File input;
	private static FileReader inputReader;
	private static BufferedReader in;
	private static File output;
	private static FileWriter outputWriter;
	private static BufferedWriter out;
	private static StringTokenizer st;

	private static void init (String fileName) throws IOException
	{
		// input
		input = new File(fileName+".in");
		inputReader = new FileReader(input);
		in = new BufferedReader(inputReader);
		
		// output
		output = new File(fileName+".out");
		outputWriter = new FileWriter(output);
		out = new BufferedWriter(outputWriter);
	}
	
	private static void done ()
	{
		try	{in.close();} catch (Exception e){}
		try	{inputReader.close();} catch (Exception e){}
		try	{out.close();} catch (Exception e){}
		try	{outputWriter.close();} catch (Exception e){}
	}
	
	// in
	private static String LINE() throws IOException
	{
		return in.readLine();
	}
	private static String TOKEN() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
		{
			st = new StringTokenizer(LINE());
		}
		return st.nextToken();
	}
	private static int INT() throws IOException
	{
		return parseInt(TOKEN());
	}
	private static long LONG() throws IOException
	{
		return parseLong(TOKEN());
	}
	private static double DOUBLE() throws IOException
	{
		return parseDouble(TOKEN());
	}
	private static String STRING() throws IOException
	{
		return TOKEN();
	}
	
	// putput
	private static String DOUBLE_STRING(Double d)
	{
		NumberFormat f = NumberFormat.getInstance();
		f.setGroupingUsed(false);
		return f.format(d);
	}
	private static DecimalFormat _DF = new DecimalFormat("0000");
	private static String DF(int i)
	{
		return _DF.format(i);
	}
	
	// out
	private static void print (String str) throws IOException
	{
		out.write(str);
		debug(str,true);
	}
	private static void println (String str) throws IOException
	{
		print(str+"\r\n");
	}
	private static void debug (String str, boolean force) throws IOException
	{
		if (debugCC==0 || cc==debugCC || force)
			System.out.print(str);
	}
	private static void debug (String str) throws IOException
	{
		if (debugCC==0 || cc==debugCC)
			System.out.print(str);
	}
	private static void debugln (String str) throws IOException
	{
		debug(str+"\r\n");
	}
}
