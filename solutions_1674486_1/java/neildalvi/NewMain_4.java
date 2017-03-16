package googlecodejam2012_round1B;
/** 
 * @author neil
 */
import java.io.*;
import java.util.*;
public class NewMain_4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException
    {        
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));   
        BufferedReader in = new BufferedReader(new FileReader("C:\\Documents and Settings\\neil\\Desktop\\A-large.in"));        
        BufferedWriter out = new BufferedWriter(new FileWriter("C:\\Documents and Settings\\neil\\Desktop\\A-large-practice-output.txt"));
        //PrintStream ps1 = new PrintStream(new FileOutputStream("C:\\Documents and Settings\\neil\\Desktop\\B-large-practice-output.txt"),true); 
        PrintStream ps = new PrintStream(System.out,true);
        StringTokenizer st;//st = new StringTokenizer(in.readLine()," ");
        int t = Integer.parseInt(in.readLine());
        int count=0;
        while(count++<t)
        {
            st = new StringTokenizer(in.readLine()," ");
            int n = Integer.parseInt(st.nextToken());
            int a[][] = new int[n][n];
            int m[] = new int[n];
            for(int i=0;i<n;i++)
            {
                st = new StringTokenizer(in.readLine()," ");
                m[i] = Integer.parseInt(st.nextToken());
                for(int j=0;j<m[i];j++)
                    a[i][j] = Integer.parseInt(st.nextToken());
            }
            ArrayList<Integer> b = new ArrayList<Integer>();
            b.clear();
            boolean flag = false;
            for(int i=0;i<n;i++)
            {
                if(m[i]>=2)
                {
                    b.add(i);
                     boolean v[] = new boolean[n];
                    v[i] = true;
                   
                    while(!b.isEmpty()&&!flag)
                    {
                        int temp = b.remove(0);
                        for(int j=0;j<m[temp];j++)
                        {
                            if(v[a[temp][j]-1])
                            {
                                flag = true;
                                break;
                            }
                            else
                            {
                                v[a[temp][j]-1] = true;
                                b.add(a[temp][j]-1);
                            }
                        }
                    }
                }
            }
            if(flag)
            {
                ps.println("Case #"+count+": Yes");
                out.write("Case #"+count+": "+"Yes"+"\n");
                 out.flush();
            }
            else
            {
                ps.println("Case #"+count+": No");
                out.write("Case #"+count+": "+"No"+"\n");
            out.flush();
            }
            
        }                
    }
}
