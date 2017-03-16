import java.io.File;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.FileReader;


public class ProbB {

	static String inputfile = "B-small.in";
	static String outputfile = "B-small.out";

		public static void main(String args[]) throws Exception {
			
			BufferedReader in = new BufferedReader(new FileReader(inputfile));
			PrintWriter out = new PrintWriter(new FileWriter(outputfile));
	
			String line = in.readLine();
			String[] inputdata =line.split(" ");

			int TCASES = Integer.parseInt(inputdata[0]);
			
			int[] a = new int[1000];
			int[] b = new int[1000];
			int[] c = new int[1000];
			int[] d = new int[1000];

			for (int i=1;i<=TCASES;i++){	

				line = in.readLine();
				inputdata =line.split(" ");
				int N = Integer.parseInt(inputdata[0]);

				for (int j=0;j<N;j++){
					line = in.readLine();
					inputdata =line.split(" ");
					a[j]=Integer.parseInt(inputdata[0]);
					b[j]=Integer.parseInt(inputdata[1]);
					c[j]=0;
					d[j]=0;
				}

				int played=0;
				int currlevel=0;
				int done=0;

				boolean flag=false;
				mainloop:
				while (!flag){
				
				//Go through 2star
				done=0;
				for (int j=0;j<N;j++){
					if (b[j]<=currlevel && d[j]==0) {
						d[j]=1; 
						done++;
						played++;
						if (c[j]==1) currlevel++;
						else currlevel+=2;
						continue mainloop;
					}
					if (d[j]==1) done++;

				}
				
				
				if (done==N) {flag=true; break;}

				//Go through 1star
				int maxearn=0;
				int bestindex=-1;
				for (int j=0;j<N;j++){
					if (a[j]<=currlevel && c[j]==0){
						if (maxearn==0) {maxearn=1; bestindex=j;}
						else if (bestindex!=-1 && d[bestindex]==1) bestindex=j;
						else if (bestindex!=-1 && b[bestindex]<b[j]) bestindex=j;
						
											
					}
				}
						
				//PLay 1 star

				if (bestindex!=-1) {c[bestindex]=1; currlevel++; played++;}
				else flag=true;

				
				}

				String ans = (done!=N) ?"Too Bad":Integer.toString(played);
				out.println("Case #"+i+": "+ans);

			}

			in.close();
			out.flush();
			out.close();

		}
}
