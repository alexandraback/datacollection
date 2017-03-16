#include<bits/stdc++.h>
using namespace std;
int main()
{
    //ofstream fout ("D-small-attempt0.out");
    //ifstream fin ("D-small-attempt0.in");
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        cout << "Case #"<<tc<<": ";
        unsigned long long int k,c,s;
        cin >> k >> c >> s;
        if(k==s)
        {
            for(unsigned long long int i=1;i<=s;i++)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
