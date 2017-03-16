package google;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Question3 {

	ArrayList<Long> result = new ArrayList<Long>();
	
	File input;
	BufferedReader br;
	FileInputStream in;
	InputStreamReader isr;
	ArrayList<CaseData> mydata;
	int totalnub = 0;
	public Question3() throws IOException
	{
		input = new File("test2");
  		in = new FileInputStream(input);
  		isr = new InputStreamReader(in,"US-ASCII");
  		br = new BufferedReader(isr);
  		mydata = new ArrayList<CaseData>();
	}
	
	void output(Long nub1, Long nub2) throws IOException
	{
		getdata(nub1, nub2);
		FileWriter writer = new FileWriter(new File("newdocument3"),true);
		String tempstring = br.readLine();
  		totalnub = Integer.valueOf(tempstring);

  		for(int i=0;i<totalnub;i++)
  		{
  			String[] mn = br.readLine().split(" ");
  			int x = Integer.valueOf(mn[0]);
  			int y = Integer.valueOf(mn[1]);
  			int total = 0;
  			for(int j = 0; j < result.size(); j++)
  			{
  				if(x<=result.get(j)&&y>=result.get(j))
  					total++;
  			}
  			
  			writer.write("Case #"+String.valueOf(i+1)+": "+String.valueOf(total)+"\n");

  		}
  		br.close();
  		isr.close();
  		in.close();
  		writer.close();
  		
		
	}
	void getdata(Long i, Long j) throws IOException
	{
//		FileWriter writer = new FileWriter(new File("newdocument3"),true);
		for(Long temp = i; temp <= j;temp++)
		{
			String reguler = String.valueOf(temp);
			char[] mystring1 = reguler.toCharArray();
			boolean pass1 = true;
			
			for(int x = 0; x < reguler.length()/2;++x)
			{
				if(mystring1[x] != mystring1[reguler.length()-1-x])
				{
					pass1 = false;
					break;
				}
			}
			if(!pass1)
				continue;
			
			Long result = temp * temp;
			String strres = String.valueOf(result);
			char[] mystring = strres.toCharArray();
			boolean pass = true;
			
			for(int x = 0; x < strres.length()/2;++x)
			{
				if(mystring[x] != mystring[strres.length()-1-x])
				{
					pass = false;
					break;
				}
			}
			if(pass)
				this.result.add(result);
//				writer.write(String.valueOf(result)+" ");
			
		}
//		writer.close();
	}
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Question3 myq = new Question3();
		myq.output(0l, 10000000l);
	}

}
