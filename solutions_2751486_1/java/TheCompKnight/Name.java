import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Name {

    private static String inputFile = "/Users/Abhishek/input1.txt";
    private static String outputFile = "/Users/Abhishek/output1.txt";
    public static void main(String[] arg) throws Exception
    {
        BufferedReader reader = new BufferedReader(new FileReader(new File(inputFile)));
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File(outputFile)));
        int testCaseCount = Integer.parseInt(reader.readLine());
        
        for(int testCase=1;testCase<=testCaseCount;testCase++)
        {
            String entries[] = reader.readLine().split(" ");
            String name = entries[0];
            int n = Integer.parseInt(entries[1]);
            long count = 0;
            count = findStatus(name,n);
            writer.write("Case #"+testCase+": "+count+"\n");
            //System.out.println("Case #"+testCase+": "+count+"\n");
        }
        
        writer.close();
        reader.close();
    }
    
    public static long findStatus(String name,int n)
    {
        long count=0;
        int lastIndex=0;
        for(int i=0;i<=name.length()-n;i++)
        {
            int j=i;
            for(j=i;j<i+n;j++)
            {
                char c = name.charAt(j); 
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    break;
            }
            
            if(j==i+n)
            {
                count = count + (i-lastIndex+1) * (name.length()-(i+n-1)); 
                //count = count + ((name.length()-(i+n-1)))*(1) *  (i-lastIndex);
                lastIndex = i+1;
            }
        }
        
        return count;
    }
}
