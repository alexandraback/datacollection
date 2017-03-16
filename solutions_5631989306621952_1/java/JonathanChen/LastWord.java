import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class LastWord
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
                String word = bufferedReader.readLine();
                String last = word.charAt(0) + "";
                for(int j = 1; j < word.length(); j++)
                {
                    if(word.charAt(j) >= last.charAt(0))
                    {
                        last = word.charAt(j) + last;
                    }
                    else
                    {
                        last += word.charAt(j);
                    }
                }
                
                output.append("Case #" + i + ": " + last + "\n");
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
    
    public static boolean finished(boolean[] nums)
    {
        for(boolean num : nums)
        {
            if(!num)
            {
                return false;
            }
        }
        return true;
    }
}