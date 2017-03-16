#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
    ifstream fin("test.in");
    ofstream fout("sol.out");
    int t,T;
    fin>>t;
    T=t;
    while(t--){
        fout<<"Case #"<<T-t<<": ";
        string s;
        fin>>s;
        string comps;
        comps.push_back(s[0]);
        for(int ctr1=1;ctr1<s.size();ctr1++)
            if(s[ctr1]!=comps[comps.size()-1])
                comps.push_back(s[ctr1]);
        if(comps[comps.size()-1]=='+')
            comps.resize(comps.size()-1);
        fout<<comps.size()<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}
