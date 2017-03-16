#include <iostream>
#define F first
#define S second
#include <algorithm>
#include <vector>
using namespace std;

long long T,TT,i,j,l,a,b,c,k,fix1[11][11],fix2[11][11],fix3[11][11],r,ans[10005][4];


main(){
	
	freopen ("C-small-attempt1.in","r",stdin);
	freopen ("output.txt","w",stdout);


	cin>>T; TT=T;
	 
	while (T--){
		cin>>a>>b>>c>>k;
		r=0;
		
		for (i=1; i<=a; i++)
			for (j=1; j<=b; j++)
				fix1[i][j] = k;
		
		for (i=1; i<=a; i++)
			for (l=1; l<=c; l++)
				fix2[i][l] = k;
		
		for (j=1; j<=b; j++)
			for (l=1; l<=c; l++)
				fix3[j][l] = k;
		
				for (l=1; l<=c; l++)
			for (j=1; j<=b; j++)
		for (i=1; i<=a; i++)
					if (fix1[i][j]>0 && fix2[i][l]>0 && fix3[j][l]>0){
						r++;
						ans[r][1]=i;
						ans[r][2]=j;
						ans[r][3]=l;
						fix1[i][j]--;
						fix2[i][l]--;
						fix3[l][j]--;
					}			 
	 
	 	cout<<"Case #"<<TT-T<<": "<<r<<endl;
	 	for (i=1; i<=r; i++)
	 		cout<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
	}
	
}
