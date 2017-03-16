import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
public class CaptainHammer
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        FileWriter out = new FileWriter(new File("out.txt"));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int Z = Integer.parseInt(st.nextToken());
        for(int z = 1; z <= Z; z++)
        {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            int[] m = new int[N];
            st = new StringTokenizer(br.readLine());
            for(int i=0;i<N;i++) {
                m[i]=Integer.parseInt(st.nextToken());
            }
            Arrays.sort(m);
            if(A==1) {
                int ans=N;
                System.out.println("Case #" +z+ ": " +ans);
                out.write("Case #" +z+ ": " +ans +"\n");
            } else {
                int ans=1000000;
                for(int i=0;i<=N;i++) {
                    int currAns=N-i;
                    int currA=A;
                    for(int j=0;j<i;j++) {
                        while(currA<=m[j]) {
                            currAns++;
                            currA+=currA-1;
                        }
                        currA+=m[j];
                    }
                    ans=Math.min(ans,currAns);
                }
                System.out.println("Case #" +z+ ": " +ans);
                out.write("Case #" +z+ ": " +ans +"\n");
            }
        }
        out.close();
    }
}