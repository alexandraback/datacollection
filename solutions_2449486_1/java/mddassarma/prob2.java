import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class prob2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("prob2_i.txt"));
		PrintWriter printer=new PrintWriter("prob2.txt");
		
		int T=Integer.parseInt(buf.readLine());
		for(int i=1;i<T+1;i++){
			printer.print("Case #"+i+": ");
			boolean done=false;
			int[][] grid;
			String[] s=buf.readLine().split(" ");
			int N=Integer.parseInt(s[0]);
			int M=Integer.parseInt(s[1]);
			grid=new int[N][M];
			for(int j=0;j<N;j++)
			{
				s=buf.readLine().split(" ");
				for(int k=0;k<M;k++)
					grid[j][k]=Integer.parseInt(s[k]);
			}
			for(int j=0;j<N;j++){
				for(int k=0;k<M;k++)
				{
					boolean worksleft=true;
					boolean worksup=true;
					for(int l=0;l<Math.max(M, N);l++)
					{
						if(l<N&&grid[l][k]>grid[j][k])
							worksleft=false;
						if(l<M&&grid[j][l]>grid[j][k])
							worksup=false;
						if(!(worksleft||worksup)){
							done=true;
							printer.println("NO");
							break;
						}
						if(done)
							break;
					}
					if(done)
						break;
				}
				if(done)
					break;
			}
			if(done)
				continue;
			printer.println("YES");
		}
		printer.close();
		

	}

}
