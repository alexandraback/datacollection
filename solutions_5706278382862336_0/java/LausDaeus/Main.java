package Round1CQA;
import Utilities.ReaderWriter2;
import java.util.ArrayList;

/**
 * Niklas Zwingenberger, May 11, 2014
 */
public class Main 
{
    public static void main(String[] args) 
    {
        //General code
        ReaderWriter2 rw = new ReaderWriter2();
        String fileName = "A-small-attempt0.in";
        String outputName = fileName.substring(0, fileName.length() - 3)+".out";
        String outputDir = "src\\Round1CQA\\";
        ArrayList<ArrayList<String>> inputs = rw.readFile(outputDir+fileName,1);
        int testCases = rw.getTC();
        String[] outputs = new String[testCases];
        System.out.println(inputs);
        //Specific code
        for(int i = 0; i < testCases; i++)
        {
            String[] numbers = inputs.get(i).get(0).split("/");

            long numerator = Long.parseLong(numbers[0]);
            long denominator = Long.parseLong(numbers[1]);
            
            
            //Simplifying
            long gcm = gcm(numerator, denominator);
            numerator /= gcm;
            denominator /= gcm;
            int required = 0;
            boolean possible = false;
            boolean done = false;
            
            if((denominator & (denominator - 1)) == 0)
            {
                possible = true;
                
                while(!done && denominator > 1)
                {
                    //System.out.println(numerator+"/"+denominator);
                    if(numerator >= denominator)
                    {
                        done = true;
                    }
                    else
                    {
                        denominator /= 2;
                        required++;
                    }
                        
                }
            }
            
            
            
            if(possible)
                outputs[i] = Integer.toString(required);
            else
                outputs[i] = "impossible";
            
            
            System.out.println("Completed: "+(i+1)+"/"+testCases);
        }
        
        //More general code
        rw.writeFileText(outputDir+outputName, outputs);
    }
    
    //Helper Methods
    public double getChild(Double parentA, Double parentB){return (parentA + parentB)/2;}

    public static long gcm(long a, long b) {return b == 0 ? a : gcm(b, a % b);} 

}
