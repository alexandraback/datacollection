/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejammer;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

/**
 *
 * @author Bruce

*/


public class IOfunctions {

    BufferedReader reader = null;
    BufferedWriter writer = null;
    //int lineNo = 0;
    public boolean echo = true;
    
    public IOfunctions(String in, String out) 
    {
	Path input = Paths.get(in);
	Path output = Paths.get(out);
	try
	{ 
	    reader = Files.newBufferedReader(input);
	    writer = Files.newBufferedWriter(output);
	}
	catch(IOException e){ e.printStackTrace(); }
    }
 
    private void write(String s)
    {
	try
	{
	    writer.write(s, 0, s.length());
	}
	catch(IOException e){ e.printStackTrace(); }
	if(echo)
	    System.out.print(s);    
    }
    
    private String readLine()
    {
	String line = null;
	try
	{
	    if((line = reader.readLine()) == null)
		throw new IOException("Null String");
	}
	catch(IOException e){ e.printStackTrace(); }
	if(echo)
	    System.out.println(line);
	return line;
    }
    
    public int readInt()
    { 
	return Integer.parseInt(readLine());
    } 
    
    public long readLong()
    { 
	return Long.parseLong(readLine());
    }  
    
    public void writeInt(int n)
    {
	write(Integer.toString(n));
    }
    
    public void writeLine(String s)
    {
	write(s);
	write("\n");
    }

    public String[] readWords()
    {
	return readLine().split(" ");
    }
    
    public char[] readCharArray()
    {
	return readLine().toCharArray();
    }
    
    public int[] readInts(int offset, int length)
    {
	String[] ints = readLine().split(" ");
	int[] values = new int[length];
	for(int i = 0; i < length; i++)
	    values[i] = Integer.parseInt(ints[i+offset]);
	return values;
    }
    public int[] readInts() 
    {
	String[] ints = readLine().split(" ");
	int[] values = new int[ints.length];
	for(int i = 0; i < values.length; i++)
	    values[i] = Integer.parseInt(ints[i]);
	return values;
    }
    
    public long[] readLongs() 
    {
	String[] ints = readLine().split(" ");
	long[] values = new long[ints.length];
	for(int i = 0; i < values.length; i++)
	    values[i] = Long.parseLong(ints[i]);
	return values;
    }

    public void finish()
    {
	try{
	    writer.close();
	    reader.close();
	}
	catch(IOException e) { e.printStackTrace(); }
    }
}
