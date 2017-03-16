import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Scanner;


public class Solution {
	static final int[][] adj =
		{ {-1,-1},{0,-1},{1,-1},{1,0},
		{1,1},{0,1},{-1,1},{-1,0} };

	static class pos {
		int x, y;
	}

	static class rect {
		int w, h;

		int area() { return w * h; }
	}

	static class Field {

		public Field(int width, int height) {
			this.width = width;
			this.height = height;
			levels = new int[width][height];
			layout = new char[width][height];

			for(int i = 0; i < width; ++i)
				for(int j = 0; j < height; ++j) {
					levels[i][j] = 8;
					layout[i][j] = '*';
					for(int k = 0; k < 8; ++k) {
						if(!inBounds(i + adj[k][0], j + adj[k][1])) {
							levels[i][j]--;
						}
					}
				}
		}

		public Field(Field src) {
			this.width = src.width;
			this.height = src.height;
			levels = new int[width][height];
			for(int i = 0; i < width; ++i)
				for(int j = 0; j < height; ++j) {
					levels[i][j] = src.levels[i][j];
				}
			layout = new char[width][height];
			for(int i = 0; i < width; ++i)
				for(int j = 0; j < height; ++j) {
					layout[i][j] = src.layout[i][j];
				}
		}

		Field copy() {
			return new Field(this);
		}

		void clearSpot(int x, int y) {
			layout[x][y] = '.';
			for(int i = 0; i < 8; ++i) {
				if(inBounds(x + adj[i][0],y + adj[i][1])) {
					levels[x+adj[i][0]][y + adj[i][1]]--;
				}
			}
		}

		boolean inBounds(int x, int y) {
			return x >= 0 && y >= 0 && x < width && y < height;
		}

		String layoutToString() {
			if(width == 0 && height == 0) return "";
			String r = "";
			for(int y = 0; y < height; ++y) {
				for(int x = 0; x < width; ++x) {
					r += layout[x][y];
				}
				if(y +1 != height) r += "\n";
			}
			return r;
		}

		String levelsToString() {
			if(width == 0 && height == 0) return "";
			String r = "";
			for(int y = 0; y < height; ++y) {
				for(int x = 0; x < width; ++x) {
					r += levels[x][y] + " ";
				}
				r += "\n";
			}
			return r;
		}

		void testSolution(char[][] field, pos click) {
			ArrayList<pos> buffer = new ArrayList<pos>();
			buffer.add(click);
			while(!buffer.isEmpty()) {
				pos next = buffer.get(0);
				buffer.remove(0);
				if(!inBounds(next.x, next.y) || field[next.x][next.y] != '.') continue;
				field[next.x][next.y] = 'm';
				if(levels[next.x][next.y] != 0) continue;
				for(int i = 0; i < 8; ++i) {
					pos nextnext = new pos();
					nextnext.x = next.x + adj[i][0];
					nextnext.y = next.y + adj[i][1];
					buffer.add(nextnext);
				}
			}
		}

		boolean isSolution(int mines) {
			char[][] lcp = new char[width][height];
			for(int i = 0; i < width; ++i) for(int j = 0; j < height; ++j) {
				lcp[i][j] = layout[i][j];
				if(layout[i][j] == '*') {
					mines--;
				}
			}
			if(mines != 0) {
				return false;
			}
			testSolution(lcp, click);
			for(int i = 0; i < width; ++i) for(int j = 0; j < height; ++j)
				if(lcp[i][j] == '.') return false;
			return true;
		}

		public int[][] levels;
		public char[][] layout;
		public int width, height;

		public pos click = new pos();
	}

	static void solve(InputStream in) {
		Scanner scn = new Scanner(in);
		int numcases = scn.nextInt();
		for(int i = 1; i <= numcases; ++i) {
			solveCase(scn, i);
		}
	}

	static boolean validizeRect(rect r, int width, int height, int spots) {
		if(r.w > width || r.h > height) return false; // Simply doesn't fit
		if(r.area() > spots) return false; // Too big to create
		int remainder = spots - r.area();
		if(remainder == 1) return false; // 1 is not allowed as remainder
		return true;
	}

	static rect findBestRect(int width, int height, int spots) {
		if(spots < 4) return null;
		rect r1 = new rect();
		rect r2 = new rect();
		r1.w = 2;
		r1.h = 2;

		while(true) {
			r2.w = r1.w;
			r2.h = r1.h + 1;
			if(validizeRect(r2, width, height, spots)) {
				r1.w = r2.w;
				r1.h = r2.h;
			} else {
				break;
			}
		}
		while(true) {
			r2.w = r1.w + 1;
			r2.h = r1.h;
			if(validizeRect(r2, width, height, spots)) {
				r1.w = r2.w;
				r1.h = r2.h;
			} else {
				break;
			}
		}
		return r1;
	}

	static void solveCase(Scanner in, int casenumber) {
		int r = in.nextInt();
		int c = in.nextInt();
		int t = in.nextInt();
		Field f = solveCase2(c, r, t);
		System.out.println("Case #" + casenumber + ":");
		if(f == null) {
			System.out.println("Impossible");
		} else {
			f.layout[f.click.x][f.click.y] = 'c';
			System.out.println(f.layoutToString());
		}
	}

	static Field solveCase2(int width, int height, int mines) {
		Field f = new Field(width, height);

		int spots = width * height - mines;

		// "Stupid" case handling

		if(spots == 1) {
			f.clearSpot(0, 0);
			f.click.x = 0;
			f.click.y = 0;
			return f;
		}

		if(mines >= width * height ) {
			return null;
		}

		if(mines == 0) {
			for(int x = 0; x < f.width; ++x) for(int y = 0; y < f.height; ++y)
				f.clearSpot(x, y);
			f.click.x = 0;
			f.click.y = 0;
			return f;
		}

		if(width == 1) {
			for(int y = 0; y < spots; ++y)
				f.clearSpot(0, y);
			f.click.x = 0;
			f.click.y = 0;
			return f;
		}

		if(height == 1) {
			for(int x = 0; x < spots; ++x)
				f.clearSpot(x, 0);
			f.click.x = 0;
			f.click.y = 0;
			return f;
		}

		if(spots < 4 || spots == 5) {
			return null;
		}

		if((width == 2 || height == 2) && spots % 2 != 0) {
			return null;
		}

		//
		/*
		 * At this point there is no field with:
		 *  - only mines
		 *  - no mines
		 *  - 1 mine
		 *  - width of 1
		 *  - height of 1
		 *  - width or height of 2 and uneven number of spots (impossible)
		 *  - less than 3 spots (because this is impossible in every case but some special ones)
		 *  - 5 spots (impossible except special cases)
		 */

		rect r = findBestRect(width, height, spots);

		for(int i = 0; i < r.w; ++i) {
			for(int j = 0; j < r.h; ++j) {
				f.clearSpot(i, j);
			}
		}

		int remainder = spots - r.area();

		pos ch = new pos();
		pos cv = new pos();
		ch.x = 0;
		ch.y = r.h;
		cv.x = r.w;
		cv.y = 0;

		while(remainder > 0) {
			int rs = remainder;

			if(ch.y < height) {
				while(remainder > 0) {
					// 1.
					// This means, we're about to have to change focus
					// and after that change we would have only 1 spot to place
					// thus we must save spots for that new focus
					if(remainder == 2 && ch.x >= r.w - 2) break;

					// 2.
					// This means we must change row. Should probably not happen, since the
					// rectangle should be maximized in size.
					if(ch.x >= r.w) break;

					// 3.
					// This means we have to put at least 2 spots here, and then subsequently we would still
					// have to change focus because of sit. 1, therefore we would've walked into a corner.
					if(ch.x == 0 && remainder == 3 && ch.x + 1 >= r.w - 2) break;

					f.clearSpot(ch.x, ch.y);
					ch.x++;
					remainder--;
				}
			}

			if(cv.x < width) {
				while(remainder > 0) {
					// Situations are the same, coordinates are just flipped
					if(remainder == 2 && cv.y >= r.h - 2) break;
					if(cv.y >= r.h) break;
					if(cv.y == 0 && remainder == 3 && cv.y + 1 >= r.h - 2) break;

					f.clearSpot(cv.x, cv.y);
					cv.y++;
					remainder--;
				}
			}

			ch.x = 0;
			ch.y++;

			cv.x++;
			cv.y = 0;

			if(rs == remainder) return null;
		}

		f.click.x = 0;
		f.click.y = 0;

		return f;
	}

	public static void main(String[] args) {
		/*
		int w = 3;
		int h = 5;
		int t = 4;
		Field f = solveCase2(w, h, t);
		if(f == null) {
			System.out.println("No solution found!");
		} else {
			if(!f.isSolution(t)) {
				System.out.println("WARNING! SOLUTION NOT VALID!");
				System.out.println(f.levelsToString());
			}
			f.layout[f.click.x][f.click.y] = 'c';
			System.out.println("Click at: " + f.click.x + ";" + f.click.y);
			System.out.println(f.layoutToString());
		}
		//*/

		/*
		int total = 0;
		int solved = 0;
		int failed = 0;
		for(int w = 1; w < 50; ++w) for(int h = 1; h < 50; ++h) for(int t = 0; t < 230; ++t) {
			if(total % 3000 == 0) {
				System.out.println(total + "/" + (50*50*50*50/4) + " completed");
			}
			Field f = solveCase2(w,h,t);
			if(f == null) {
				failed++;
			} else {
				solved++;
				if(!f.isSolution(t)) {
					System.err.println("SEVERE, NOT A SOLUTION SUBMITTED!");
					System.out.println(f.layoutToString());
					System.out.println(f.levelsToString());
					System.out.println(f.click.x + ";" + f.click.y);
					System.out.println("case:" + w + " " + h + " " + t);
					System.exit(0);
				}
			}
			total++;
		}

		System.out.println("DONE " + total + " " + solved + " " + failed);
		//*/

		///*
		String infile;
		if(args.length == 0) {
			Scanner scn = new Scanner(System.in);
			infile = scn.nextLine();
		} else {
			infile = args[0];
		}

		InputStream is;

		try {
			is = new FileInputStream(infile);

			solve(is);

			is.close(); 
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//*/
	}
}
