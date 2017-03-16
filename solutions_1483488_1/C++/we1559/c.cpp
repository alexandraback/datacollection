#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int toint(char* source)
{
    int ln=strlen(source);
    int ret=0;
    for(int i=0;i<ln;i++)
        ret=ret*10+source[i]-'0';
    return ret;
}

void tochar(int source,char* target)
{
    int ln=0;
    char help[10];
    while(source!=0)
    {
        help[ln++]='0'+(source%10);
        source/=10;
    }
    for(int i=0;i<ln;i++)
        target[i]=help[ln-i-1];
    target[ln]='\0';
}

int main()
{
    int t,Anum,Bnum,n,m,result,s,te;
    int data[1000];
    char A[10],B[10],N[10],M[10];
    cin>>t;
    for(int casenum=1;casenum<=t;casenum++)
    {
        cin>>A>>B;
        result=te=0;
        int la=strlen(A),lb=strlen(B);
        Anum=Bnum=0;
        for(int i=0;i<la;i++)
            Anum=Anum*10+A[i]-'0';
        for(int i=0;i<lb;i++)
            Bnum=Bnum*10+B[i]-'0';
        for(n=Anum;n<Bnum;n++)
        {
            s=0;
            tochar(n,N);
            int ln=strlen(N);
            for(int i=1;i<ln;i++)
            {
                for(int j=0;j<ln;j++)
                {
                    M[(j+i)%ln]=N[j];
                }
                M[ln]='\0';
                m=toint(M);
                if(m>=Anum && m<=Bnum && m>n)
                {
                    data[s]=m;
                    s++;
                }
            }
            sort(data,data+s);
            int now=data[0];
            if(s!=0)
                result++;
            for(int o=1;o<s;o++)
            {
                if(now!=data[o])
                {
                    result++;
                    now=data[o];
                }
            }
        }
        cout<<"Case #"<<casenum<<": "<<result<<endl;
    }
    return 0;
}
