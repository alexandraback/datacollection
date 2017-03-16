#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("B-small-attempt0.in");
    ofstream out("A-small.out");
#define cin in
#define cout out
    int T;
    cin>>T;
    for(int iT=0;iT<T;iT++)
    {
        string S;
        cin>>S;

        cout<<"Case #"<<iT+1<<": ";
        int ans=0;
        if(S.length()==1)
        {
            if(S=="+")
                cout<<"0\n";
            else
                cout<<"1\n";
            continue;
        }
        for(int i=0;i<S.length()-1;i++)
        {
            if(S[i]!=S[i+1])
                ans++;
        }
        if(S[S.length()-1]=='-')
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}
