package com.my;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		try {
			RecycledNumbers r = new RecycledNumbers();

			String fileLocation = "C://Training//Google//RecycledNumbers//src//com//my//smallInput.txt";

			BufferedReader reader = r.getInputFile(fileLocation);

			String line = reader.readLine();
			int count =1;
			while ( ( line = reader.readLine()) != null	 ) {

				String inputs[] = line.split(" " );
				int numCount = r.recycle(Integer.parseInt(inputs[0]),Integer.parseInt(inputs[1]));

				System.out.println("Case #" + count + ": " + numCount);
				
				++count;
			}

			//System.out.println(r.recycle(100,999));
		} catch (Exception e) {
			// TODO: handle exception
		}
	}
}

class RecycledNumbers	{


	public BufferedReader getInputFile(String fileLocation)	throws Exception{

		BufferedReader reader = new BufferedReader(new FileReader(new File(fileLocation)));

		return reader;
	}

	int recycle(int first, int second) throws Exception{

		int count = 0;

		for( int i=first; i<=second; ++i)	{

			String str = Integer.toString(i);
			Set  set = new HashSet();

			int div = 1;

			for( int j =0 ; j<str.length()-1; ++j)	{

				div = div*10;
				int trail = i % div ;

				String s = str.substring(0,str.length()- (j+1));
				int newNum = Integer.parseInt(trail + s);

				if( i < newNum && newNum <= second)	{
 					if( !set.contains(newNum))	{
						set.add(newNum);
						++count;
					}
				}
			}


		}

		return count;
	}
}
