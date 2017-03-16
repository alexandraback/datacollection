import java.io.*;

class Main3
{
    public static void main(String args[]) throws IOException
    {
        String in = null;
        BufferedReader br = new BufferedReader(new FileReader("inp.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
        int nooftest = Integer.parseInt(br.readLine());
        for(int i=0;i<nooftest;i++)
        {
            int R,C,M;
            String hh[] = br.readLine().split(" ");
            R = Integer.parseInt(hh[0]);
            C = Integer.parseInt(hh[1]);
            M = Integer.parseInt(hh[2]);
            bw.write("Case #"+(i+1)+":\n");
            int S = R * C;
            int B = S - M;
            
            if(B == 1)
            {
                char ch[][] = new char[R][C];
                for(int j=0;j<R;j++)
                {
                    for(int k=0;k<C;k++)
                    {
                        ch[j][k] = '*';
                    }
                }
                ch[0][0] = 'c';
                for(int j=0;j<R;j++)
                    bw.write(new String(ch[j])+"\n");
                continue;
            }
            
            int poss = 1;
            int minreq = 4;
            int min = Math.min(R,C);
            if(min == 1)
                minreq = 1;
            
            if(B < minreq)
            {
                bw.write("Impossible\n");
                continue;
            }
            
            if(B <= min*2)
            {
                if(B % 2 == 0)
                {
                    char ch[][] = new char[R][C];
                    for(int j=0;j<R;j++)
                    {
                        for(int k=0;k<C;k++)
                        {
                            ch[j][k] = '*';
                        }
                    }
                    if(min == R)
                    {
                        int d = 0;
                        for(int k=0;k<min && d<B;k++)
                        {
                            ch[k][0] = '.';
                            ch[k][1] = '.';
                            d += 2;
                        }
                    }
                    else
                    {
                        int d = 0;
                        for(int k=0;k<min && d<B;k++)
                        {
                            ch[0][k] = '.';
                            ch[1][k] = '.';
                            d += 2;
                        }
                    }
                    ch[0][0] = 'c';
                    for(int j=0;j<R;j++)
                        bw.write(new String(ch[j])+"\n");
                    continue;
                }
                else
                {
                    poss = 0;
                }
            }
            
            if(B > min*2)
            {
                if(B % min == 1)
                {
                    poss = 0;
                }
                else
                {
                    char ch[][] = new char[R][C];
                    for(int j=0;j<R;j++)
                    {
                        for(int k=0;k<C;k++)
                        {
                            ch[j][k] = '*';
                        }
                    }
                    if(min == R)
                    {
                        int d = 0;
                        for(int j=0;j<C && d<B;j++)
                        {
                            for(int k=0;k<R && d<B;k++)
                            {
                                ch[k][j] = '.';
                                d++;
                            }
                        }
                    }
                    else
                    {
                        int d = 0;                        
                        for(int j=0;j<R && d<B;j++)
                        {
                            for(int k=0;k<C && d<B;k++)
                            {
                                ch[j][k] = '.';
                                d++;
                            }
                        }
                    }
                    ch[0][0] = 'c';
                    for(int j=0;j<R;j++)
                        bw.write(new String(ch[j])+"\n");
                    continue;
                }
            }
            
            min = Math.max(R,C);
            
            if(B <= min*2)
            {
                if(B % 2 == 0)
                {
                    char ch[][] = new char[R][C];
                    for(int j=0;j<R;j++)
                    {
                        for(int k=0;k<C;k++)
                        {
                            ch[j][k] = '*';
                        }
                    }
                    if(min == R)
                    {
                        int d = 0;
                        for(int k=0;k<min && d<B;k++)
                        {
                            ch[k][0] = '.';
                            ch[k][1] = '.';
                            d += 2;
                        }
                    }
                    else
                    {
                        int d = 0;
                        for(int k=0;k<min && d<B;k++)
                        {
                            ch[0][k] = '.';
                            ch[1][k] = '.';
                            d += 2;
                        }
                    }
                    ch[0][0] = 'c';
                    for(int j=0;j<R;j++)
                        bw.write(new String(ch[j])+"\n");
                    continue;
                }
                else
                {
                    bw.write("Impossible\n");
                    continue;
                }
            }
            
            if(B > min*2)
            {
                if(B % min == 1)
                {
                    bw.write("Impossible\n");
                    continue;
                }
                else
                {
                    char ch[][] = new char[R][C];
                    for(int j=0;j<R;j++)
                    {
                        for(int k=0;k<C;k++)
                        {
                            ch[j][k] = '*';
                        }
                    }
                    if(min == R)
                    {
                        int d = 0;
                        for(int j=0;j<C && d<B;j++)
                        {
                            for(int k=0;k<R && d<B;k++)
                            {
                                ch[k][j] = '.';
                                d++;
                            }
                        }
                    }
                    else
                    {
                        int d = 0;                        
                        for(int j=0;j<R && d<B;j++)
                        {
                            for(int k=0;k<C && d<B;k++)
                            {
                                ch[j][k] = '.';
                                d++;
                            }
                        }
                    }
                    ch[0][0] = 'c';
                    for(int j=0;j<R;j++)
                        bw.write(new String(ch[j])+"\n");
                    continue;
                }
            }
        }
        bw.flush();
        bw.close();
        System.out.println("done");
    }
    /*
    static void click(char ch[][], int j, int k)
    {
        char ch[][] = new char[R][C];
                    for(int j=0;j<R;j++)
                    {
                        for(int k=0;k<C;k++)
                        {
                            ch[j][k] = '*';
                        }
                    }
                    if(min == R)
                    {
                        for(int k=0;k<min;k++)
                        {
                            ch[k][0] = '.';
                            ch[k][1] = '.';
                        }
                    }
                    else
                    {
                        for(int k=0;k<min;k++)
                        {
                            ch[0][k] = '.';
                            ch[1][k] = '.';
                        }
                    }
                    ch[0][0] = 'c';
                    for(int j=0;j<R;j++)
                        bw.write(new String(ch[j])+"\n");
                    continue;
        
        
        
        if(ch[j][k]=='.')
        {
            int vv = 0;
            try{ if(ch[j-1][k-1] == '*') vv++; }catch(Exception mm){}
            try{ if(ch[j  ][k-1] == '*') vv++; }catch(Exception mm){}
            try{ if(ch[j+1][k-1] == '*') vv++; }catch(Exception mm){}
            try{ if(ch[j-1][k  ] == '*') vv++; }catch(Exception mm){}
            try{ if(ch[j+1][k  ] == '*') vv++; }catch(Exception mm){}
            try{ if(ch[j-1][k+1] == '*') vv++; }catch(Exception mm){}
            try{ if(ch[j  ][k+1] == '*') vv++; }catch(Exception mm){}
            try{ if(ch[j+1][k+1] == '*') vv++; }catch(Exception mm){}
            
            ch[j][k]=(char)(vv+48);
            
            if(vv==0)
            {
                try{ if(ch[j-1][k-1] == '.') click(ch,j-1,k-1); }catch(Exception mm){}
                try{ if(ch[j  ][k-1] == '.') click(ch,j  ,k-1); }catch(Exception mm){}
                try{ if(ch[j+1][k-1] == '.') click(ch,j+1,k-1); }catch(Exception mm){}
                try{ if(ch[j-1][k  ] == '.') click(ch,j-1,k  ); }catch(Exception mm){}
                try{ if(ch[j+1][k  ] == '.') click(ch,j+1,k  ); }catch(Exception mm){}
                try{ if(ch[j-1][k+1] == '.') click(ch,j-1,k+1); }catch(Exception mm){}
                try{ if(ch[j  ][k+1] == '.') click(ch,j  ,k+1); }catch(Exception mm){}
                try{ if(ch[j+1][k+1] == '.') click(ch,j+1,k+1); }catch(Exception mm){}     
            }
        }
    }*/
}