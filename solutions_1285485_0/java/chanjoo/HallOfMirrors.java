package codejam;

import java.util.HashSet;
import java.util.Scanner;

public class HallOfMirrors extends Solver {

	public static void main(String...args) {
		HallOfMirrors solver = new HallOfMirrors();
//		System.out.println(solver.solve("3 3 1\n###\n#X#\n###"));
//		System.out.println(solver.solve("3 3 2\n###\n#X#\n###"));
//		System.out.println(solver.solve("3 3 3\n###\n#X#\n###"));
//		System.out.println(solver.solve("5 6 10\n######\n#..X.#\n#.#..#\n#...##\n######"));
//		solver.solveSampleOf('D');
		solver.solveSmallOf('D', 0);
	}
	
	enum Block { MIRROR, ME, REFLECT_ME }
	Room room;
	
	@Override
	public String evaluate() {
		room = new Room(in.nextInt(), in.nextInt());
		int d = in.nextInt();
		
		room.read(in);
		HashSet<Coord> resultSet = new HashSet<Coord>();
		
		Coord x = Coord.rc(0, 0);
		for(int i=-d; i<=d; i++) {
			for(int j=-d; j<=d; j++) {
				if(i==0 && j==0) continue;
				Coord c = Coord.rc(i,j);
				Block b = room.get(c);
				if(x.dist(c)<=d) {
					if(b==Block.ME) {
						resultSet.add(c.least());
					}
				}
			}
		}
		
		return String.valueOf(resultSet.size());
	}
	
	static class Coord {
		final int r;
		final int c;
		
		private Coord(int row, int column) {
			r = row;
			c = column;
		}
		
		public static Coord rc(int row, int column) {
			return new Coord(row, column);
		}
		
		public Coord offset(Coord d) {
			return Coord.rc(r+d.r, c+d.c);
		}
		
		public Coord pack(Coord boundary) {
			int tr = r;
			int tc = c;
			while(!in(tr, tc, boundary)) {
				if(tr<1) tr=-tr+1;
				if(tc<1) tc=-tc+1;
				if(tr>=boundary.r-1) tr=-(tr-(boundary.r-1))-1+(boundary.r-1);
				if(tc>=boundary.c-1) tc=-(tc-(boundary.c-1))-1+(boundary.c-1);
			}
			return Coord.rc(tr, tc);
		}
		
		private static boolean in(int r, int c, Coord boundary) {
			if(r<1 || c<1) return false;
			if(r>=boundary.r-1 || c>=boundary.c-1) return false;
			return true;
		}
		
		public double dist(Coord to) {
			int dr = to.r-r;
			int dc = to.c-c;
			return Math.sqrt(dr*dr + dc*dc);
		}
		
		public Coord least() {
			int gcd = gcd(r, c);
			return Coord.rc(r/gcd, c/gcd);
		}
		
		private int gcd(int a, int b) {
			if(a<0) a = -a;
			if(b<0) b = -b;
			if(a==b) return a;
			if(b==0) return a;
			if(a>b) {
				return gcd(b, a%b);
			} else {
				return gcd(b, a);
			}
		}
		
		public String toString() {
			return "(" + r + ", " + c + ")";
		}

		@Override
		public boolean equals(Object obj) {
			if(obj instanceof Coord) {
				Coord c = (Coord) obj;
				return c.r == this.r && c.c == this.c;
			} else
				return super.equals(obj);
		}

		@Override
		public int hashCode() {
			return (r<<10) + c;
		}
		
	}
	
	static class Room {
		Block[][] data;
		Coord size;
		Coord x;
		
		public Room(int row, int column) {
			size = Coord.rc(row, column);
			data = new Block[size.r][size.c];
		}
		
		public void read(Scanner in) {
			for(int i=0; i<size.r; i++) {
				char[] rdata = in.next().toCharArray();
				for(int j=0; j<size.c; j++) {
					switch(rdata[j]) {
					case '#':
						data[i][j] = Block.MIRROR;
						break;
					case 'X':
						data[i][j] = Block.ME;
						x = Coord.rc(i, j);
						break;
					}
				}
			}
		}
		
		public Block get(Coord d) {
			d=d.offset(x);
			d=d.pack(size);
			return data[d.r][d.c];
		}
		
		public String toString() {
			StringBuilder buf = null;
			for(Block[] row: data) {
				if(buf==null) buf = new StringBuilder();
				else buf.append('\n');
				for(Block b: row) {
					if(b==null) {
						buf.append('.');
						continue;
					}
					switch(b) {
					case ME:
						buf.append('X');
						break;
					case MIRROR:
						buf.append('#');
						break;
					}
				}
			}
			return buf.toString();
		}
	}
	
}
