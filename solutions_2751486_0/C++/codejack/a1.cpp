#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
    long long int i,j,k,l,m,n,t,sum,last,p,q,T;
    char s[1000010];
    bool flag;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>t;
    T=t;
    getchar();
    while(t--)
    {
        //sum=0;
        fscanf (fin, "%s", s+1);
        //scanf("%s",s+1);
        fin>>s+1;
        fin>>n;
        fgetc(fin);
        l=strlen(s+1);
        flag=true;
        last=0;
        for(i=1;i+n-1<=l;i++)
        {
            k=0;
            for(j=i;j<=l;j++)
            {
                if(s[j]!='a' && s[j]!='e'&& s[j]!='i' && s[j]!='o' && s[j]!='u')
                k++;
                else
                break;
            }
            if(k>=n)
            {
                while(k>=n)
                {
                    if(flag)
                    {
                        p=(i-last);
                        q=l-(i+n-1)+1;
                        sum+=(p*q);
                        last=i;
                        flag=false;
                    }
                    else
                    {
                        p=(i-last);
                        q=l-(i+n-1)+1;
                        sum+=(p*q);
                        last=i;
                    }
                    i++;
                    k--;
                }
            }
            else
            i=j;
        }
        fout<<"Case #"<<T-t<<": "<<sum<<"\n";

    }
    return 0;
}
