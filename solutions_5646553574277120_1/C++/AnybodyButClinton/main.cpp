#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

//#define out cout

int main()
{
    int t;in>>t;
    for(int i=0;i<t;++i)
    {
        int c,d,v,ans=0;in>>c>>d>>v;int sum=0;vector<int>a;
        for(int j=0;j<d;++j){int e;in>>e;a.push_back(e);}
        sort(a.begin(),a.end());
        int j=0;bool ended=0;
        while(sum*c<v)
        {
            if(!ended&&a[j]<=sum*c+1)
            {
                sum+=a[j];
                if(j+1<a.size())++j;
                else ended=1;
            }
            else
            {
                sum+=sum*c+1;
                ++ans;
            }
        }
        out<<"Case #"<<i+1<<": "<<ans<<endl;
    }
    return 0;
}
