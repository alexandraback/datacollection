package googlecodejam2012_qualification;
/** 
 * @author neil
 */
import java.io.*;
import java.util.*;
public class NewMain3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException
    {        
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));   
        BufferedReader in = new BufferedReader(new FileReader("C:\\Documents and Settings\\neil\\Desktop\\B-small-in.in"));        
        BufferedWriter out = new BufferedWriter(new FileWriter("C:\\Documents and Settings\\neil\\Desktop\\B-small-output.txt"));
        PrintStream ps = new PrintStream(System.out,true);
        StringTokenizer st;//st = new StringTokenizer(in.readLine()," ");
        int count=0;
        int t = Integer.parseInt(in.readLine());
        while(count++<t)
        {
            int score=0;
            
            st = new StringTokenizer(in.readLine()," ");
            int n = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            
            int a[] = new int[n];
            
            for(int i=0;i<n;i++)
            {
                a[i] = Integer.parseInt(st.nextToken());
            }
            
            boolean selected[] = new boolean[n];
            
            //int b[] = new int[n];
            
            for(int i=0;i<n;i++)
            {
                if(a[i]>=p)
                {
                    if(a[i]%3==0)
                    {
                        if(a[i]/3>=p){ score++; selected[i] = true;}
                    }
                    else
                    {
                        if(a[i]/3+1>=p){ score++;selected[i] = true;}
                    }
                }
                
            }
            
            for(int i=0;i<n;i++)
            {
                if(!selected[i]&&a[i]>=p)
                {
                    if(s==0) break;
                    if(a[i]%3==2)
                    {
                        if(a[i]/3+2>=p){  score++; s--; }
                    }
                    else
                    {
                        if(a[i]/3+1>=p){ score++; s--;  }
                    }
                    
                }
            }
            
            
            
            
            ps.println("Case #"+count+": "+score);
            out.write("Case #"+count+": "+score+"\n");
            out.flush();
        }                
    }
}
