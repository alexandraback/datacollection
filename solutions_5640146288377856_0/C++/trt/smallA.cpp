#include <iostream>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);
    int z;
    cin>>z;
    for (int i=1;i<=z;i++)
    {
        int r,c,w;
        cin>>r>>c>>w;
        cout<< "Case #"<<i<<": "<<(c/w)+w-1 + ((c%w)>0)<<endl;
    }
}
