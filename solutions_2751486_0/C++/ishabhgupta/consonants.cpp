using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<utility>
#include<climits>
#include<sstream>

#define unsigned long long int ulli
#define FRm(i, m, n)     for( int i = m; i <=n; i++)
#define FRrev(i, n)         for( int i = n; i >= 0; i-- )
#define FRrevm(i,n,m)         for( int i = n; i >= m; i-- )
#define max(a,b) ((a)>(b)?(a):(b))
#define S(a) scanf("%d",&(a))
#define P(a) printf("%d",(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define NL printf("\n")
#define sqr(a) ((a)*(a))
#define SL(a) scanf("%lld",&(a))
#define PL(a) printf("%lld",(a))
#define lli long long int
#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define inarrd(arr,n) for(int i=0;i<n;i++)S(arr[i]);
#define outarrd(arr,n) for(int i=0;i<n;i++){PFd(arr[i]);PF(" ");}NL;
#define outarrN(arr,n) for(int i=0;i<n;i++){PFd(arr[i]);PFN;}

int main(){
    int tc,cs=1,ans,n,c;
    string str;
    S(tc);
    while(tc--){
        ans=0;
        cin>>str;
        S(n);
        for(int i=0;i<str.length();i++)
            for(int j=i+n;j<=str.length();j++){
                c=0;
                for(int k=i;k<j;k++){
                    if(str[k]=='a' || str[k]=='e' || str[k]=='i'|| str[k]=='o' || str[k]=='u')
                        c=0;
                    else
                        c++;
                    if(c>=n){
                        ans++;
                        break;
                    }
                }
            }

        printf("Case #%d: %d\n",cs++,ans);
    }
}
