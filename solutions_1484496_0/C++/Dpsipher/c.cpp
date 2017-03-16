#include"iostream"
#include"cstdio"
#include"vector"
#include"math.h"
#include"algorithm"
#include"string.h"
#include"sstream"
#include"stack"
#include"queue"
#include"map"
#define maX(a, b) ((a) >= (b) ? (a) : (b))
#define miN(a, b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) < (0) ? (a)*(-1) : (a))
#define pb(x) push_back(x)
#define pii pair<double,int>
#define ll long long
using namespace std;
int sum[1<<20];
int main()
{
	int test,t,i,j,n,mask;
	cin>>test;
	bool f;
	for(t=1;t<=test;t++)
	{
		f=0;
		printf("Case #%d:\n",t);
		cin>>n;
		vector<int> A(n);
		for(i=0;i<n;i++){
			cin>>A[i];
		}
		sum[0]=0;
		map<int,int> pos;
		for(mask=1;mask<(1<<n);mask++)
		{
			for(i=0;i<n;i++){
				if(mask&(1<<i)){
					sum[mask]=sum[mask^(1<<i)]+A[i];
					break;
				}
			}
			
			if(pos[sum[mask]]){
				f=1;
					for(i=0;i<n;i++){
						if(pos[sum[mask]]&(1<<i)){
							cout<<A[i]<<" ";
						}
					}
					cout<<endl;
					for(i=0;i<n;i++){
						if(mask&(1<<i)){
							cout<<A[i]<<" ";
						}
					}
					cout<<endl;
				break;
			}
			pos[sum[mask]]=mask;
		}
	
		if(!f)
		cout<<"Impossible\n";
	}
	return 0;
}
