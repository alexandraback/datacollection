#include <bits/stdc++.h>

using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007


#define fin cin
#define fout cout
#define double long double
/*
ifstream fin("input.in");
ofstream fout("output.out");
*/
int hash[29];

    string s1,s2;
int k,l,s;
char ch[26];int x=0;

int countstring(string a,string b)
{
    int c=0;
    for(int i=0;i<a.length()-b.length()+1;i++)
    {
        string z=a.substr(i,b.length());
        if(z==b)c++;
    }
    return c;
}

double prob(string s)
{
    double kans=1;
    for(int i=0;i<s.length();i++)
    {
        int num=s[i]-'A';
        kans=kans*(double)hash[num]/s1.length();
    }
    return kans;
}

double zans=0;
int maxans=0;

void recur(string temp)
{
    if(temp.length()==s)
    {

        zans+=prob(temp)*countstring(temp,s2);
        //cout<<zans<<" ";
        maxans=max(maxans,countstring(temp,s2));
        //cout<<countstring(temp,s2)<<" ";
        return;
    }
    for(int i=0;i<x;i++)
    {
        recur(temp+ch[i]);
    }
}

int main()
{
    int t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(hash,0,sizeof(hash));
            x=0,zans=0,maxans=0;
            fin>>k>>l>>s;
            fin>>s1>>s2;
            for(int i=0;i<s1.length();i++)
            {
                int num=s1[i]-'A';
                hash[num]++;
            }
            for(int i=0;i<26;i++)
            {
                if(hash[i]!=0)
                {
                    ch[x++]=i+'A';
                }
            }
            /*
            for(int i=0;i<x;i++)fout<<ch[i];
            fout<<endl;
            */
                    cout<<"Case #"<<i<<": ";
        //fout<<ans;

            string temp;
            recur(temp);
            //cout<<zans<<endl;
            double u=maxans;
            printf("%.7Lf\n",u-zans);
    }
}
