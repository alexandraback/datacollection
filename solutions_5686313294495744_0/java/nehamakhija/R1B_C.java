import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class R1B_C {
	
	public static void main(String[] args)throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int t=Integer.parseInt(br.readLine());
		
		for(int z=1; z<=t; z++){
			int n=Integer.parseInt(br.readLine());
			String topics[][]=new String[n][2];
			int fakes=0;
			for(int i=0; i<n; i++){
				topics[i]=br.readLine().split(" ");
				
			}
			for(int i=0; i<n; i++){
				int aob=0;
				int bob=0;
				for(int j=0; j<n; j++){
					if(j!=i){
						if(topics[j][0].equals(topics[i][0])){
							aob=1;
						}
						if(topics[j][1].equals(topics[i][1])){
							bob=1;
						}
						if(aob==1 && bob==1){
							fakes++;
							break;
						}
					}
				}
			}
			System.out.println("Case #"+z+": "+fakes);
		}
	}
}
