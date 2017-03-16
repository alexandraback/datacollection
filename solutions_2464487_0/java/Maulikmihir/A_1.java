import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;


public class A_1 {
	
	public static void main(String args[]){
		
		try{
		
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			String strTmp = br.readLine();
			BufferedWriter bw = new BufferedWriter(new FileWriter( new File("output.txt"),false));
			
			
			int inputSize = Integer.parseInt(strTmp);
			
			for(int i=0;i<inputSize;i++  ){

				
				// processing inputline
				strTmp = br.readLine();
				String[] line = strTmp.split(" ");
				long r = Long.parseLong(line[0]);
				long t = Long.parseLong(line[1]);
				
				// producing output
				long output = 0 ;
				long counter = 1 ;
				while(true){
					
					long requiredT = 2*r + counter ;
					
					if(t>=requiredT){
						t-=requiredT;
						output++;
						counter+=4;
					}else{
						break;
					}
				}
				
								
				
                System.out.println("Case #"+(i+1)+": " + output );			
				bw.write("Case #"+(i+1)+": " + output );
				bw.newLine();
				
			}
			
			bw.close();
			br.close();
		
		
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}

}

