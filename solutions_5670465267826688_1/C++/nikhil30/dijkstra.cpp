#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;


#define cin fin
#define cout fout


int s[10000005];
int from[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int p[10000005];

void pre(int len)
{
    p[0]=s[0];
    for(int i=1;i<len;i++)
    {
        p[i]=from[(abs)(p[i-1])][s[i]];
        if(p[i-1]<0) p[i]*=-1;
    }
}


int main()
{
    ifstream fin;
    fin.open("C-large.in");
    ofstream fout;
    fout.open("output.txt");
    int test_case;
    cin>>test_case;
    for(int h=1;h<=test_case;h++)
    {
        cout<<"Case #"<<h<<": ";
        lol l,x;
        cin>>l>>x;
        lol temp=x/4;
        if(temp>2)
        {
            temp-=2;
            temp*=4;
            x-=temp;
        }
        string str;
        cin>>str;
        bool flag=true;
        for(int i=0;i<l;i++)
        {
            if(str[i]=='i') s[i]=2;
            else if(str[i]=='j') s[i]=3;
            else if(str[i]=='k') s[i]=4;
        }
        for(int i=1;i<x;i++)
        {
            for(int j=0;j<l;j++)
            {
                s[i*l+j]=s[j];
            }
        }
        int len=l*x;
        pre(len);
        if(p[len-1]!=-1) flag=false;
        len--;


        int first_i_pos=-1,last_k_pos=-1;


        for(int i=0;i<len;i++)
        {
            if(p[i]==2)
            {
                first_i_pos=i;
                break;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(p[i]==4)
            {
                last_k_pos=i;
            }
        }
        if(last_k_pos<=first_i_pos || first_i_pos==-1) flag=false;
        (flag)?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}
