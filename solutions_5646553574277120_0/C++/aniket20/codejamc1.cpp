#include<bits/stdc++.h>
#define N 1000000007
#define maxs 100005
#define mins 1005
#define ll long long
#define pb push_back
using namespace std;

int a[31];
int dp[20][31],arr[20][31];
vector<int>v1;
int main()
{
	int t,r,c,w,ans,cnt=1,d,v,i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&c,&d,&v);
		for(i=0;i<d;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<d;i++){
			for(j=0;j<=v;j++){
				dp[i][j]=0;
			}
		}
		dp[0][a[0]]=1;
		dp[0][0]=1;
		for(i=1;i<d;i++){
			for(j=0;j<=v;j++){
				dp[i][j]=dp[i-1][j];
				if(j-a[i]>=0)
					dp[i][j]=dp[i][j] | dp[i-1][j-a[i]];
			}
		}
		int fl1=0;
		for(i=1;i<=v;i++){
          //  cout<<dp[d-1][i]<<" ";
            if(dp[d-1][i]==0){
                fl1++;
            }
		}
		for(i=1;i<=v;i++){
            int fl2=0;
            for(j=0;j<d;j++){
                if(a[j]==i){
                    fl2=1;
                    break;
                }
            }
            if(fl2==0){
                v1.pb(i);
            }
		}

		ans=fl1;
		for(i=1;i<(1<<15);i++){
			for(j=0;j<=15;j++){
				for(k=0;k<=v;k++){
					arr[j][k]=0;
				}
			}
			for(k=0;k<=v;k++){
				arr[0][k]=dp[d-1][k];
			}
			int c1=0;
			for(j=1;j<=15;j++){
				if((i&(1<<(j-1)))!=0)
				{
					int fl=0;
					if(fl==0){
						c1++;
						for(k=0;k<=v;k++){
							arr[c1][k]=arr[c1-1][k];
							if(k-v1[j-1]>=0)
								arr[c1][k]=arr[c1][k] | arr[c1-1][k-v1[j-1]];
						}
					}
				}
			}
			int fl=0;
			for(k=1;k<=v;k++){
				if(arr[c1][k]==0){
                  //  cout<<k<<" ";
					fl=1;
					break;
				}
			}
			if(fl==0){
				if(c1<ans){
                    ans=c1;
                   // cout<<i<<" ";
				}
			}
		}
		printf("Case #%d: %d\n",cnt,ans);
		cnt++;
		v1.clear();
	}
	return 0;
}
