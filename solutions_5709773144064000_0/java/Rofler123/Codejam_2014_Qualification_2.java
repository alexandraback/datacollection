
package codejam_2014_qualification_2;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Codejam_2014_Qualification_2
{
    private static int T;
    private static double Farm;
    private static double Added;
    private static double Target;
    private static final String filename = "B-small-attempt0";
    public static void main(String[] args)
    {
        String file_content = read_file(filename + ".in");
        try
        {
            PrintWriter writer = new PrintWriter(filename + ".out", "UTF-8");
            Scanner sc = new Scanner(file_content);
            T = sc.nextInt();
            for(int t=0; t<T; t++)
            {
                Double Rate = 2.0;
                Farm = sc.nextDouble();
                Added = sc.nextDouble();
                Target = sc.nextDouble();
                Double last = Target/Rate;
                Double curr = last-((Target-Farm)/Rate)+Target/(Rate+Added);
                while(true)
                {
                    if(curr>last)
                        break;
                    Rate+=Added;
                    last = curr;
                    curr = last-((Target-Farm)/Rate)+Target/(Rate+Added);
                }
                writer.println("Case #" + (t + 1) + ": " + last);
            }
            writer.close();
            sc.close();
        } catch(InputMismatchException imme) {
        } catch(FileNotFoundException e) {
        } catch (UnsupportedEncodingException ex) {
            Logger.getLogger(Codejam_2014_Qualification_2.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    private static String read_file(String f)
    {
        String file_content = "";
        try
        {
            BufferedReader br = new BufferedReader(new FileReader(f));
            StringBuilder sb = new StringBuilder();
            String line = br.readLine();
            while (line != null)
            {
                sb.append(line);
                sb.append("\n");
                line = br.readLine();
            }
            file_content = sb.toString();
        } catch (FileNotFoundException e) {
        } catch (IOException ex) {
            Logger.getLogger(Codejam_2014_Qualification_2.class.getName()).log(Level.SEVERE, null, ex);
        }
        return file_content;
    }
}

