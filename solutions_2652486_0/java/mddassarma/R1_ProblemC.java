import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class R1_ProblemC {

	public static String name="problemC";
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader(name+".txt"));
		PrintWriter printer=new PrintWriter(name+"_out.txt");
		int R=0;
		buf.readLine();
		String[] str=buf.readLine().split(" ");
		R=Integer.parseInt(str[0]);
		int N=Integer.parseInt(str[1]);
		int M=Integer.parseInt(str[2]);
		int K=Integer.parseInt(str[3]);
		int[][][][] allsets=new int[6][6][6][8];
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				for(int k=0;k<6;k++)
					for(int a=0;a<2;a++)
						for(int b=0;b<2;b++)
							for(int c=0;c<2;c++){
								allsets[i][j][k][a+b*2+c*4]=1;
								if(a==1)
									allsets[i][j][k][a+b*2+c*4]*=i;
								if(b==1)
									allsets[i][j][k][a+b*2+c*4]*=j;
								if(c==1)
									allsets[i][j][k][a+b*2+c*4]*=k;
							}
		printer.println("Case #1:");
		for(int i=1;i<=R;i++){
			
			str=buf.readLine().split(" ");
			int[][][] which=new int[6][6][6];
			boolean[][][] poss=new boolean[6][6][6];
			int max=0;
			int whichera=0;
			int whicherb=0;
			int whicherc=0;
			for(int j=0;j<K;j++){

				int t=Integer.parseInt(str[j]);
				for(int a=2;a<6;a++)
					for(int b=2;b<6;b++)
						for(int c=2;c<6;c++){
							boolean any=false;
							if(poss[a][b][c])
								continue;
							for(int d=0;d<8;d++){

								if(allsets[a][b][c][d]==t){
									which[a][b][c]++;
									if(which[a][b][c]>max){
										max=which[a][b][c];
										whichera=a;
										whicherb=b;
										whicherc=c;
									}
									any=true;
								}
							}
							if(!any)
								poss[a][b][c]=true;
						}


			}
			if(!poss[whichera][whicherb][whicherc]){
				max=0;
				for(int a=2;a<6;a++)
					for(int b=2;b<6;b++)
						for(int c=2;c<6;c++){
							//System.out.println(poss[a][b][c]+","+which[a][b][c]);
							if(!poss[a][b][c]&&which[a][b][c]>max){
								whichera=a;
								whicherb=b;
								whicherc=c;
								max=which[a][b][c];
							}
						}
			}
			printer.println(whichera+""+whicherb+""+whicherc);

		}
		printer.close();
	}
}
