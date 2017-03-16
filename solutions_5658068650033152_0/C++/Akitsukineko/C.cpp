
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


long
gcd ( long a, long b )
{
    long c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}


int main()
{
    int numTestCase;
    cin>>numTestCase;
    //cout<<"XD :"<<numTestCase;
    for(int tc = 0; tc<numTestCase; tc++)
    {
    	int K = 0;
        int M = 0;
        int N = 0;
        
        int result = 0;
        cin>>N;
        cin>>M;
        cin>>K;
        
        if (M>N) {
            int tmp = N;
            N = M;
            M = tmp;
        }
        
        if (M<=2) {
            cout<<"Case #"<<tc+1<<": "<<K<<endl;
        }
        else if(K<5)
        {
            cout<<"Case #"<<tc+1<<": "<<K<<endl;
        }
        else if(K<8)
        {
            cout<<"Case #"<<tc+1<<": "<<K-1<<endl;
        }
        else
        {
            if (N == 3 && M == 3) {
                int ans[]={7,8};
                cout<<"Case #"<<tc+1<<": "<<ans[K-8]<<endl;
            }
            else if (N == 4 && M == 3) {
                int ans[]={6,7,8,9,10};
                cout<<"Case #"<<tc+1<<": "<<ans[K-8]<<endl;
            }
            else if (N == 4 && M == 4) {
                int ans[]={6,7,7,8,8,9,10,11,12};
                cout<<"Case #"<<tc+1<<": "<<ans[K-8]<<endl;
            }
            else if (N == 5 && M == 3) {
                int ans[]={6,7,8,8,9,10,11,12};
                cout<<"Case #"<<tc+1<<": "<<ans[K-8]<<endl;
            }
            else if (N == 5 && M == 4) {
                int ans[]={6,7,7,8,8,9,9,10,10,11,12,13,14};
                cout<<"Case #"<<tc+1<<": "<<ans[K-8]<<endl;
            }
            else if (N == 6 && M == 3) {
                int ans[]={6,7,8,8,9,10,10,11,12,13,14};
                cout<<"Case #"<<tc+1<<": "<<ans[K-8]<<endl;
            }
            
        }
    }

    return 0;
}

