package temp;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class C3 {

	/**
	 * @param args
	 */
	static char[][] f;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int casess = sc.nextInt();
		for(int cases=1;cases<=casess;cases++){
			System.out.println("Case #"+cases+":");

			int R = sc.nextInt(),C=sc.nextInt(),M=sc.nextInt();
			int space = R*C-M;
			if(R==1&&C==1){
				if(M==1){
					System.out.println("Impossible");
				}
				else{
					System.out.println("c");
				}
			}
			else if(R==1||C==1){
				
				if(output1(R,C,space)){
					outputField(f);
				}
				else{
					System.out.println("Impossible");
				}
			}
			else{
				if(output(R,C,space)){
					outputField(f);
				}
				else{
					System.out.println("Impossible");
				}
			}
		}			
	}
	static boolean output1(int R,int C,int space){
		if(space==0)return false;
		f = new char[R][C];
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				f[i][j]='*';
			}
		}
		f[0][0]='c';
		if(space==1){
			return true;
		}
		if(R==1){
			f[0][1]='.';
		}
		else{
			f[1][0]='.';
		}
		space-=2;

		L:for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(space==0)break L; 
				if(f[i][j]!='*')continue;
				f[i][j]='.';
				space--;
			}
		}
		return true;
	}
	static boolean output(int R,int C,int space){
		if(space==0||space==2||space==3||space==5||space==7){
			return false;
		}

		if((R==2&&C>2) || (R>2&&C==2)){
			if(space>=2 && space%2==1){
				return false;
			}
		}


		f = new char[R][C];
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				f[i][j]='*';
			}
		}
		f[0][0]='c';
		if(space==1){
			return true;
		}
		f[0][1]='.';
		f[1][1]='.';
		f[1][0]='.';
		space-=4;
		int[] lim = {R,C};
		int[] t = {2,2};
		int p = 0;
		for(;;){
			if(t[0]==lim[0]&&t[1]==lim[1])break;
			if(t[0]==lim[0]&&t[1]==lim[1])break;
			if(space<2)break;
			if(t[p]==lim[p]){
				p=1-p;
				continue;
			}
			if(p==0)
				f[t[p]][0]=f[t[p]][1]='.';
			else{
				f[0][t[p]]=f[1][t[p]]='.';
			}
			t[p]++;
			space-=2;
			p = 1-p;

		}
		if((t[0]-2)*(t[1]-2) < space){
			return false;
		}

		for(int i=2;i<t[0];i++){
			for(int j=2;j<t[1];j++){
				if(space<=0)break;
				f[i][j]='.';
				space--;
			}
		}
		return true;
	}
	static boolean check(char[][] f,int space){
		int[][] field=new int[f.length][f[0].length];
		int[] v1 = {1,1, 1, 0,-1,-1,-1,0};
		int[] v2 = {1,0,-1,-1,-1, 0, 1,1};
		for(int i=0;i<field.length;i++){
			for(int j=0;j<field[0].length;j++){

				if(f[i][j]=='*'){
					field[i][j]=10;

					continue;
				}
				int cnt=0;
				for(int k=0;k<8;k++){
					int ii = i + v1[k];
					int jj = j + v2[k];
					if(ii<0||ii>=field.length||jj<0||jj>=field[0].length)continue;
					if(f[ii][jj]=='*'){
						cnt++;
					}
				}
				field[i][j]=cnt;
			}
		}
		Queue<int[]>q=new LinkedList<int[]>();
		q.add(new int[]{0,0});
		field[0][0]=-10;
		while(!q.isEmpty()){
			int y = q.peek()[0];
			int x = q.poll()[1];
			for(int k=0;k<8;k++){
				int yy = y + v1[k];
				int xx = x + v2[k];
				if(yy<0||yy>=field.length||xx<0||xx>=field[0].length)continue;
				if(field[yy][xx]!=-10){
					if(field[yy][xx]==0){
						field[yy][xx]=-10;
						q.add(new int[]{yy,xx});
					}
					else if(field[yy][xx]>0){
						field[yy][xx]*=-1;
					}
				}
			}
		}
//		outputField(field);
		for(int i=0;i<field.length;i++){
			for(int j=0;j<field[0].length;j++){
				if(field[i][j]>0 && f[i][j]!='*'){
					return false;
				}

			}
		}
		return true;
	}
	static void err(){
		for(int i=0;i<10;i++){
			System.err.println("*******************");
		}
	}
	static void outputField(char[][] field){
		for(int i=0;i<field.length;i++){
			for(int j=0;j<field[0].length;j++){
				System.out.print(field[i][j]);
			}
			System.out.println();
		}
	}
	static void outputField(int[][] field){
		for(int i=0;i<field.length;i++){
			for(int j=0;j<field[0].length;j++){
				System.out.print(field[i][j]+" ");
			}
			System.out.println();
		}
	}
}
