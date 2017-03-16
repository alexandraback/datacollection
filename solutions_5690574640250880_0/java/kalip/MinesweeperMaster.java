import java.io.*;
import java.util.*;
class MinesweeperMaster
{
    PrintWriter pr;
    int I,R=4,C=7,M=3,min[][];
    boolean flag;
    public static void main(String args[])throws IOException
    {
        new MinesweeperMaster().go2();
    }
    public void go2()throws IOException
    {
        BufferedReader bf=new BufferedReader(new FileReader("csmall.in"));
        pr=new PrintWriter(new FileWriter("out.txt"));
        StringTokenizer st;
        int N=Integer.parseInt(bf.readLine());
        for(I=1;I<=N;I++)
        {
            st=new StringTokenizer(bf.readLine());
            R=Integer.parseInt(st.nextToken());
            C=Integer.parseInt(st.nextToken());
            M=Integer.parseInt(st.nextToken());
            System.out.println(R+" "+C+" "+M);
            if(M==0)
            {
                
                    System.out.println("Case #"+I+":");
                    pr.println("Case #"+I+":");
                for(int i =0;i<R;i++)
                {
                            for(int j=0;j<C;j++)
                            {
                                if(i==0&&j==0)
                                {
                                    System.out.print("c");
                                    pr.print("c");
                                }
                                else
                                {
                                    System.out.print(".");
                                    pr.print(".");
                                }
                             }
                            System.out.println();
                            pr.println();
                 }
                }
             else if(R*C-M==1)
            {
                
                    System.out.println("Case #"+I+":");
                    pr.println("Case #"+I+":");
                for(int i =0;i<R;i++)
                {
                            for(int j=0;j<C;j++)
                            {
                                if(i==0&&j==0)
                                {
                                    System.out.print("c");
                                    pr.print("c");
                                }
                                else
                                {
                                    System.out.print("*");
                                    pr.print("*");
                                }
                             }
                            System.out.println();
                            pr.println();
                 }
                }
            else
            {
                    System.out.println("Case #"+I+":");
                    pr.println("Case #"+I+":");
                    min=new int[R][C];
                    M=R*C-M;
                    if(M>0)
                        min[0][0]=1;
                    M--;
                    if(M>0)
                        paintAllNeighbours();
                    flag=check();
                    if(!flag)
                    {
                        repair();
                        flag=check();
                    }
                    if(!flag)
                    {
                        pr.println("Impossible");
                        System.out.println(flag);
                    }
                    //else 
                    {
                        for(int i =0;i<R;i++)
                        {
                            for(int j=0;j<C;j++)
                            {
                                if(i==0&&j==0)
                                {
                                    System.out.print("c");
                                    if(flag)
                                        pr.print("c");
                                }
                                else if(min[i][j]==0)
                                {
                                    System.out.print("*");
                                    if(flag)
                                        pr.print("*");
                                }
                                else
                                {
                                    System.out.print(".");
                                    if(flag)
                                        pr.print(".");
                                }
                            }
                            System.out.println();
                            if(flag)
                                pr.println();
                        }
                    }
            }
        }
        bf.close();
        pr.close();
    }
    public void paintAllNeighbours()
    {
        int u=0,v=0;
        while(M>0)
        {
            if(u<C)
            {
                for(int i=0;i<v&&M>0;i++)
                {
                    if(min[i][u]==0&&M>0)
                    {
                        min[i][u]=1;
                        M--;
                    }
                }
                u++;
            }
            if(v<R)
            {
                for(int i=0;i<u&&M>0;i++)
                {
                    if(min[v][i]==0&&M>0)
                    {
                        min[v][i]=1;
                        M--;
                    }
                }
                v++;
            }
        }
    }
    
    public void repair()
    {
        flag=true;
        int c=0,mx=0,my=0,c1,c2,nx=0,ny=0;
        outer :
        for(int i=C-1;i>0;i--)
        {
            c=0;
            for(int j=0;j<R;j++)
            {
                if(min[j][i]==1)
                    c++;
                else
                {
                    if(c==0)
                        continue outer;
                    else if(c>2)
                    {
                        mx=j-1;
                        my=i;
                        break outer;
                    }
                    if(c==1)
                    {
                        mx=j-1;
                        my=i;
                        break outer;
                    }
                }
            }
        }
        c1=c;
        outer :
        for(int i=R-1;i>0;i--)
        {
            c=0;
            for(int j=0;j<C;j++)
            {
                if(min[i][j]==1)
                    c++;
                else
                {
                    if(c==0)
                        continue outer;
                    else if(c>2)
                    {
                        nx=i;
                        ny=j-1;
                        break outer;
                    }
                    if(c==1)
                    {
                        nx=i;
                        ny=j-1;
                        break outer;
                    }
                }
            }
        }
        c2=c;
        if(mx+1==nx&&my==ny+1)
        {
            return;
        }
        if(c1==c2&&c1==1)
        {
            min[mx][my]=0;
            min[nx][ny+1]=1;
        }
        if(c1==1&&c2>2)
        {
            min[mx+1][my]=1;
            min[nx][ny]=0;
        }
        if(c2==1&&c1>2)
        {
            min[mx][my]=0;
            min[nx][ny+1]=1;
        }
    }
    
    public boolean check()
    {
        int tmp[][]=new int[R][C];
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(min[i][j]==0)
                    tmp[i][j]=-1;
                else
                    tmp[i][j]=0;
            }
        }
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
            {
                if(tmp[i][j]==0)
                {
                    if(i+1<R&&tmp[i+1][j]==-1)
                        tmp[i][j]++;
                        
                    if(i-1>=0&&tmp[i-1][j]==-1)
                        tmp[i][j]++;
                        
                    if(j+1<C&&tmp[i][j+1]==-1)
                        tmp[i][j]++;
                    
                    if(j-1>=0&&tmp[i][j-1]==-1)
                        tmp[i][j]++;
                        
                    if(i+1<R&&j+1<C&&tmp[i+1][j+1]==-1)
                        tmp[i][j]++;
                        
                    if(i+1<R&&j-1>=0&&tmp[i+1][j-1]==-1)
                        tmp[i][j]++;
                        
                    if(j+1<C&&i-1>=0&&tmp[i-1][j+1]==-1)
                        tmp[i][j]++;
                    
                    if(j-1>=0&&i-1>=0&&tmp[i-1][j-1]==-1)
                        tmp[i][j]++;
                }
            }
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
            {
                if(tmp[i][j]>0)
                {
                    if(i+1<R&&tmp[i+1][j]==0)
                         continue;
                        
                    if(i-1>=0&&tmp[i-1][j]==0)
                        continue;
                        
                    if(j+1<C&&tmp[i][j+1]==0)
                        continue;
                    
                    if(j-1>=0&&tmp[i][j-1]==0)
                        continue;
                        
                    if(i+1<R&&j+1<C&&tmp[i+1][j+1]==0)
                        continue;
                        
                    if(i+1<R&&j-1>=0&&tmp[i+1][j-1]==0)
                        continue;
                        
                    if(j+1<C&&i-1>=0&&tmp[i-1][j+1]==0)
                        continue;
                    
                    if(j-1>=0&&i-1>=0&&tmp[i-1][j-1]==0)
                        continue;
                    System.out.println(i+" "+j);
                    return false;
                }
            }
            return true;
        
    }
    
    public void go()throws IOException
    {
        
    }
}