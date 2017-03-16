#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;


#define cin fin
#define cout fout


int s[100005];
int from[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int p[100005];

void pre(int len)
{
    p[0]=s[0];
    for(int i=1;i<len;i++)
    {
        p[i]=from[(abs)(p[i-1])][s[i]];
        if(p[i-1]<0) p[i]*=-1;
    }
    /*for(int i=0;i<len;i++)
        cerr<<p[i]<<" ";
    cerr<<"\n";*/
}


int main()
{
    ifstream fin;
    fin.open("C-small-attempt0.in");
    ofstream fout;
    fout.open("output.txt");
    int test_case;
    cin>>test_case;
    for(int h=1;h<=test_case;h++)
    {
        cout<<"Case #"<<h<<": ";
        int l,x;
        cin>>l>>x;
        string str;
        cin>>str;
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
        bool flag=true;
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
        //cerr<<first_i_pos<<" "<<last_k_pos<<"\n";
        //cerr<<flag<<" sdfsdf\n";
        if(last_k_pos<=first_i_pos || first_i_pos==-1) flag=false;
        (flag)?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}
