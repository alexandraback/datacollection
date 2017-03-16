#include <iostream>
#include <algorithm>
using namespace std;

long long m[105];
int A, N;

void real_main()
{
    long long S = 100000;
    cin>>A>>N;
    for (int i=0;i<N;i++)
        cin>>m[i];
    
    if (A ==1) {cout<<N<<endl; return;}
    
    sort(m, m+N);
    long long size = A, ope = 0;
    for (int i=0;i<N;i++)
    {
        if (size > m[i])
            size += m[i];
        else
        {
            S = min(S, ope+N-i);
            
            long long ns = m[i]+1;
            while (size<ns)
            {
                size += size-1;
                ope++;
            }
            size+=m[i];
        }
    }
    S = min(S, ope);
    cout<<S<<endl;

}

int main()
{
    int T; cin>>T;
    for (int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        real_main();
    }
}
