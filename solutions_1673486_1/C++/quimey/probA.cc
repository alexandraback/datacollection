#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<complex>
#include<set>
#include<map>
#include<sstream>
#include<string>
#include<deque>
#include<sys/time.h>
#include<fstream>
#include<bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define all(v) v.begin(),v.end()

timeval start,end;

/*
 Functions used to measure times
*/
void init_time()
{
	gettimeofday(&start,NULL);
}

double get_time()
{
	gettimeofday(&end,NULL);
	return (1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec))/1000000.0;
}

int main()
{
    int T;
    cin>>T;
    forn(tt,T)
    {
        int A,B;
        cin>>A>>B;
        vector<double>v(A),p(A);
        forn(i,A)cin>>v[i];
        p[0]=1-v[0];
        forn(i,A-1)p[i+1]=1-v[i+1]+(v[i+1])*p[i];
        double r=200000000,t;
        //hago algunos backspaces
        forn(i,A)
        {
            t=2*i+B-A+1+(B+1)*p[A-1-i];
            r=min(r,t);
            //cout<<t<<endl;
        }
        //enter de una
        t=1+B+1;
        r=min(r,t);
        //cout<<t<<endl;
        printf("Case #%d: %.6f\n",tt+1,r);
    }
}
