
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class pro2 {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main ( String [] args ) throws IOException
	{
	int N = Integer.parseInt(br.readLine());

	for(int i = 0;i < N; i++)
	System.out.println("Case #" + (i+1) + ": " + cal());
	}

	private static String cal() throws IOException {
		String[] buffer = br.readLine().split("\\s");
		int p=Integer.parseInt(buffer[2]);
		int winner=0;
		int s=Integer.parseInt(buffer[1]);
		int tempS=0;
	
		
		for(int i=0;i<Integer.parseInt(buffer[0]);i++){
			int score=Integer.parseInt(buffer[i+3]);
			if(score%3==0){
			    if(p<=(score/3))
				winner++;
							    
			    else if(p<=(score/3)+1 && tempS<s && (score/3)-1>=0){
				winner++;
				tempS++;
			    }
			}
			
			if(score%3==1)
			    if(p<=(score/3)+1)
				winner++;
		
			if(score%3==2){
			    if(p<=(score/3)+1)
			       winner++;

			    else if(p<=(score/3)+2 && tempS<s){
				winner++;
				tempS++;}
			    
			}				
		}
			

	return Integer.toString(winner);
	}

}