import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class BFF
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
                boolean[] checked = new boolean[Integer.parseInt(bufferedReader.readLine())];
                String[] values = bufferedReader.readLine().split(" ");
                int[] children = new int[values.length];
                for(int j = 0; j < values.length; j++)
                {
                    children[j] = Integer.parseInt(values[j]);
                }
                
                int startIndex = 0;
                int maxLength = 0;
                int current = firstUnchecked(checked);
                ArrayList<Integer> currentLoop = new ArrayList<Integer>();
                HashMap<Integer, Integer> chainMap = new HashMap<Integer, Integer>();
                while(current != -1)
                {
                    while(!currentLoop.contains(current))
                    {
                        checked[current] = true;
                        currentLoop.add(current);
                        current = children[current] - 1;
                    }
                    
                    // Check for ring
                    startIndex = current;
                    current = children[current] - 1;
                    int length = 1;
                    while(current != startIndex)
                    {
                        length++;
                        current = children[current] - 1;
                    }
                    
                    // Check for chain
                    if(length == 2)
                    {
                        ArrayList<Integer> chainEnd = new ArrayList<Integer>();
                        chainEnd.add(current);
                        chainEnd.add(children[current] - 1);
                        int chainLength = Math.max(getChainLength(current, children, checked, chainEnd), 
                                getChainLength(children[current] - 1, children, checked, chainEnd)) + 1;
                        chainMap.put(Math.min(current, children[current] - 1), chainLength);
                    }
                    
                    maxLength = Math.max(length, maxLength);
                    currentLoop.clear();
                    current = firstUnchecked(checked);
                }

                int totalChainLength = 0;
                for(Integer chain : chainMap.keySet())
                {
                    totalChainLength += chainMap.get(chain);
                }
                output.append("Case #" + i + ": " + Math.max(maxLength, totalChainLength) + "\n");
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
    
    public static int firstUnchecked(boolean[] checked)
    {
        for(int i = 0; i < checked.length; i++)
        {
            if(!checked[i])
            {
                return i;
            }
        }
        return -1;
    }
    
    public static ArrayList<Integer> getAdmirers(int person, int[] children)
    {
        ArrayList<Integer> array = new ArrayList<Integer>();
        for(int i = 0; i < children.length; i++)
        {
            if(children[i] - 1 == person)
            {
                array.add(i);
            }
        }
        return array;
    }
    
    public static int getChainLength(int person, int[] children, boolean[] checked, ArrayList<Integer> seen)
    {
        ArrayList<Integer> array = getAdmirers(person, children);
        if(array.isEmpty())
        {
            return 1;
        }

        int maxChainLength = 0;
        for (int i = 0; i < children.length; i++) {
            int child = children[i];
            if(!seen.contains(child))
            {
                seen.add(child);
                checked[i] = true;
                maxChainLength = Math.max(getChainLength(child, children, checked, seen), maxChainLength);
            }
        }
        return maxChainLength + 1;
    }
}