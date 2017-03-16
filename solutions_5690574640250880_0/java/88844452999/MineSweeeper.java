package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class MineSweeeper {

	public static void main(String[] args) throws IOException {
		
		
		
		
		// TODO Auto-generated method stub
		File file=new File("C-small-attempt1.in");
        Writer output = null;
        File out=new File("C-small-attempt1.out");
        output = new BufferedWriter(new FileWriter(out));
        BufferedReader fileIn = new BufferedReader(new FileReader(file));
        String fileLine,delims,outs;
        String[] tokens;
        int cases,i,r,c,m;
        
        String ans;
        
       
        fileLine=fileIn.readLine();
        cases = Integer.parseInt(fileLine);
        delims = "[ ]+";
        System.out.println("Cases = "+cases);
        
        for	(i=0;i<cases;++i)
        {
        output.write("Case #");
        output.write(Integer.toString(i+1));
        output.write(": ");
    	fileLine=fileIn.readLine();
    	tokens = fileLine.split(delims);
    	r = Integer.parseInt(tokens[0]);
    	c = Integer.parseInt(tokens[1]);
    	m = Integer.parseInt(tokens[2]);
    	char[][] result = solve2(r,c,m);
    	if(result[0][0]=='i')
    	{
    		ans = "Impossible";
    	}
    	else
    	{
    		ans = maptostring(result);
    	}
    	output.write("\n");
    	output.write(ans);
        output.write("\r\n");
        System.out.println(ans);
        }
        output.close();

	}

	private static String maptostring(char[][] solve2) {
		// TODO Auto-generated method stub
		
		String f = "";
		for(int r = 0;r<solve2.length;++r)
		{
			String s = "";
			for(int c = 0;c<solve2[0].length;++c)
			{
				s = s + solve2[r][c];
			}
			f = f +s + "\n";
			
		}
			
		return f.substring(0, f.length()-1);
	}

	private static String solve(int r, int c, int m) {
		// TODO Auto-generated method stub
		String s = "";
		char[][] map = new char[r][c];
		if(r*c-m==1)
		{
			String row = "";
			for(int i=0;i<c;++i)
			{
				row = row + "*"; 
			}
			s = row;
			for(int i=0;i<r-1;++i)
			{
				s = s + "\n" + row; 
			}
			s =s.substring(0, s.length()-1) + "c";
			
			
		}
		else if(r==1)
		{
			for(int i=0;i<c;++i)
			{
				if(m>0)
				{
					s = s + "*";
					--m;
				}
				else if(i == c-1)
				{
					s = s + "c";
				}
				else
				{
					s = s + ".";
				}
				
			}
						
		}
		else if(c == 1)
		{
			s = "*";
			m = m-1;
			for(int i=0;i<r-1;++i)
			{
				if(m>0)
				{
					s = s + "\n*";
					--m;
				}
				else if(i == r-2)
				{
					s = s + "\nc";
				}
				else
				{
					s = s + "\n.";
				}
				
			}
		}
		else if(r == 2)
		{
			if(m%r==0&&r*c-m>2)
			{
				m = m/r;
				for(int i=0;i<c;++i)
				{
					if(m>0)
					{
						s = s + "*";
						--m;
					}
					else if(i == c-1)
					{
						s = s + "c";
					}
					else
					{
						s = s + ".";
					}
					
				}
				s =s +"\n" + s.substring(0, s.length()-1) + ".";
				
				
			}
			else
			{
				s = "Impossible";
			}
		}
		else if(c == 2&&r*c-m>2)
		{
			if(m%c==0)
			{
				m = m/c;
				for(int i=0;i<r;++i)
				{
					if(m>0)
					{
						s = s + "**\n";
						m = m-1;
					}
					else if(i == r-1)
					{
						s = s + ".c";
					}
					else
					{
						s = s + "..\n";
					}
					
				}
							
				
			}
			else
			{
				s = "Impossible";
			}
		}
		else if(r == 3)
		{
			if(r*c-m<=3)
			{
				s = "Impossible";
			}
			else
			{
				
			}
		}
		
		
		
		return s;
	}

	private static char[][] solve2(int r, int c, int m) {
		// TODO Auto-generated method stub
		
		//System.out.println("solve 2 " + Integer.toString(m)  + "   r and c " + Integer.toString(r) +  "   " + Integer.toString(c));
		
		if(m<0)
		{
			return null;
		}
		
		char[][] map = new char[r][c];
		if(r*c-m==1)
		{
			for(int i=0;i<c;++i)
			{
				for(int j=0;j<r;++j)
				{
					map[j][i]='*'; 
				}
			}
			
			map[0][0]='c';	
			
		}
		else if(m==0)
		{
			for(int i=0;i<c;++i)
			{
				for(int j=0;j<r;++j)
				{
					map[j][i]='.'; 
				}
			}
			
			map[0][0]='c';	
			
		}
		else if(r==1)
		{
			for(int i=0;i<c;++i)
			{
				if(m>0)
				{
					map[0][i] =  '*';
					--m;
				}
				else if(i == c-1)
				{
					map[0][i] = 'c';
				}
				else
				{
					map[0][i] = '.';
				}
				
			}
						
		}
		else if(c == 1)
		{
			char[][] map2 = solve2(c,r,m);
			map = maprotate(map2);
		}
		else if(r == 2)
		{
			if(m%r==0&&r*c-m>2)
			{
				m = m/r;
				for(int i=0;i<c;++i)
				{
					if(m>0)
					{
						map[0][i] = '*';
						map[1][i] = '*';
						--m;
					}
					else if(i == c-1)
					{
						map[0][i] = '.';
						map[1][i] = 'c';
					}
					else
					{
						map[0][i] = '.';
						map[1][i] = '.';
					}
					
				}
				
							
			}
			else
			{
				map[0][0] = 'i';
			}
		}
		else if(c == 2)
		{
			char[][] map2 = solve2(c,r,m);
			map = maprotate(map2);
		}
		else if(r == 3)
		{
			if(r*c-m<=3)
			{
				map[0][0] = 'i';
			}
			else if(r*c-m==4)
			{
				for(int i=0;i<c;++i)
				{
					for(int j=0;j<r;++j)
					{
						map[j][i]='*'; 
					}
				}
				
				map[0][0]='c';
				map[0][1]='.';
				map[1][0]='.';
				map[1][1]='.';
			}
			else if(r*c-m==5)
			{
				map[0][0]='i';
			}
			else if(r*c-m==6)
			{
				for(int i=0;i<c;++i)
				{
					for(int j=0;j<r;++j)
					{
						map[j][i]='*'; 
					}
				}
				
				map[0][0]='.';
				map[1][0]='c';
				map[2][0]='.';
				map[0][1]='.';
				map[1][1]='.';
				map[2][1]='.';
			}
			else if(r*c-m==7)
			{
				map[0][0]='i';
			}
			else if(r*c-m==8)
			{
				for(int i=0;i<c;++i)
				{
					for(int j=0;j<r;++j)
					{
						map[j][i]='*'; 
					}
				}
				
				map[0][0]='.';
				map[1][0]='c';
				map[2][0]='.';
				map[0][1]='.';
				map[1][1]='.';
				map[2][1]='.';
				map[0][2]='.';
				map[1][2]='.';
				
			}
			else if (m==0)
			{
				for(int i=0;i<c;++i)
				{
					for(int j=0;j<r;++j)
					{
						map[j][i]='.'; 
					}
				}
				map[0][0] = 'c';
				
			}
			else if (m==1)
			{
				for(int i=0;i<c;++i)
				{
					for(int j=0;j<r;++j)
					{
						map[j][i]='.'; 
					}
				}
				map[0][0] = 'c';
				map[r-1][c-1] = '*';
				
			}
			else if (m==2)
			{
				for(int i=0;i<c;++i)
				{
					for(int j=0;j<r;++j)
					{
						map[j][i]='.'; 
					}
				}
				map[0][0] = 'c';
				map[r-1][c-1] = '*';
				map[r-1][c-2] = '*';
			}
			else
			{
				int a = m/3;
				if(m%3<0)
				{
					System.out.println(Integer.toString(m) + "  " +Integer.toString(c-a) + "   m%3 " + Integer.toString(m%3));
					return null;
				}
				
				char[][] map2 = solve2(r,c-a,m%3);
				
				for(int i=0;i<c;++i)
				{
					for(int j=0;j<r;++j)
					{
						map[j][i]='*'; 
					}
				}
				for(int i=0;i<map2[0].length;++i)
				{
					for(int j=0;j<map2.length;++j)
					{
						map[j][i]=map2[j][i]; 
					}
				}
								
				
			}
			
			
			
		}
		else if (c==3)
		{
			char[][] map2 = solve2(c,r,m);
			map = maprotate(map2);
		}
		else if(m<r&&m<c)
		{
			for(int i=0;i<c;++i)
			{
				for(int j=0;j<r;++j)
				{
					map[j][i]='.'; 
				}
			}
			map[0][0] = 'c';
			int t = r-1;
			int y = c-1;
			
			while(m>0)
			{
				map[t][y] = '*';
				--m;
				if(t-1>=0&&y+1<=c-1)
				{
					t =t-1;
					y = y+1;
				}
				else
				{
					y = c - (r-t) -1;
					t = r-1;
					 
				}
			}
			
		}
		else 
		{
			int newr = r;
			int newc = c;
			
			while((newr<=m&&newc-1>=3)||(newc<=m&&newr-1>=3))
			{
				if(newr<=m&&newc-1>=3)
				{
					newc = newc-1;
					m = m-newr;
				}
				else
				{
					newr =newr-1;
					m = m-newc;
				}
			}
			
			for(int i=0;i<c;++i)
			{
				for(int j=0;j<r;++j)
				{
					map[j][i]='*'; 
				}
			}
			
			char[][] map2 = solve2(newr,newc,m);
			
			for(int i=0;i<map2[0].length;++i)
			{
				for(int j=0;j<map2.length;++j)
				{
					map[j][i]=map2[j][i]; 
				}
			}
			
			
				
		}
		
		
		
		return map;
	}

	private static char[][] maprotate(char[][] map2) {
		// TODO Auto-generated method stub
		char[][]map = new char[map2[0].length][map2.length];
		for(int r = 0;r<map.length;++r)
		{
			for(int c = 0;c<map[0].length;++c)
			{
				map[r][c] =map2[c][r]; 
			}
			
		}
		return map;
	}

	
}
