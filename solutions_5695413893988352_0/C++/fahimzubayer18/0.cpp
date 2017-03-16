#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<string>vi,vj;

void gen(string s,vector<string> &v,int i)
{
    if(i==s.size())
    {
        v.push_back(s);
        return;
    }
    if(s[i]!='?') gen(s,v,i+1);
    else
    {
        for(char c='0';c<='9';c++)
        {
            s[i]=c;
            gen(s,v,i+1);
        }
    }
}

int find_dif(string si,string sj)
{
    int i,j;
    i=j=0;
    for(int a=0;a<si.size();a++)
    {
        i=i*10+si[a]-'0';
        j=j*10+sj[a]-'0';
    }
    return abs(i-j);
}

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int a,b,c,d,e,x,y,z,t;



    scanf("%d",&t);

    for(int te=1;te<=t;te++)
    {
        printf("Case #%d: ",te);

        string si,sj;

        bool eq=true;

        cin>>si>>sj;

        vi.clear();
        vj.clear();

        gen(si,vi,0);
        gen(sj,vj,0);

        int dif;
        string ans_si,ans_sj;
        dif=-1;
        ans_si="";
        ans_sj="";

        for(a=0;a<vi.size();a++)
        {
            for(b=0;b<vj.size();b++)
            {
                x=find_dif(vi[a],vj[b]);

                if(dif==x)
                {
                    if(ans_si>vi[a])
                    {
                        ans_si=vi[a];
                        ans_sj=vj[b];
                    }
                    else
                    {
                        if(ans_si==vi[a])
                        {
                            if(ans_sj>vj[b])
                            {
                                ans_sj=vj[b];
                            }
                        }
                    }
                }
                else
                {
                    if(dif==-1 || dif>x)
                    {
                        dif=x;
                        ans_si=vi[a];
                        ans_sj=vj[b];
                    }
                }
            }
        }

        cout<<ans_si<<" "<<ans_sj<<endl;
    }


    return 0;
}
