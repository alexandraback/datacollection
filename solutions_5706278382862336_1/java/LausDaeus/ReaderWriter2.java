
package Utilities;
import java.io.*;
import java.util.ArrayList;


        
public class ReaderWriter2 
{
    private int testCases;
    private long startTimeMs = System.currentTimeMillis();
    
    public int getTC()
    {
        return this.testCases;
    }
    
    public ArrayList<ArrayList<String>> readFile(String path,int linesPerItem)
    {
        BufferedReader reader = null;
        ArrayList<ArrayList<String>> rawInput = new ArrayList<ArrayList<String>>();
        int lineCounter;
        
        try
        {
            reader = new BufferedReader(new FileReader(path));
            String currentLine;
            
            System.out.println("--Reading in file from "+path+" --");
            System.out.println("--Reading in lines--");
                        
            //Sets number of test-cases from first line
            testCases = Integer.parseInt(reader.readLine());
            
            currentLine = reader.readLine();
            
            for(int item = 0; item < testCases; item++)
            {
                rawInput.add(new ArrayList<String>());
                lineCounter = 0;
                
                while(lineCounter < linesPerItem && currentLine != null)
                    {
                        //System.out.println(currentLine);
                        rawInput.get(item).add(currentLine);
                        currentLine = reader.readLine();
                        lineCounter++;
                    }
            }          
        }
        
        catch(IOException ex)
        {
            ex.printStackTrace();                    
        }
        
        finally
        {
            try{reader.close();}
            catch(IOException ex){ex.printStackTrace();}
            System.out.println("--Reading Complete--");      
        }
        return rawInput;
    }
    
    public void writeFileText(String path, String[] output)
    {
        BufferedWriter writer = null;
        
        try
        {
            File file = new File(path);
            
            if(!file.exists())
            {
                file.createNewFile();
            }
            
            System.out.println("--Writing file to "+file+" --");
            
            writer = new BufferedWriter(new FileWriter(file));
            
            for(int i = 0; i < output.length; i++)
            {   
                String temp = "Case #"+Integer.toString(i+1)+": "+output[i];
                writer.write(temp);
                writer.newLine();
            }
            writer.close();                        
        }
        catch(IOException ex)
        {
            ex.printStackTrace();
        }
        finally
        {
            try{writer.close();}
            catch(IOException ex){ex.printStackTrace();}
            System.out.println("--Writing Complete--");  
            System.out.println("Execution time: "+(System.currentTimeMillis()-startTimeMs)+" ms");
        }
    }
}
