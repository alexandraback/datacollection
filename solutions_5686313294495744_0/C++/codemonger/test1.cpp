#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
#define sc(x) scanf("%d",&(x))
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define forii(n) for(int ii=0;ii<n;ii++)
#define forjj(n) for(int jj=0;jj<n;jj++)
#define forkk(n) for(int kk=0;kk<n;kk++)




int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	
	int t;
	sc(t);
	for(int z=1;z<=t;z++){
		printf("Case #%d: ",z);
		int n;
		sc(n);
		string s[n][2];
		int a[n];
		fori(n){
			a[i]==0;
			forj(2){
				cin>>s[i][j];
			}
		}

		// fori(n){
		// 	forj(2){
		// 		cout<<s[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		int count=0;
		fori(n){
			int flag1=0,flag2=0;
			forj(n){
				if(i==j || a[j]==1)continue;
				if(s[i][0].compare(s[j][0]) == 0){					
					flag1=1;break;
				}
			}
			forj(n){
				if(i==j || a[j]==1)continue;
				if(s[i][1].compare(s[j][1]) == 0){
					flag2=1;break;
				}
			}
			if(flag1==1 && flag2==1){
				count++;
				//a[i]=1;
			}
		}
		cout<<count<<endl;
		
		



	}

		
	

}