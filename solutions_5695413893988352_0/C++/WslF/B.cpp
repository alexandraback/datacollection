//solution by Wsl_F
#include <bits/stdc++.h>

using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

int C,J;
string C_,J_;

int l;

void rec(string &s, int i)
{
    if (s[i]=='#')
    {
        int c= stoi(s.substr(0,l));
        int j= stoi(s.substr(l,l));
        //cout<<"c: "<<c<<"  j: "<<j<<endl;

        if (abs(c-j)==abs(C-J))
            if ((c<c) || (c==C && j<J))
                {C= c; J= j; C_= s.substr(0,l); J_= s.substr(l,l);}
        if (abs(c-j)<abs(C-J))
            {C= c; J= j; C_= s.substr(0,l); J_= s.substr(l,l);}
        return;
    }

    if (s[i]!='?') rec(s,i+1);
    else
    {
        for (int q= 0; q<10; q++)
        {
            s[i]= '0'+q;
            rec(s,i+1);
        }
        s[i]= '?';
    }
}

void solve()
{
    string c,j;
    cin>>c>>j;
    l= c.length();
    C= 1000; J= 0;
    string s= c+j+'#';
    rec(s,0);
    cout<<C_<<" "<<J_<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 srand(__rdtsc());
 // LL a[110];
 // memset(a,0,sizeof(a));

 freopen("B-small-attempt0.in","r",stdin);
 freopen("output_B_small.txt","w",stdout);
 //cout<<fixed;
 //cout<<setprecision(9);

 int T;
 cin>>T;
 for (int testCase= 1; testCase <= T; testCase++)
 {
     cout<<"Case #"<<testCase<<": ";
     solve();
 }


 return 0;
}
