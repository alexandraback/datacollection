import java.lang.Math;

public class MineSweeper{
	static int R,C,M;
	static String[] sets;
	static String result="";
	static char[][] output;

	public static void main(String[] args){
		sets=args[0].split("\n");
		int T= Integer.parseInt(sets[0]);
		for (int board=0;board<T;board++)
		set(board);

		System.out.println("\nOutput\n"+result);
	}

	public static void set(int board){
		String[] roundSet=sets[board+1].split(" ");
		R=Integer.parseInt(roundSet[0]);
		C=Integer.parseInt(roundSet[1]);
		M=Integer.parseInt(roundSet[2]);

		if (!test()) result+=
			"Case #"+(board+1)+":\nImpossible\n";
		else printPossible(board+1);
	}

	public static boolean test(){
		output=new char[R][C];
		initOutput();
		output[0][0]='c';
		if(R*C-M==1) return true;
		if (M>=R*C) return false;
		if (R==1){
			for (int col=1;col<C;col++){
				if (col<C-M) output[0][col]='.';
				else output[0][col]='*';
			}
			return true;
		} else if (C==1){
			for (int line=1;line<R;line++){
				if (line<R-M) output[line][0]='.';
				else output[line][0]='*';
			}
			return true;
		} else {
			int N=R*C-M;
			if (N < 4 ||N==5||N==7){
				return false;
			}
			int N2=N/2;
			boolean even=(N%2==0);

			output[1][0]='.';
			output[0][1]='.';
			output[1][1]='.';

			if (R==2){
				if (!even) return false;
				for (int col=2;col<N/2;col++){
					output[0][col]='.';
					output[1][col]='.';
				}
				return true;
			} else if (C==2){
				if (!even) return false;
				for (int ln=2;ln<N/2;ln++){
					output[ln][0]='.';
					output[ln][1]='.';
				}
				return true;
			}

			if (N2 <=C){
				if (even){
					for (int col=2;col<N2;col++){
						output[0][col]='.';
						output[1][col]='.';
					}
					return true;
				} else {
					for (int col=1;col<N2-1;col++){
						output[0][col]='.';
						output[1][col]='.';
					}
					output[2][0]='.';
					output[2][1]='.';
					output[2][2]='.';
					return true;
				}
			} else {
				for(int col=2;col<C;col++){
						output[0][col]='.';
						output[1][col]='.';
				}
				N2-=C;
				N-=2*C;
				if (N2 <=R-2){
					if (even){
						for (int ln=0;ln<N2;ln++){
							output[ln+2][0]='.';
							output[ln+2][1]='.';
						}
						return true;
					} else {
						for (int ln=0;ln<N2;ln++){
							output[ln+2][0]='.';
							output[ln+2][1]='.';
						}
						output[2][2]='.';
						return true;
					}
				} else {
					for (int ln=2;ln<R;ln++){
						output[ln][0]='.';
						output[ln][1]='.';
						N2--;
						N-=2;
					}

					for(int ln=2;ln<R;ln++){
						for (int col=2;col<C;col++){
							output[ln][col]='.';
							N--;
							if (N==0) return true;
						}
					}
				}

			}

		}
		return false;
	}

	public static void initOutput(){
		for(int ln=0;ln<R;ln++){
			for (int col=0;col<C;col++){
				output[ln][col]='*';
			}
		}
	}

	public static void printPossible(int board){
		result+="Case #"+board+":\n";
		for(int ln=0;ln<R;ln++){
			for (int col=0;col<C;col++){
				result+=Character.toString(output[ln][col]);
			}
			result+="\n";
		}
	}

	/*
	public static void testMineField(){
		System.out.println("\n\n Test "+ R +" "+ C +"\n");
		for(int ln=0;ln<R;ln++){
			for (int col=0;col<C;col++){
				System.out.print(Character.toString(output[ln][col]));
			}
			System.out.println("");
		}
	}
	*/

}