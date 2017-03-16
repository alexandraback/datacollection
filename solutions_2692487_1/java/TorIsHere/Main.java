import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.Arrays;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String file_name = "A-large.in";
	    try {
	    	BufferedReader br = new BufferedReader(new FileReader(file_name));
	        StringBuilder sb = new StringBuilder();
	        
	        /**read numCase*/
	        String line = br.readLine();

	        int caseNumber = Integer.parseInt(line);
	        int caseCount = 0;
	        /**************/
	 
	       
	       
	        
	        
	       
	        line = br.readLine();
	       
	        while (line != null) {
	        	
	        	 
	        	
	        	String Armininput[] = line.split(" ");
		        
		        
		        
	        	/**read radius and paint*/
	        	
	        	
	        	
	        	long  ArminMote = Long.parseLong(Armininput[0]);
		       
	        
	        	line = br.readLine();
	        	
	        	String Motein[] = line.split(" ");
	        	 int[] Moteinput = new int[Motein.length]; 

	        	    for(int i=0; i<Moteinput.length; i++) {
	        	    	Moteinput[i] = Integer.parseInt(Motein[i]);
	        	    }
	        	int result = findresult(ArminMote,Moteinput);
	        	
	        	
	 	        /*************************/
		       
	        	
	        
		        
		        
		        /*************************/
	        	
	        	
	        	    
	     
	            	
	            	++caseCount;
	            	sb.append("Case #"+caseCount+": ");
	            	
	            	
	            		sb.append(result+"\n");
	            	
	            		//read next line
	            	 line = br.readLine();
	 		        
	 		  
	            
	        }
	      
	        try {
	 
				File file = new File("result.txt");
	 
				// if file doesnt exists
				if (!file.exists()) {
					file.createNewFile();
				}
	 
				FileWriter fw = new FileWriter(file.getAbsoluteFile());
				BufferedWriter bw = new BufferedWriter(fw);
				bw.write(sb.toString());
				bw.close();
				br.close();
	 
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
	    }catch(IOException x){
	    	System.out.println(x.getMessage());
	    }
	}

	public static int findresult(long Amote,int [] mote){
		int best = 0;
		int tempBest = 0;
		long sum = Amote;
		int limit = Integer.MAX_VALUE;
		Arrays.sort(mote);
		
		for(int i = 0;i<mote.length;i++){
			/*if(mote[i]<0)
			{
				break;
				
			}*/
			
			if(sum>mote[i])
			{
				sum += mote[i];
			}
			else if(sum+sum-1>mote[i])
			{
				best++;
				sum+= sum + mote[i] -1;
			}
			else
			{
				limit = mote.length - i;
				tempBest = best +limit;
				int count = 0;
				while(limit>0&&i<mote.length)
				{
					if(sum>mote[i]){
						sum+= mote[i];
						i++;
					}
					else{
						limit--;
						sum+= sum -1;
						count++;
						if(sum>mote[i]){
							sum+= mote[i];
							i++;
						
						}
					}
				}
				
				if(tempBest<best+count){
					return tempBest;
				}
				else{
					return best+count;
				}
				
			}
		}
		
		
		
		return best;
		
	}
	
}
