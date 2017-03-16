/*------Coded by Gitanshu Behal------*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<cctype>
#include<ciso646>
#include<stdbool.h>
#include<cstddef>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<complex>
#include<functional>
#include<numeric>
#include<limits>
#include<stdexcept>
#include<string>
#include<utility>
#include<fstream>


		/*--------scan/print--------*/
# define s(n) scanf("%d",&n)
# define p(n) printf("%d",n)
# define pln(n) printf("%d\n",n)
# define sln(n) scanf("%d\n",&n)
# define plld(x) printf("%lld\n",x)

		/*--------FOR LOOPS--------*/
# define For(I,l,m) for(int I=l;I<=m;I++)
# define ForInt(I,l,m) for(I=l;I<=m;I++)
# define NFor(I,l,m) for(int I=l;I>=m;I--)
# define NForInt(I,l,m) for(I=l;I>=m;I--)

		/*--------others--------*/
# define TEST int t; scanf("%d",&t); while(t--)
# define ZERO(x) memset(x,0,sizeof(x))
# define SET(x,y) memset(x,y,sizeof(x))
# define NEWLINE printf("\n")

/*--------2 option--------*/
# define YES printf("YES\n")
# define NO printf("NO\n")

/*------DIRECTELY USABLE----> sort(array,array+size),swap(a,b),------*/


using namespace std;

unsigned long long int BinarySearch(unsigned long long int n,unsigned long long int th,unsigned long long int r)
{
        unsigned long long int low=1,high=n, mid;
        while(low <= high)
        {
                mid = (low + high)/2;
                if( (2*mid*mid+(2*r-1)*mid) <= th && (2*(mid+1)*(mid+1)+(2*r-1)*(mid+1))>th)
                {
                        return mid; 
                }
                else if( (2*mid*mid+(2*r-1)*mid) < th && (2*(mid+1)*(mid+1)+(2*r-1)*(mid+1))<th)
                {
					low=mid+1;	
				}
				else if( (2*mid*mid+(2*r-1)*mid) < th && (2*(mid+1)*(mid+1)+(2*r-1)*(mid+1))==th)
				{
					return mid+1;
				}
                else if((2*mid*mid+(2*r-1)*mid) > th)
                {
                        high = mid-1;
                }

        }
}

/*-------begin of main---------*/
int main()
{
	int t;
	s(t);
	for(int G=0;G<t;G++)
	{
		unsigned long long int r,th,ans,x=1000000100;
		cin>>r>>th;
		if(th/r>1000000100)
		ans=BinarySearch(x,th,r);
		else
		ans=BinarySearch(th/r,th,r);
		
		cout<<"Case #"<<G+1<<": "<<ans<<"\n";
		//printf("Case #%d: %ud\n",G+1,ans);
		
	}	
}
