// Time Remaining: 59min 14sec Rank: 1003 Score: 21
// Let's start

// Time Remaining: 14min 14sec Rank: 1672 Score: 21
// For Small
import java.util.*;
import java.io.*;

public class B
{
    static final int INF=1<<29;
    static int h,n,m;
    static int[][] ceil=new int[104][104];
    static int[][] floor=new int[104][104];

    static int[][] mindis=new int[104][104];
    static boolean[][] done=new boolean[104][104];

    static int[] dx=new int[]{-1,1,0,0};
    static int[] dy=new int[]{0,0,-1,1};

    static void edsger()
    {
        while(true)
        {
            int bx=-1,by=-1;
            for(int i=2;i<n+2;i++)
            for(int j=2;j<m+2;j++)
                if(!done[i][j]&&(bx==-1||mindis[i][j]<mindis[bx][by]))
                {
                    bx=i;
                    by=j;
                }
            if(bx==-1)
                break;
            done[bx][by]=true;

            for(int r=0;r<4;r++)
            {
                int nx=bx+dx[r];
                int ny=by+dy[r];
                if(floor[bx][by]+50>ceil[nx][ny]||floor[nx][ny]+50>ceil[nx][ny])
                    continue;
                if(floor[nx][ny]+50>ceil[bx][by])
                    continue;
                int curtime=Math.max(mindis[bx][by],h-(ceil[nx][ny]-50));
                int curh=h-curtime;
                int bij=100;
                if(curh-floor[bx][by]>=20)
                    bij=10;
                if(curtime==0)
                    bij=0;
                mindis[nx][ny]=Math.min(mindis[nx][ny],curtime+bij);
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int cas=1;cas<=t;cas++)
        {
            h=sc.nextInt();
            n=sc.nextInt();
            m=sc.nextInt();
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    ceil[i+2][j+2]=sc.nextInt();
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    floor[i+2][j+2]=sc.nextInt();
            for(int i=0;i<mindis.length;i++)
                Arrays.fill(mindis[i],INF);
            mindis[2][2]=0;
            for(int i=0;i<mindis.length;i++)
                Arrays.fill(done[i],false);
            edsger();
            double res=mindis[n+1][m+1]/10.0;
            System.out.println("Case #"+cas+": "+res);
        }
    }
}