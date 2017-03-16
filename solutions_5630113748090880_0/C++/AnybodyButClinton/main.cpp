#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream in("c.in");
ofstream out("c.out");

int main()
{
    int t;
    in>>t;
    for(int i=1;i<=t;++i){
        int n;
        in>>n;
        int l[2*n-1][n];
        int h[2501];
        for(int j=0;j<2501;++j)h[j]=0;
        for(int j=0;j<2*n-1;++j)for(int k=0;k<n;++k){in>>l[j][k];++h[l[j][k]];}
        vector<int>v;
        for(int j=0;j<2501;++j)if(h[j]%2==1)v.push_back(j);
        sort(v.begin(),v.end());
        out<<"Case #"<<i<<":";
        for(int j=0;j<v.size();++j)out<<" "<<v[j];
        out<<endl;
    }
    return 0;
}
