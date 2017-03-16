import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author John
 */
public class Main 
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        
        int testCases = Integer.parseInt(in.readLine());
        String[] tokens;
        
        for(int testNumber = 1; testNumber <= testCases; testNumber++)
        {
            out.append("Case #").append(testNumber).append(": ");
            
            tokens = in.readLine().trim().split("\\s+");
            
            int c = Integer.parseInt(tokens[0]);
            int d = Integer.parseInt(tokens[1]);
            int v = Integer.parseInt(tokens[2]);
            
            int[] coinValues = new int [d];
            
            tokens = in.readLine().trim().split("\\s+");
            
            for(int i = 0; i < d; i++)
            {
                coinValues[i] = Integer.parseInt(tokens[i]);
            }
            
            int currentValue = 1;
            int nextIndex = 0;
            int newDenomCoinsNeeded = 1;
            
            if(coinValues[0] == 1)
            {
                 nextIndex++;
                 newDenomCoinsNeeded--;
            }
            
            int counter = c + 1;
            
            while(counter <= v)
            {
                if(nextIndex < d)
                {
                    if(coinValues[nextIndex] <= counter)
                    {
                        currentValue = coinValues[nextIndex];
                        nextIndex++;
                        counter = c * currentValue + counter;
                    }
                    else
                    {
                        newDenomCoinsNeeded++;
                        currentValue = counter;
                        counter = currentValue * c + counter;
                    }
                }
                else
                {
                    newDenomCoinsNeeded++;
                    currentValue = counter;
                    counter = currentValue * c + counter;
                }
            }
            
            out.append(newDenomCoinsNeeded).append("\n");
        }
        
        System.out.println(out);
    }

}
