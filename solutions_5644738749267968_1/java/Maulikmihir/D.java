package p4;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class D {
	
	
		public static void main(String args[]){
			
			try{
			
				BufferedReader br = new BufferedReader(new FileReader(args[0]));
				
				String strTmp = br.readLine();
				
				BufferedWriter bw = new BufferedWriter(new FileWriter( new File("output.txt"),false));
				
				
				int inputSize = Integer.parseInt(strTmp);
				
				
				for(int i=0;i<inputSize;i++  ){

				
					// processing inputline
					int N = Integer.parseInt( br.readLine() );
					
					String[] strNaomi = br.readLine().split(" ");
					String[] strKen   = br.readLine().split(" ");
					
					double dNaomi[] = new double[N];
					double dKen[]   = new double[N];
					
					for(int j=0;j<N;j++){
						dNaomi[j] = Double.parseDouble(strNaomi[j]);
						dKen[j]   = Double.parseDouble(strKen[j]);
					}
					
					Arrays.sort(dNaomi);
					Arrays.sort(dKen);
					
					// produce output
					int warPoint = 0 ;
					int deceitfulWarPoint = 0 ;
					
					
					// Play War
					int tailNaomi = N-1, headNaomi = 0, tailKen= N-1, headKen = 0 ;
					
					for(int j=0;j<N;j++){
						
						if( dNaomi[headNaomi] > dKen[headKen]  ){
							deceitfulWarPoint++;
							headNaomi++;
							headKen++;
						}else{
							headNaomi++;
							tailKen--;
						}
					}
					
					// Play Deceitful War
					
					tailNaomi = N-1; 
					headNaomi = 0;
					tailKen= N-1;
					headKen = 0 ;
					
					for(int j=0;j<N;j++){
						
						if( dNaomi[tailNaomi] > dKen[tailKen]  ){
							warPoint++;
							tailNaomi--;
							headKen++;
						}else{
							int k=0;
							for( k=tailKen ; k>headKen ; k--){
								if(dNaomi[tailNaomi] > dKen[k] ){
									break;
								}
							}
							
							if(k+1<N){
								dKen[k+1]=0 ;
								Arrays.sort(dKen);
								tailNaomi--;
								headKen++;
							}	
							
						}
					}
					
					
					

		
					System.out.println("Case #"+(i+1)+": "+	deceitfulWarPoint + " " + warPoint );			

					bw.write("Case #"+(i+1)+": "+ deceitfulWarPoint + " " + warPoint );
					bw.newLine();
				}
				
				bw.close();
				br.close();
			
			
			}catch(Exception ex){
				ex.printStackTrace();
			}
		}
		

}
