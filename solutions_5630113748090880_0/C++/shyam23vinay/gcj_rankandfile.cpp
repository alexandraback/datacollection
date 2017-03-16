#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout ("B-small-attempt0.out");
    ifstream fin ("B-small-attempt0.in");
    int t;
    fin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        fout << "Case #"<<tc<<": ";
        int n;
        fin >> n;
        int a[2*n*n-n+1];
        map<int,int>m;
        for(int i=0;i<2*n*n-n;i++)
        {
            int p;
            fin >> p;
            if(!m[p])
                m[p]=1;
            else
                m[p]++;
        }
        vector<int>v;
        for(int i=1;i<=2500;i++)
        {
            if(m[i] && m[i]%2==1)
                v.push_back(i);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            fout << v[i] << " ";
        fout << endl;
    }
    return 0;
}
