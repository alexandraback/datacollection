import java.io.*;
import java.util.*;


/**
 * Write a description of class QuestionA here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class QA
{


    public static String readline(BufferedReader br)
    {
        String s = "";
        try{
            s = br.readLine();
        } catch (IOException ioe) {
            System.out.println("IO error trying to read the file!");
            System.exit(1);
        }
        return s;
    }

    public static void main(String[] args)
    {
         try 
        {
        InputStream ips=new FileInputStream("README.txt"); 
        
        
        InputStreamReader ipsr=new InputStreamReader(ips);
        BufferedReader br=new BufferedReader(ipsr);
        int cases = Integer.parseInt(readline(br));
        BufferedWriter writer;
       
            writer= new BufferedWriter(new OutputStreamWriter(new FileOutputStream("QA.txt"), "utf-8"));
            for(int c = 1; c <=cases; c++)
            {
                String[] words = readline(br).split(" ");
                int R = Integer.parseInt(words[0]);
                int C = Integer.parseInt(words[1]);
                int W = Integer.parseInt(words[2]);
                
                int count = R*(C/W);
                if(C%W == 0) count += (W-1);
                else count += W;
                
             

                writer.write("Case #"+c +": "+ count);
                writer.newLine();
            }
            writer.close();
        }

        catch (FileNotFoundException e) {System.out.println("Can't find the file!");} 
        catch (IOException ex) {System.out.println("IO error trying to write the file!");} 
       
        
    }       
    
    public static long min(ArrayList<Long> a, ArrayList<Long> b, int n)
    {
        Collections.sort(a);
        Collections.sort(b, Collections.reverseOrder());
    
        long count = 0;
        for (int i = 0; i < n; i++)
        {
            count += a.get(i)*b.get(i);
        }
        return count;
    }
}
