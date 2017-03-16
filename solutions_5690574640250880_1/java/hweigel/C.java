import java.util.Arrays;
import java.util.Scanner;


public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		outer: for(int kases=1;kases<=T;kases++) {
			System.out.println("Case #"+kases+":");
			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();
			int F = R*C-M;

			char [][] board = new char[R][C];
			for(int i=0;i<R;i++)
				Arrays.fill(board[i],'*');
			if(F!=1) {
				if(R==1) {
					for(int i=0;i<F;i++) {
						board[0][i]='.';
					}
				}
				else if(C==1) {
					for(int i=0;i<F;i++) {
						board[i][0]='.';
					}
				}
				else if(F==2 || F==3 || F==5 || F==7) {
					System.out.println("Impossible");
					continue outer;
				}
				else if(R==2) {
					if(F%2==1) {
						System.out.println("Impossible");
						continue outer;
					}
					if(F%2==0) {
						for(int i=0;i<F/2;i++) {
							board[0][i]='.';
							board[1][i]='.';
						}
					}
				}
				else if(C==2) {
					if(F%2==1) {
						System.out.println("Impossible");
						continue outer;
					}
					if(F%2==0) {
						for(int i=0;i<F/2;i++) {
							board[i][0]='.';
							board[i][1]='.';
						}
					}				
				}			
				else if(R>=3 && C>=3) {
					if(F<=8) {
						switch(F) {
						case 8:
							board[2][0]='.';
							board[2][1]='.';
						case 6:
							board[0][2]='.';
							board[1][2]='.';
						case 4:
							board[0][0]='.';
							board[1][0]='.';
							board[0][1]='.';
							board[1][1]='.';							
						}
					}
					else if(F<= R*C - (R-2)*(C-2)) {
						for(int i=0;i<3;i++) {
							for(int j=0;j<3;j++) {
								board[i][j]='.';
							}
						}
						F-=8;
						if(F%2==0)
							board[2][2]='*';
						else
							F--;
						int i=3;
						while(F>0 && i<R) {
							board[i][0]='.';
							board[i][1]='.';
							i++;
							F-=2;
						}
						i=3;
						while(F>0 && i<C) {
							board[0][i]='.';
							board[1][i]='.';
							F-=2;
							i++;
						}
					}
					else {
						for(int i=0;i<R;i++) {
							board[i][0]='.';
							board[i][1]='.';
						}
						for(int i=0;i<C;i++) {
							board[0][i]='.';
							board[1][i]='.';
						}
						F-=2*R+2*C-4;
						int diag=0;
						int i=0;
						int j=0;
						while(F>0) {
							if(j<0 || i+2==R) {
								diag++;
								j=Math.min(C-3, diag);
								i=diag-j;
							}
							board[i+2][j+2]='.';
							i++;
							j--;
							F--;
						}
					}
				}
			}
			board[0][0]='c';
			for(int i=0;i<R;i++) {
				String s="";
				for(int j=0;j<C;j++) {
					s+=board[i][j];
				}
				System.out.println(s);
			}
		}
	}

}
