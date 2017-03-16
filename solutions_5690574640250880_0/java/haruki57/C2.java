package temp;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class C2 {

	/**
	 * @param args
	 */
	static int R,C,M,space;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int casess = sc.nextInt();
		for(int cases=1;cases<=casess;cases++){
			System.out.println("Case #"+cases+":");
			
			R = sc.nextInt();C=sc.nextInt();M=sc.nextInt();
			space = R*C-M;
			char[][] mx = new char[R][C];
			cp=new char[R][C];
			if(rec(mx,0,0,0)){
				outputField(mx);
				
			}
			else{
//				System.out.println(R+" "+C+" "+M);
				System.out.println("Impossible");
				
			}

		}			
	}
	static int cnt=0;
	static boolean rec(char[][] mx,int r,int c,int mine){
		if(mine>M)return false;
		if(c==C){
			c=0;
			r++;
			if(r==R){
				if(mine!=M)return false;
//				outputField(mx);
//				System.out.println(cnt++);
				if(check(mx)){
					return true;
				}
				return false;
			}
		}
		mx[r][c]='.';
		if(rec(mx,r,c+1,mine)){
			return true;
		}
		mx[r][c]='*';
		if(rec(mx,r,c+1,mine+1)){
			return true;
		}
		return false;
	}
	static char[][] cp;
	static boolean check(char[][] mx){
		copy(mx,cp);
		for(int i=0;i<mx.length;i++){
			for(int j=0;j<mx[0].length;j++){
				if(cp[i][j]=='.'){
					cp[i][j]='c';
					if(isOK(cp,i,j,mx)){
						return true;
					}
					copy(mx,cp);
				}
			}
		}
		return false;
	}
	static boolean isOK(char[][] mx,int y,int x,char[][] origin){
		Queue<int[]> q = new LinkedList<int[]>();
		q.add(new int[]{y,x});
		mx[y][x]=1;
		int cnt=countMine(mx,y,x);
		int spaces = 0;
		while(!q.isEmpty()){
			int yyy = q.peek()[0];
			int xxx = q.poll()[1];
			cnt=countMine(mx,yyy,xxx);
			spaces++;
			if(cnt==0){
				for(int i=0;i<8;i++){
					int yy = yyy+v1[i];
					int xx = xxx+v2[i];
					if(yy<0||yy>=mx.length||xx<0||xx>=mx[0].length)continue;
					if(mx[yy][xx]=='.'){
						q.add(new int[]{yy,xx});
						mx[yy][xx]=1;
					}
				}
			}
		}
		if(spaces==space){
			origin[y][x]='c';
			return true;
		}
		else{
			return false;
		}
		/*
		for(int i=0;i<mx.length;i++){
			for(int j=0;j<mx[0].length;j++){
				if(mx[i][j]==1 && origin[i][j]!='.'){
					return false;
				}
				if(mx[i][j]!=1 && origin[i][j]=='.'){
					return false;
				}
				if(mx[i][j]==1 && origin[i][j]=='*'){
					return false;
				}
			}
		}
		origin[y][x]='c';
		return true;
		*/
	}
	static int[] v1 = {1,1, 1, 0,-1,-1,-1,0};
	static int[] v2 = {1,0,-1,-1,-1, 0, 1,1};
	static int countMine(char[][] mx,int y,int x){
		int cnt=0;
		for(int i=0;i<8;i++){
			int yy = y+v1[i];
			int xx = x+v2[i];
			if(yy<0||yy>=mx.length||xx<0||xx>=mx[0].length)continue;
			if(mx[yy][xx]=='*'){
				cnt++;
			}
		}
		return cnt;
	}
	static void copy(char[][] mx,char[][]cp){
		for(int i=0;i<mx.length;i++){
			for(int j=0;j<mx[0].length;j++){
				cp[i][j]=mx[i][j];
			}
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
}
