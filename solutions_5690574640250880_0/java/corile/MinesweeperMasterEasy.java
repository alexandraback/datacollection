import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;


public class MinesweeperMasterEasy {

	/**
	 * @param args
	 */
	static int t, r, c, m;  
	static int ans = 0;  
	static int num = 0;  
	static int flag[] = new int[105]; 
	static int vis[] = new int[105];
	static int dir[][] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};  
	
	private static class Pair{
		int first;
		int second;
		
		Pair(int x, int y)
		{
			this.first = x;
			this.second = y;
		}
	}
	
	public static void main(String[] args) {
		//Open The file
				BufferedReader br=null;
				try {
					br = new BufferedReader(new FileReader("C-small-attempt0.in"));
					//br = new BufferedReader(new InputStreamReader(System.in));
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				//FileWriter fstream = new FileWriter("out.txt");
				//BufferedWriter out = new BufferedWriter(fstream);
				
				//Get the test case number
				int casenum = readLineAsInt(br);
				
				//Process each case
				for(int j = 1; j <= casenum; j++)
				{
					//Read the selected row
					String[] s = new String[3];
					try {
						s = br.readLine().split(" ");
					} catch (IOException e) {
						e.printStackTrace();
					}
					
					//Parse the selected row into numbers
					r = Integer.parseInt(s[0]);
					c = Integer.parseInt(s[1]);
					m = Integer.parseInt(s[2]);
					num = j;
					Solve();
					//System.out.printf("Case #%d: %.7f\n",j,minTime);
										
					//System.out.println("Case #"+(j+1)+": "+getProbability(numDiamonds, x, y));
				}
				try {
					br.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

	}

	public static int readLineAsInt(BufferedReader br)
	{
		int val = 0;
		try {
			val = Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			return val;
		}
	}
	
	public static void printStringArray(String[] s)
	{
		for(String str:s)
		{
			System.out.print(str+", ");
		}
		System.out.println("");
	}
	
	public static void Solve()  
	{  
	    for(int i=0;i<flag.length;i++)
	    	flag[i]=0;
	    
	    if(dfs() == 0)  
	    {  
	        System.out.printf("Case #%d:\nImpossible\n",num);  
	    }  
	}  
	
	public static int dfs()  
	{  
	    int comb = (1 << m) - 1;  
	    for(int i=0;i<flag.length;i++)
	    	flag[i]=0;
	    int i = 1;  
	    int j = 0;  
	    while(true)  
	    {  
	        if((i & comb)!=0)  
	        {  
	            flag[j] = 1;  
	        }  
	        ++j;  
	        i*=2;  
	        if(j >= r*c) break;  
	    }  
	  
	    int res = r * c - m;  
	  
	    for(int x = 0; x < r; ++x)  
	    {  
	        for(int y = 0; y < c; ++y)  
	        {  
	            if(flag[x*c+y] == 0)  
	            {  
	                ans = 0;  
	                for(int ii=0;ii<vis.length;ii++)
	        	    	vis[ii]=0;
	                bfs(x, y);  
	                if(ans == res)  
	                {  
	                    System.out.printf("Case #%d:\n",num);  
	                    for(int l = 0; l < r; ++l)  
	                    {  
	                        for(int g = 0; g < c; ++g)  
	                        {  
	                            if(l == x && g == y) System.out.print("c");  
	                            else if(flag[l*c+g] == 1) System.out.print("*");  
	                            else System.out.print(".");  
	                        }  
	                        System.out.println();  
	                    }  
	                    return 1;  
	                }  
	            }  
	        }  
	    }  
	  
	    while(comb < 1 << r*c)  
	    {  
	        int p1 = comb & -comb, p2 = comb + p1;  
	        comb = ((comb & ~p2) / p1 >> 1) | p2;  
	  
	        for(int ii=0;ii<flag.length;ii++)
		    	flag[ii]=0; 
	        int i1 = 1;  
	        int j1 = 0;  
	        int ans1 = 0;  
	        while(true)  
	        {  
	            if((i1 & comb)!=0)  
	            {  
	                flag[j1] = 1;  
	                ++ans1;  
	            }  
	            ++j1;  
	            i1*=2;  
	            if(j1 >= r*c) break;  
	        }  
	  
	        for(int x = 0; x < r; ++x)  
	        {  
	            for(int y = 0; y < c; ++y)  
	            {  
	                if(flag[x*c+y] == 0)  
	                {  
	                    ans = 0;  
	                    for(int ii=0;ii<vis.length;ii++)
		        	    	vis[ii]=0;  
	                    bfs(x, y);  
	                    if(ans == res)  
	                    {  
	                        System.out.printf("Case #%d:\n",num);  
	                        for(int l = 0; l < r; ++l)  
	                        {  
	                            for(int g = 0; g < c; ++g)  
	                            {  
	                                if(l == x && g == y) System.out.print("c");  
	                                else if(flag[l*c+g] == 1) System.out.print("*");  
	                                else System.out.print(".");  
	                            }  
	                            System.out.println();
	                        }  
	                        return 1;  
	                    }  
	                }  
	            }  
	        }  
	    }  
	    return 0;  
	}  

	public static void bfs(int x, int y)  
	{  
	    Queue<Pair> que = new LinkedList<Pair>();  
	  
	    que.add(new Pair(x, y));  
	    vis[x*c+y] = 1;  
	    ans = 1;  
	  
	    while(que.size()>0)  
	    {  
	        Pair p = que.poll();  
	        
	        int mark = 1;  
	        for(int i = 0; i < 8; ++i)  
	        {  
	            int nx = p.first + dir[i][0], ny = p.second + dir[i][1];  
	            if(nx >= 0 && nx < r && ny >= 0 && ny < c)  
	            {  
	                if(flag[nx*c+ny] == 1) mark = 0;  
	            }  
	        }  
	        if(mark!=0)  
	        {  
	            for(int i = 0; i < 8; ++i)  
	            {  
	                int nx = p.first + dir[i][0], ny = p.second + dir[i][1];  
	                if(nx >= 0 && nx < r && ny >= 0 && ny < c && vis[nx*c+ny] == 0)  
	                {  
	                    vis[nx*c+ny] = 1;  
	                    ans++;  
	                    que.add(new Pair(nx, ny));  
	                }  
	            }  
	        }  
	    }  
	}  
}
