import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class B {



	public static void main(String args[]){
		
		try{
		
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			String strTmp = br.readLine();
			BufferedWriter bw = new BufferedWriter(new FileWriter( new File("output.txt"),false));
			
			
			int inputSize = Integer.parseInt(strTmp);
			
			for(int i=0;i<inputSize;i++  ){

				// processing inputline
				strTmp = br.readLine();
				int N = Integer.parseInt(strTmp);
				
				int[] oneStar = new int[N];
				int[] twoStar = new int[N];
				int[] achieved_star = new int[N];
				
				
				for (int j=0 ; j<N ; j++  ){
					String[] line = br.readLine().split(" ");
					oneStar[j] = Integer.parseInt(line[0]);
					twoStar[j] = Integer.parseInt(line[1]);
					achieved_star[j] = 0;
				}
				
				boolean isChange = true;
				int stars = 0;
				int res = 0;
				while(isChange){
					isChange = false;
					
					// loop for 2 star
					for( int j=0;j<N;j++ ){
						
						if( twoStar[j]<= stars && achieved_star[j]!=2 ){
							
							if( achieved_star[j]==1 ){
								stars+=1;
							}else{
								stars+=2;
							}
							achieved_star[j]=2;
							res+=1;
							isChange = true;
						}
					}
					
					if(isChange){
						continue;
					}
					
					// loop for 1 star
					int max_1 = 0;
					int max_2 = -1;
					for( int j=0;j<N;j++ ){
						
						if( oneStar[j]<= stars && achieved_star[j]==0 ){
							
							if(max_2 < twoStar[j] ){
								max_2 = twoStar[j];
								max_1 = j ;
							}
							isChange = true;
						}
					}
					
					if(isChange){
						stars+=1;
						res+=1;
						achieved_star[max_1]=1;
					}
					
				}
				
				
				
								
				//Check the achieved star array
				String result = Integer.toString(res) ;
				for(int j=0;j<N ; j++){
					if(achieved_star[j]!=2){
						result="Too Bad";
						break;
					}
				}
				
				
				
				// produce output
                System.out.println("Case #"+(i+1)+": " + result );			
				bw.write("Case #"+(i+1)+": " + result);
				bw.newLine();
			}
			
			bw.close();
			br.close();
		
		
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	


}
