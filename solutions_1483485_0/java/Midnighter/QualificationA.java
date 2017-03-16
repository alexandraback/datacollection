package midnighter.googlejam.y2012;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class QualificationA
{
	static final String inFileName = "inputs/A-small-attempt0.in";
	static final String outFileName = "outputs/A-small.out";
	
	static String[] samplesIn = new String[]{
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	
	static String[] samplesOut = new String[]{
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"};
	
	char[] mappings = new char[255];

    Scanner in;
    PrintWriter out;
   
    public String oneCase()
    {
    	String str = in.nextLine();
    	String res = "";
        for (int i = 0; i < str.length(); i++)
        	res += mappings[str.charAt(i)];
        return res;
    }
   
    public void run() throws Exception
    {
        in = new Scanner(new FileReader(inFileName));
        out = new PrintWriter(new FileWriter(outFileName));
        
        for (int i = 0; i < 3; i++)
        	for (int k = 0; k < samplesIn[i].length(); k++)
        		mappings[samplesIn[i].charAt(k)] = samplesOut[i].charAt(k);
        mappings['q'] = 'z';
        mappings['z'] = 'q';
       
        int nCases = in.nextInt();
        in.nextLine();
        for (int c = 1; c <= nCases; c++)
            out.println("Case #" + c + ": " + oneCase());
       
        out.flush();
        out.close();
        in.close();
    }
   
    public static void main(String[] args) throws Exception
    {
        new QualificationA().run();
    }
}
