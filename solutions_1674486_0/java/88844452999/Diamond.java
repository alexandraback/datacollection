package jam;

import jam.Sol;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

import javax.sql.ConnectionPoolDataSource;

public class Diamond {
	public static void main(String[] x)throws IOException{
		
		  File file=new File("A-small-attempt1.in");
	        Writer output = null;
	        File out=new File("A.out");
	        output = new BufferedWriter(new FileWriter(out));
	        BufferedReader fileIn = new BufferedReader(new FileReader(file));
	        String fileLine,delims,outs;
	        String[] tokens;
	        int cases,i,j,N,M,k,c;
	        int classes[];int connections[][];
	        
	        fileLine=fileIn.readLine();
	        cases = Integer.parseInt(fileLine);
	        delims = "[ ]+";
	        System.out.println("Cases = "+cases);
	        for	(i=0;i<cases;++i)
	        {
	        output.write("Case #");
	        output.write(Integer.toString(i+1));
	        output.write(": ");
	    	fileLine=fileIn.readLine();
	    	N = Integer.parseInt(fileLine);
	    	classes = new int [N];
	    	connections = new int [N][N];
	    	for	(j=0;j<N;++j)
		    {
	    		for	(k=0;k<N;++k)
			    {
	    			connections [j][k] = 0;
			    }
		    }
	    	for	(j=0;j<N;++j)
		    {
	    		fileLine=fileIn.readLine();
		        tokens = fileLine.split(delims);
		        M = Integer.parseInt(tokens[0]);
		        for	(k=1;k<=M;++k)
			    {
		        	c = Integer.parseInt(tokens[k]);
		        	connections[j][c-1] = 1;
		        	//connections[c-1][j] = 1;
			    }
	    		 
		    }
	    	Sol Solu;
	    	Solu = new Sol(connections);
	    	String s = Solu.soln();
	        output.write(s);
	        output.write("\r\n");
	        System.out.println(s);
	        }
	        output.close();

	}


	
		

}
