import java.util.Arrays;
import java.util.Scanner;


public class DiamondInheritance {

	/**
	 * @param args
	 */
	static int[][] arr=new int[1000][1000];
	static int[][] aa=new int[1000][1000];
	static int[][] cc=new int[1000][1000];
	static int[][] dd=new int[1000][1000];
	static boolean diamond;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int cases=in.nextInt()+1;
		for(int tt=1;tt<cases;tt++){
			diamond=false;
			int size=in.nextInt();
			for(int i=0;i<size;i++){
				int paths=in.nextInt();
				for(int j=0;j<size;j++){
					arr[i][j]=0;
					aa[i][j]=0;
					cc[i][j]=0;
					dd[i][j]=0;
				}
				for(int j=0;j<paths;j++){
					int way=in.nextInt()-1;
					arr[i][way]=1;
					dd[i][way]=1;
					aa[i][way]=1;
				}
			}
			for(int i=0;i<size;i++){
				matmul(size);
				if(diamond){
					System.out.printf("Case #%d: Yes\n", tt);
					break;
				}
			}
			if(!diamond){
				System.out.printf("Case #%d: No\n", tt);
			}
		}
	}
	public static void matmul(int size){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cc[i][j]=0;
				for(int k=0;k<size;k++){
					cc[i][j]+=aa[i][k]*arr[k][j];
				}
			}
		}
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				aa[i][j]=cc[i][j];
				dd[i][j]+=cc[i][j];
				if(dd[i][j]>1){
					diamond=true;
					return;
				}
			}
		}
	}

}
