package google;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Question2 {
	File input;
	BufferedReader br;
	FileInputStream in;
	InputStreamReader isr;
	ArrayList<CaseData> mydata;
	int totalnub = 0;
	public Question2() throws IOException
	{
		input = new File("test1");
  		in = new FileInputStream(input);
  		isr = new InputStreamReader(in,"US-ASCII");
  		br = new BufferedReader(isr);
  		mydata = new ArrayList<CaseData>();
	}
	
	private void getdata() throws IOException
	{
		
  		String tempstring = br.readLine();
  		totalnub = Integer.valueOf(tempstring);
  		
  		FileWriter writer = new FileWriter(new File("newdocument1"),true);
		
		
  		for(int i=0;i<totalnub;i++)
  		{
  			String[] mn = br.readLine().split(" ");
  			int line = Integer.valueOf(mn[0]);
  			int col = Integer.valueOf(mn[1]);
  			CaseData1 mycase = new CaseData1(line,col);
  			String[] mystring = new String[line];
  			for(int j = 0; j < line; j++)
  			{
  				mystring[j] = br.readLine();
  			}
  			mycase.pushdata(mystring);
  			if(mycase.test())
  				writer.write("Case #"+String.valueOf(i+1)+": YES\n");
  			else
  				writer.write("Case #"+String.valueOf(i+1)+": NO\n");
  		}
  		br.close();
  		isr.close();
  		in.close();
  		writer.close();
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Question2 myq = new Question2();
		myq.getdata();
	}

}
