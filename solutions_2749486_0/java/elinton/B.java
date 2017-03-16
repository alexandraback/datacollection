package codejam;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class B extends CodeJam {

	public B(String file) throws Exception {
		super(file);
	}
	
	
	@Override
	public Object processCase(int caseNumber) throws Exception {
		int[] xy = readIntArray();
		
		int x = 0, y = 0;
		int targetX = xy[0], targetY = xy[1];
		
		StringBuilder path = new StringBuilder();
		
		int dx = targetX - x;
		int dy = targetY - y;
		
		double d = Math.sqrt(dx*dx + dy*dy);
		
		
		
		do {
			
			if (targetX != x) {
//				dx = targetX - x;
				if (targetX > x && x + path.length()+1 <= targetX) {
					path.append('E');
					x+=path.length();
				} else {
					path.append('W');
					x-=path.length();
				}
				if (targetX == x && targetY == y) return path;
			}
			
//			System.out.println(path);
			
			if (targetY != y) {
				dy = targetY - y;
				if (targetY > y && y + path.length()+1 <= targetY) {
					path.append('N');
					y+=path.length();
				} else {
					path.append('S');
					y-=path.length();
				}
				if (targetX == x && targetY == y) return path;
			}
//			System.out.println(x+","+y);
		} while(true);
		
		
	}
	
	public static void main(String[] args) throws IOException, InterruptedException, Exception {
		new B("B-small-attempt0.in").start();
	}

}
