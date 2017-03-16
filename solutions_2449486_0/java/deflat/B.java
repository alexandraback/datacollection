import java.util.*;
import java.io.*;
public class B {
	
	int[][] map;
	int N,M;
	int[] linemax;
	int[] lineremain;
	
	/**************************************/
	void run(String inputfile){
	try{
		Scanner s;
		File file=new File("output.txt");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
		if(inputfile.equals("test")) s=new Scanner(System.in);
		else s=new Scanner(new FileInputStream(new File(inputfile)));
		int cases=s.nextInt();
		for(int X=0;X<cases;X++){
			pw.print("Case #"+(X+1)+": ");
	/**************************************/
			
			N=s.nextInt();
			M=s.nextInt();
			map=new int[N][M];
			linemax=new int[N+M];
			lineremain=new int[N+M];
			for(int i=0;i<N+M;i++){
				linemax[i]=-1;
				lineremain[i]=0;
			}
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					map[i][j]=s.nextInt();
					if(map[i][j]>linemax[i]){
						linemax[i]=map[i][j];
						lineremain[i]=1;
					}else if(map[i][j]==linemax[i]) lineremain[i]++;
					if(map[i][j]>linemax[N+j]){
						linemax[N+j]=map[i][j];
						lineremain[N+j]=1;
					}else if(map[i][j]==linemax[N+j]) lineremain[N+j]++;
				}
			}
			int linecount=N+M;
			int cellcount=N*M;
			while(linecount>0){
				int tg=-1;
				int tgnum=-1;
				for(int i=0;i<N+M;i++){
					if(linemax[i]>tgnum){
						tg=i;
						tgnum=linemax[i];
					}
				}
				int x,y,d,lim;
				if(tg<N){
					x=tg;
					y=0;
					d=0;
					lim=M;
				}else{
					x=0;
					y=tg-N;
					d=1;
					lim=N;
				}
				for(int i=0;i<lim;i++){
					if(map[x][y]==tgnum){
						map[x][y]=-1;
						cellcount--;
						if(tgnum==linemax[x]){
							lineremain[x]--;
							if(lineremain[x]==0){
								linemax[x]=-1;
								linecount--;
							}
						}
						if(tgnum==linemax[N+y]){
							lineremain[N+y]--;
							if(lineremain[N+y]==0){
								linemax[N+y]=-1;
								linecount--;
							}
						}
					}
					x+=d;
					y+=(1-d);
				}
			}
			if(cellcount==0) pw.println("YES");
			else pw.println("NO");
			
			

	/**************************************/
		}
		pw.close();
	}catch(IOException e){
		System.out.println(e);
		System.exit(0);
	}}
	/**************************************/
	public static void main(String[] args){
		
		new B().run(args[0]);
	}
}
