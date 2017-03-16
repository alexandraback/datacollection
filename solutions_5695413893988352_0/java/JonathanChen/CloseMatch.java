import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CloseMatch
{
    public static void main(String[] args)
    {
        try
        {
            File file = new File("input.txt");
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            StringBuffer output = new StringBuffer();
            
            int lines = Integer.parseInt(bufferedReader.readLine());
            for(int i = 1; i <= lines; i++)
            {
                String[] line = bufferedReader.readLine().split(" ");
                Attempt min = bruteForce(line[0], line[1], 0);
                
                output.append("Case #" + i + ": " + min.first + " " + min.second + "\r\n");
            }
            fileReader.close();
            
            file = new File("output.txt");
            FileWriter fileWriter = new FileWriter(file);
            fileWriter.write(output.toString());
            fileWriter.flush();
            fileWriter.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
    
    public static Attempt bruteForce(String first, String second, int index)
    {
    	if(index == first.length())
    	{
    		if(second.contains("?"))
    		{
    			second = bruteForce(second, first, 0).first;
    		}
    		return new Attempt(first, second);
    	}
    	
    	Attempt min = null;
    	String temp = first;
    	for(int i = 0; i < 10; i ++)
    	{
    		if(first.charAt(index) == '?')
    		{
    			temp = first.substring(0, index) + i + first.substring(index + 1, first.length());
    		}
    		Attempt current = bruteForce(temp, second, index + 1);
    		
    		if(min == null || current.difference < min.difference)
    		{
    			min = current;
    		}
    	}
    	return min;
    }
    
    public static class Attempt
    {
    	public Attempt(String first, String second)
    	{
    		this.first = first;
    		this.second = second;
    		difference = Math.abs(Integer.parseInt(first) - Integer.parseInt(second));
    	}
    	
    	String first;
    	String second;
    	int difference;
    }
}