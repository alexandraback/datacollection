#include <bits/stdc++.h>

using namespace std;

int ta;
int menor = 1000;
char s1[5], s2[5], rs1[5], rs2[5];

void rec2(int i)
{
    if(i==ta)
    {
        //cout<<"chegou"<<endl;
        int v = abs(atoi(s1)-atoi(s2));
        //cout<<s1<<" "<<s2<<endl;
        if(v<menor)
        {
            menor = v;
            rs1[0] = s1[0];
            rs1[1] = s1[1];
            rs1[2] = s1[2];
            rs1[3] = s1[3];
            rs2[0] = s2[0];
            rs2[1] = s2[1];
            rs2[2] = s2[2];
            rs2[3] = s2[3];
        }
        return;
    }
    int k;
    if(s2[i]=='?')
    {
        for(k=0;k<10;k++)
        {
            s2[i] = '0'+k;
            rec2(i+1);
        }
        s2[i]='?';
    }
    else
        rec2(i+1);
}

void rec(int i)
{
    if(i==ta)
    {
        rec2(0);
        return;
    }
    int j;
    if(s1[i]=='?')
    {
        for(j=0;j<10;j++)
        {
            s1[i]='0'+j;
            rec(i+1);
        }
        s1[i]='?';
    }
    else
        rec(i+1);
}

void resolver(int t)
{
    int i, m = 0;
    scanf("%s %s", s1, s2);
    ta = strlen(s1);
    menor = 1000;
    rec(0);
    cout<<"Case #"<<t<<": "<<rs1<<" "<<rs2<<endl;
}

int main()
{
    int t, i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
