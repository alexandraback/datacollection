#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<iostream>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DOR(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define bug puts("Fuck");
#define LL long long
#define pb push_back
#define mp make_pair

#define nMax 1010
#define eps 1e-8
#define inf 0x7fffffff

int t;
int l[nMax],d[nMax][10];
int a[nMax];
int n,m,k;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    scanf("%d",&t); scanf("%d%d%d",&n,&m,&k);
    printf("Case #1:\n");
    while(t--){
       // cout<<t<<' '<<n<<' '<<m<<' '<<k<<endl;
        memset(l,0,sizeof(l));
        for(int i=0;i<k;i++) scanf("%d",&a[i]);//,cout<<a[i]<<' ';cout<<endl;
        for(int i=0;i<k;i++){
            for(int j=m;j>=2;j--) {
                d[i][j]=0;
                while(a[i]%j==0) {
                    a[i]/=j;
                    d[i][j]++;
                }
                l[j]=max(l[j],d[i][j]);
            }
        }
        int s=0;
        for(int j=m;j>=2 && s<n;j--){
            while(l[j]&&s<n){
                printf("%d",j);
                l[j]--;
                s++;
            }
        }
        while(s<n) printf("2"),s++;
        printf("\n");
        //cout<<t<<endl;
    }

	return 0;
}
