package gcj2013.r1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;

public class Bullseye {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		
		for(int i=1;i<=T;++i)
		{
			String[] tok=br.readLine().split(" ");
			BigInteger r=new BigInteger(tok[0]);
			BigInteger t=new BigInteger(tok[1]);
			
			BigInteger min=BigInteger.ZERO;
			BigInteger max=new BigInteger(Long.toString(Long.MAX_VALUE));
			BigInteger two=new BigInteger("2");
			
			for(int iter=1;iter<=70;++iter)
			{
				BigInteger x=min.add(max).divide(two);
				
				BigInteger temp=x.subtract(BigInteger.ONE);
				temp=temp.multiply(x);
				temp=temp.multiply(two);
				temp=temp.add(x);
				temp=temp.add(two.multiply(x).multiply(r));
				if(temp.compareTo(t)>0)
					max=x;
				else
					min=x;						
			}
			BigInteger res=min.add(max).divide(two);
			System.out.println("Case #"+i+": "+res);
		}
		br.close();
	}

}
