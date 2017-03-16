import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;


public class Mirror {

	
	static int d,h,w;
	static int adjust=0;
	
	static float targetX,targetY;
//	static Vector<coord> images=new Vector<coord>();
	static Vector<Slope> slo=new Vector<Slope>();
	
	public static void main(String args[]) throws FileNotFoundException, InterruptedException
	{
		Scanner in=new Scanner(new FileReader("basic.in"));
		PrintWriter pw=new PrintWriter("mirr.out");
		
		int cases=in.nextInt();
		in.nextLine();
		
		for(int counter=1;counter<=cases;counter++)
		{
			h=in.nextInt();
			w=in.nextInt();
			d=in.nextInt();
			
			adjust=0;
			
//			images.clear();
//			System.out.println(images.size());
			
			in.nextLine();
			
			
//			if(counter==34)
//				System.out.println();
//				System.out.println(h+" "+" "+w+" "+d);
			for(int i=h;i>0;i--)
			{
				String line=in.nextLine();
				
				for(int j=0;j<w;j++)
				{
					if(line.charAt(j)=='X')
					{
						targetY=(float) (i-1.5);
						targetX=(float) (j-0.5);
						break;
					}
				}
			}
			
			w-=2;
			h-=2;
			
			slo.clear();

//			Vector<Float> valy=new Vector<Float>();
//			Vector<Float> valx=new Vector<Float>();
			
			int maxx=(int) Math.ceil((d+w)/(float)w)*4;
			int maxy=(int) Math.ceil((d+h)/(float)h)*4;
			
			
			for(int i=-maxx;i<=maxx;i+=2)
			{
				for(int j=-maxy;j<=maxy;j+=2)
				{
					if(Math.abs(j)%2!=0)
						continue;
					int variations=0;
				while(variations<4){
					float xc=(float) (i*w+targetX*Math.pow(-1, variations/2));
					float yc=(float) (j*h+targetY*Math.pow(-1, variations%2));
					
//					if(xc==1.5&&yc==0.5)
//						System.out.println();
					variations++;
					float distance=(float) Math.sqrt(Math.pow(xc-targetX, 2)+Math.pow(yc-targetY, 2));
					
					if(xc>0&&xc<w&&yc>0&&yc<h)
					{
//						System.out.println("EEEEEEEEEEEEEEERRRRRRRRRRRRRRRROOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRR");
						continue;
					}
					if(distance<=d)
					{
						float xd=(xc-targetX);
						float yd=(yc-targetY);
						
						float slope;
						if(xd==0&&yd==0)
							continue;
						else if(yd==0)
							slope=9999;
						else
							slope=(xd/yd);
						
						addslope(slope,xc,yc);
//						System.out.println(xc+" "+yc);
//						if(!slo.contains(slope))
//						{
//							slo.add(slope);
//							System.out.println("slope "+slope);
//						}
					}
				}
				}
			}
			
//			reflect(new coord(targetX,targetY));

//			Iterator<coord> it=images.iterator();
						
//			while(it.hasNext())
//			{
//				coord prospect=it.next();
//				float xd=(prospect.x-targetX);
//				float yd=(prospect.y-targetY);
//				
//				float slope;
//				if(xd==0&&yd==0)
//					continue;
//				else if(yd==0)
//					slope=(float) (xd/0.00001);
//				else
//					slope=(xd/yd);
//				
//				if(!slo.contains(slope))
//					slo.add(slope);
//			}
			System.out.println("Case #"+counter+": "+(slo.size()+adjust));
			pw.println("Case #"+counter+": "+(slo.size()+adjust));
			Thread.sleep(1000);
			continue;
		}
		pw.close();
	}
	
	private static void addslope(float slope, float xd, float yd) {
		
		Iterator<Slope> iter=slo.iterator();
		
		while(iter.hasNext())
		{
			Slope temp=iter.next();
			int index=slo.indexOf(temp);
			if(temp.s!=slope)
				continue;
			
			if(temp.x==-999)
			{
				temp.x=xd;
				temp.y=yd;
				slo.set(index, temp);
				return;
			}
			
			if(temp.both)
				return;
			
			if((xd-targetX)*(temp.x-targetX)+(yd-targetY)*(temp.y-targetY)<0)
			{
				adjust++;
				temp.both=true;
				slo.set(index, temp);
			}
			return;
		}
		
		Slope t=new Slope();
		t.s=slope;
		t.x=xd;
		t.y=yd;
		
		slo.add(t);
	}

	/*public static void reflect(coord c)
	{
//		coord ans;
//		Vector<coord> ls=new Vector<coord>();
		
		if(Math.sqrt(Math.pow(c.x-targetX, 2)+Math.pow(c.y-targetY, 2))>d)
			return;
		
//		Iterator<coord> iter=images.iterator();
//		boolean flag=true;
//		
//		while(iter.hasNext())
//			if(iter.next().equals(c))
//				flag=false;
//		
//		if(!flag)
//		{
//			System.out.println("rejecting");
//			return;
//		}
		
//		images.add(c);

		float xd=(c.x-targetX);
		float yd=(c.y-targetY);
		
		float slope;
		if(xd==0&&yd==0)
			System.out.println();
		else
		{
			if(yd==0)
				slope=(float) (xd/0.00001);
			else
				slope=(xd/yd);
		
			if(!slo.contains(slope))
				slo.add(slope);
		}
		
		
		if(c.x<w)
			reflect(new coord(2*w-c.x,c.y));
		if(c.x>0)
			reflect(new coord(-c.x,c.y));
//		else
//		{
//			ls.add(new coord(-c.x,c.y));
//			ls.add(new coord(w-c.x,c.y));
//		}
		
		if(c.y<h)
			reflect(new coord(c.x,2*h-c.y));
		if(c.y>0)
			reflect(new coord(c.x,-c.y));
		
//		return ans;
	}
	
*/
}