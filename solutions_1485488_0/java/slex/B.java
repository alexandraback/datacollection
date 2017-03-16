import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class B {

	Scanner scan;
	InputStream in;
	int[][]F;
	int[][]C;
	int n,m;
	int H;
	int[][]dir = {{-1,0},{1,0},{0,-1},{0,1}};
	boolean[][]starting;
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	boolean can(int x1,int y1,int x2, int y2, int h){
		if(x2<0||x2>=n||y2<0||y2>=m)return false;
		if(F[x1][y1]+50 > C[x2][y2])return false;
		if(F[x2][y2]+50 >C[x2][y2])return false;
		if(h+50 > C[x2][y2])return false;
		if(F[x2][y2]+50 >C[x1][y1])return false;
		return true;
	}
	
	double gap(int x1, int y1, int x2, int y2){
		if(!can(x1,y1,x2,y2,0))return -1;
		if(can(x1,y1,x2,y2,H))return -1;
		double d = H - (C[x2][y2]-50-1e-9);
		return d/10;
	}
	
	void go(int x, int y){
		if(starting[x][y])return;
		starting[x][y]=true;
		for(int d=0;d<4;d++){
			int x2=x+dir[d][0];
			int y2=y+dir[d][1];
			if(can(x,y,x2,y2,H))go(x2,y2);
		}
		
	}
	
	double solve(){
		H=scan.nextInt();n=scan.nextInt();m=scan.nextInt();
		F = new int[n][m];
		C=new int[n][m];
		starting = new boolean[n][m];
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			C[i][j]=scan.nextInt();
		}
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)F[i][j]=scan.nextInt();
		
		TreeSet<Double>G = new TreeSet<Double>();
		for(int x=0;x<n;x++)for(int y=0;y<m;y++){
			for(int d=0;d<4;d++){
				int x2=x+dir[d][0];
				int y2=y+dir[d][1];
				double g = gap(x,y,x2,y2);
				if(g>-1)G.add(g);
			}
		}
		go(0,0);
		int[][]T = new int[n][m];
		for(int[]t:T)fill(t,1000000000);
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(starting[i][j])T[i][j]=0;
		for(int k=0;k<=10000;k++){
			int ch = H-k;
			if(ch<0)break;
			for(int x=0;x<n;x++)for(int y=0;y<m;y++){
				if(T[x][y]>k)continue;
				for(int d=0;d<4;d++){
					int x2=x+dir[d][0];
					int y2=y+dir[d][1];
					
					if(!can(x,y,x2,y2,ch))continue;
					if(T[x2][y2] <T[x][y])continue;
					int mt = 0;
					if(F[x][y]+20 <=ch)mt = 10;
					else mt = 100;
					T[x2][y2]=min(T[x2][y2],k+mt);
				}
			}
		}
		for(int k=0;k<=10000;k++){
			for(int x=0;x<n;x++)for(int y=0;y<m;y++){
				if(T[x][y]>k)continue;
				for(int d=0;d<4;d++){
					int x2=x+dir[d][0];
					int y2=y+dir[d][1];
					
					if(!can(x,y,x2,y2,0))continue;
					if(T[x2][y2] <T[x][y])continue;
					if(T[x][y]<H)continue;
					int mt = 100;
					
					T[x2][y2]=min(T[x2][y2],T[x][y]+mt);
				}
			}
		}
		return T[n-1][m-1]/10.0;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			double r =solve();
			System.out.format("Case #%d: %f\n",i+1,r);
		}
	}
	
	B() throws Exception{
		String cn = B.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt3.in";
		String largeName = cn+"-large.in";
		InputStream in = new BufferedInputStream(new FileInputStream(smallName));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new B().solveAll();
	}

}
