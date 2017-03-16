package Qualif14;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class C {
	// get Pb Letter for input/output file names.
	public static String pbLetter;
	static {
		pbLetter=new Object() { }.getClass().getEnclosingClass().getName();
		int idx = pbLetter.lastIndexOf('.');
		if(idx != -1) pbLetter = pbLetter.substring(idx+1);
		pbLetter = pbLetter.toUpperCase();
	}
	public static int[] winning = {0xF,0xF0,0xF00,0xF000,0x1111,0x2222,0x4444,0x8888,0x1248,0x8421};

	public static void main(String[] args) throws Throwable {
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-small.in"));
		//System.out.println(System.getProperty("user.dir"));
		Scanner sc = new Scanner(new File("./"+pbLetter+"-small-attempt1.in"));

		//Scanner sc = new Scanner(new File("./"+pbLetter+"-large.in"));

		TeePrintStream out= new TeePrintStream(System.out, "./output-"+pbLetter+".txt");

		int testCount = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= testCount; i++) {
			out.format("Case #%d: ",i );
			solve(sc, out);
		}
		out.close();
	}

	static void solve(Scanner sc, PrintStream out) {
		out.println();
		int  row,col,mines;

		row = sc.nextInt();
		col= sc.nextInt();
		mines = sc.nextInt();
		if(mines == row*col) {
			out.println("Impossible");return;
		}
		if(mines == row*col -1) {
			for(int i=0; i<row-1 ;++ i) {
				for(int j=0; j<col ;++ j) {
					out.print("*");
				}
				out.println();
			}
			for(int j=0; j<col-1 ;++ j) {
				out.print("*");
			}
			out.println("c");
			return;
		}
		
		boolean transpose = false;
		if(col < row) {
			transpose = true;
			int tmp = row;
			row = col;
			col = tmp;
		}
		boolean[][] b= new boolean[row][col];
		if(row == 1) {
			if(mines >= col ) out.println("Impossible");
			else {
				int i;
				for (i=0; i < mines;++i) b[0][i]=true;
				for(;i < col-1;++i) b[0][i]=false;
			}
		} else if (row == 2) {
			if((row*col - mines)%2 ==0 ) {
				int left = (row*col - mines)/2;
				if(left == 1) {
					out.println("Impossible"); return;
				}
				int i;
				for(i=0; i<left ;++ i) {
					b[0][col-i-1] = false;
					b[1][col-i-1] = false;
				}
				for(; i<col ;++ i) {
					b[0][col-i-1] = true;
					b[1][col-i-1] = true;
				}
			} else { // odd and <>1
				out.println("Impossible"); return;
			}
		} else { //row>=3
			int left = row*col-mines;
			if (left == 2||left == 3 || left == 5 || left == 7) {
				out.println("Impossible"); return;
			}
			if(left>= 2*row +2) {
				int count = mines;
				for(int j=0 ; j <col ; ++j) {
					for (int i = 0 ; i< row;++i) {
						if(count-- > 0) b[i][j] = true;
						else b[i][j] = false;
						if(count == 0 && i== row-2) {
							b[i][j] = false;
							b[i+1][j] = false;
							count=1;
							break;
						}
					}
				}
			} else {
				for(int i=0 ; i <row ; ++i) {
					for(int j=0 ; j <col ; ++j) {
						b[i][j] = true;
					}
				}
				if(left%2 ==0) {
					int count = mines;
					for(int i=0 ; i <left/2 ; ++i) {
						b[row-1][col-1-i]=false;
						b[row-2][col-1-i]=false;
					}
				} else { // odd left (>=9)
					for(int i=1 ; i <=3 ; ++i) {
						for(int j=1; j <=3 ; ++j) {
							b[row-i][col-j] = false;
						}
					}
					left= (left-9)/2;
					for(int i=0 ; i <left ; ++i) {
						b[row-1][col-4-i] = false;
						b[row-2][col-4-i] = false;
					}
				}
				
			}
		}
			

		// display
		int j;
		if(transpose) {
			for(int i=0; i<col-1 ;++ i) {
				for(j=0; j<row ;++ j) {
					out.print(b[j][i] ? "*": ".");
				}
				out.println();
			}
			for(j=0; j<row-1 ;++ j) {
				out.print(b[j][col-1] ? "*": ".");
			}
			out.println("c");
		} else {
			for(int i=0; i<row-1 ;++ i) {
				for(j=0; j<col ;++ j) {
					out.print(b[i][j] ? "*": ".");
				}
				out.println();
			}
			for(j=0; j<col-1 ;++ j) {
				out.print(b[row-1][j] ? "*": ".");
			}
			out.println("c");
		}

	}



	static class TeePrintStream extends PrintStream {
		protected PrintStream parent;

		public TeePrintStream(PrintStream orig, OutputStream os, boolean flush)
				throws IOException {
			super(os, flush);
			parent = orig;
		}
		public TeePrintStream(PrintStream orig, String fn)
				throws IOException {
			this(orig, new FileOutputStream(fn), true);
		}

		public boolean checkError() {
			return parent.checkError() || super.checkError();
		}
		public void write(int x) {
			parent.write(x);
			super.write(x); 
		}

		/** override write(). This is the actual "tee" operation. */
		public void write(byte[] x, int o, int l) {
			parent.write(x, o, l); 
			super.write(x, o, l);
		}

		/** Close both streams. */
		public void close() {
			parent.close();
			super.close();
		}
		/** Flush both streams. */
		public void flush() {
			parent.flush();
			super.flush();
		}
	}
}