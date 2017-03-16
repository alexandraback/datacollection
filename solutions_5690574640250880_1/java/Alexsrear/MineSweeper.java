package codejam;

import java.awt.Point;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class MineSweeper {
	
	int rows,cols,mines;
	
	public MineSweeper(RandomAccessFile rafin) throws Exception{
		String inputline;
		StringTokenizer st;
		
		inputline = rafin.readLine();
		st = new StringTokenizer(inputline," ");
		rows = Integer.parseInt(st.nextToken());
		cols = Integer.parseInt(st.nextToken());
		mines = Integer.parseInt(st.nextToken());
	}
	
	public MineSweeper() {
		// TODO Auto-generated constructor stub
	}

	public String getStatus() {
		//StringBuffer sb = new StringBuffer("");
		
		int fills = rows*cols - mines;
		if (fills<=0) return "\r\nImpossible";
		
		List<int[][]> boardCandidates = null;
		
		/*
		if (fills<mines) {
			boardCandidates = getBoards(rows, cols, fills, 0, -1);
		} else
			boardCandidates = getBoards(rows, cols, mines, -1, 0);
		*/
		boardCandidates = getBoards(rows, cols, fills, 0, -1);
		List<int[][]> boardCandidates2 = getBoards(rows, cols, mines, -1, 0);
		for (int i=0; i<boardCandidates2.size(); i++)
			boardCandidates.add(boardCandidates2.get(i));
			
		//boardCandidates = getBoards(rows,cols,mines);
		System.out.println(boardCandidates.size() + " boards!");
		
		for (int i=0; i<boardCandidates.size(); i++) {
			int[][] board = boardCandidates.get(i);
			
			
			//System.out.println("Board " + i);
			/*
			System.out.println(toString(boardCandidates.get(i)));
			System.out.println("");
			*/
			
			completeBoard(board);
			//System.out.println("completed!");
			Point p = checkBoard(board);
			//System.out.println("checked!");
			if (p!=null) //{
				return "\r\n" + toStatusString(p, board);
				//System.out.println("Board VALID!");
				//System.out.println(toStatusString(p, board));
			//} else
				//System.out.println("Board IN-Valid!");
				 
				 
		}
		
		return "\r\nImpossible";
		//return sb.toString();
	}
	
	public String toStatusString(Point pstart, int[][] board) {
		StringBuffer sb = new StringBuffer("");
		for (int i=0; i<board.length; i++) { 
			for (int j=0; j<board[0].length; j++) {
				if (i==pstart.x && j==pstart.y) 
					sb.append("c");
				else {
					if (board[i][j] < 0)
						sb.append("*");
					else
						sb.append(".");
				}
			}
			if (i<board.length-1) sb.append("\r\n");
		}
		
		return sb.toString();
	}
	
	public List<int[][]> getBoards(int rows, int cols, int mines) {
		List<int[][]> list = new ArrayList<int[][]>();
		int count = rows*cols;
		long max = 1 << count;
		int nonzerobit;
		int cboard=0;
		for (long i=0; i<max; i++) {
			nonzerobit = countNonZeroBit(i);
			if (nonzerobit == mines) {
				int[][] board = longToArray(i, rows,cols,0, -1);
				list.add(board);
				cboard++;
			}
		}
		
		System.out.println(cboard + " boards");
		return list;
	}
	
	public int countNonZeroBit(long l) {
		int count=0;
		long x;
		for (int i=0; i<63; i++) {
			x = l&1;
			if (x==1)
				count++;
			l = l >> 1;
		}
		return count;
	}
	
	public int[][] longToArray(long l, int rows, int cols, int fill0, int fill1) {
		int[][] board = new int[rows][cols];
		int count = rows*cols;
		int r,c;
		long x;
		for (int i=0; i<count; i++) {
			r = i/cols;
			c = i%cols;
			x = l&1;
			board[r][c] = (x==0? fill0: fill1);
			l = l>>1;
		}
		return board;
	}
	
	public int countAmongArray(int[][] is, int x) {
		int count=0;
		for (int i=0; i<is.length; i++)
			for (int j=0; j<is[0].length; j++)
				if (is[i][j]==x) count++;
		return count;
	}
	
	public List<int[][]> getBoards(int rows, int cols, int smallpart, int smallfill, int bigfill) {
		List<int[][]> list = new ArrayList<int[][]>();
		
		if (smallpart==0) {
			int[][] is = new int[rows][cols];
			for (int i=0; i<rows; i++) 
				for (int j=0; j<cols; j++)
					is[i][j] = bigfill;
			list.add(is);
			return list;
			
		}
		int rc,cc;
		
		for (rc=1; rc<=rows; rc++) {
			for (cc=1; cc<=cols; cc++) {
				if (rc*cc>smallpart) continue;
				int left = smallpart-rc*cc; 
				if (left >= Math.max(rc,cc)) continue;
				if (left==0) {
					int[][] is = new int[rows][cols];
					for (int i=0; i<rows; i++) {
						for (int j=0; j<cols; j++) {
							if (i<rc && j<cc)
								is[i][j] = smallfill;
							else
								is[i][j] = bigfill;
						}
					}
					list.add(is);
				}
				else {
					if (left<rc && cc<cols) {
						int[][] is = new int[rows][cols];
						for (int i=0; i<rows; i++) {
							for (int j=0; j<cols; j++) {
								if (i<rc && j<cc)
									is[i][j] = smallfill;
								else
									is[i][j] = bigfill;
							}
						}
						for (int i=0; i<left; i++)
							is[i][cc] = smallfill;
						list.add(is);
					}
					if (left<cc && rc<rows) {
						int[][] is = new int[rows][cols];
						for (int i=0; i<rows; i++) {
							for (int j=0; j<cols; j++) {
								if (i<rc && j<cc)
									is[i][j] = smallfill;
								else
									is[i][j] = bigfill;
							}
						}
						for (int i=0; i<left; i++)
							is[rc][i] = smallfill;
						list.add(is);
					}
				}
			}
		}
		return list;
	}
	
	public void completeBoard(int[][] board) {
		int r = board.length; 
		int c = board[0].length;
		int x;
		
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (board[i][j] >= 0) {
					board[i][j] = 0;
					x = 0;
					for (int k=Math.max(0, i-1); k<=Math.min(r-1, i+1); k++)
						for (int l=Math.max(0, j-1); l<=Math.min(c-1, j+1); l++)
							x += board[k][l]<0? board[k][l]: 0;
					board[i][j] = -1*x;
				}
			}
		}
	}
	
	public Point checkBoard(int[][] board) {
		HashMap<Point,String> dealed = new HashMap<Point,String>();
		HashMap<Point,String> waitdealed = new HashMap<Point,String>();
		ArrayList<Point> undeallist = new ArrayList<Point>();
		int mcount = 0;
		int opencount = 0;
		int r = board.length;
		int c = board[0].length;
		Point pStart=null;
		Point pOnly=null;
		
		boolean[][] bs = new boolean[r][c];
		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++) {
				bs[i][j] = false;
				if (pOnly==null && board[i][j]>=0)
					pOnly = new Point(i,j);
				if (pStart==null && board[i][j]==0)
					pStart = new Point(i,j);
				if (board[i][j]==-1)
					mcount++;
			}
		
		if (mcount == r*c-1) {
				return pOnly;
		}
		
		if (pStart==null)
			return null;
		
		bs[pStart.x][pStart.y] = true;
		opencount++;
		undeallist.add(pStart);
		
		while (undeallist.size()>0) {
			Point p = undeallist.get(0);
			Point p1;
			dealed.put(p, null);
			for (int k=Math.max(0, p.x-1); k<=Math.min(r-1, p.x+1); k++)
				for (int l=Math.max(0, p.y-1); l<=Math.min(c-1, p.y+1); l++) {
					if (k!=p.x || l!=p.y) {
						if (bs[k][l]==false) {
							bs[k][l] = true;
							opencount++;
						}
						if (board[k][l]==0) {
							p1 = new Point(k,l);
							if (dealed.containsKey(p1) == false) {
								if (waitdealed.containsKey(p1) == false) {
									undeallist.add(p1);
									waitdealed.put(p1, null);
								}
							}
						}
					}
				}
			undeallist.remove(0);
			//System.out.println(opencount + " opened...");
		}
		
		System.out.println(mcount + " mines.");
		System.out.println(opencount + " opened.");
		System.out.println(toString(bs));
		
		if (opencount+mcount == r*c)
			return pStart;
		
		return null;
	}

	public String toString(int[][] is) {
		StringBuffer sb = new StringBuffer("");
		sb.append("[");
		for (int j=0; j<is.length; j++) {
			if (j>0) sb.append(" ");
			sb.append("[");
			for (int i=0; i<is[0].length; i++) {
				if (i>0)
					sb.append(",");
				sb.append(is[j][i]);
			}
			sb.append("]");
		}
		sb.append("]");
		return sb.toString();
	}

	public String toString(boolean[][] bs) {
		StringBuffer sb = new StringBuffer("");
		for (int j=0; j<bs.length; j++) {
			for (int i=0; i<bs[0].length; i++) {
				if (bs[j][i]==true)
					sb.append(1);
				else
					sb.append(0);
			}
			sb.append("\r\n");
		}
		return sb.toString();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			
			/*
			MineSweeper ms = new MineSweeper();
			
			long l = 63;
			System.out.println(ms.countNonZeroBit(l));
			int[][] is = ms.longToArray(l, 5, 5, 0, -1);
			System.out.println(ms.toString(is));
			if (true) return;
			*/
			
			long oldtime = System.currentTimeMillis();
			
			String infilename="d:/codejam/data/C-large.in";
			String outfilename="d:/codejam/data/C-large.out";
			//String infilename="d:/codejam/data/MineSweeper.in";
			//String outfilename="d:/codejam/data/MineSweeper.out";
			RandomAccessFile rafin = new RandomAccessFile(infilename, "r");
			RandomAccessFile rafout = new RandomAccessFile(outfilename, "rw");
			rafout.setLength(0);
			
			int count = Integer.parseInt(rafin.readLine().trim());
			MineSweeper o;
			System.out.println(count + " cases.");
			for (int i=1; i<=count; i++) {
				o = new MineSweeper(rafin);
				rafout.writeBytes("Case #" + i + ": " + o.getStatus());
				if (i<count)
					rafout.writeBytes("\r\n");
				System.out.println("Case " + i + " dealed!");
				System.gc();
			}
			
			rafin.close();
			rafout.close();
			
			long newtime = System.currentTimeMillis();
			double seconds = (double)(newtime-oldtime)/1000;
			System.out.println(seconds + " seconds");
		} catch (Exception e) {
			e.printStackTrace(System.out);
		}

	}

}
