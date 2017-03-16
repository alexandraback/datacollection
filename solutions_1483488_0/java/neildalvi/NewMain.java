package googlecodejam2012_qualification;
/** 
 * @author neil
 */
import java.io.*;
import java.util.*;
public class NewMain {

    /**
     * @param args the command line arguments
     */
    static boolean recycle(int n,int m)
    {
        String N = Integer.toString(n);
        String M = Integer.toString(m);
        for(int i=1;i<N.length();i++)
        {
            N = N.substring(N.length()-1)+N.substring(0,N.length()-1);
            //System.out.println("checking "+N+" "+M);
            if(N.equals(M)) return true;
        }
        return false;
    }
    
    public static void main(String[] args) throws IOException
    {        
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));   
        BufferedReader in = new BufferedReader(new FileReader("./src/googlecodejam2012_qualification/io/C-small-input.in"));        
        BufferedWriter out = new BufferedWriter(new FileWriter("./src/googlecodejam2012_qualification/io/C-small-output.txt"));
        PrintStream ps = new PrintStream(System.out,true);
        StringTokenizer st;//st = new StringTokenizer(in.readLine()," ");
        int t = Integer.parseInt(in.readLine());
        int count=0,count1=0;
        while(count++<t)
        {
            st = new StringTokenizer(in.readLine()," ");
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            count1=0;
            for(int i=A;i<=B;i++)
            {
                int m = i;
                for(int j=A;j<m;j++)
                {
                    int n = j;
                    if(Integer.toString(m).length()==(Integer.toString(n).length())&&recycle(n,m))
                    {
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
