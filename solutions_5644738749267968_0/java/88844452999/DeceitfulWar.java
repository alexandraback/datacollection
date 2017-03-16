package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;

public class DeceitfulWar {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File file=new File("D-small-attempt0.in");
        Writer output = null;
        File out=new File("D-small-attempt0.out");
        output = new BufferedWriter(new FileWriter(out));
        BufferedReader fileIn = new BufferedReader(new FileReader(file));
        String fileLine,delims,outs;
        String[] tokens;
        int cases,n,i;
        ArrayList<Double> naomi,ken;
        
        String ans;
        
       
        fileLine=fileIn.readLine();
        cases = Integer.parseInt(fileLine);
        delims = "[ ]+";
        System.out.println("Cases = "+cases);
        
        for	(i=0;i<cases;++i)
        {
        	naomi = new ArrayList<Double>();
        	ken = new ArrayList<Double>();
        output.write("Case #");
        output.write(Integer.toString(i+1));
        output.write(": ");
    	fileLine=fileIn.readLine();
    	n= Integer.parseInt(fileLine);
    	fileLine=fileIn.readLine();
    	tokens = fileLine.split(delims);
    	for(int j =0;j<n;++j)
    	{
    		naomi.add(Double.parseDouble(tokens[j]));
    	}
    	
    	
    	fileLine=fileIn.readLine();
    	tokens = fileLine.split(delims);
    	for(int j =0;j<n;++j)
    	{
    		ken.add(Double.parseDouble(tokens[j]));
    	}
    	
    	ans = solve(n,naomi,ken);
    	output.write(ans);
        output.write("\r\n");
        System.out.println(ans);
        }
        output.close();
	}

	private static String solve(int n, ArrayList<Double> naomi,
			ArrayList<Double> ken) {
		// TODO Auto-generated method stub
		Collections.sort(naomi);
		Collections.sort(ken);
		int points = 0,pointsd = 0;
		int pos = 0;
		 ArrayList<Double>  n2 = (ArrayList<Double>) naomi.clone();
		 ArrayList<Double>  k2 = (ArrayList<Double>) ken.clone();
		
		for(Double d: n2)
		{
			 pos = Collections.binarySearch(k2, d);
			 if(-1*(pos + 1) >= k2.size() )
			 {
				 points++;
				 k2.remove(0);
			 }
			 else
			 {
				 k2.remove(-1*(pos+1));
			 }
			 
		}
		
		n2 = (ArrayList<Double>) naomi.clone();
		k2 = (ArrayList<Double>) ken.clone();
		
		for(Double d: k2)
		{
			 pos = Collections.binarySearch(n2, d);
			 if(-1*(pos + 1) >= n2.size() )
			 {
				
				 n2.remove(0);
			 }
			 else
			 {
				 n2.remove(-1*(pos+1)); 
				 pointsd++;
			 }
			 
		}
		
		String s = Integer.toString(pointsd) + " " +Integer.toString(points); 
		return s;
	}

}
