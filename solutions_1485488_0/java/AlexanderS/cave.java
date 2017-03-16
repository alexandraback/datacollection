import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class cave {

	
	static int n;
	static int m;
	static int[][] floors;
	static int[][] ceils;
	static int[][] mintimes;//times multiplied by 10
	static int h;
	
	
	
	static boolean isValid(int x, int y){
		return x>=0&&x<n&&y>=0&&y<m;
	}
	
	static boolean canmove(int x1, int y1, int x2, int y2){
		if(!isValid(x2,y2))return false;
		if(ceils[x1][y1]-floors[x2][y2]<50){
			return false;
		}
		if(ceils[x2][y2]-floors[x2][y2]<50){
			return false;
		}
		if(ceils[x2][y2]-floors[x1][y1]<50){
			return false;
		}
		if(ceils[x2][y2]-h<50){
			return false;
		}
		return true;
	}
	
	static boolean willmove(int x1, int y1, int x2, int y2){
		if(!isValid(x2,y2))return false;
		if(ceils[x1][y1]-floors[x2][y2]<50){
			return false;
		}
		if(ceils[x2][y2]-floors[x2][y2]<50){
			return false;
		}
		if(ceils[x2][y2]-floors[x1][y1]<50){
			return false;
		}
		return true;
	}
	
	static int getTime(int stime, int x1, int y1,int x2, int y2){//minimum time when you can reach point 2 from point 1
		if(stime==0&&canmove(x1,y1,x2,y2)){
			return 0;
		}
		if(!willmove(x1,y1,x2,y2)){
			return -1;
		}
		int sheight=h-stime;
		if(ceils[x2][y2]-sheight>=50){
			if(sheight-floors[x1][y1]>=20){
				return stime+10;
			}else{
				return stime+100;
			}
		}else{
			if(ceils[x2][y2]-floors[x1][y1]>=70){
				return (h-ceils[x2][y2]+50)+10;
			}else{
				return (h-ceils[x2][y2]+50)+100;
			}
		}
		
	}
	
	static void move(int x, int y){
		if(!isValid(x,y))return;
		int a=getTime(mintimes[x][y],x,y,x+1,y);
		if(a!=-1&&mintimes[x+1][y]==-1){
			mintimes[x+1][y]=a;
			move(x+1,y);
		}else if(a!=-1&&a<mintimes[x+1][y]){
			mintimes[x+1][y]=a;
			move(x+1,y);
		}
		
		a=getTime(mintimes[x][y],x,y,x-1,y);
		if(a!=-1&&mintimes[x-1][y]==-1){
			mintimes[x-1][y]=a;
			move(x-1,y);
		}else if(a!=-1&&a<mintimes[x-1][y]){
			mintimes[x-1][y]=a;
			move(x-1,y);
		}
		
		a=getTime(mintimes[x][y],x,y,x,y+1);
		if(a!=-1&&mintimes[x][y+1]==-1){
			mintimes[x][y+1]=a;
			move(x,y+1);
		}else if(a!=-1&&a<mintimes[x][y+1]){
			mintimes[x][y+1]=a;
			move(x,y+1);
		}
		
		a=getTime(mintimes[x][y],x,y,x,y-1);
		if(a!=-1&&mintimes[x][y-1]==-1){
			mintimes[x][y-1]=a;
			move(x,y-1);
		}else if(a!=-1&&a<mintimes[x][y-1]){
			mintimes[x][y-1]=a;
			move(x,y-1);
		}
	}
	
	
	
	
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(
				"C:\\Users\\Alex\\workspace\\chapter1\\prob.in.txt"));
		PrintWriter output = new PrintWriter(new BufferedWriter(new FileWriter(
				"C:\\Users\\Alex\\workspace\\chapter1\\prob.out.txt")));
		int num=Integer.parseInt(reader.readLine());
		for(int test=1;test<=num;test++){
			StringTokenizer st=new StringTokenizer(reader.readLine());
			output.print("Case #"+test+": ");
			h=Integer.parseInt(st.nextToken());
			n=Integer.parseInt(st.nextToken());
			m=Integer.parseInt(st.nextToken());
			floors=new int[n][m];
			ceils=new int[n][m];
			mintimes=new int[n][m];
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					mintimes[i][j]=-1;
				}
			}
			for(int i=0;i<n;i++){
				st=new StringTokenizer(reader.readLine());
				for(int j=0;j<m;j++){
					ceils[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			for(int i=0;i<n;i++){
				st=new StringTokenizer(reader.readLine());
				for(int j=0;j<m;j++){
					floors[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			mintimes[0][0]=0;
			move(0,0);
			output.println(mintimes[n-1][m-1]/10.0);
		}
		output.close();

	}

}
