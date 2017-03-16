import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class jam7 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			File fin1 = new File("d:\\C-small-attempt1.in");
	    	FileInputStream fs1 = new FileInputStream(fin1);
	    	BufferedReader br1 = new BufferedReader(new InputStreamReader(fs1));
	    	
	    	File fout6 = new File("d:\\cjamout2");
	    	FileOutputStream fos6 = new FileOutputStream(fout6);
	    	BufferedWriter wr6 = new BufferedWriter(new OutputStreamWriter(fos6));
	        /*
	    	System.out.println(decode("y qee"));
	        System.out.println(decode("ejp mysljylc kd kxveddknmc re jsicpdrysi"));
	        System.out.println(decode("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"));
	        System.out.println(decode("de kr kd eoya kw aej tysr re ujdr lkgc jv"));
		    */
	    	String line = br1.readLine();
	    	int n = 1;
	    	line = br1.readLine();
	    	while(line!=null)
	    	{
	            String[] code = line.split(" ");
	            int[] nums = new int[20];
	            for(int i=0;i<20;i++)
	            	nums[i]=Integer.parseInt(code[i]);
	            int[] flag = new int[20];
	            Hashtable<Integer,HashSet<HashSet<Integer>>> hs = new Hashtable<Integer,HashSet<HashSet<Integer>>>();
	            
	            String ans = subset(nums,flag,0,19,hs);
	            if(ans==null)
	            	ans="\nImpossible";
	    	   if(!line.trim().equals(""))
	    	   {
	    		   wr6.write("Case #"+String.valueOf(n++)+": "+ans);
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
	private static String solve(ArrayList<HashSet<Integer>> ar, int i) {
		// TODO Auto-generated method stub
		for(int k=0;k<ar.size();k++)
			for(int j=k+1;j<ar.size();j++)
			{
				HashSet<Integer> s1 = ar.get(k);
				HashSet<Integer> s2 = ar.get(j);
				if(!s1.equals(s2)&&sumeq(s1,s2))
				{
					return "\n"+dump(s1)+"\n"+dump(s2);
				}
			}
		return "\nImpossible";
	}
	private static String dump(HashSet<Integer> s) {
		// TODO Auto-generated method stub
		String ans = "";
		Iterator<Integer> it = s.iterator();
		while(it.hasNext())
		{
			ans+=String.valueOf(it.next())+" ";
		}
		return ans.trim();
	}
	private static boolean sumeq(HashSet<Integer> s1, HashSet<Integer> s2) {
		// TODO Auto-generated method stub
		Iterator<Integer> it1 = s1.iterator();
		Iterator<Integer> it2 = s2.iterator();
		int sm1=0;
		int sm2=0;
		while(it1.hasNext())
		{
			sm1+=it1.next();
		}
		while(it2.hasNext())
		{
			sm2+=it2.next();
		}
		if(sm1==sm2)
			return true;
		return false;
	}
	static String subset(int s[],int f[],int m,int n,Hashtable<Integer,HashSet<HashSet<Integer>>> ht)
	{
	    int i;
	    f[m] = 0;  //标记该元素出现
	    boolean flag = false;
	    if (m == n)
	    {   
	    	HashSet<Integer> hs = new HashSet<Integer>();
	    	int sum = 0;
	        for(i = 0; i <= n; i++) 
	        {
	            if (f[i] == 0) ;
	            else {
	            	sum+=s[i];
	            	hs.add(s[i]);   
	            }
	        }
	        if(!ht.containsKey(sum))
	        	{
	        	ht.put(sum, new HashSet<HashSet<Integer>>());
	        	ht.get(sum).add(hs);
	        	return null;
	        	}
	        else
	        {
	        	Iterator<HashSet<Integer>> itr = ht.get(sum).iterator();
	        	if(itr.hasNext())
	        	{
	        		return "\n"+dump(itr.next())+"\n"+dump(hs);
	        	}
	        }
	    }
	    else 
	    {
	    	String ss = subset(s,f,m+1,n,ht);
	    	if(ss!=null)
	    	    return ss;
	    }
	  
	    f[m] = 1;  //标记该元素不出现
	    if (m == n)
	    {   
	    	HashSet<Integer> hs = new HashSet<Integer>();
	    	int sum = 0;
	        for(i = 0; i <= n; i++) 
	        {
	            if (f[i] == 0) ;
	            else {
	            	sum+=s[i];
	            	hs.add(s[i]);   
	            }
	        }
	        if(!ht.containsKey(sum))
	        	{
	        	ht.put(sum, new HashSet<HashSet<Integer>>());
	        	ht.get(sum).add(hs);
	        	return null;
	        	}
	        else
	        {
	        	Iterator<HashSet<Integer>> itr = ht.get(sum).iterator();
	        	if(itr.hasNext())
	        	{
	        		return "\n"+dump(itr.next())+"\n"+dump(hs);
	        	}
	        }
	    }
	    else  
	    {
	    	String ss = subset(s,f,m+1,n,ht);
	    	if(ss!=null)
	    	    return ss;
	    }
	    return null;
	}
}
