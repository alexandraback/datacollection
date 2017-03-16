import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class MinesweeperMaster {

	/**
	 * @param args
	 */
	public static void main(String[] args) {		
		if(args.length>0)
		try {
			System.setIn(new FileInputStream(args[0]));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
		Scanner in = new Scanner(System.in);
	
		int T = in.nextInt();
		
		for(int iCase=1;iCase<=T;iCase++){
			int R=in.nextInt();
			int C=in.nextInt();
			int M=in.nextInt();
			int min=R>1&&C>1?4:2;//minimum number of non-mine cells
			String ans="";
			int clickCol=C-1;
			int clickRow=R-1;
			//System.out.print(""+R+","+C+","+M+":");
			try{
				if(R*C-min<M && !(M==0 || M==R*C-1)) throw new Exception("\nImpossible");
				if((R==2 || C==2) && M%2==1 && !(R*C-M==1||M==0)) throw new Exception("\nImpossible");
				if((R>1&&C>1) && (R*C-M)<9 && (R*C-M)%2==1 && !(R*C-M==1||M==0)) throw new Exception("\nImpossible");
				char b[][] = new char[R][C];//board
				for(int i=0;i<R;i++)
					for(int j=0;j<C;j++)
						b[i][j]='.';
				int i=0;
				int j=0;
				for(int k=0;k<M;k++){//placing the bombs
					b[i][j]='*';
					if(i<R-2){
						if(j<C-1) j++;
						else {i++;j=0;}
					}else{
						if(i<R-1) i++;
						else {i=R==1?0:R-2;j++;}
					}
				}
				//fixing
				if(j==C-1 && !(R*C-M==1||M==0) && C!=1){
					b[i][j-1]='.';
					i++;j=0;
					b[i][j]='*';
					if(i==R-2){
						b[i-1][C-3]='.';
						b[R-1][j]='*';
					}
				}
				//fixing
				if(i==R-1 && R!=1 && C!=1 && !(R*C-M==1||M==0)){//if 2d min of 9bombs required
					b[R-3][C-1]='.';//moving the odd BOMBS!!!
					b[R-3][C-2]='.';
					b[R-3][C-3]='.';
					b[i][j]='*';
					b[i-1][j+1]='*';
					b[i][j+1]='*';
				}
				b[clickRow][clickCol]='c';
				for(int n=0;n<R;n++) ans+="\n"+new String(b[n]);
			}catch(Exception e){
				ans=e.getMessage();
			}
			//int count=0;
			//for(int i=0;i<ans.length();i++) if(ans.charAt(i)=='*') count++;
			System.out.println("Case #" + iCase + ": "+ ans);
		}
			

	}

}
