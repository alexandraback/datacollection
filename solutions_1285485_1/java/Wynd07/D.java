import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class D {
	public static void main (String [] args) throws IOException {new D().run();}
	public void run() throws IOException{
		Scanner file = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D4.out")));
		int times = Integer.parseInt(file.nextLine());
		for(int asdf = 0; asdf<times; asdf++){
			System.out.println (asdf);
			int row = file.nextInt(), col = file.nextInt();
			int d = file.nextInt(); file.nextLine();
			double px=0,py=0;
			for(int i = 0; i<row; i++){
				String s = file.nextLine();
				if( s.contains("X")){
					py = i+.5-1; px = s.indexOf("X")+.5-1;
				}
			}
			row-=2;col-=2;
			int XLIM = 500;
			int YLIM = 500;
			HashSet<Double> set = new HashSet<Double>();
			for(int x = -XLIM; x<=XLIM; x++)
			for(int y = -YLIM; y<=YLIM; y++){
				if( x==0&&y==0)continue;
				double xx,yy;
				if( x%2==0) xx = x*col+px;
				else xx = (x+1)*col-px;
				if( y%2==0) yy = y*row+py;
				else yy = (y+1)*row-py;
				if( Math.sqrt(Math.pow(xx-px,2)+Math.pow(yy-py,2))  <= d)
					set.add(Math.atan2(yy-py,xx-px));
			}
			int count = 0;
			for(double d1 : set)
				for(double d2 : set)
					if( Math.abs(d1-d2)<1e-5)count++;
			if(count != set.size()) System.out.println ("FAIL");
			out.println ("Case #"+(asdf+1)+": "+set.size());
			//System.out.println (set);
		}
		out.close();
		System.exit(0);
	}
}