#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int sait[300];
int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    // a, e, i, o, and u
    sait['a'] = sait['e'] = sait['i'] = sait['o'] = sait['u'] = 1;
    int t;
    fin>>t;
    for (int ii=0;ii<t;ii++)
    {
        //cout<<ii<<endl;
        string name;
        vector <pair<int,int> > inter;
        long long n,ans = 0,cur = 0;
        fin>>name>>n;
        for (int i=0;i<name.length();i++)
        {
            if (sait[name[i]]) cur = 0;
            else cur++;
            if (cur >= n) inter.push_back(make_pair(i-n+1,i));
        }
        //for (int i=0;i<inter.size();i++) fout<<inter[i].first<<" "<<inter[i].second<<endl;
        if (!inter.empty())
            ans = (inter[0].first+1) * (name.length() - inter[0].second);
        for (int i=1;i<inter.size();i++)
            ans += (inter[i].first - inter[i-1].first) * (name.length() - inter[i].second);
        fout<<"Case #"<<ii+1<<": "<<ans<<endl;
    }
    return 0;
}
