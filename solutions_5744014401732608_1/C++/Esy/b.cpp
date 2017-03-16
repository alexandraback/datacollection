#include <iostream>
#include <string>
#include <string.h>
using namespace std;

typedef long long llong;

short A[55][55];
llong L[55];

void init()
{
    L[1]=1;
    L[2]=1;
    for(int i=3; i<55; i++)
    {
        L[i]=2*L[i-1];
    }
}

void print(int B)
{
    for(int i=1; i<=B; i++)
    {
        for(int j=1; j<=B; j++)
        {
            cout<< A[i][j];
        }
        cout<< endl;
    }
}

int main()
{
    init();
	int T;
	int B;
	llong M;
	llong v[55];
	cin >> T;
	for(int t=1; t<=T; t++)
	{
	    memset(A, 0, 55*55*sizeof(short));
	    memset(v, 0, 55*sizeof(llong));
	    cin>> B >> M;
	    cout<< "Case #" << t << ": ";
	    if(M>L[B])
	    {
	        cout<< "IMPOSSIBLE" << endl;
	        continue;
	    }
	    cout<< "POSSIBLE" << endl;
	    A[1][2]=1;
	    for(int b=3; b<=B; b++)
	    {
	        if(M >= L[b])
	        {
	            for(int i=1; i<b; i++)
	                A[i][b]=1;
	        }
	        else
	        {
	            llong rem = M;
	            while(rem>0)
	            {
	                for(int i=b-1; i>=1; i--)
    	            {
    	                if(L[i] <= rem)
    	                {
    	                    A[i][b]=1;
    	                    rem -= L[i];
    	                    break;
    	                }
    	            }   
	            }
	        }
	    }
	    print(B);
	}
	return 0;
}
