import java.util.*;
import java.io.*;


public class problem2
{
    private final Scanner sc;
    private static final boolean debug = true;

    static void debug(Object ... objects)
    {
        if(debug)
            System.err.println(Arrays.toString(objects));        
    }

    problem2()
    {
        sc = new Scanner(new BufferedInputStream(System.in));
    }

    public static void main(String [] args)
    {
        (new problem2()).solve();
    }
    
    
    void solve()
    {
        int T = sc.nextInt();
        int cs = 0;
        while(cs < T)
        {
            cs++;
            int N =sc.nextInt();
            int level[][] = new int[N][2];
            boolean used[][] = new boolean[N][2];
            for(int i=0;i<N;i++)
            {
                level[i][0] = sc.nextInt();
                level[i][1] = sc.nextInt();
            }

            int stars = 0;
            int turns = 0;
            while(true)
            {
                int minIndex = -1;
                int type = -1;
                for(int i=0;i<N;i++)
                {
                    if(!used[i][1]&& level[i][1] <= stars)
                    {
                        minIndex=i;
                        type = 1;
                        break;
                    }
                    if(!used[i][0]&&level[i][0] <= stars&&
                            (minIndex == -1 || level[minIndex][1]<level[i][1]))
                    {
                        minIndex = i;
                        type = 0;                        
                    }
                }

                if(minIndex < 0) break;

                turns++;
                stars++;
                if(type == 1)
                {
                    used[minIndex][1] = true;
                    if(!used[minIndex][0])
                        stars+=1;
                }
                
                used[minIndex][0] = true;            
            }
            String answer = "Too Bad";
            if(stars == 2*N)
                answer = Integer.toString(turns);

            System.out.println("Case #" + cs+ ": "+answer);
        }

    }
}
