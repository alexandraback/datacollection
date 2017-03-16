import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class jam3 {

	/**
	 * @param args
	 */
	static int chuli(String s)
	{
		int count = 0;
		String[] ab = s.split(" ");
		int a = Integer.parseInt(ab[0]);
		int b = Integer.parseInt(ab[1]);
		HashSet<String> over = new HashSet<String>();
		HashSet<String> cur = new HashSet<String>();
		for(int i=a;i<=b;i++)
		{
			String is = String.valueOf(i);
			if(!over.contains(is))
			{
				cur.clear();
				String is2 = is+is;
				for(int i2=0;i2<is.length();i2++)
				{
					String ns = is2.substring(i2, i2+is.length());
					int ins = Integer.parseInt(ns);
					if(ins>=a&&ins<=b)
						cur.add(ns);
				}
				count+=(cur.size()*(cur.size()-1))/2;
				over.addAll(cur);
			}
		}
		return count;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			/*
	    	System.out.println(chuli("1 9"));
	    	System.out.println(chuli("10 40"));
	    	System.out.println(chuli("100 500"));
	    	System.out.println(chuli("1111 2222"));
		    */
			File fin1 = new File("d:\\C-small-attempt0.in");
	    	FileInputStream fs1 = new FileInputStream(fin1);
	    	BufferedReader br1 = new BufferedReader(new InputStreamReader(fs1));
	    	
	    	File fout6 = new File("d:\\cjamout1");
	    	FileOutputStream fos6 = new FileOutputStream(fout6);
	    	BufferedWriter wr6 = new BufferedWriter(new OutputStreamWriter(fos6));
	        
	    	String line = br1.readLine();
	    	int n = 1;
	    	line = br1.readLine();
	    	while(line!=null)
	    	{
	    	   if(!line.trim().equals(""))
	    	   {
	    		   wr6.write("Case #"+String.valueOf(n++)+": "+String.valueOf(chuli(line)));
	    	       wr6.newLine();
	    	   }
	    	   line = br1.readLine();
	    	  
			}
	    	br1.close();
	    	fs1.close();
	    	
	    	wr6.close();
	    	fos6.close();
	    	
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

}
