#include <iostream>
#define F first
#define S second
#include <algorithm>
#include <vector>
using namespace std;

long long T,TT,b,m,rao[100],i,j,last;
char ans[100][100];

main(){
	
	freopen ("B-large.in","r",stdin);
	freopen ("output.txt","w",stdout);


	cin>>T; TT=T;
	 
	 while (T--){
	 
	 	cin>>b>>m;
	 	
		for (i=1; i<=b; i++)
	 	 for (j=1; j<=b; j++)
	 	 	ans[i][j]='0';
		
		last = b;
	 	b--;
	 	
	 	
	 	
	 	rao[1]=1;
	 	
	 	for (i=2; i<=b; i++){
	 		rao[i] = 0;
		 
	 	 for (j=1; j<i; j++)
	 	 	{
			  ans[j][i]='1';
			  rao[i] += rao[j];
			}
		}
		
		for (i=b; i>=1; i--)
			if (rao[i] <= m){
				m-= rao[i];
				ans[i][last] = '1';
			} 
	 
	 
	 	cout<<"Case #"<<TT-T<<": ";
	 	if (m!=0) cout<<"IMPOSSIBLE"<<endl; else{
	 		cout<<"POSSIBLE"<<endl;
	 		
	 		for (i=1; i<=last; i++)
	 			{
	 				for (j=1; j<=last; j++)
	 				cout<<ans[i][j];
	 				cout<<endl;
				}
		}
	}
	
}
