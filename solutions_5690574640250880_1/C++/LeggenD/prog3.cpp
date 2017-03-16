#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

bool check_prime(int D)
{
    int i,j=sqrt(D);
    if (D%2 ==0)
    {
        return false;
    }
    for(i=3;i<=j;i+2)
    {
        if (D%i ==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int T,x,i,j,R,C,M,D,M1,k,l,m,F1=0,F2=0;
    fstream input;
    fstream output;
    input.open("C-large.in",ios::in);
    output.open("large-ot.txt",ios::out);
    input>>T;
    for (x=1;x<=T;x++)
    {
        input>>R>>C>>M;
        D=(R*C)-M;
        output<<"Case #"<<x<<":"<<endl;
        if (D==1)
        {
            for (k=0;k<R-1;k++)
            {
                for(l=0;l<C;l++)
                    output<<"*";
                output<<endl;
            }
            for(l=0;l<C-1;l++)
                output<<"*";
            output<<"c";
            output<<endl;
        }
        else if (R==1 && M<C-1)
        {
            output<<"c";
            for(i=1;i<C-M;i++)
                output<<".";
            for(i=0;i<M;i++)
                output<<"*";
            output<<endl;
        }
        else if (R==1)
        {
            output<<"Impossible"<<endl;
        }
        else if (C==1 && M<R-1)
        {
            output<<"c"<<endl;
            for(i=1;i<R-M;i++)
                output<<"."<<endl;
            for(i=0;i<M;i++)
                output<<"*"<<endl;
        }
        else if (C==1)
        {
            output<<"Impossible"<<endl;
        }
        else if (M>(R*C)-4)
        {
            output<<"Impossible"<<endl;
        }
        else if (D==5 || D==7 )
        {
            output<<"Impossible"<<endl;
        }
        else
        {
            F1=0;
            F2=0;
            for (m=2;m<=R;m++)
            {
                if (D%m ==0 && (D/m<C && D/m>1))
                {
                    F1=m;
                    F2=D/m;
                    break;
                }
            }
            if (!(F1<2 || F2<2))
            {
                for (k=0;k<R-F1;k++)
                {
                    for(l=0;l<C;l++)
                        output<<"*";
                    output<<endl;
                }
                for(k;k<R-1;k++)
                {
                    for(l=0;l<C-F2;l++)
                        output<<"*";
                    for(l;l<C;l++)
                        output<<".";
                    output<<endl;
                }
                for(l=0;l<C-F2;l++)
                    output<<"*";
                for(l;l<C-1;l++)
                    output<<".";
                output<<"c";
                output<<endl;
            }
            else
            {
                i=0;
                j=0;
                M1=M;
                while (M1>=C && i<R-2)
                {
                    M1=M1-C;
                    i++;
                }
                while (M1>=(R-i) && j<(C-2))
                {
                    M1=M1-(R-i);
                    j++;
                }
                if (M1==0)
                {
                    for(k=0;k<i;k++)
                    {
                        for(l=0;l<C;l++)
                            output<<"*";
                        output<<endl;
                    }
                    for (k=i;k<R-1;k++)
                    {
                        for(l=0;l<j;l++)
                            output<<"*";
                        for(l;l<C;l++)
                            output<<".";
                        output<<endl;
                    }
                    for(l=0;l<j;l++)
                        output<<"*";
                    for(l;l<C-1;l++)
                        output<<".";
                    output<<"c";
                    output<<endl;
                }
                else if(i==R-2 || j==C-2)
                {
                    output<<"Impossible"<<endl;
                }
                else
                {
                    for(k=0;k<i;k++)
                    {
                        for(l=0;l<C;l++)
                            output<<"*";
                        output<<endl;
                    }
                    for (k=i;k<R-1;k++)
                    {
                        for(l=0;l<j;l++)
                            output<<"*";
                        if (M1>=C-j-2)
                        {
                            for(l;l<C-2;l++)
                                output<<"*";
                            M1=M1-(C-j-2);
                        }
                        else
                        {
                            for(l;M1>0;l++)
                            {
                                output<<"*";
                                M1--;
                            }
                        }
                        for(l;l<C;l++)
                            output<<".";
                        output<<endl;
                    }
                    for(l=0;l<j;l++)
                        output<<"*";
                    for(l;l<C-1;l++)
                        output<<".";
                    output<<"c";
                    output<<endl;
                }
            }
        }
    }
    input.close();
    output.close();
    return 0;
}
