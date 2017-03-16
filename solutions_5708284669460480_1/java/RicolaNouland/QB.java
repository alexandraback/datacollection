import java.io.*;
import java.util.*;
//import org.apache.commons.io.FileUtils;
//import org.apache.commons.lang.StringUtils;

/**
 * Write a description of class QuestionA here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class QB
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
       
            writer= new BufferedWriter(new OutputStreamWriter(new FileOutputStream("QB.txt"), "utf-8"));
            for(int c = 1; c <=cases; c++)
            {
                String[] words = readline(br).split(" ");
                int K = Integer.parseInt(words[0]);
                int L = Integer.parseInt(words[1]);
                int S = Integer.parseInt(words[2]);
                
                String kb = readline(br);
                double[] tab = new double[128];
                ArrayList<Character> list= new ArrayList<Character>();
                for(int i = 0; i<K; i++)
                {
                    tab[kb.charAt(i)]++;
                }
                for(int i = 0; i<128; i++)
                {
                    if(tab[i] >0)
                    {
                        list.add((char)i);
                        tab[i] /= K;
                    }
                }
                
                
                
                String sb = readline(br);
                
                System.out.println(Arrays.toString(tab));
                System.out.println(list);
                double result = 0;
                
                if(Math.pow(list.size(), S) > 10000000)
                {
                    result = S/L;
                }
                else{
                int maxInst = 0;
                double totalProb =0;
                  String s = "";
                   ArrayList<String> sl= new ArrayList<String>();
                  createString(S, list, s, sl);

                  
                  
                for(int i = 0; i < sl.size(); i++)
                {
                  
                    s = sl.get(i);
                    double prob = 1;
                    for(int j =0; j<s.length();j++)
                    {
                        char ca = s.charAt(j);
                        //System.out.println(ca);
                        // System.out.println(tab[ca]);
                        prob *= tab[ca];
                        //System.out.println(prob);
                    }
                    
                    //System.out.println(s);
                   // System.out.println(prob);
                    int inst = instances(s, sb);
                    if(inst > maxInst) maxInst = inst;
                    totalProb += inst*prob;
                }
            
                
                    result = maxInst -totalProb;
            } 

writer.write("Case #"+c +": "+ result);
                writer.newLine();
            }
            writer.close();
        }

        catch (FileNotFoundException e) {System.out.println("Can't find the file!");} 
        catch (IOException ex) {System.out.println("IO error trying to write the file!");} 
       
        
    }       
    
    public static int instances(String s, String sb)
    {
        int count = 0;
        int ind = -1;
        while(ind+1 < s.length())
        {
          ind = s.indexOf(sb,ind+1);
          if (ind >= 0) count ++;
          else ind = s.length();
        }
        return count;
    }
    
     public static void createString(int S, ArrayList<Character> list, String start, ArrayList<String> result)
    {
        
        if(S==0)
        {
            result.add(start);
        }
        
        else{

        for(int i = 0; i< list.size(); i++)
        {
            char ca = list.get(i);
             
            createString(S-1, list, start+Character.toString(ca), result);
        }
        
    }
    }
}
