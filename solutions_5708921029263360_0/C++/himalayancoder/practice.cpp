#include<bits/stdc++.h>
#define ll   long long

#define md 1000000007
#define inf 1e18
using namespace std;
int nazr1[100][100],nazr2[100][100],nazr3[100][100];
vector < pair<int,pair<int,int> > > a;
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
     		for(int i=0;i<100;i++)
     		for(int j=0;j<100;j++)
     		nazr1[i][j]=nazr2[i][j]=nazr3[i][j]=0;
     		a.clear();
     		int j,p,s,k;
     		cin>>j>>p>>s>>k;
     		int ct=0;
     		//cout<<j<<p<<s<<k<<endl;
     		for(int l=1;l<=j;l++)
     			for(int m=1;m<=p;m++)
     				for(int n=1;n<=s;n++){
     					
     					
     					if(nazr1[l][m]<k && nazr2[m][n]<k && nazr3[l][n]<k){
     						ct++;
     						a.push_back(make_pair(l,make_pair(m,n)));
     						nazr1[l][m]++;
     						nazr2[m][n]++;
     						nazr3[l][n]++;
     					}
     					
     				}
     			cout<<ct<<endl;
     			for(int i=0;i<a.size();i++){
     				cout<<a[i].first<<" "<<a[i].second.first<<" "<<a[i].second.second<<endl;
     			}
     		
     	
        }
    
    return 0;  
}
