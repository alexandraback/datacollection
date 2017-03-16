/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Hardik
 */
import java.io.*;
import java.text.DecimalFormat;

public class Contestants {
    public static void main(String args []) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
        BufferedWriter brw = new BufferedWriter(new FileWriter("output"));

        int t = Integer.parseInt(br.readLine());
        for (int i = 0 ; i < t ; i++)
        {
            String [] inp = br.readLine().split(" ");
            int n = Integer.parseInt(inp[0]);
            int [] input = new int [n];
            int total = 0;
            int min = Integer.MAX_VALUE;
            int indexmin = 0;
            for (int j = 0 ; j < n ; j++)
            {
                input[j] = Integer.parseInt(inp[j+1]);
                total+=input[j];
                if (input[j] < min)
                    min = input[j];
            }

            double extra = (double) total - (min*n);
            double dd = ((total+extra)/total)/n;
            DecimalFormat d = new DecimalFormat("##.######");
            StringBuffer output = new StringBuffer();
            double f;
            int neg = 0;
            int rem =0;
            for (int k = 0 ;  k < n ; k++)
            {
                if (input[k]!= min)
                {
                    f = (dd - (((double) input[k] - min)/total));
                    if (f < 0)
                    {
                        neg++;
                        rem+=input[k];
                        input[k] = -1;
                    }
                }
            }

            extra =  (total - (min*(n-neg)) - rem);
            dd =  ((double)(total+extra)/total)/(n-neg);
            for (int k = 0 ; k < n ; k++)
            {
                if (input[k]==min)
                    output.append(Double.valueOf(d.format( dd*100)) + " ");
                else if(input[k] != -1)
                {
                    f = (double) (dd - (((double) input[k] - min)/total))*100;
                    output.append(Double.valueOf(d.format(f)) + " ");
                }
                else
                    output.append("0.0 ");
            }
            brw.write("Case #"+(i+1)+": "+output + "\n");
        
        }
        brw.close();
    }

}
