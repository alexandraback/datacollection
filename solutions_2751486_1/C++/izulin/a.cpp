#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool iscons(char a)
{
    return !(a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
}

int main()
{
    int T;
    cin >> T;
    for(int it=1;it<=T;it++)
    {
        int l;
        string x;
        cin >> x >> l;
        int n = x.size();
        l--;
        vector<int> con(n+1);
        for(int i=n;i>=0;i--)
            if(iscons(x[i]))
                con[i] = con[i+1]+1;

        vector<int> pos;

        pos.push_back(-1);

        for(int i=0;i<n-l;i++)
            if(con[i]>l)
                pos.push_back(i);

        pos.push_back(n-l);

        long long ans = ((long long)(n-l)*(long long)(n-l+1))/2;

        for(int i=0;i+1<pos.size();i++)
        {
//            cerr << pos[i] << ' ' << pos[i+1] << endl;
            ans -= ((long long)(pos[i+1]-pos[i])*(long long)(pos[i+1]-pos[i]-1))/2;
        }

        cout << "Case #" << it << ": " << ans << endl;

    }
}
