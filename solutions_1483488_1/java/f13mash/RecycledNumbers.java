import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class RecycledNumbers {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=cases;t++){
			String[] inp=br.readLine().trim().split(" ");
			int start=Integer.parseInt(inp[0]);
			int end=Integer.parseInt(inp[1]);
			System.out.println("Case #"+t+": "+getAns(start, end));
		}
	}
	
	public static long getAns(int start, int end){
		boolean[] visited=new boolean[end+1];
		long total=0;
		int max=0;
		
		int digitCount=1;
		int mult=10;
		while(start/(mult) !=0){
			digitCount++;
			mult*=10;
		}
		for(int n=start;n<=end;n++){

			int count=1;
			if(visited[n])
				continue;
			
			visited[n]=true;
			for(int s=1;s<digitCount;s++){
				int o=n;
				int fst=(int) Math.pow(10, s), oth=(int) Math.pow(10, digitCount-s);
				int rem=o%fst;
				o/=fst;
				o+=(rem*oth);
				if(o>=start && o<=end && !visited[o]){
					if(rem/(Math.pow(10,digitCount-s-1))>0){
						if(o!=n){
							count++;
							visited[o]=true;
						}
					}
				}
			}
			total+=count*(count-1)/2;
			
		}
		return total;
	}

}
