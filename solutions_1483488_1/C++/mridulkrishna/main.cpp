#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

int main()
{
    long t, i, c, j, k, m, l, b, nos[10];
    char test[10], stack1[10], stack2[10], cmp[10];
    ofstream fout ("C-large.out");
    ifstream fin ("C-large.in");
    fin>>t;
    long tt[t][2];
    for(i=0;i<t;i++)
        fin>>tt[i][0]>>tt[i][1];
    for(i=0;i<t;i++)
    {
        c=0;
        for(j=0;j<10;j++)
            cmp[j]=0;
        itoa(tt[i][1], cmp, 10);
        for(j=tt[i][0];j<=tt[i][1];j++)
        {
            if(j<=10)
                continue;
            for(k=0;k<10;k++)
            {
                 test[k]=0;
                 nos[k]=0;
            }
            itoa(j, test, 10);
            for(k=1;test[k];k++)
            {
                if(test[k]>=test[0] && test[k]<=cmp[0])
                {
                    for(m=0;m<10;m++)
                    {
                        stack1[m]=0;
                        stack2[m]=0;
                    }
                    for(m=k, l=0;test[m];m++, l++)
                        stack1[l]=test[m];
                    stack1[l]=0;
                    for(m=0;m<k;m++)
                        stack2[m]=test[m];
                    stack2[m]=0;
                    strcat(stack1, stack2);
                    b = atoi(stack1);
                    if(b>j && b<= tt[i][1])
                    {
                        for(m=0;nos[m]!=0 && nos[m]!=b;m++);
                        if(nos[m]==0)
                        {
                            nos[m]=b;
                            c++;
                        }
                    }
                }
            }
        }
        fout<<"Case #"<<i+1<<": "<<c<<"\n";
    }
    return 0;
}
