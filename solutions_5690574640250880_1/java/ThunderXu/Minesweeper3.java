import java.util.*;


public class Minesweeper3 {
	public void solve()
	{
		Scanner sc = new Scanner(System.in);
		int numTest = sc.nextInt();
		for(int i=0;i<numTest;i++)
		{
			int R = sc.nextInt();
			int C = sc.nextInt();
			int M = sc.nextInt();
			if(M>R*C)
			{
				System.out.printf("Case #%d:\n", i+1);
				System.out.printf("Impossible\n");
				continue;
			}
			ArrayList<Integer> arr = new ArrayList<Integer>(R*C);
			for(int z=0;z<R*C;z++)
			{
				arr.add(0);
			}
			
			boolean hasRes = false;
			for(int z=0;z<R*C;z++)
			{
				ArrayList<Integer> newArr = (ArrayList<Integer>) arr.clone();
				newArr.set(z, 5);
				ArrayList<Integer> res = findResult(newArr, M,R,C);
				if(res!=null)
				{
					hasRes = true;
					
					System.out.printf("Case #%d:\n", i+1);
					for(int o=0;o<R;o++)
					{
						for(int p=0;p<C;p++)
						{
							if(getValue(o,p,res,R,C)==0||getValue(o,p,res,R,C)==6)
							{
								System.out.printf(".");
							}
							else if(getValue(o,p,res,R,C)==1)
							{
								System.out.printf("*");
							}
							else if(getValue(o,p,res,R,C)==5)
							{
								System.out.printf("c");
							}
						}
						System.out.printf("\n");
					}
					break;
				}
				
			}

			if(!hasRes)
			{
				System.out.printf("Case #%d:\n", i+1);
				System.out.printf("Impossible\n");
			}			
		}
		sc.close();
	}
	
	public ArrayList<Integer> findResult(ArrayList<Integer> arr, Integer mineNum, Integer R, Integer C)
	{
		if(CountBlank(arr)==mineNum)
		{
			for(int i=0;i<R*C;i++)
			{
				if(arr.get(i)==0)
				{
					arr.set(i, 1);
				}
			}
			return arr;
		}
		else if(CountBlank(arr)<mineNum)
		{
			return null;
		}
		else
		{
			for(int x=0;x<R;x++)
			{
				for(int y=0;y<C;y++)
				{
					Integer val = getValue(x,y,arr,R,C); 
					if(val==5||val==6)
					{
						ArrayList<Integer> newArr = (ArrayList<Integer>) arr.clone();
						Integer fillCount=0;
						if(y>0)
						{
							if(getValue(x,y-1,newArr,R,C)==0)
							{
								fillCount++;
								fillValue(x,y-1,newArr,R,C,6);
							}
						}
						if(y<C-1)
						{
							if(getValue(x,y+1,newArr,R,C)==0)
							{
								fillCount++;
								fillValue(x,y+1,newArr,R,C,6);
							}
						}
						if(x>0)
						{
							if(getValue(x-1,y,newArr,R,C)==0)
							{
								fillCount++;
								fillValue(x-1,y,newArr,R,C,6);
							}
							if(y>0)
							{
								if(getValue(x-1,y-1,newArr,R,C)==0)
								{
									fillCount++;
									fillValue(x-1,y-1,newArr,R,C,6);
								}
								
							}
							if(y<C-1)
							{
								if(getValue(x-1,y+1,newArr,R,C)==0)
								{
									fillCount++;
									fillValue(x-1,y+1,newArr,R,C,6);
								}
								
							}
						}
						if(x<R-1)
						{
							if(getValue(x+1,y,newArr,R,C)==0)
							{
								fillCount++;
								fillValue(x+1,y,newArr,R,C,6);
							}
							if(y>0)
							{
								if(getValue(x+1,y-1,newArr,R,C)==0)
								{
									fillCount++;
									fillValue(x+1,y-1,newArr,R,C,6);
								}
							}
							if(y<C-1)
							{
								if(getValue(x+1,y+1,newArr,R,C)==0)
								{
									fillCount++;
									fillValue(x+1,y+1,newArr,R,C,6);
								}
							}
						}
						if(fillCount>0)
						{
							ArrayList<Integer> ans = findResult(newArr,mineNum,R,C);
							if(ans!=null)
							{
								return ans;
							}
						}
						
					}
				}
			}
		}
		return null;
	}
	
	private Integer CountBlank(ArrayList<Integer> arr)
	{
		Integer count = 0;
		for(int i=0;i<arr.size();i++)
		{
			if(arr.get(i)==0)
			{
				count++;
			}
		}
		return count;
	}
	
	private Integer getValue(Integer x, Integer y, ArrayList<Integer> arr, Integer R, Integer C)
	{
		if((C*x+y)>=arr.size())
		{
			return null;
		}
		return arr.get(C*x+y);
	}
	
	private void fillValue(Integer x, Integer y, ArrayList<Integer> arr, Integer R, Integer C, Integer value)
	{
		arr.set(C*x+y, value);
		return;
	}
}
