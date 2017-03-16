#include<bits/stdc++.h>
#define ll   long long

#define md 1000000007
#define inf 1e18
using namespace std;
int a[100][100];
ll p[100];
int main()
{
	ios_base::sync_with_stdio(0);
   #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);    
    #endif
      int test;
      cin>>test;
      p[1]=1;
      p[2]=1;
      for(int i=3;i<=50;i++)
      	p[i]=2*p[i-1];
     for(int tst=1;tst<=test;tst++){
     	cout<<"Case #"<<tst<<": ";
     		ll b,m;
     		cin>>b>>m;
     		for(int i=1;i<=b;i++){
     			for(int j=1;j<=b;j++){
     				a[i][j]=0;
     			}
     		}
     		for(int i=1;i<=b;i++){
     			for(int j=i+1;j<=b;j++){
     				a[i][j]=1;
     			}
     		}
     		
     		ll t=(ll)1<<(b-2);
     		//cout<<b<<endl;
     		if(m>t)
     		cout<<"IMPOSSIBLE"<<endl;
     		else{
     			cout<<"POSSIBLE"<<endl;
     			ll d=t-m;
     			int i=b-1;
     			while(d>0){
     				if(d>=p[i]){
     					d-=p[i];
     					a[i][b]=0;
     				}
     				i--;
     			}
     			for(int i=1;i<=b;i++){
     				for(int j=1;j<=b;j++)
     					cout<<a[i][j];
     					cout<<endl;
     			}
     		}
     		
     	
        }
    
    return 0;  
}
