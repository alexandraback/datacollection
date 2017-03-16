import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {

	public static void main(String[] args)throws Exception{
		System.setOut(new PrintStream("A.out"));
		BufferedReader br=new BufferedReader(new FileReader("B-small-attempt0.in"));
		StringTokenizer st;
		final int T = Integer.parseInt(br.readLine());
		c:for(int t=0;t<T;t++){
			System.out.print("Case #"+(t+1)+": ");
			st=new StringTokenizer(br.readLine()," ");
			final int N=Integer.parseInt(st.nextToken());
			final int M=Integer.parseInt(st.nextToken());
			int[] maxN=new int[N],maxM=new int[M];
			int[][] matrix=new int[N][M];
			for(int e=0;e<N;e++){
				st=new StringTokenizer(br.readLine()," ");
				for(int i=0;i<M;i++){
					matrix[e][i]=Integer.parseInt(st.nextToken());
					maxN[e]=Math.max(maxN[e],matrix[e][i]);
					maxM[i]=Math.max(maxM[i],matrix[e][i]);
				}
			}
			for(int e=0;e<N;e++)for(int i=0;i<M;i++)if(matrix[e][i]<maxN[e]&&matrix[e][i]<maxM[i]){
				System.out.println("NO");
				continue c;
			}
			System.out.println("YES");
		}
		br.close();
		System.out.close();
	}
}
