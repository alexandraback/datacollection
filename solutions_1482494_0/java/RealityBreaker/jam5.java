import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Comparator;


public class jam5 {

	/**
	 * @param args
	 */
	class mycomp1 implements Comparator
	{
        int[][] dict;
		public mycomp1(int[][] dic)
		{
			dict = dic;
		}
		@Override
		public int compare(Object arg0, Object arg1) {
			// TODO Auto-generated method stub
			Integer i1 = (Integer)arg0;
			Integer i2 = (Integer)arg1;
			
			return dict[i1][0]<dict[i2][0]?1:0;
		}
		
	};
	class mycomp2 implements Comparator
	{
        int[][] dict;
		public mycomp2(int[][] dic)
		{
			dict = dic;
		}
		@Override
		public int compare(Object arg0, Object arg1) {
			// TODO Auto-generated method stub
			Integer i1 = (Integer)arg0;
			Integer i2 = (Integer)arg1;
			
			return dict[i1][1]<dict[i2][1]?1:0;
		}
		
	};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			File fin1 = new File("d:\\B-small-attempt1.in");
	    	FileInputStream fs1 = new FileInputStream(fin1);
	    	BufferedReader br1 = new BufferedReader(new InputStreamReader(fs1));
	    	
	    	File fout6 = new File("d:\\cjamout");
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
	    		int N = Integer.parseInt(line);
	    		int[][] star = new int[N][2];
	    		for(int i=0;i<N;i++)
	    		{
	    		String line1=br1.readLine();
	    		String[] xn = line1.split(" ");
	    		int[] pr = new int[2];
	    		for(int j=0;j<2;j++)
	    		   pr[j]=Integer.parseInt(xn[j]);
	    		   star[i]=pr;
	    		}
	    		String ans = solve(N,star);
	    	   
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

	private static String solve(int N, int[][] star) {
		// TODO Auto-generated method stub
		int rst = 0;
		int sum = 0;
		
		int[] f = new int[N];
		int[] s = new int[N];
		for(int i=0;i<N;i++)
		{
			f[i]=i;
			s[i]=i;
		}
  
			  for (int i = 0; i < N; i++) {// i从一开始，因为第一个数已经是排好序的啦   
			   for (int j = i; j >0; j--) {   
			    if (star[f[j]][0] < star[f[j - 1]][0]) {   
			     int temp = f[j];   
			     f[j] = f[j - 1];   
			     f[j - 1] = temp;   
			    }
			    
			    if (star[s[j]][1] < star[s[j - 1]][1]) {   
				     int temp = s[j];   
				     s[j] = s[j - 1];   
				     s[j - 1] = temp;   
				    }   
			   }   
			  } 
	    
		int cur1 = 0;
		for(int i=0;i<N;)
		{
			
			if(sum>=star[s[i]][1])
			{
				sum+=2;
				rst++;
				i++;
				continue;
			}
			else
			{
				if(cur1>=N||sum<star[f[cur1]][0])
					return "Too Bad";
				else
				{
					sum++;
					rst++;
					cur1++;
				}
			}
		}
		return String.valueOf(rst);
	}

}
