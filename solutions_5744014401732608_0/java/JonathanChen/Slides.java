import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Slides
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
            	String[] input = bufferedReader.readLine().split(" ");
                int buildings = Integer.parseInt(input[0]);
                int ways = Integer.parseInt(input[1]);
                boolean[][] slides = new boolean[buildings][buildings];
                if(ways > Math.pow(2, buildings - 2))
                {
                    output.append("Case #" + i + ": IMPOSSIBLE\r\n");
                    continue;
                }
                
                // Construct main path
                int pathSize = getMaxTwoPower(ways);
                ways -= Math.pow(2, pathSize);
                pathSize += 2;
                if(pathSize != buildings)
                {
                	slides[0][buildings - pathSize] = true;
                }
                for(int j = buildings - pathSize; j < buildings; j++)
                {
                	for(int k = j + 1; k < buildings; k++)
                    {
                    	slides[j][k] = true;
                    }
                }
                
                // Construct supplement
                while(ways > 0)
                {
                	pathSize = getMaxTwoPower(ways);
                    ways -= Math.pow(2, pathSize);
                    pathSize += 2;
                    slides[0][buildings - pathSize] = true;
                }
                
                output.append("Case #" + i + ": POSSIBLE\r\n");
                for(boolean[] row : slides)
                {
                	for(boolean col : row)
                	{
                		output.append(col ? 1 : 0);
                	}
            		output.append("\r\n");
                }
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
    
    public static int getMaxTwoPower(int num)
    {
    	int max = 1, power = 0;;
    	while(max * 2 <= num)
    	{
    		max *= 2;
    		power++;
    	}
    	return power;
    }
}