#include <bits/stdc++.h>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	static long long t,te,i,j,k,n,m,ans,arr[1001],vis[1001],vis1[1001],a[1001],tre,ans1,maxLink[1001],x,y,p;
	cin>>t;
	queue<int>q;
	for(te=0;te<t;te++){
	vector<int>adj[1001];
		cin>>n;
		m=ans=ans1=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			arr[i]--;
			adj[arr[i]].push_back(i);
		}
		for(i=0;i<n;i++){
			for(j=k=0;j<n;j++)vis[j]=0;
			q.push(i);
			vis[i]=1;
			while(!q.empty()){
				for(j=0,x=q.size();j<x;j++){
					p=q.front();
					q.pop();
					for(y=0;y<adj[p].size();y++){
						if(vis[adj[p][y]]==1)continue;
						if(arr[p]==adj[p][y])continue;
						vis[adj[p][y]]=1;
						q.push(adj[p][y]);
					}
				}
				k++;
			}
			maxLink[i]=k;
		}
		for(i=0;i<n;i++)vis[i]=vis1[i]=a[i]=0;
		for(i=tre=0;i<n;i++){
			if(vis1[i]!=0)continue;
			for(j=0,k=i;j<2000;j++,k=arr[k]);
			if(vis1[k]==0){
				tre++;
				m=tre;
			}
			else m=vis1[k];
			k=i;
			while(vis1[k]==0){
				vis1[k]=m;
				k=arr[k];
			}
		}
		for(i=0;i<n;i++){
			m++;
			for(j=0,k=i;(vis[k]/10000)!=m;k=arr[k],j++){
				vis[k]=m*10000+j;
			}
			ans=max(ans,10000*m+j - vis[k]);
			if((10000*m+j - vis[k])==2){
				a[vis1[k]]=max(a[vis1[k]],maxLink[k]+maxLink[arr[k]]);
			}
		}
		for(i=1;i<=tre;i++)ans1+=a[i];
		cout<<"Case #"<<(te+1)<<": "<<max(ans,ans1)<<"\n";

	}
	return 0;
}