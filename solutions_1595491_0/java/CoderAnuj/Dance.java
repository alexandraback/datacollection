import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;


public class Dance {

	static int getMaxGooglers(int N,int S, int p, int[] t) {
		int count=0;
		int surpriseCount=0;
		
		int avg=p*3;
		for(int i=0;i<N;i++) {
			
			/*if(t[i]>=avg)
				count++;
			
			else */
			if(t[i]>=p) {
				if(t[i]>=avg-2)
			
				count++;
			
			else if(surpriseCount<S)
			{
				if(t[i]>=avg-4) {
					count++;
					surpriseCount++;
				}
			}
			}
		}
		return count;
	}
	public static void main(String args[]) {
		try {
			BufferedReader br=new BufferedReader(new InputStreamReader(new FileInputStream("c:\\gcj\\B\\B-small-attempt1.in")));
			String line=br.readLine();
			PrintStream ps=new PrintStream("c:\\gcj\\B\\B-small1.out");
			
			int n=Integer.parseInt(line);
				for(int i=1;i<=n;i++) {
					
					line=br.readLine();				
					String[] nums=line.split(" ");
					int N=Integer.parseInt(nums[0]);
					int S=Integer.parseInt(nums[1]);
					int P=Integer.parseInt(nums[2]);
					int t[]=new int[N];
					for(int j=0;j<N;j++)
					{
						t[j]=Integer.parseInt(nums[j+3]);
					}
					ps.println("Case #"+i+": "+getMaxGooglers(N, S, P, t));
											
				}
			} 
			catch(Exception e) {
				e.printStackTrace();
			}
			
			
		}
		

	public static void ain(String[] args) {
		// TODO Auto-generated method stub
		
		int N=2;
		int S=1;
		int p=1;
		int[] t={8,0};
		System.out.println(" count : " + getMaxGooglers(N, S, p, t));
	}

}
