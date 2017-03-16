#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int ti=0;ti<t;++ti)
    {
        int n;
        cin>>n;
        vector<long double> v1,v2;
        v1.resize(n);
        v2.resize(n);
        for(int i=0;i<n;++i)
            cin>>v1[i];
        for(int i=0;i<n;++i)
            cin>>v2[i];
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        int off=0;
        for(int i=0;i+off<n;)
        {
            if(v1[i+off]>v2[i])
                ++i;
            else
                ++off;
        }
        int w=0;
        for(int i=0;i<n;++i)
        {
            if(upper_bound(v2.begin(),v2.end(),v1[i])==v2.end())
            {
                v2.erase(v2.end()-1);
                ++w;
            }else
                v2.erase(upper_bound(v2.begin(),v2.end(),v1[i]));
        }
        cout<<"Case #"<<ti+1<<": "<<n-off<<" "<<w<<endl;

    }
    return 0;
}
