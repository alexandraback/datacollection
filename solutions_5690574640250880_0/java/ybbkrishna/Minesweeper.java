import java.util.Scanner;


public class Minesweeper {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int j=0;j<n;j++) {
			int r =sc.nextInt(),
				c = sc.nextInt(),
				m=sc.nextInt();
			if(r*c-m==1) {
				System.out.println("Case #"+(int)(j+1)+":");
				String a[][] = new String[r][c];
				completeFill(a,r-1,c-1,"*");
				printAll(a, r-1, c-1);
			}
			else if(r<2||c<2) {
				if(((r*c) - m) <2) {
					System.out.println("Case #"+(int)(j+1)+":");
					System.out.println("Impossible");
				}
				else {
					System.out.println("Case #"+(int)(j+1)+":");
					draw(r,c,m);
				}
			}
			else if(((r*c) - m) <4) {
				System.out.println("Case #"+(int)(j+1)+":");
				System.out.println("Impossible");
			}
			else {
				System.out.println("Case #"+(int)(j+1)+":");
				if(r==3&&m==2&&c==3|| r==2&&m==1 || c==2&&m==1) {
					System.out.println("Impossible");
				}
				else {
					draw(r,c,m);
				}
			}
		}
	}
	public static void draw(int r,int c, int m) {
		String a[][] = new String[r][c];
		int norow=r-1,nocol=c-1;
		completeFill(a,norow,nocol,".");
		int startR=0,startC=0;
		int red = 2;
		norow = r;
		nocol = c;
		int row=r,col=c;
		boolean first = true;
		boolean print =true;
		while(m>0&&norow>0&&nocol>0) {
			if(m<norow&&m<nocol) {
				if(norow>nocol) {
					norow=norow-red;
					//startR = startR + red;
				}
				else {
					nocol=nocol-red;
					//startC = startC + red;
				};
				red=1;
			}
			else {
				int[] temp = squareFill(a, norow, nocol, startR, startC, m,row,col,first);
				norow = temp[0];
				nocol = temp[1];
				startR =r- temp[0];
				startC =c -temp[1];
				row = temp[3];
				col = temp[4];
				m = temp[2];
				red=2;
				//System.out.println(norow + " "+ nocol+ " "+m);
				if(norow==3&&nocol==3&&m==2 || norow==2&&m==1 || nocol==2&&m==1) {
					print =false;
					System.out.println("Impossible");
					break;
				}
			}
			first = false;
		}
		//rectFill(a, 1, r, 1, c);
		if(print)
			printAll(a, r-1, c-1);
	}
	public static void completeFill(String[][] a,int row,int col,String x) {
		for(int i=0;i<=row;i++) {
			for(int j=0;j<=col;j++) {
				a[i][j] = x;
			}
		}
		a[row][col] = "c";
	}
	public static void printAll(String[][] a,int row,int col) {
		for(int i=0;i<=row;i++) {
			for(int j=0;j<=col;j++) {
				System.out.print(a[i][j]);
			}
			System.out.println();
		}
	}
	public static int[] squareFill(String[][] a,int norow,int nocol,int startR,int startC,int m,int r, int c, boolean first) {
		if(norow < nocol) {
			int fil = 1;
			/*if(fil>nocol-2&&first) {
				m = m%norow + ((fil-nocol+2)*norow);
				fil = nocol-2;
			}
			else {
				m = m - ;
			}*/
			m = m - norow;
			for(int i=startR;i<startR+norow;i++) {
				for(int j=startC;j<startC+fil;j++) {
					a[i][j] = "*";
				}
			}
			nocol= nocol-fil;
			c = nocol;
			norow = r;
		}
		else {
			int fil = 1;
			/*if(fil>norow-2&&first) {
				m = m%nocol + ((fil-norow+2)*nocol);
				fil = norow-2;
			}
			else {
				m = m%nocol;
			}*/
			m = m-nocol;
			for(int i=startR;i<startR+fil;i++) {
				for(int j=startC;j<startC+nocol;j++) {
					a[i][j] = "*";
				}
			}
			norow = norow-fil;
			r= norow;
			nocol = c;
		}
		return new int[] {norow,nocol,m,r,c};
	}
}
