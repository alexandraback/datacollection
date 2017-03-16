#include<bits/stdc++.h>
#define ll   long long

#define md 1000000007

using namespace std;
int a[100][100];
int hs[3000];
int ans[100];
int main()
{
	ios_base::sync_with_stdio(0);
   #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);    
    #endif
      int test;
      cin>>test;
     for(int tst=1;tst<=test;tst++){
     	cout<<"Case #"<<tst<<": ";
     	int n;
     	cin>>n;
     	for(int i=0;i<3000;i++){
     		hs[i]=0;
     	}
     	for(int i=0;i<2*n-1;i++){
     	for(int j=0;j<n;j++)
     	{
     		int x;
     		cin>>x;
     		hs[x]++;
     	}
     	}
     	int ct=0;
     	for(int i=0;i<3000;i++)
     		if(hs[i]%2)
     			ans[ct++]=i;
     	for(int i=0;i<ct;i++)
     		cout<<ans[i]<<" ";
     		cout<<endl;
     	
     	
     }
    return 0;  
}
