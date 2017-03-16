import java.util.ArrayList;
import java.util.Scanner;


public class D {

	private static ArrayList<boolean[][]> agons;
	private static boolean[][] fields;
	private static int num;
	private static boolean rich;
	private static boolean possible;

	public static void main(String[] args) {
		
		ArrayList<ArrayList<boolean[][]>> nagons = new ArrayList<ArrayList<boolean[][]>>();
		for(int num = 1; num <= 6; ++num)
		{
			ArrayList<boolean[][]> cur = new ArrayList<boolean[][]>();
			nagons.add(cur);
			
			fill(cur, new boolean[num][num], new boolean[num][num], num, true);
			
		}
		
		Scanner s = new Scanner(System.in);
		
		int numCases = s.nextInt();
		
		for(int numC = 0; numC < numCases; ++numC)
		{
			rich = false;
			num = s.nextInt();
			int w = s.nextInt();
			int h = s.nextInt();
			
			if(num >= 7)
			{
				rich = true;
			}/*else if(w * h < num || (w * h) % x != 0)
			{
				rich = true;
			}else if (num > w && num > h)
			{
				rich = true;
			}else
			{
				int smaller = (int) Math.min(w, h);
				int bigger = (int) Math.max(w, h);
				if(num >= smaller * 2 + 1)
				{
					rich = true;
				}
			}
			*/
			
			if(!rich)
			{
				agons = nagons.get(num-1);
				
				for(boolean[][] curr : agons)
				{
					possible = false;
					fields = new boolean[w][h];
					
					for(int x = 0-curr.length; x < w+curr.length && !possible; ++x)
					{
						for(int y = 0-curr.length; y < h+curr.length && !possible; ++y)
						{
							for(int i = 0; i < 4 && !possible; ++i)
							{
								// try to put it here.
								tryHere(x, y, curr);
								boolean[][] reversed = new boolean[num][num];
								reverseX(curr, reversed);
								tryHere(x, y, reversed);
								boolean[][] reversedY = new boolean[num][num];
								reverseY(curr, reversedY);
								tryHere(x, y, reversedY);
								reverseY(reversed, reversedY);
								tryHere(x, y, reversedY);
								
								rotate90(curr, reversed);
								curr = reversed;
							}
						}
					}
					if(!possible)
					{
						rich = true;
						break;
					}
				}
				
			}	
			
			
			System.out.print("Case #");
			System.out.print(numC+1);
			System.out.print(": ");
			if(rich)
			{
				System.out.println("RICHARD");
			}else
			{
				System.out.println("GABRIEL");
			}
		}
		

	}
	
	static void tryHere(int x, int y, boolean[][] curr)
	{
		
		for(int a = 0; a < fields.length; ++a)
		{
			for(int b = 0; b < fields[a].length; ++b)
			{
				fields[a][b] = false;
			}
		}
		
		for(int xx = 0; xx < curr.length; ++xx)
		{
			for(int yy = 0; yy < curr.length; ++yy)
			{
				if(curr[xx][yy])
				{
					if(!saveSet(fields, xx+x, yy+y, true))
					{
						return;
					}
				}			
			}
		}
		
		
		// get free spaces.
		boolean[][] calculated = new boolean[fields.length][fields[0].length];
		for(int a= 0; a < calculated.length; ++a)
		{
			for(int b = 0; b < calculated[a].length; ++b)
			{
				int number = floodFill(calculated, a, b);
				if(number % num != 0)
				{
					return;
				}
			}
		}
		
		possible = true;
	}
	
	static int floodFill(boolean[][] calculated, int a, int b)
	{
		if(a < 0 || b < 0 || a >= fields.length || b >= fields[0].length || calculated[a][b] || fields[a][b])
		{
			return 0;
		}
		int num = 1;
		calculated[a][b] = true;
		num += floodFill(calculated, a+1, b);
		num += floodFill(calculated, a-1, b);
		num += floodFill(calculated, a, b+1);
		num += floodFill(calculated, a, b-1);
		
		return num;
	}
	
	static boolean saveSet(boolean[][] arr, int x, int y, boolean value)
	{
		if(x < 0 || y < 0 || x >= arr.length || y >= arr[x].length)
		{
			return false;
		}
		arr[x][y] = value;
		return true;
	}
	
	static boolean saveAcc(boolean[][] arr, int x, int y)
	{
		if(x < 0 || y < 0 || x >= arr.length || y >= arr[x].length)
		{
			return false;
		}
		return arr[x][y];
	}
	
	static void rotate90(boolean[][] input, boolean[][] output)
	{
		boolean[][] output2 = new boolean[input.length][input.length];
		transpose(input, output2);
		reverseX(output2, output);
	}
	
	static void reverseY(boolean[][] input, boolean[][] output)
	{
		for(int x =  0; x < input.length; ++x)
		{
			for(int y = 0; y < input.length; ++y)
			{
				output[x][y] = input[x][input.length-1-y];
			}
		}
	}
	
	static void reverseX(boolean[][] input, boolean[][] output)
	{
		for(int x =  0; x < input.length; ++x)
		{
			for(int y = 0; y < input.length; ++y)
			{
				output[x][y] = input[input.length - 1 - x][y];
			}
		}
	}
	
	static void transpose(boolean[][] input, boolean[][] output)
	{
		for(int x =  0; x < input.length; ++x)
		{
			for(int y = 0; y < input.length; ++y)
			{
				output[x][y] = input[y][x];
			}
		}
	}
	
	static void fill(ArrayList<boolean[][]> list, boolean[][] curr, boolean[][] tried, int toFill, boolean first)
	{
		if(toFill <= 0)
		{
			boolean[][] newA = new boolean[curr.length][];
			for(int i = 0; i < curr.length; ++i)
			{
				newA[i] = curr[i].clone();
			}
			list.add(newA);
			return;
		}
		
		for(int x = 0;  x < curr.length; ++x)
		{
			for(int y = 0; y < curr[x].length; ++y)
			{
				if(!curr[x][y] /*&& !tried[x][y]*/)
				{
					if(first || saveAcc(curr, x-1, y) || saveAcc(curr, x+1, y) || saveAcc(curr, x, y-1) || saveAcc(curr, x, y+1))
					{
						curr[x][y] = true;
						tried[x][y] = true;
						fill(list, curr, tried, toFill-1, false);
						curr[x][y] = false;
					}
				}
			}
		}
		
	}

	
}
