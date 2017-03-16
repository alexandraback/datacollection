#include <iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream fin("B-small-attempt2.in");
    ofstream fout("B-small-attempt2.out");
    int t, i, j;
    fin>>t;
    int n[t], s[t], p[t], d[200][200], c=0, num;
    for(i=0;i<t;i++)
    {
        fin>>n[i]>>s[i]>>p[i];
        for(j=0;j<n[i];j++)
            fin>>d[i][j];
    }
    for(i=0;i<t;i++)
    {
        c=0;
        for(j=0;j<n[i];j++)
        {
            if(p[i]>10)
                break;
            num=d[i][j];
            if(num<=1)
            {
                if(num>=p[i])
                    c++;
            }
            else if(num==2)
            {
                if(p[i]<=1)
                    c++;
                else if(p[i]==2 && s[i]>0)
                {
                    c++;
                    s[i]--;
                }
            }
            else if(num>27)
                c++;
            else if((num/3)>=p[i])
                c++;
            else if(num%3==2)
            {
                if((num/3+1)>=p[i])
                    c++;
                else if((num/3+2)>=p[i] && s[i]>0)
                {
                    c++;
                    s[i]--;
                }
            }
            else if(num%3==1)
            {
                if((num/3+1)>=p[i])
                    c++;
            }
            else if((num/3+1)>=p[i] && s[i]>0)
            {
                c++;
                s[i]--;
            }
        }
        fout<<"Case #"<<i+1<<": "<<c<<"\n";
    }
    return 0;
}
