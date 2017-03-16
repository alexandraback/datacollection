import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;


public class A_3 {
	
	public static void main(String args[]){
		
		try{
		
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			String strTmp = br.readLine();
			BufferedWriter bw = new BufferedWriter(new FileWriter( new File("output.txt"),false));
			
			
			int inputSize = Integer.parseInt(strTmp);
			
			for(int i=0;i<inputSize;i++  ){
				
				System.out.println("Case #"+(i+1)+":" );			
				bw.write("Case #"+(i+1)+":");
				bw.newLine();

				// processing inputline
				strTmp = br.readLine();
				String[] line = strTmp.split(" ");
				int R = Integer.parseInt(line[0]);
				int N = Integer.parseInt(line[1]);
				int M = Integer.parseInt(line[2]);
				int K = Integer.parseInt(line[3]);
				
				// producing output
				
				for(int j=0;j<R;j++){
					strTmp = br.readLine();
					line = strTmp.split(" ");
					
					int[] num = new int[K];
					int[] output = new int[N];
					int ind = 0;
					
					for(int k=0;k<K;k++){
						num[k] = Integer.parseInt(line[k]);
					}
					
					for(int n : num){
						
						if(n==1){
							continue;
						}
						
						while(n>1){
							
							for(int l=M;l>1;){
								
								if(n%l==0){
									output[ind++] = l ;
									n/=l;
									
									if(ind>=N){
										break;
									}
								}else{
									l--;
								}
							}
							
							if(ind>=N){
								break;
							}
							
						}
						
						if(ind>=N){
							break;
						}
						
						
					}
					
					if(ind<N-1){
						
						for(int l=ind;l<N;l++){
							output[l]=2;
						}
						
					}
					
					StringBuffer sb = new StringBuffer();
					
					for(int l=0;l<N;l++){
						sb.append(output[l]);
					}
					
					System.out.println(sb.toString());
					bw.write(sb.toString());
					bw.newLine();
					
				}
				
			}
			
			bw.close();
			br.close();
		
		
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}

}

