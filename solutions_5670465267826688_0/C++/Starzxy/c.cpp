#include<cstdio>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

int T,n;
long long t;
map<pair<string,string>,string>h;
string str,str1;
string f[80000],g[80000];

inline string pow(string s,long long p)
{
    if(p==1)return s;
    string temp=pow(s,p>>1);
    temp=h[make_pair(temp,temp)];
    if(p&1)temp=h[make_pair(temp,s)];
    return temp;
}
inline string calc()
{
    if(t==8)return "1";
    string temp=str.substr(0,1);
    int len=str.length();
    for(int i=1;i<len;i++)
        temp=h[make_pair(temp,str.substr(i,1))];
    return pow(temp,t-8);
}

inline void prepare()
{
    h[make_pair("1","1")]="1";
    h[make_pair("1","i")]="i";
    h[make_pair("1","j")]="j";
    h[make_pair("1","k")]="k";
    h[make_pair("1","-1")]="-1";
    h[make_pair("1","-i")]="-i";
    h[make_pair("1","-j")]="-j";
    h[make_pair("1","-k")]="-k";

    h[make_pair("i","1")]="i";
    h[make_pair("i","i")]="-1";
    h[make_pair("i","j")]="k";
    h[make_pair("i","k")]="-j";
    h[make_pair("i","-1")]="-i";
    h[make_pair("i","-i")]="1";
    h[make_pair("i","-j")]="-k";
    h[make_pair("i","-k")]="j";

    h[make_pair("j","1")]="j";
    h[make_pair("j","i")]="-k";
    h[make_pair("j","j")]="-1";
    h[make_pair("j","k")]="i";
    h[make_pair("j","-1")]="-j";
    h[make_pair("j","-i")]="k";
    h[make_pair("j","-j")]="1";
    h[make_pair("j","-k")]="-i";

    h[make_pair("k","1")]="k";
    h[make_pair("k","i")]="j";
    h[make_pair("k","j")]="-i";
    h[make_pair("k","k")]="-1";
    h[make_pair("k","-1")]="-k";
    h[make_pair("k","-i")]="-j";
    h[make_pair("k","-j")]="i";
    h[make_pair("k","-k")]="1";

    h[make_pair("-1","1")]="-1";
    h[make_pair("-1","i")]="-i";
    h[make_pair("-1","j")]="-j";
    h[make_pair("-1","k")]="-k";
    h[make_pair("-1","-1")]="1";
    h[make_pair("-1","-i")]="i";
    h[make_pair("-1","-j")]="j";
    h[make_pair("-1","-k")]="k";

    h[make_pair("-i","1")]="-i";
    h[make_pair("-i","i")]="1";
    h[make_pair("-i","j")]="-k";
    h[make_pair("-i","k")]="j";
    h[make_pair("-i","-1")]="i";
    h[make_pair("-i","-i")]="-1";
    h[make_pair("-i","-j")]="k";
    h[make_pair("-i","-k")]="-j";

    h[make_pair("-j","1")]="-j";
    h[make_pair("-j","i")]="k";
    h[make_pair("-j","j")]="1";
    h[make_pair("-j","k")]="-i";
    h[make_pair("-j","-1")]="j";
    h[make_pair("-j","-i")]="-k";
    h[make_pair("-j","-j")]="-1";
    h[make_pair("-j","-k")]="i";

    h[make_pair("-k","1")]="-k";
    h[make_pair("-k","i")]="-j";
    h[make_pair("-k","j")]="i";
    h[make_pair("-k","k")]="1";
    h[make_pair("-k","-1")]="k";
    h[make_pair("-k","-i")]="j";
    h[make_pair("-k","-j")]="-i";
    h[make_pair("-k","-k")]="-1";
}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);

    prepare();

    ios::sync_with_stdio(false);
    scanf("%d",&T);
    for(int K=1;K<=T;K++)
    {
        scanf("%d%I64d",&n,&t);
        //printf("%d %I64d\n",n,t);
        cin>>str;
        bool flag=false;
        if(t<=7)
        {
            str1=str;
            for(int i=2;i<=t;i++)str1=str1+str;
            int len=str1.length();

            f[0]=str1.substr(0,1);
            for(int i=1;i<len;i++)
                f[i]=h[make_pair(f[i-1],str1.substr(i,1))];
            g[len-1]=str1.substr(len-1,1);
            for(int i=len-2;i>=0;i--)
                g[i]=h[make_pair(str1.substr(i,1),g[i+1])];

            for(int i=0;i<len;i++)
                if(f[i]=="i")
                {
                    for(int j=len-1;j>i+1;j--)
                        if(g[j]=="k")
                        {
                            string temp=h[make_pair(g[i+1],pow("k",3))];

                            if(temp=="j")
                            {
                                //printf("%d %d %d\n",i,j);
                                flag=true;
                                break;
                            }
                        }
                    if(flag)break;
                }
        }
        else
        {
            str1=str+str+str+str;
            int len=str1.length();

            f[0]=str1.substr(0,1);
            for(int i=1;i<len;i++)
                f[i]=h[make_pair(f[i-1],str1.substr(i,1))];
            g[len-1]=str1.substr(len-1,1);
            for(int i=len-2;i>=0;i--)
                g[i]=h[make_pair(str1.substr(i,1),g[i+1])];

            string temp=calc();

            for(int i=0;i<len;i++)
                if(f[i]=="i")
                {
                    for(int j=0;j<len;j++)
                        if(g[j]=="k")
                        {
                            //printf("%d %d\n",i,j);
                            if(h[make_pair(h[make_pair(g[i+1],temp)],f[j-1])]=="j")
                            {
                                flag=true;
                                break;
                            }
                        }
                    if(flag)break;
                }
        }
        printf("Case #%d: ",K);
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
/*
5
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
*/
