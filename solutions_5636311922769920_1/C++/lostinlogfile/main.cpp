#include <iostream>
#include <fstream>
typedef long long Int;
using namespace std;

int main()
{
    ifstream in("D-large.in");
    ofstream out("A-small.out");
#define cin in
#define cout out
    int T;
    cin>>T;
    for(int iT=0;iT<T;iT++)
    {
        Int K,C,S;
        cin>>K>>C>>S;
        cout<<"Case #"<<iT+1<<": ";
        if((S<K-1)||((C==1)&&(S<K)))
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        if(K==1)
        {
            cout<<"1";
        }
        else
        for(int i=((C==1)?0:1);i<K;i++)
        {
            cout<<i+1<<" ";
        }
        cout<<endl;

    }
    return 0;
    return 0;
}
