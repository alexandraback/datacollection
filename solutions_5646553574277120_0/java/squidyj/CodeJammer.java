package codejammer;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

/**
 *
 * @author Bruce
 */


public class CodeJammer {
 
    public static String solveA(IOfunctions io)
    {
	int[] values = io.readInts();
	int R = values[0];
	int C = values[1];
	int W = values[2];
	
	//we have to check each row once at a minimum
	int score;
	//we need to make sure that we check a minimum number of spaces
	if(C % W == 0)
	    score =  R * C / W;
	else
	    score = R * (C / W + 1);
	
	score += W - 1;
	return "" + score;
    }

    public static String solveB(IOfunctions io)
    {
	int[] values = io.readInts();
	int numKeys = values[0];
	int wordLength = values[1];
	int numTyped = values[2];
	
	if(wordLength > numTyped)
	    return "0.0";
	
	char[] keyboard = io.readCharArray();
	char[] word = io.readCharArray();
	boolean exists = false;
	
	//confirm word can be found
	for(char c : word)
	{
	    exists = false;
	    for(char c2 : keyboard)
		exists = exists || c2 == c;
	    if(!exists)
		return "0.0";			
	}
	
	int keyLength = wordLength;
	for(int i = 1; i < wordLength; i++)
	{
	    exists = true;
	    for(int j = 0; j < i; j++)
	    {
		exists = exists && word[j] == word[wordLength - i + j - 1];
	    }
	}
	    
	return "";
    }
    
    public static String solveC(IOfunctions io)
    {
	int[] values = io.readInts();
	int C = values[0];
	int D = values[1];
	int V = values[2];
	int[] existing = io.readInts();
	
	int newCoins = 0;
	int sum = 0;
	int i = 0;
	while(sum < V)
	{
	    if(i >= D || (sum+1) < existing[i])
	    {
		sum += (sum+1) * C;
		newCoins++;
	    }
	    else
	    {
		sum += existing[i] * C;
		i++;
	    }
	}

	return "" + newCoins;
    }
 
    public static void main(String[] args) 
    {
	//IOfunctions io = new IOfunctions("D:\\test.txt", "D:\\1Ctest.txt");
	IOfunctions io = new IOfunctions(args[0], "D:\\CSmall.txt");
	int numCases = io.readInt();

	String output;
	for(int n = 0; n < numCases; n++)
	{
	    output = "Case #" + (n+1) + ": " + solveC(io);
	    io.writeLine(output);
	}
	io.finish();								//ensure the write buffer gets flushed and both resources are closed.

    } 
}
