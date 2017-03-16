#include <iostream>
#include <list>

using namespace std;

int main()
{
    int T,N,p;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>N;
        int A[2500] = {0};
        for(int i=0;i<2*N-1;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>p;
                A[p-1]++;
            }
        }

        cout<<"Case #"<<t<<": ";

        for(int i=0;i<2500;i++)
        {
            if(A[i]%2==1)
                cout<<i+1<<" ";
        }

        cout<<endl;
    }
    return 0;
}