import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class mines {

	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("file.in"));
		PrintWriter printer=new PrintWriter("file.out");
		int T=Integer.parseInt(buf.readLine());
		for(int i=1;i<=T;i++){
			printer.println("Case #"+i+": ");
			int R,C,M;
			String[] s=buf.readLine().split(" ");
			R=Integer.parseInt(s[0]);
			C=Integer.parseInt(s[1]);
			boolean rot=false;
			if(R<C){
				rot=true;
				int t=C;
				C=R;
				R=t;
			}
			M=Integer.parseInt(s[2]);
			boolean[][] grid=new boolean[R][C];
			if(R==1||C==1){
				for(int j=0;j<M;j++)
					grid[j][0]=true;
				print(rot,printer,grid,R,C);
			}else{
				if(M+1==R*C){
					for(int j=0;j<R;j++)
						for(int k=0;k<C;k++)
							grid[j][k]=true;
					grid[R-1][C-1]=false;
					print(rot,printer,grid,R,C);
				}else{
					int M2=M;

					if(M2/C>=R-3){
						//case 1
						//System.out.print(i+",");
						grid=new boolean[R][C];
						for(int j=0;j<R-3;j++)
							for(int k=0;k<C;k++)
								grid[j][k]=true;

						int B=(M2-C*(R-3))%3;
						int A=(M2-C*(R-3))/3;
						//System.out.println(A+","+B);
						if(A+B<=C-2){
							for(int j=0;j<A;j++)
								for(int k=R-3;k<R;k++)
									grid[k][j]=true;
							for(int j=A;j<A+B;j++)
								grid[R-3][j]=true;
							print(rot,printer,grid,R,C);
							System.out.println(i+"~");
							continue;
						}

					}
					if(M2/C>=R-2&&(M2-C*(R-2))%2==0){
						//case 2
						grid=new boolean[R][C];
						for(int j=0;j<R-2;j++)
							for(int k=0;k<C;k++)
								grid[j][k]=true;
						int A=(M2-C*(R-2))/2;
						if(A<=C-2){
							for(int j=0;j<A;j++)
								for(int k=R-2;k<R;k++)
									grid[k][j]=true;
							print(rot,printer,grid,R,C);
							System.out.print(i+"!\n");
							continue;
						}
					}
					//case 3
					grid=new boolean[R][C];
					int base=-1;
					for(int j=0;j<R-4;j++)
						if(M2>=C){
							for(int k=0;k<C;k++)
								grid[j][k]=true;
							M2-=C;
							base=j;
						}
					int A=M2/2;
					int B=M2%2;
					if(A+B>C-2||A!=0&&R==3)
						printer.println("Impossible");
					else{
						for(int j=0;j<A;j++)
							for(int k=base+1;k<base+3;k++)
								grid[k][j]=true;
						if(B==1)
							grid[base+1][A]=true;
						print(rot,printer,grid,R,C);
					}
				}



			}

		}
		printer.close();
	}
	public static void print(boolean rot,PrintWriter p,boolean[][] grid,int R,int C){
		if(!rot)
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++)
					if(grid[i][j])
						p.print("*");
					else if(i==R-1&&j==C-1)
						p.print("c");
					else
						p.print(".");
				p.println();
			}
		else
			for(int j=0;j<C;j++){
				for(int i=0;i<R;i++)
					if(grid[i][j])
						p.print("*");
					else if(i==R-1&&j==C-1)
						p.print("c");
					else
						p.print(".");
				p.println();
			}
	}
}
