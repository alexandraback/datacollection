package mirrors;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Small {

	public static void main(String[] args) throws IOException {
		File file = new File("D-small-attempt0.in");
		FileReader fr = new FileReader(file);
		BufferedReader in = new BufferedReader(fr);

		String line = in.readLine();
		String[] tokens;
		int num = Integer.parseInt(line);
		int i=1,H,W,D,idx;
		int myX = 0,myY = 0;
		while (i <= num) {
			line = in.readLine();
			tokens = line.split(" ");
			H = Integer.parseInt(tokens[0]);
			W = Integer.parseInt(tokens[1]);
			D = Integer.parseInt(tokens[2]);
			for(int j=0;j<H;j++){
				line = in.readLine();
				idx = line.indexOf('X');
				if(idx>-1){
					myX = 2*idx - W + 1;
					myY = 2*j   - H + 1;
				}
			}
			System.out.println("Case #" + i + ": " + handleCase(2*W-4, 2*H-4, myX, myY, 2*D));
			i++;
		}
	}

	private static int handleCase(int w, int h, int x, int y, int D){
		int maxRow = D/h+2;
		int maxCol = D/w+2;
		
		//System.out.println("w="+w+" h="+h+" x="+x+" y="+y+" maxRow"+maxRow+" maxCol="+maxCol);
		int xLoc, yLoc, xDiff, yDiff;
		int count = 0;
		ArrayList<Point> used = new ArrayList<Point>();
		
		for(int i=-maxRow;i<=maxRow;i++){
			for(int j=-maxCol;j<=maxCol;j++){
				yLoc = i%2==0 ? h*i+y : h*i-y;
				xLoc = j%2==0 ? w*j+x : w*j-x;
				
				yDiff = yLoc - y;
				xDiff = xLoc - x;
				
				if(xDiff*xDiff + yDiff*yDiff <= D*D){
					//System.out.println("("+j+","+i+") in range");
					if(checkAndAdd(xDiff, yDiff, used)){
						count++;
					}
				}
			}
		}
		return count;
	}
	
	private static boolean checkAndAdd(int diffX,int diffY, ArrayList<Point> used){
		if(diffX==0 && diffY==0){
			return false;
		}
		
		int gcd = GCD(abs(diffX),abs(diffY));
		
		diffX /= gcd;
		diffY /= gcd;
		for(Point p:used){
			if(p.x==diffX && p.y==diffY){
				return false;
			}
		}
		used.add(new Point(diffX,diffY));
		return true;
	}
	
	private static int GCD(int a, int b){
	   if (b==0) return a;
	   return GCD(b,a%b);
	}
	
	private static int abs(int a){
		return a>0 ? a : -a;
	}
}
