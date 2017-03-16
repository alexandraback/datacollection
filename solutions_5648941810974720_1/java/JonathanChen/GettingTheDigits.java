import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class GettingTheDigits
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
                String input = bufferedReader.readLine();
                ArrayList<Integer> digits = new ArrayList<Integer>();
                
                while(input.contains("Z"))
                {
                	digits.add(0);
                	input = remove(input, "ZERO");
                }
                while(input.contains("W"))
                {
                	digits.add(2);
                	input = remove(input, "TWO");
                }
                while(input.contains("U"))
                {
                	digits.add(4);
                	input = remove(input, "FOUR");
                }
                while(input.contains("F"))
                {
                	digits.add(5);
                	input = remove(input, "FIVE");
                }
                while(input.contains("X"))
                {
                	digits.add(6);
                	input = remove(input, "SIX");
                }
                while(input.contains("S"))
                {
                	digits.add(7);
                	input = remove(input, "SEVEN");
                }
                while(input.contains("G"))
                {
                	digits.add(8);
                	input = remove(input, "EIGHT");
                }
                while(input.contains("T"))
                {
                	digits.add(3);
                	input = remove(input, "THREE");
                }
                while(input.contains("I"))
                {
                	digits.add(9);
                	input = remove(input, "NINE");
                }
                while(input.contains("O"))
                {
                	digits.add(1);
                	input = remove(input, "ONE");
                }
                
                Collections.sort(digits);
                String number = "";
                for(Integer digit : digits)
                {
                	number += digit;
                }
                
                output.append("Case #" + i + ": " + number + "\r\n");
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
    
    public static String remove(String input, String word)
    {
    	for(int i = 0; i < word.length(); i++)
    	{
    		boolean found = false;
    		for(int j = 0; j < input.length() && !found; j++)
    		{
    			if(word.charAt(i) == input.charAt(j))
    			{
    				found = true;
    				input = input.substring(0, j) + input.substring(j + 1, input.length());
    			}
    		}
    	}
    	return input;
    }
}