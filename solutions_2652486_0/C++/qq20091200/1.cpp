#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define FIN

using namespace std;

typedef long long LL;

const int MAXN = 13;

int R,N,M,K;
int num[MAXN],res[MAXN],cnt[MAXN];
int has[9];

int main()
{
    #ifdef FIN
        freopen("C-small-1-attempt2.in","r",stdin);
        freopen("C-small-1-attempt2.out","w",stdout);
    #endif
    int cas,T;
    cin>>T;
    for(cas=1;cas<=T;cas++) {
    	cin>>R>>N>>M>>K;
        cout<<"Case #"<<cas<<":\n";
        while(R--)
        {
        	int i,j,k,len=0;
        	
        	for(i=0;i<K;i++)
        	cin>>num[i];
        	sort(num,num+K);
        	memset(has,0,sizeof(has));
        	
        	for(i=0;i<K && len<N;i++)
        	{
        		if(num[i]==1) continue;
        		if(num[i]==2 && has[2]==0) {
        			res[len++]=2;
        			has[2]++;
        		}
        		if(num[i]==3 && has[3]==1) {
        			res[len++]=3;
        			has[3]++;
        		}
        		if(num[i]==5 && has[5]==false) {
        			res[len++]=2;
        			has[5]++;
        		}
        		for(j=0;j<4;j++)
        		{
					cnt[j]=0;
					while(num[i]%(j+2)==0) {
						cnt[j]++;
						num[i]/=(j+2);
					}
        		}
        		if(num[i]!=1) break;
        		for(j=has[4];j<cnt[0]/2 && len<N;j++)
        		{
					res[len++]=4;
					has[4]++;
        		}
        		if(cnt[0]%2==1 && has[2]==0)
        		{
        			res[len++]=2;
        			has[2]++;
        		}
        		for(j=1;j<4;j++)
        		{
        			for(k=has[j+2];k<cnt[j] && len<N;k++)
        			{
						res[len++]=j+2;
						has[j+2]++;
        			}
        		}
        	}
        	
        	for(;len<N;len++) res[len]=2;
        	
        	for(i=0;i<N;i++)
        	cout<<res[i];
        	cout<<endl;
        }
    }
    return 0;
}

