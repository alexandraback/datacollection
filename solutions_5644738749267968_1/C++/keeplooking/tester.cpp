#include<bits/stdc++.h>
#define sc(n) scanf("%d",&n)
#define pn(n) printf("%d\n",n)
#define slc(n) scanf("%lld",&n)
#define pln(n) printf("%lld\n",n)
#define ps(n) printf("%d ",n) //
using namespace std;
double A[1009],B[1009];
int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t,ty = 1,n;
	int ans1,ans2;
	cin>>t;
	while(t--){
		cin>>n;
		printf("Case #%d: ",ty++);
		for(int i=0;i<n;i++)
			cin>>A[i];
		for(int i=0;i<n;i++)
			cin>>B[i];
		sort(A,A+n);
		sort(B,B+n);
		ans1=0,ans2=0;
		int i,j,k=0;
		for(i=0;i<n;i++){
			for(j=k;j<n;j++){
				if(A[i]<B[j]){
					ans1++;
					k=j+1;
					break;
				}
				k = j + 1;
			}
		}
		k=0;
		for(i=0;i<n;i++){
			for(j=k;j<n;j++){
				if(B[i]<A[j]){
					ans2++;
					k=j+1;
					break;
				}
				else{
					k = j + 1;
				}
			}
		}
		
		printf("%d %d\n",ans2,n-ans1);
	}
}
