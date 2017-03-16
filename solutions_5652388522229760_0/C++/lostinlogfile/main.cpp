#include <iostream>
#include <fstream>
#include <set>
typedef long long Int;
using namespace std;
Int solve(Int st)
{
    set<int> s;
    s.insert(0);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    Int cur=st;
    Int tr=0;
    while(s.size()>0)
    {
        tr++;
        if(tr>1590)
            return -1;
        Int a=cur;
        while(a>0)
        {
            s.erase(a%10);
            a=a/10;
        }
        cur+=st;
    }
    return cur-st;

}
int main()
{
    ifstream in("A-small-attempt0.in");
    ofstream out("A-small.out");
#define cin in
#define cout out
    int T;
    cin>>T;
    for(int iT=0;iT<T;iT++)
    {
        int s;
        cin>>s;
        Int o=solve(s);
        cout<<"Case #"<<iT+1<<": ";
        if(o==-1)
            cout<<"INSOMNIA\n";
        else
            cout<<o<<endl;

    }
    return 0;
    return 0;
}
