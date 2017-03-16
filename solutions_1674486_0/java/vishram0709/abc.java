import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class abc {
	public static void main(String args[]) 
	{
		int vertex = 0;
		int tcount =0;
		try{
			  // Create file 
			  FileWriter fstream = new FileWriter("A-small-attempt0.out");
			  BufferedWriter out = new BufferedWriter(fstream);
			 
		
      
		
		 Scanner myfile;
		try {
			myfile = new Scanner(new FileReader("A-small-attempt0.in"));
				 int testcases = myfile.nextInt();
         while (testcases != 0 || myfile.hasNextInt())  
         {          // Read file content using a while loop
        	
        	 
        	 vertex = myfile.nextInt();
        
        	 int[][] arr = new int[vertex][vertex];
        	 
        	 for(int i=0;i<vertex;i++)
        	 {
        		for(int j=0;j<vertex;j++)
        		{
        			arr[i][j] = 0;
        		}
        		 int edge = myfile.nextInt();
        		 for(int j=0;j<edge;j++)
        		 {
        			 int connectedto = myfile.nextInt();
        			 arr[i][connectedto-1] = 1;
        		 }
        		 
        	 }
        	 
        	 
        	 int flag =0;
        	 for (int k = 0; k < vertex; k++)
        	 {
       	      for (int i = 0; i < vertex; i++) 
       	      {
       	    	 
        	        for (int j = 0; j < vertex; j++) 
        	        {
        	        	
        	        	//System.out.println(i+""+j);
        	        	if(i==j)
        	        		continue;
        	        	else if(arr[i][j]!= 0 && arr[i][k]!= 0 && arr[k][j]!=0 && k!=j &&  k!=i )
        	        	{
        	        		
        	        		{
        	        			//System.out.println(i+""+j+""+k);
        	        			
        	        			flag = 1;
        	        			break;
        	        		}
        	        		
        	        	}
        	        	else
        	        	{
        	        		if(arr[i][k]!=0 && arr[k][j]!=0)
        	        		arr[i][j] = 1;
        	        	}
        	        	
        	        	
        	  
        	       }
        	      //  System.out.println(arr[k][i]);
        	        //arr[i][j] = Math.min(path[i][j], path[i][k] + path[k][j]);
       	      }
       	     
        	 }
        	 
        	 
        	 if(flag ==1)
        		 out.write("Case #"+ ++tcount+": "+"Yes\n");
        	 else
        		 out.write("Case #"+ ++tcount+": "+"No\n");
        	 
        	 testcases--;
        	}

		  
         
         myfile.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} // Reading file using Scanner

		out.close();
		}catch (Exception e){//Catch exception if any
			  System.err.println("Error: " + e.getMessage());
			  }
		
		
	}

	
}
