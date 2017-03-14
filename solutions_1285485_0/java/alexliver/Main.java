import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

import javax.imageio.ImageIO;

class findRes
{
	double angle;
	double x,y;
	double d;
	boolean found = false;
}
public class Main {
	public static int X, Y, D;
	public static char[][] mat;
	public static final double [] starts = new double[]{0,Math.PI/2, Math.PI, Math.PI*3/2};
	public static final double EPS = CGConst.EPS;
	public static double posx, posy;
	public static int dblcmp(double d1, double d2)
	{
		if(Math.abs(d1-d2)<EPS)
			return 0;
		if(d1<d2)
			return -1;
		return 1;
	}
	public static List<double[]> mirrors;
	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream(new File("in.txt"));
		FileOutputStream fos = new FileOutputStream(new File("out.txt"));
		Scanner sc = new Scanner(fis);
		PrintWriter out = new PrintWriter(fos);
		int cases = sc.nextInt();
		for(int cs = 1; cs <= cases; cs++)
		{
			Y = sc.nextInt();
			X = sc.nextInt();
			D = sc.nextInt();
			mat = new char[Y][X];
			sc.nextLine();
			mirrors = new ArrayList<double[]>();
			int cnt = 0;
			for(int i=0; i<Y; i++)
			{
				String line = sc.nextLine();
				for(int j=0; j<X; j++)
				{
					mat[i][j] = line.charAt(j);
					if(mat[i][j] == 'X')
					{
						posx = 0.5+j;
						posy = 0.5+i;
					}
					else if(mat[i][j] =='#')
					{
						mirrors.add(new double[]{j,i});
					}
				}
			}
			Set<Double> used = new TreeSet<Double>(new Comparator<Double>(){

				@Override
				public int compare(Double arg0, Double arg1) {
					arg0 = adjust(arg0);
					arg1 = adjust(arg1);
					return dblcmp(arg0, arg1);
				}
				
			});
			for(double start : starts)
			{
				for(double s1 = 0; s1 <=D; s1++)
					for(double s2=1; s2<=D; s2++)
					{
						double r = Math.sqrt(s1*s1+s2*s2);
						
						if(dblcmp(r,D)<=0)
						{
							double angle = start + Math.atan(s1/s2);
							if(used.contains(angle))
								continue;
							else
								used.add(angle);
							List<Double> xlist = new ArrayList<Double>();
							List<Double> ylist = new ArrayList<Double>();
							
							double curx = posx, cury = posy;
							double curd = D;
							
							while(dblcmp(curd, 0)>0)
							{
								xlist.add(curx);
								ylist.add(cury);
								
								findRes fr=find(angle, curx, cury, curd);
								if(fr.found)
								{
									cnt++;
//									double ang=adjust(start + Math.atan(s1/s2));
//									System.out.println(ang);
//									for(int i=0; i<xlist.size(); i++)
//										System.out.println("\t"+xlist.get(i)+" "+ylist.get(i));
//									draw(xlist, ylist, 100,"img"+ang);
									break;
								}
								angle = fr.angle;
								curx = fr.x;
								cury = fr.y;
								curd = fr.d;
							}
						}
					}
			}
			
			out.println("Case #"+cs+": "+cnt);
			System.out.println("Case #"+cs+": "+cnt);
		}
		sc.close();
		out.close();
	}
	private static void draw(List<Double> xlist, List<Double> ylist, int size,String name) {
		int w = size*X, h = size*Y;
		BufferedImage bi = new BufferedImage(w, h,BufferedImage.TYPE_INT_ARGB);
		
		Graphics2D g = bi.createGraphics();
		for(int i=0; i<xlist.size()-1; i++)
		{
			g.setColor(Color.BLACK);
			g.drawLine((int)(xlist.get(i)*size), (int)(ylist.get(i)*size),
					(int)(xlist.get(i+1)*size), (int)(ylist.get(i+1)*size));
		}
		for(double[] arr:mirrors)
		{
			g.drawRect((int)arr[0]*size, (int)arr[1]*size, size, size);
		}
		try {
			ImageIO.write(bi, "png", new File("C:\\"+name+".png"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	protected static double adjust(double arg0) {
		while(arg0 >= Math.PI*2)
			arg0 -= Math.PI*2;
		while(arg0 < 0)
			arg0 += Math.PI*2;
		return arg0;
	}
	private static findRes find(double angle, double curx, double cury, double curd) {
		final double[][] sides = new double[][]{
				{0,1,1,1},{1,0,1,1},{0,0,1,0},{0,0,0,1}
		};
		final double MAX = 100;
		Point start = new Point(curx, cury);
		Point end = new Point(curx + curd*Math.cos(angle), cury + curd*Math.sin(angle));
		if(dblcmp(curx, posx)!=0 || dblcmp(cury, posy) != 0)
		{
			Point ori = new Point(posx, posy);
			double dis = ori.minus(start).abs();
			if(CG.intersectSP(start, end, ori))
			{
				boolean found = false;
				for(double [] arr:mirrors)
				{
					
					for(int i=0; i<sides.length; i++)
					{
						Point p1 = new Point(arr[0]+sides[i][0], arr[1]+sides[i][1]);
						Point p2 = new Point(arr[0]+sides[i][2], arr[1]+sides[i][3]);
						Point p = new Point();
						int ind=CG.crossPointSS(p1, p2, start, end, p);
						if(!p.equals(start)&&ind !=0 &&p.minus(start).abs()<dis)
							found = true;
						
					}
				}
				if(!found)
				{
					findRes res = new findRes();
					res.found = true;
					return res;
				}
			}
		}
		double mindis = Double.MAX_VALUE;
		Point inter = null;
		List<Integer> interSides = new ArrayList<Integer>();
		List<double[]> interMirrors = new ArrayList<double[]>();
		for(double [] arr:mirrors)
		{
			
			for(int i=0; i<sides.length; i++)
			{
				Point p1 = new Point(arr[0]+sides[i][0], arr[1]+sides[i][1]);
				Point p2 = new Point(arr[0]+sides[i][2], arr[1]+sides[i][3]);
				Point p = new Point();
				int ind=CG.crossPointSS(p1, p2, start, end, p);
				if(ind != 0 && !p.equals(start))
				{
					double dis = p.minus(start).abs();
					if(dblcmp(dis, mindis)<0)
					{
						interSides.clear();
						interMirrors.clear();
						mindis = dis;
					}
					if(dblcmp(dis,mindis) == 0)
					{
						inter = p;
						interSides.add(i);
						interMirrors.add(arr);
					}
				}
				
			}
		}
		final double [] toadd = new double[]{0,Math.PI,0,Math.PI};
		findRes res = new findRes();
		if(inter != null)
		{
			res.x = inter.x;
			res.y = inter.y;
			res.d = curd - inter.minus(start).abs();
		}

		if(interMirrors.size() == 0)
		{
			res.d=0;
			
		}
		else if(interMirrors.size()==1)
		{
			res.angle = toadd[interSides.get(0)] - angle;
			
		}
		else if(interMirrors.size() ==2)
		{
			Point maxPt = new Point(curx + MAX*Math.cos(angle), cury+MAX*Math.sin(angle));
			int cnt = 0;
			for(int i=0; i<sides.length; i++)
			{
				Point p1 = new Point(interMirrors.get(0)[0]+sides[i][0], interMirrors.get(0)[1]+sides[i][1]);
				Point p2 = new Point(interMirrors.get(0)[0]+sides[i][2], interMirrors.get(0)[1]+sides[i][3]);
				Point p = new Point();
				int ind=CG.crossPointSS(p1, p2, start, maxPt, p);
				if(ind != 0)
					cnt++;
			}
			if(cnt == 2)
				res.angle = angle;
			else
				res.d=0;
		}
		else if(interMirrors.size() == 4)
		{
			Set<Integer> used = new TreeSet<Integer>();
			int rep = -1;
			for(Integer side:interSides)
			{
				if(used.contains(side))
					rep = side;
				else
					used.add(side);
			}
			if(used.size() == 4)
				res.angle = angle;
			else
			{
				res.angle = toadd[rep]-angle;
			}
		}
		else if(interMirrors.size() == 6)
		{
			res.angle = angle+Math.PI;
		}
		else
		{
			System.out.println("fuck");
		}
		return res;
	}
}
