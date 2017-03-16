import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in;
		try {
			in = new Scanner(new File("C:\\temp\\google\\C-large.in"));
			int T = in.nextInt();
			for(int cas=1; cas<=T; cas++) {
				
				int R_o = in.nextInt();
				int C_o = in.nextInt();
				int M = in.nextInt();
				
				int R=R_o;
				int C=C_o;
				boolean reverseDirection=(R_o>C_o);
				
				if (reverseDirection) {
					R=C_o;
					C=R_o;
				}
					
				
				int requitedempty = R*C-M;
				int emptycolumn = requitedempty/R;
				
				System.out.printf("Case #%d:\n", cas);
				
				int remaining=requitedempty-emptycolumn*R; //safer way
				
				if(emptycolumn<2) {
					if (requitedempty==0) {
						System.out.printf("Impossible\n");
					}else {
						if (R==1) {
							//anything will be good
							printMap(R,C,reverseDirection,emptycolumn,0,0,0,0);
						}else {
							if (requitedempty==1) {
								//good - one point
								printMap(R,C,reverseDirection,0,0,0,0,0);
							}else if (( requitedempty%2 ==0) &&(requitedempty>2))   // need adjustment.
							{
								//good, two columns
								printMap2Column(R,C,reverseDirection,requitedempty,0,0,0);
							}else {
								if (requitedempty/2 >3) {
									printMap2Column(R,C,reverseDirection,requitedempty,3,0,0);
								}else
									System.out.printf("Impossible\n");
							}
								
						}
					}
						
				}else {
					if (R==1) {
						//anything will be good
						printMap(R,C,reverseDirection,emptycolumn,0,0,0,0);
					}else if (R==2) {
						// only even will be good
						if ( requitedempty%2 ==0) {
							//good, two columns
							printMap2Column(R,C,reverseDirection,requitedempty,0,0,0);
						}else {
							System.out.printf("Impossible\n");
						}
					}else { //R>=3
						if (remaining==1) {
							if (emptycolumn==2) {
								//good, remove 2. add 3
								if (R>3)
									printMap(R,C,reverseDirection,emptycolumn,remaining,2,0,0);
								else
									System.out.printf("Impossible\n");
							}else {
								//all good -- minus one from last column
								printMap(R,C,reverseDirection,emptycolumn,remaining,1,0,0);
							}
						}else {
							//all good
							printMap(R,C,reverseDirection,emptycolumn,remaining,0,0,0);
						}	
					}	
				}
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void printMap(int R,int C, boolean reverseDirection, int emptycolumn, int remaining, int missingLastColumn,int clickX, int clickY) {
		if (reverseDirection) {
			for (int x=0;x<C;x++) {
				for (int y=0;y<R;y++) {
					if ((y==clickX) && (x==clickY)) {
						System.out.printf("c");
					}else {
						if (x<emptycolumn) {
							if ((y==R-1) && (x >= emptycolumn-missingLastColumn)) 
								System.out.printf("*");
							else
								System.out.printf(".");
						}else if (x>emptycolumn) {
							System.out.printf("*");
						}else {
							if (y< remaining+missingLastColumn)
								System.out.printf(".");
							else 
								System.out.printf("*");
						}
					}
				}
				System.out.printf("\n");
			}
			
		}else {
			for (int y=0;y<R;y++) {
				for (int x=0;x<C;x++) {
					if ((x==clickX) && (y==clickY)) {
						System.out.printf("c");
					}else {
						if (x<emptycolumn) {
							if ((y==R-1) && (x >= emptycolumn-missingLastColumn)) 
								System.out.printf("*");
							else
								System.out.printf(".");
						}else if (x>emptycolumn) {
							System.out.printf("*");
						}else {
							if (y< remaining+missingLastColumn)
								System.out.printf(".");
							else 
								System.out.printf("*");
						}
					}
				}
				System.out.printf("\n");
			}
		}
	}
	
	public static void printMap2Column(int R,int C, boolean reverseDirection, int total,int remain, int clickX, int clickY) {
		if (reverseDirection) {
			for (int x=0;x<C;x++) { 
				for (int y=0;y<R;y++) { 
					if ((x==clickY) && (y==clickX)) {
						System.out.printf("c");
					}else {
						if (( (x< (total-remain)/2) && (y<2)) ||( (y==2) && (x<remain)))
							System.out.printf(".");
						else 
							System.out.printf("*");
					}
				}
				System.out.printf("\n");
			}
			
		}else {
			for (int y=0;y<R;y++) { 
				for (int x=0;x<C;x++) {  
					if ((x==clickX) && (y==clickY)) {
						System.out.printf("c");
					}else {
						if (( (x< (total-remain)/2) && (y<2)) ||( (y==2) && (x<remain)))
							System.out.printf(".");
						else 
							System.out.printf("*");
					}
						
				}
				System.out.printf("\n");
			}
		}
	}

}
