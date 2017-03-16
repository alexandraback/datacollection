/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2012_qualification;
import java.io.*;
import java.util.*;
/** 
 * @author neil
 */
public class NewMain2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)  throws IOException
    {         
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));   
        BufferedReader in = new BufferedReader(new FileReader("C:\\Documents and Settings\\neil\\Desktop\\C-large.in"));        
        BufferedWriter out = new BufferedWriter(new FileWriter("C:\\Documents and Settings\\neil\\Desktop\\C-large-output.txt"));
        PrintStream ps = new PrintStream(System.out,true);
        StringTokenizer st;//st = new StringTokenizer(in.readLine()," ");
        int t = Integer.parseInt(in.readLine());
        int count=0,count1=0;
        while(count++<t)
        {
            count1=0;
            st = new StringTokenizer(in.readLine()," ");
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            //boolean n[] = new boolean[B+1];
            for(int i=A;i<=B;i++)
            {
                String N = Integer.toString(i);
                 ArrayList<String> hey = new ArrayList<String>();
                for(int j=1;j<N.length();j++)
                {
                   
                    N = N.substring(N.length()-1)+N.substring(0,N.length()-1);
                    if(!N.startsWith("0")&&(Integer.parseInt(N)>=A&&Integer.parseInt(N)<i)&&!hey.contains(N))
                    {
                        hey.add(N);
                        //System.out.println(N+" : "+i);
                        count1++;                                                
                    }                    
                }                            
            }                                                        
            
            ps.println("Case #"+count+": "+count1);
            out.write("Case #"+count+": "+count1+"\n");
            out.flush();
        }   
       
       
    }
}
