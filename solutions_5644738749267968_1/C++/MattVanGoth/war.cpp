#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        vector<long double> k,l;
        k.resize(n);
        l.resize(n);
        set<long double> s;
        for(int i=0;i<n;i++)
        {
            cin>>k[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>l[i];
            s.insert(l[i]);
        }
        sort(k.begin(),k.end());
        sort(l.begin(),l.end());
        int a=0,b=n-1,w=0;
        for(int i=0;i<n;i++)
        {
            if(k[i]>l[a])
            {
                w++;
                a++;
            }
            else
            {
                b--;
            }
        }
        int y=0;
        for(int i=0;i<n;i++)
        {
            if(s.lower_bound(k[i])!=s.end())
            {
                s.erase(s.lower_bound(k[i]));
            }
            else
            {
                y++;
            }
        }
        cout<<"Case #"<<z+1<<": "<<w<<" "<<y<<endl;
        k.clear();
        l.clear();
    }
    return 0;
}
