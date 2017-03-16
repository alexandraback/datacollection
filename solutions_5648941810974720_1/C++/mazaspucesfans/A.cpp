#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    int N=s.size();

    map<char,int> counts;
    for(int i=0; i<N; i++) counts[s[i]]++;

    int ans[10]={0};

    int z=counts['Z'];
    ans[0]=z;

    counts['Z']-=z;
    counts['E']-=z;
    counts['R']-=z;
    counts['O']-=z;




    int u=counts['U'];
    ans[4]=u;

    counts['F']-=u;
    counts['O']-=u;
    counts['U']-=u;
    counts['R']-=u;

    int x=counts['X'];
    ans[6]=x;

    counts['S']-=x;
    counts['I']-=x;
    counts['X']-=x;

    int w=counts['W'];
    ans[2]=w;

    counts['T']-=w;
    counts['W']-=w;
    counts['O']-=w;

    int g=counts['G'];
    ans[8]=g;

    counts['E']-=g;
    counts['I']-=g;
    counts['G']-=g;
    counts['H']-=g;
    counts['T']-=g;

    int f=counts['F'];
    ans[5]=f;

    counts['F']-=f;
    counts['I']-=f;
    counts['V']-=f;
    counts['E']-=f;

    int v=counts['V'];
    ans[7]=v;

    counts['S']-=v;
    counts['E']-=v;
    counts['V']-=v;
    counts['E']-=v;
    counts['N']-=v;

    int o=counts['O'];
    ans[1]=o;

    counts['O']-=o;
    counts['N']-=o;
    counts['E']-=o;


    int t=counts['T'];
    ans[3]=t;

    counts['T']-=t;
    counts['H']-=t;
    counts['R']-=t;
    counts['E']-=t;
    counts['E']-=t;

    ans[9]=counts['I'];


    stringstream ss;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<ans[i]; j++) ss << i;
    }
    return ss.str();
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        //int N;
        //cin >> N;
        //int result=solve(N);
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }
    return 0;
}
