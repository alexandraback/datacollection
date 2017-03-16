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
	return "";
    }
    
    public static String solveC(IOfunctions io)
    {
	return "";
    }
 
    public static void main(String[] args) 
    {
	//IOfunctions io = new IOfunctions("D:\\test.txt", "D:\\1atest.txt");
	IOfunctions io = new IOfunctions(args[0], "D:\\ALarge.txt");
	int numCases = io.readInt();

	String output;
	for(int n = 0; n < numCases; n++)
	{
	    output = "Case #" + (n+1) + ": " + solveA(io);
	    io.writeLine(output);
	}
	io.finish();								//ensure the write buffer gets flushed and both resources are closed.

    } 
}
