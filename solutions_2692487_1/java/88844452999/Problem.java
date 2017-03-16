package jam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Problem {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		 File file=new File("A-large.in");
	        Writer output = null;
	        File out=new File("A-large.out");
	        output = new BufferedWriter(new FileWriter(out));
	        BufferedReader fileIn = new BufferedReader(new FileReader(file));
	        String fileLine,delims,outs;
	        String[] tokens;
	        String str;
	        int cases,i,j,opers,armin,motecount;
	        ArrayList<Integer> motes;
	        
	      
	        fileLine=fileIn.readLine();
	        cases = Integer.parseInt(fileLine);
	        delims = "[ ]+";
	        System.out.println("Cases = "+cases);
	        for	(i=0;i<cases;++i)
	        {
	        	fileLine=fileIn.readLine();
	        	tokens = fileLine.split(delims);
	        	armin = Integer.parseInt(tokens[0]);
	            motecount = Integer.parseInt(tokens[1]);
	            System.out.println("armin  = " + armin + " motes = " + motecount);
	            fileLine=fileIn.readLine();
	            tokens = fileLine.split(delims);
	            motes = new ArrayList<Integer>();
	            for(j=0;j<motecount;++j)
	            {
	            	motes.add(Integer.parseInt(tokens[j]));
	            }
	            
	        	output.write("Case #");
	        	output.write(Integer.toString(i+1));
	        	output.write(": ");
	        	opers = solve(armin,motes);
	        	 	
	        	//fileLine =  check(state);
	        	System.out.println(opers);
	        	output.write(Integer.toString(opers));
	        	output.write("\r\n");
	     	       
	        }
	        output.close();
	  }

	private static int solve(int armin, ArrayList<Integer> motes) {
		// TODO Auto-generated method stub
		Collections.sort(motes);
		int count = 0;
		int arnew =armin;
		if (motes.size() == 0)
		{
			return 0;
		}
		if(arnew == 1)
		{
			return motes.size();
		}
		if(arnew<=motes.get(0))
		{
			
			while(arnew <= motes.get(0))
			{
				arnew =2*arnew -1;
				++count;
			}
			System.out.println("%% "+count);
			if(count>motes.size())
			{
				return motes.size();
			}
			else
			{
				return Math.min(motes.size(), count + solve(arnew,motes));
			}
		}
		else
		{
			while(motes.size()>0 && arnew>motes.get(0))
			{
				arnew =arnew + motes.get(0);
				motes.remove(0);
			}
			return solve(arnew,motes);
		}
		
		
	}
}
