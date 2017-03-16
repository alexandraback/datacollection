import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class jam6 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			File fin1 = new File("d:\\A-small-attempt1.in");
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
	            int N = Integer.parseInt(code[0]);
	    		int[] fs = new int[N];
	    		for(int i=0;i<N;i++)
	    			fs[i]=Integer.parseInt(code[i+1]);
	    		
	    	   if(!line.trim().equals(""))
	    	   {
	    		   wr6.write("Case #"+String.valueOf(n++)+": "+solve(N,fs));
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
	private static String MyToString(double f1) {
		// TODO Auto-generated method stub
		if(f1==0)
			return "0.000000";
		java.text.DecimalFormat   df   =new   java.text.DecimalFormat("#.000000");
		return df.format(f1);
		//String result = String.format("%.2f");
	}
	private static String solve(int n, int[] fs) {
		// TODO Auto-generated method stub
		String ans = "";
		int sum = 0;
		for(int i=0;i<n;i++)
			sum+=fs[i];
		
		double aver = 2.0*sum/n;
		double dd2 = 2.0*sum;
		
		double[] an = new double[n];
		int count = 0;
		for(int i=0;i<n;i++)
		{
			if(fs[i]>aver)
			{
				an[i]=0.0;
				count++;
				dd2=dd2-fs[i];
			}
			else
				an[i]=-1.0;
		}
		double aver2 = dd2/(n-count);
		
		for(int i=0;i<n;i++)
		{
			if(an[i]==-1.0)
			{
				an[i]=solve(aver2,sum,i,n,fs);
			}
		}
		
		for(int i=0;i<n;i++)
		{
			String mts = MyToString(an[i]);
			ans+=mts;
			if(i!=n-1)
				ans+=" ";
		}
		return ans;
	}
	private static double solve(double a,int sum, int i, int n, int[] fs) {
		// TODO Auto-generated method stub
		
		
		return (a-((double)fs[i]))/(sum+0.0)*100.0;
	}

}
