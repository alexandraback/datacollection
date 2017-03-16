package google;

public class CaseData1 {

	public int[][] data;
	public int[][] loc;
	public boolean[][] hassearch;
	int line = 0;
	int columne = 0;
	public CaseData1(int i,int j)
	{
		line = i;
		columne = j;
		data = new int[i][j];
		loc = new int[i][j];
		hassearch = new boolean[i][j];
		cleanloc();
		for(int x = 0; x < line; x++)
		{
			for(int y=0;y < columne;y++)
			{
				hassearch[x][y] = false;
			}
		}
	}
	public void cleanloc()
	{
		for(int i = 0; i < line; i++)
		{
			for(int j=0;j < columne;j++)
			{
				loc[i][j] = 2;
			}
		}
	}
	public void pushdata(String[] temp)
	{
		
		for(int i = 0; i < line; i++)
		{
			String mystring = temp[i];
			String[] numbers = mystring.split(" ");
			for(int j=0;j < columne;j++)
			{
				data[i][j] = Integer.valueOf(numbers[j]);
			}
		}
	
	}
	public boolean test()
	{

		for(int i = 0; i < line; ++i)
			for(int j = 0; j < columne; j++)
			{
				
				if(!smalltest(i,j))
				{
					return false;
				}
				
			}
//		
//		for(int x = 0; x < line; ++x)
//			for(int y = 0; y < columne; y++)
//			{
//				if(!hassearch[x][y])
//					return false;
//			}
		return true;
	}
	
	public boolean smalltest(int x, int y)
	{
		cleanloc();
		boolean pass = true;
		boolean pass1 = true;
		loc[x][y] = 1;
		for(int i = 0; i < line; ++i)
		{
			if(data[i][y] > data[x][y])
				pass = false;
		}
		
		for(int j = 0; j < columne; j++)
		{
			if(data[x][j] > data[x][y])
				pass1 = false;
		}
//
//		for(int i = 0; i < line; ++i)
//			for(int j = 0; j < columne; j++)
//			{
//				if(loc[i][j] == 0 &&(i==0||i==line-1||j==0||j==columne-1))
//					return true;
//			}
		
		return (pass||pass1);
	}
	public void getmap()
	{
		int x = 0;
		int y = 0;
		boolean hasit = false;
		while(true)
		{
		hasit = false;
		for(int i = 0; i < line; ++i)
			for(int j = 0; j < columne; j++)
			{
				if(loc[i][j] == 1)
				{
					x = i;
					y = j;
					hasit = true;
				}
					
			}
		
		loc[x][y] = 0;
		
		if(!hasit)
			break;
		if(x > 0)
		{
			if(data[x-1][y] <= data[x][y] && loc[x-1][y] == 2)
				loc[x-1][y] = 1;
		}
		if(x < line - 1)
		{
			if(data[x+1][y] <= data[x][y]&& loc[x+1][y] == 2)
				loc[x+1][y] = 1;
		}
		
		if(y > 0)
		{
			if(data[x][y-1] <= data[x][y]&& loc[x][y-1] == 2)
				loc[x][y-1] = 1;
		}
		if(y < columne - 1)
		{
			if(data[x][y+1] <= data[x][y]&& loc[x][y+1] == 2)
				loc[x][y+1] = 1;
		}
		
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
