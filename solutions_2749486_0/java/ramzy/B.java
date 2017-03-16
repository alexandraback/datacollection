package codejam.y2013.round1C;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {
	
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("inputs/1C/B.in"));
		PrintWriter output = new PrintWriter("inputs/1C/B.out");


		String out;
		int N = input.nextInt();
		for(int c = 1; c <= N; c++) {
			int x = input.nextInt();
			int y = input.nextInt();
			
			out = "Case #" + c + ": " + solve(1,x,y);
			String str = solve(1,x,y);
			for(int i = 0; i < str.length(); i++) {
				char cc = str.charAt(i);
				if(cc == 'N') y-=i+1;
				if(cc == 'S') y+=i+1;
				if(cc == 'E') x-=i+1;
				if(cc == 'W') x+=i+1;
			}
			if(x!= 0)
				System.out.println("x " + x);
			if(y!=0)
				System.out.println("y " + y);
			
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}

	private static String solve(int i, int x, int y) {
		int sX = x > 0 ? 1 : -1;
		int sY = y > 0 ? 1 : -1;
		StringBuilder str = new StringBuilder();
		
		while(sX*x > 0 && sY*y > 0) {
			while(sX*x >= sY*y) {
				if(sX == 1) {
					x -= (i++);
					str.append("E");
				} else {
					x += (i++);
					str.append("W");
				}
			}
			while(sX*x < sY*y) {
				if(sY == 1) {
					y -= (i++);
					str.append("N");
				} else {
					y += (i++);
					str.append("S");
				}				
			}
		}
		//System.out.println(x);
		//System.out.println(y);
		if(x != 0) {
			int o = -1*sX*x;
			//for(int j = 0; j < o; j++) {
			while(x != 0) {
				if(sX*x == 0) break;
				if(x > 0) {
					x += (i++);
					str.append("W");
					if(sX*x == 0) break;
					x -= (i++);
					str.append("E");
				} else {
					x -= (i++);
					str.append("E");
					if(sX*x == 0) break;
					x += (i++);
					str.append("W");
				}
			}
		}
		// N +y S -y E +x W -x
		if(y != 0) {
			int o = -1*sY*y;
			//for(int j = 0; j < o; j++) {
			while(y != 0) {
				if(sY*y == 0) break;
				if(y > 0) {
					y += (i++);
					str.append("S");
					if(sY*y == 0) break;
					y -= (i++);
					str.append("N");
				} else {
					y -= (i++);
					str.append("N");
					if(sY*y == 0) break;
					y += (i++);
					str.append("S");
				}
			}
		}
		if(i > 500) System.out.println("adsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\nadsf\n");
		return str.toString();
	}
	
}