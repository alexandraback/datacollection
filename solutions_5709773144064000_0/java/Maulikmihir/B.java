package p2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class B {
	
	
		public static void main(String args[]){
			
			try{
			
				double factor = 1e7; 
				
				BufferedReader br = new BufferedReader(new FileReader(args[0]));
				
				String strTmp = br.readLine();
				
				BufferedWriter bw = new BufferedWriter(new FileWriter( new File("output.txt"),false));
				
				
				int inputSize = Integer.parseInt(strTmp);
				
				
				for(int i=0;i<inputSize;i++  ){

				
					// processing inputline
					String[] inp = br.readLine().split(" ");
					double C = Double.parseDouble(inp[0]);
					double F = Double.parseDouble(inp[1]);
					double X = Double.parseDouble(inp[2]);
					double rate = 2.0 ;
					
					// produce output
					double current ;
					double next ;
					double total = 0.0 ;
					
					do{
						current = X/rate ;
						next = (C/rate) + (X/(rate+F));
						
						if (current>next){
							total += (C/rate) ;
						}else{
							total += (X/rate) ;
						}
						rate+=F ;
						
						
					}while(current>next);
					
					total = Math.round(total * factor) / factor;
					
					System.out.println("Case #"+(i+1)+": "+	total );			

					bw.write("Case #"+(i+1)+": "+ total );
					bw.newLine();
				}
				
				bw.close();
				br.close();
			
			
			}catch(Exception ex){
				ex.printStackTrace();
			}
		}
		

}
