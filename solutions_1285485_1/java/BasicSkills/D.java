import java.io.*;
import java.util.*;


public class D {
	
	public static class Pair {
		public int r;
		public int c;
		
		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}

		@Override
		public boolean equals(Object o) {
			if (o == null)
				return false;
			if (!(o instanceof Pair))
				return false;
			
			Pair p = (Pair) o;
			if (this.r == p.r && this.c == p.c)
				return true;
			else
				return false;
		}
	}
	
	static char[][] d = new char[30][];
	static int H;
	static int W;
	static int D;
	static int row;
	static int column;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("D.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D.out")));
		
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; ++ i) {
			String st = in.readLine();
			String[] input = st.split(" ");
			
			H = Integer.parseInt(input[0]);
			W = Integer.parseInt(input[1]);
			D = Integer.parseInt(input[2]);
			
			for (int r = 0; r < H; ++ r)
				d[r] = in.readLine().toCharArray();
			
			for (int r = 0; r < H; ++ r)
				for (int c = 0; c < W; ++ c)
					if (d[r][c] == 'X') {
						row = r;
						column = c;
					}
			
			List<Pair> s = new ArrayList<Pair>();
			int ans = 0;
			for (int r = 1; r < D; ++ r) {
				for (int c = 1; c < D; ++ c) {
					int gcd = gcd(r, c);
					int dr = r / gcd;
					int dc = c / gcd;
					Pair p = new Pair(dr, dc);
					if (!s.contains(p)) {
						s.add(p);
						if (mapSearch(dr, dc, 1, 1))
							++ ans;
						if (mapSearch(dr, dc, 1, -1))
							++ ans;
						if (mapSearch(dr, dc, -1, 1))
							++ ans;
						if (mapSearch(dr, dc, -1, -1))
							++ ans;
					}
				}
			}
			if (lineSearch(1, 0))
				++ ans;
			if (lineSearch(-1, 0))
				++ ans;
			if (lineSearch(0, 1))
				++ ans;
			if (lineSearch(0, -1))
				++ ans;
			
			out.println("Case #" + (i + 1) + ": " + ans);
		}
		
		in.close();
		out.close();
	}
	
	private static boolean mapSearch(int dr, int dc, int dx, int dy) {
		int x = 0;
		int y = 0;
		int posX = row;
		int posY = column;
		
		while(Math.pow(x, 2) + Math.pow(y, 2) < Math.pow(D, 2)) {
			if((x + 0.5) * dr < (y + 0.5) * dc) {
	            posX += dx;
	            x += 1;
	            if(d[posX][posY] == '#'){
	                dx = -dx;
	                posX += dx;
	            }
			}
			else if((x + 0.5) * dr > (y + 0.5) * dc) {
	            posY += dy;
	            y += 1;
	            if(d[posX][posY] == '#'){
	                dy = -dy;
	                posY += dy;
	            }
			}
	        else {
	            x += 1;
	            y += 1;
	            posX += dx;
	            posY += dy;
	            if(d[posX][posY]=='#'){
	                if(d[posX - dx][posY] == '#' && d[posX][posY - dy] == '#'){
	                    dx = -dx;
	                    dy = -dy;
	                    posX += dx;
	                    posY += dy;
	                }
	                else if(d[posX - dx][posY] == '#'){
	                    dy = -dy;
	                    posY += dy;
	                }
	                else if(d[posX][posY - dy] == '#'){
	                    dx = -dx;
	                    posX += dx;
	                }
	                else{ 
	                	return false;
	                }
	            }
	        }
	        if(d[posX][posY] == 'X' && y * dc == x * dr
	        		&& Math.pow(x,2) + Math.pow(y,2) <= Math.pow(D,2)) {
	            return true;
	        }
		}
		
		return false;
	}
	
	public static boolean lineSearch(int dx, int dy){
		int posX = row;
		int posY = column;
		
	    for(int i = 0; i < D; ++ i){
	    	posX += dx;
	    	posY += dy;
	        if(d[posX][posY] == '#'){
	            dx = -dx;
	            dy = -dy;
	            posX += dx;
	            posY += dy;
	        }
	        if(d[posX][posY] == 'X'){
	        	return true;
	        }
	    }
	    return false;
	}
	
	private static int gcd (int a, int b) {
		if (b == 0)
			return a;
		else
			return gcd(b, a % b);
	}
	
}
