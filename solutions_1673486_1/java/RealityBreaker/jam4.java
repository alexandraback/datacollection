import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.*;

public class jam4 {

	/**
	 * @param args
	 */
	private static double solve(int a, int b, double[] pr) {
		// TODO Auto-generated method stub
		double exp = 20001.0;
		double[] gl = new double[a+1];
		gl[0]=1;
		for(int i=1;i<=a;i++)
			gl[i]=gl[i-1]*pr[i-1];
		
		double hc = gl[a]*(b-a+1)+(1.0-gl[a])*(b-a+1+b+1);
		exp = hc<exp?hc:exp;
		double gv = (1+b+1);
		exp = gv<exp?gv:exp;
		for(int i=1;i<=a;i++)
		{
			double mo = gl[a-i]*(i+b-(a-i)+1)+(1.0-gl[a-i])*(i+b-(a-i)+1+b+1);
			exp = mo<exp?mo:exp;
		}
		return exp;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
		File fin1 = new File("d:\\A-large.in");
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
    		String[] code = line.split(" ");
    		int a = Integer.parseInt(code[0]);
    		int b = Integer.parseInt(code[1]);
    		
    		String line1=br1.readLine();
    		String[] xn = line1.split(" ");
    		double[] pr = new double[xn.length];
    		for(int i=0;i<xn.length;i++)
    		   pr[i]=Double.parseDouble(xn[i]);
    		
    		double ans = solve(a,b,pr);
    		BigDecimal   ab   =   new   BigDecimal(ans); 
    		double   f1   =   ab.setScale(6,   BigDecimal.ROUND_HALF_UP).doubleValue(); 
    	   
    		if(!line.trim().equals(""))
    	   {
    		   wr6.write("Case #"+String.valueOf(n++)+": "+MyToString(f1));
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
		java.text.DecimalFormat   df   =new   java.text.DecimalFormat("#.000000");
		return df.format(f1);
		//String result = String.format("%.2f");
	}

	

}
