import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;


public class Googlerese {
	private static Map<String, String> knowledgeBase = new HashMap<String, String>();
	
	static
	{
		knowledgeBase.put("our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
		knowledgeBase.put("there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
		knowledgeBase.put("so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");
		knowledgeBase.put("aozq", "yeqz");
	}


    private BufferedReader reader;
    private BufferedWriter writer;
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        Googlerese googlerese = new Googlerese(args[0]);
        googlerese.executeTests();
    }
    

    public Googlerese(String filename)
    {
        // Open file
        File file = new File(filename);
        try
        {
            reader = new BufferedReader(new FileReader(file));
            writer = new BufferedWriter(new FileWriter(file+".out"));
        }
        catch (IOException e)
        {
            // Failed to open new buffered reader
            System.err.println("Failed to open FileReader");
            e.printStackTrace();
            System.exit(-1);
        }
    }
    
    private void executeTests()
    {
    	Map<Character, Character> cipher = trainCipher();
    	
        // Read number of test cases
        int numberOfTests = 0; 
        
        try
        {
            // Read number of tests (first line)
            numberOfTests = Integer.parseInt(reader.readLine());
        }
        catch (NumberFormatException | IOException e)
        {
            // Failed to read a line
            System.err.println("Failed to read a line");
            e.printStackTrace();
            System.exit(-1);
        }

        for (int testCase = 1; testCase <= numberOfTests; testCase++)
        {
            String encodedSentence;
            try
            {
                encodedSentence = reader.readLine();
                String translated = translate(encodedSentence, cipher);
                writer.write("Case #" + testCase + ": " + translated + '\n');
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
        
        try
        {
            reader.close();
            writer.flush();
            writer.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
    
    private static String translate(String encoded, Map<Character, Character> cipher)
    {
    	StringBuilder builder = new StringBuilder();
    	for (int i = 0; i < encoded.length(); i++)
    	{
    		builder.append(cipher.get(encoded.charAt(i)));
    	}
    	
    	return builder.toString();
    }
    
    private static Map<Character, Character> trainCipher()
    {
    	Map<Character, Character> cipher = new HashMap<Character, Character>();
    	Map<Character, Character> reverseCipher = new HashMap<Character, Character>();
    	
    	for (Map.Entry<String, String> entry : knowledgeBase.entrySet())
    	{
    		String encoded = entry.getValue();
    		String decoded = entry.getKey();
    		
    		for (int i = 0; i < encoded.length(); i++)
    		{
    			cipher.put(encoded.charAt(i), decoded.charAt(i));
    			reverseCipher.put(decoded.charAt(i), encoded.charAt(i));
    		}
    	}
    	
    	List<Character> unusedEncoded = new LinkedList<Character>();
    	List<Character> unusedDecoded = new LinkedList<Character>();
    	
    	for (char ch = 'a'; ch <= 'z'; ch++)
    	{
    		if (!cipher.containsKey(ch))
    		{
    			System.out.println("Missing encrypted character: " + ch);
    			unusedEncoded.add(ch);
    		}
    		if (!reverseCipher.containsKey(ch))
    		{
    			System.out.println("Missing decrypted character: " + ch);
    			unusedDecoded.add(ch);
    		}
    	}
    	
    	return cipher;
    }
}
