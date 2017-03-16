#include <iostream>
#include <fstream>
typedef long long Int;
using namespace std;

int main()
{
    ifstream in("D-small-attempt0.in");
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
        for(int i=0;i<S;i++)
        {
            Int Out=0;
            Int pow=1;
            for(int j=0;j<C;j++,pow*=K)
            {
                Out+=i*pow;
            }
            cout<<Out+1<<" ";
        }
        cout<<endl;

    }
    return 0;
    return 0;
}
