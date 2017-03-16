import java.text.DecimalFormat;
import java.io.*;
import java.util.Scanner;
import java.util.*;
import java.math.*;
class Solution{
	public static void main(String args[]) throws IOException{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i=0;i<cases;i++){
			int rc = in.nextInt(),cc=in.nextInt(),mc=in.nextInt();
			int r = rc,c=cc,m=mc;
			int arr[][] = new int[r][c];
			System.out.println("Case #"+(i+1)+":");
			if(r==1||c==1||((r*c)-1)==m){
//				System.out.println("Entering case 1");
				for(int j =0;j<r;j++){
					for(int k=0;k<c;k++){
						if(j==r-1&&k==c-1){System.out.print("c");}
						else if(m<=0){System.out.print(".");}
						else{m--;System.out.print("*");}
					}
					System.out.println();
				}
			}
			else if (((r*c)-4)<m){
					//impossible
				System.out.println("Impossible");
			}
			else {
					int flag = 0 ;
					if(m==0)flag=1;
					while(flag==0&&m!=0){
						//System.out.println("Mines :"+m);
						int min = (r<=c)?r:c;
						int max = (r>=c)?r:c;
						int xcord = rc - r ,ycord = cc - c;
						if(m<min){
							int flag1=0;
							int tempr=r-2,tempc=c-2;
							//System.out.println("temp r "+tempr+" col "+tempc);
										for(int j = xcord;j<xcord+tempr;j++){
											for(int k = ycord;k<ycord+tempc;k++){
												arr[j][k]=1;
												m--;
												if(m==0) break;
											}
											if(m==0)break;
										}
							if(m==0) flag=1;
							m=0;
						}
						else{
//								System.out.println("Fill in min ");
								// fill in the min
								if(r==min){
									for (int j = xcord;j<rc;j++){arr[j][ycord] = 1; m--; if (m<=0) break;}
									if(m!=0){c--;}
									// fill row
								}
								else{
									for (int j = ycord;j<cc;j++){arr[xcord][j] = 1; m--; if (m<=0) break;}
									if(m!=0){r--;}
									// fill col
								}
								if(m==0){flag=1;}
						}
					}
					if(flag==0)System.out.println("Impossible");
					else{
						for (int j=0;j<rc;j++){
							for(int k=0;k<cc;k++){
//								System.out.print(arr[j][k]);
								if(j==rc-1&&k==cc-1)
								System.out.print("c");
								else if(arr[j][k]==1)
								System.out.print("*");
								else
								System.out.print(".");
							}
							System.out.println();
						}
					}
				}
		}
	}
}
