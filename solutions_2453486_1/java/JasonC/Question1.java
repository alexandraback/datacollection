package google;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Question1 {
	File input;
	BufferedReader br;
	FileInputStream in;
	InputStreamReader isr;
	ArrayList<CaseData> mydata;
	int totalnub = 0;
	public Question1() throws IOException
	{
		input = new File("test");
  		in = new FileInputStream(input);
  		isr = new InputStreamReader(in,"US-ASCII");
  		br = new BufferedReader(isr);
  		mydata = new ArrayList<CaseData>();
	}
	private void getdata() throws IOException
	{
		
  		String tempstring = br.readLine();
  		totalnub = Integer.valueOf(tempstring);
  		
  		for(int i=0;i<totalnub;i++)
  		{
  			CaseData temp = new CaseData();
  			for(int j=0;j<4;j++)
  			{
	  			tempstring = br.readLine();
	  			
	  			
	  			for(int x=0;x<4;x++)
	  			{
		  			String mychar= tempstring.substring(x, x+1);
		  			temp.pushdata(j*4+x, mychar);
	  			}
  			}
  			mydata.add(temp);
  			br.readLine();
  		}
  		br.close();
  		isr.close();
  		in.close();
  		
	}
	public void setdata() throws IOException
	{
		FileWriter writer = new FileWriter(new File("newdocument"),true);
		for(int i=0;i<totalnub;++i)
		{
			writer.write(test(i)+"\n");
		}
		writer.close();
	}
	boolean strequal(String s1, String s2)
	{
		if(s1.equals(s2)&&!s1.equals("."))
			return true;
		else if(s1.equals("T")&&!s2.equals("."))
			return true;
		else if(s2.equals("T")&&!s1.equals("."))
			return true;
		return false;
	}
	
	boolean testequal(String s1, String s2,String s3, String s4)
	{
		if(s1.equals("T"))
			if(s2.equals(s3)&&s2.equals(s4)&&!s2.equals("."))
				return true;
		if(s2.equals("T"))
			if(s1.equals(s3)&&s1.equals(s4)&&!s1.equals("."))
				return true;
		if(s3.equals("T"))
			if(s2.equals(s4)&&s2.equals(s1)&&!s2.equals("."))
				return true;
		if(s4.equals("T"))
			if(s2.equals(s3)&&s2.equals(s1)&&!s2.equals("."))
				return true;
		if(s1.equals(s3)&&s1.equals(s4)&&s1.equals(s2)&&!s2.equals("."))
			return true;
		
		return false;
	}
	
	public String test(int nub)
	{
		CaseData temp = mydata.get(nub);
		boolean haspoint = false;
		for(int i=0;i<4;i++)
		{
			if(testequal(temp.line1[i][1], temp.line1[i][2], temp.line1[i][3], temp.line1[i][0]))
			{
				if (temp.line1[i][0].equals("O")||(temp.line1[i][0].equals("T")&&temp.line1[i][1].equals("O")))
					return "Case #"+String.valueOf(nub+1)+": O won";
				if (temp.line1[i][0].equals("X")||(temp.line1[i][0].equals("T")&&temp.line1[i][1].equals("X")))
					return "Case #"+String.valueOf(nub+1)+": X won";

					
			}
			else if(temp.line1[i][0].equals(".")||
					temp.line1[i][1].equals(".")||
					temp.line1[i][2].equals(".")||
					temp.line1[i][3].equals("."))
				haspoint = true;
			
		}
		
		for(int i=0;i<4;i++)
		{
			if(testequal(temp.line1[1][i], temp.line1[2][i], temp.line1[3][i], temp.line1[0][i]))
			{
				
				if (temp.line1[0][i].equals("O")||(temp.line1[0][i].equals("T")&&temp.line1[1][i].equals("O")))
					return "Case #"+String.valueOf(nub+1)+": O won";
				if (temp.line1[0][i].equals("X")||(temp.line1[0][i].equals("T")&&temp.line1[1][i].equals("X")))
					return "Case #"+String.valueOf(nub+1)+": X won";
				
			}
			
		}
		if(testequal(temp.line1[0][0], temp.line1[1][1], temp.line1[2][2], temp.line1[3][3]))
		{
			if (temp.line1[0][0].equals("O")||(temp.line1[0][0].equals("T")&&temp.line1[1][1].equals("O")))
				return "Case #"+String.valueOf(nub+1)+": O won";
			if (temp.line1[0][0].equals("X")||(temp.line1[0][0].equals("T")&&temp.line1[1][1].equals("X")))
				return "Case #"+String.valueOf(nub+1)+": X won";

			
		}
		if(testequal(temp.line1[3][0], temp.line1[2][1], temp.line1[1][2], temp.line1[0][3]))
		{
			if (temp.line1[3][0].equals("O")||(temp.line1[3][0].equals("T")&&temp.line1[2][1].equals("O")))
				return "Case #"+String.valueOf(nub+1)+": O won";
			if (temp.line1[3][0].equals("X")||(temp.line1[3][0].equals("T")&&temp.line1[2][1].equals("X")))
				return "Case #"+String.valueOf(nub+1)+": X won";
		
			
		}
		if (haspoint == true)
			return "Case #"+String.valueOf(nub+1)+": Game has not completed";
		else
			return "Case #"+String.valueOf(nub+1)+": Draw";
		
	}
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Question1 myq = new Question1();
		myq.getdata();
		myq.setdata();
	}

}
