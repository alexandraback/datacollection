import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Set;


public class Round1B_A
{
    static long operations = 0;
    
    static long initialMote = 0;
    static long numMotes = 0;
    
    static long currentMoteSize = 0;
    
    public static void main(String[] args)
    {
//        String sDefaultFile = "A-small-attempt0.in";
        String sDefaultFile = "A-large.in";
        String sFile = null;
        BufferedReader reader = null;
        BufferedWriter out = null;

        long inputN = 0; // Number of test cases to process

        if (args.length == 0)
        {
            sFile = sDefaultFile;
            System.out.println("Using Default Input " + sFile);
        }
        else
        {
            sFile = args[0];  
            System.out.println("Using " + sFile);
        }

        try
        {
            reader = new BufferedReader(new FileReader(new File(sFile)));
            String outString = sDefaultFile.substring(0, sFile.lastIndexOf('.'));
            out = new BufferedWriter(new FileWriter(outString + ".out"));
        }
        catch (FileNotFoundException e)
        {
            System.out.println("Exiting: " + sFile + " does not exist");
            e.printStackTrace();
            return;
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        List<Long> motes = new ArrayList<Long>();
        String[] values;
        
        if (reader != null)
        {
            try 
            {
                inputN = Integer.parseInt(reader.readLine());

                System.out.println("Processing " + inputN + " Values...");
                
                long initialMoteNumber = 0;
                
                for (long i = 0; i < inputN; i++)
                {
                    out.write(String.format("Case #%d: ", i+1));
                    values = reader.readLine().split("\\s+");
                    
                    initialMote = Long.parseLong(values[0]);
                    numMotes = Long.parseLong(values[1]);
                    
                    motes.clear();
                    
                    currentMoteSize = initialMote;
                    operations = 0;
                    
                    values = reader.readLine().split("\\s+");
                    for (String s : values)
                    {
                        motes.add(Long.parseLong(s));
                    }
                    
                    Collections.sort(motes);
                    
                    if (currentMoteSize == 1)
                    {
                        out.write(motes.size() + "\n");
                        continue;
                    }
                    
                    Iterator<Long> setIterator = motes.iterator();
                    while (setIterator.hasNext()) 
                    {
                        Long num = setIterator.next();
                        if (currentMoteSize > num)
                        {
                            currentMoteSize += num;
                            setIterator.remove();
                        }
                    }
                    
                    initialMoteNumber = motes.size();
                    
                    if (initialMoteNumber != 0 && initialMoteNumber != 1)
                    {
                        recurseFunc(motes);
                        if (operations < initialMoteNumber)
                        {
                            out.write(operations + "\n");
                        }
                        else
                        {
                            out.write(initialMoteNumber + "\n");
                        }
                    }
                    else
                    {
                        out.write(initialMoteNumber + "\n");
                    }
                    
                    out.flush();
                }
                
                System.out.println("Processing Done!");
                
                out.close();
                reader.close();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
    }
    
    public static void recurseFunc(List<Long> motes)
    {
        if (motes.isEmpty())
        {
            return;
        }
        
        Iterator<Long> setIterator = motes.iterator();
        while (setIterator.hasNext()) 
        {
            Long num = setIterator.next();
            if (currentMoteSize > num)
            {
                currentMoteSize += num;
                setIterator.remove();
            }
        }
        
        numMotes = motes.size();
        
        if (numMotes == 0 || numMotes == 1)
        {
            operations += numMotes;
            return;
        }
        else
        {
            currentMoteSize += (currentMoteSize - 1);
            operations++;
            
            recurseFunc(motes);
        }
    }
}
