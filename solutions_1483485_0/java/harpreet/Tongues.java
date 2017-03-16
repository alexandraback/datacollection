package com.my;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.InputStream;
import java.util.Properties;

public class Tongues {


	public void translate()	{
		
		String fileLocation = "C://Training//Google//SpeakingInTongues//src//com//my//smallInput.txt";
		
		try {
			
			Properties pro = getLanguageProperties();
			
			BufferedReader reader = getInputFile(fileLocation);
			String line = reader.readLine();
			
			int count=1;
			while ( ( line = reader.readLine()) != null	 ) {
				
				String s = line;//"ejp mysljylc kd kxveddknmc re jsicpdrysi";
				
				System.out.print("Case #" + count + ": ");
				++count;
				for( int i=0; i<s.length();++i)	{
					String ss = ""+s.charAt(i);
					 
					String out = pro.getProperty(ss);
					 
					if( out == null || "".equalsIgnoreCase(out))	
						System.out.print(ss);
					else
						System.out.print(out);
				}
				System.out.println("");
				
			}
			
		} catch (Exception e) {
			System.out.println(e);
		}
		
		
	}
	public Properties getLanguageProperties()	throws Exception {

		//InputStream in =  Tongues.class.getClassLoader().getSystemResourceAsStream("C://Training//Google//SpeakingInTongues//src//com//my//strings.properties");

		Properties pro = new Properties();
		InputStream in = new FileInputStream(new File("C://Training//Google//SpeakingInTongues//src//com//my//strings.properties"));
		System.out.println(in);
		pro.load(in);
		
		System.out.println(pro);
		return pro;
		
	}
	
	public BufferedReader getInputFile(String fileLocation)	throws Exception{
		
		BufferedReader reader = new BufferedReader(new FileReader(new File(fileLocation)));
		
		return reader;
	}
}
