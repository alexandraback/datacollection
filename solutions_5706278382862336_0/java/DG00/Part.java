import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Part {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		  try {
	            // TODO code application logic 
	            BufferedReader reader = new BufferedReader(new FileReader("E:\\CODE PRACTICE\\codejam\\A-small-attempt2.in"));
	            BufferedWriter writer = new BufferedWriter(new FileWriter("E:\\CODE PRACTICE\\codejam\\ans.out"));
	            int T = Integer.parseInt(reader.readLine());
	            for (int i = 1; i <= T; i++)
	            {   
	            	int count =0,	count1 = 0;                
	                String[] s = reader.readLine().split("/");
	           long a = Integer.parseInt(s[0]) , a1 = Integer.parseInt(s[0]);
	          long b= Integer.parseInt(s[1]) ,b1= Integer.parseInt(s[1]);
	            
	           
	                  while (a%b != 0 )
	                  {
	                	  a = a*2;
	                	  count++;
	                	  
	                  }
	                  if(count<=40){
	                	  while(a1/b1 <1){
	                		  a1=a1*2;
	                		  count1 ++;
	                		                                      
	                	  }
	                	  writer.write("Case #"+i+": " +count1);
		                  writer.newLine();
	                  }
	                  else{
	                	  writer.write("Case #"+i+": " +"impossible");
		                  writer.newLine();
	                  }
	            }
	          
	          
	          
	            reader.close();
	            writer.close();
	        } catch (Exception ex) {
	            Logger.getLogger(A2013.class.getName()).log(Level.SEVERE, null, ex);
	        }
		
		
		
		
		
		
		
		

	}

}
