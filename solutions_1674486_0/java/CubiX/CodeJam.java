import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;

public class CodeJam
{
    private static BufferedReader reader;
    private static BufferedWriter writer;
    private static LinkedList<LinkedList<Clazz>> paths;
    
    public static void main(String args[]) throws Exception
    {
        prepareFiles("A-small-attempt1");
        
        int T = Integer.parseInt(reader.readLine()); // test cases
        
        for(int t = 0; t < T; t++)
        {
        	int N = Integer.parseInt(reader.readLine()); // num of classes
        	
        	HashMap<Integer, Clazz> clazzes = new HashMap<Integer, Clazz>();
        	
        	for(int i = 0; i < N; i++)
        	{
        		Clazz clazz = new Clazz();
        		clazz.value = i + 1;
        		
        		clazzes.put(clazz.value, clazz);
        	}
        	
        	for(int i = 0; i < N; i++)
        	{
        		Clazz clazz = clazzes.get(i + 1);
        		
        		String[] line = reader.readLine().split(" ");
        		int M = Integer.parseInt(line[0]); // num of parent classes
        		
        		for(int j = 0; j < M; j++)
        		{
        			int value = Integer.parseInt(line[j + 1]);
        			
        			Clazz parent = clazzes.get(value);
        			
        			if(!clazz.links.contains(parent))
        			{
        				clazz.links.add(parent);
        			}
        			else
        			{
        				break;
        			}
        		}
        	}
        	
        	paths = new LinkedList<LinkedList<Clazz>>();
        	
        	for(int i = 0; i < N; i++)
        	{
        		Clazz clazz = clazzes.get(i + 1);
        		
        		LinkedList<Clazz> pathSoFar = new LinkedList<Clazz>();
    			getPath(pathSoFar, clazz);
        	}
        	
        	print(getCase(t + 1));
        	
        	boolean matching = false;
        	
        	for(int i = 0; i < paths.size(); i++)
        	{
        		LinkedList<Clazz> path1 = paths.get(i);
        		
        		for(int j = i + 1; j < paths.size(); j++)
            	{
					LinkedList<Clazz> path2 = paths.get(j);
					
					if(path1.get(0).equals(path2.get(0)) && path1.get(path1.size() - 1).equals(path2.get(path2.size() - 1)))
					{
						matching = true;
						break;
					}
            	}
        		
        		if(matching == true)
        		{
        			break;
        		}
        	}
        	
        	print(matching ? "Yes" : "No");
        	
        	//print(paths);
        	print("\n");
        }
     
            
        putAwayFiles();
    }
    
    private static void getPath(LinkedList<Clazz> pathSoFar, Clazz clazz) 
    {
    	pathSoFar = (LinkedList<Clazz>)pathSoFar.clone();
    	
    	if(clazz.links.size() == 0)
    	{
			pathSoFar.add(clazz);
			
    		if(pathSoFar.size() > 1)
    		{
    			paths.add(pathSoFar);
    		}
    	}
    	else
    	{
    		pathSoFar.add(clazz);
    		
	    	for(Clazz parent : clazz.links)
			{
				getPath(pathSoFar, parent);
			}
    	}
	}

	private static class Clazz
    {
    	LinkedList<Clazz> links = new LinkedList<>();
    	int value;
    	
    	@Override
    	public String toString()
    	{
    		return value + "";
    	}
    }
    
    private static void prepareFiles(String fileName) throws IOException
    {
        reader = new BufferedReader(new FileReader(new File(fileName + ".in")));
        writer = new BufferedWriter(new FileWriter(new File(fileName + ".out")));
    }
    
    private static void putAwayFiles() throws IOException
    {
        reader.close();
        writer.flush();
        writer.close();
    }
    
    private static String getCase(int i)
    {
        return "Case #" + i + ": ";
    }
    
    private static void print(Object object) throws IOException
    {
        System.out.print(object.toString());
        writer.write(object.toString());
    }
}


