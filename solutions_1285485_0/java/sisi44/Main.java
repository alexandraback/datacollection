import java.util.*;

class Point implements Comparable<Point>{
	int x;
	int y;
	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
	@Override
	public boolean equals(Object o)
	{
		return x==((Point)o).x && y == ((Point)o).y;
	}
	@Override
	public int compareTo(Point o) {
		// TODO Auto-generated method stub
		if(x>o.x)
			return 1;
		else if(x<o.x)
			return -1;
		else 
		{
			if(y == o.y)
				return 0;
			else if(y>o.y)
				return 1;
			else return -1;
		}
	}
}
public class Main{
	static int gcd(int a, int b) //a>=0,b >=1
	{
		if(a%b == 0) return b;
		return gcd(b, a%b);
	}
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<=T; cc++)
		{
			int H = in.nextInt();
			int W = in.nextInt();
			int D = in.nextInt();
			in.nextLine();
			char[][] tab = new char[H][W];
			int xMan = 0;
			int yMan = 0;
			for(int i = 0; i<H; i++)
			{
				String s = in.nextLine();
				for(int j = 0; j<W; j++)
				{
					tab[i][j] = s.charAt(j);
					if(s.charAt(j) ==  'X')
					{
						xMan = j;
						yMan = i;
					}
					
				}
			}
			TreeSet<Point> S = new TreeSet<Point>();
			
			int up[][] = new int[2][2];
			int down[][] = new int[2][2];
			int left[][] = new int[2][2];
			int right[][] = new int[2][2];
			up[0][0] = yMan; // on double
			down[0][0] = H-1-yMan; //
			left[0][0] = xMan;
			right[0][0] = W-1-xMan;
			up[1][0] = up[0][0];
			left[1][0] = right[0][0];
			up[1][1] = down[0][0];
			left[1][1] = right[0][0];
			up[0][1] = down[0][0];
			left[0][1] = left[0][0];
			for(int i = 0; i<2 ; i++)
				for(int j = 0; j<2; j++)
				{
					down[i][j] = H-1- up[i][j];
					right[i][j]= W-1 -left[i][j];
				}
			int res = 0;
			//System.out.println(xMan +" "+yMan+" "+D);
			int nbW = D/(W-2)+1;
			int nbH = D/(H-2)+1;
 			for(int i = -nbW; i<= nbW; i++)
			{
				for(int j = -nbH; j<= nbH; j++)
				{ 
						if(i == 0 && j == 1)
						{
							int h = (H-2)*(j-1)+up[0][0]+down[0][j%2]-1; //System.out.println("h = "+h);
							if(h <= D)
							{
								S.add(new Point(0,h));
								res++;
								//System.out.println(i+" "+ j);
							}
						}
						else if(i == 0 && j==-1)
						{
							int aj = -j;
							int h = (H-2)*(aj-1)+down[0][0]+up[0][aj%2]-1;
							if(h <= D)
							{
								S.add(new Point(0, -h));
								res++;
								//System.out.println(i+" "+ j);
							}
						}
						else if(j == 0 && i==1)
						{
							int w = (W-2)*(i-1)+right[0][0]+left[i%2][0]-1;
							if(w <= D)
							{
								S.add(new Point(w, 0));
								res++;
								//System.out.println(i+" "+ j);
							}
						}
						else if(j==0 && i==-1)
						{
							int ai = -i;
							int w = (W-2)*(ai-1)+left[0][0]+right[ai%2][0]-1;
							if(w <= D)
							{
								S.add(new Point(-w,0));
								res++;
								//System.out.println(i+" "+ j);
							};
						}
						else if(i< 0 && j< 0)
						{
							int ai = -i;
							int aj = -j;
							int w = (W-2)*(ai-1)+left[0][0]+right[ai%2][aj%2]-1;
							int h = (H-2)*(aj-1)+down[0][0]+up[ai%2][aj%2]-1;//System.out.println("h = "+h);
							//if(cc==28)System.out.println("h = "+w+" "+h+" "+(w*w+h*h) +" " +D*D);
							long l = w*w+h*h ;
							if(l < D*D+1)
							{
								int gc = gcd(w,h);
								Point p = new Point(-w/gc, -h/gc);
								//if(cc==28)System.out.println("p = "+p.x +" " +p.y);
								if(!S.contains(p))
								{
									S.add(p);
									res++;
								}
									
								//System.out.println(i+" "+ j);
							}
						}
						else if(i<0 && j>0)
						{
							int ai = -i;
							int w = (W-2)*(ai-1)+left[0][0]+right[ai%2][j%2]-1;
							int h = (H-2)*(j-1)+up[0][0]+down[ai%2][j%2]-1;
							long l = w*w+h*h ;
							if(l < D*D+1)
							{
								int gc = gcd(w,h);
								Point p = new Point(-w/gc, h/gc);
								if(!S.contains(p))
								{
									S.add(p);
									res++;
								}
								//System.out.println(i+" "+ j);
							}
						}
						else if(i>0 && j<0)
						{
							int aj = -j;
							int w = (W-2)*(i-1)+right[0][0]+left[i%2][aj%2]-1;
							int h = (H-2)*(aj-1)+down[0][0]+up[i%2][aj%2]-1;
							long l = w*w+h*h ;
							if(l<= D*D)
							{
								int gc = gcd(w,h);
								Point p = new Point(w/gc, -h/gc);
							
								if(!S.contains(p))
								{
									S.add(p);
									res++;
								}
								//System.out.println(i+" "+ j);
							}
						}
						else if(i>0 && j>0)
						{
							int w = (W-2)*(i-1)+right[0][0]+left[i%2][j%2]-1;
							int h = (H-2)*(j-1)+up[0][0]+down[i%2][j%2]-1;
							long l = w*w+h*h ;
							if(l<= D*D)
							{
								int gc = gcd(w,h);
								Point p = new Point(w/gc, h/gc);
							
								if(!S.contains(p))
								{
									S.add(p);
									res++;
								}
								//System.out.println(i+" "+ j);
							}
						}
					
				}
			}
			//for(Point p: S)
			//{
			//	System.out.println(p.x+" "+p.y);
			//}
			
			System.out.println("Case #"+cc+": "+res);
		}
	}
}