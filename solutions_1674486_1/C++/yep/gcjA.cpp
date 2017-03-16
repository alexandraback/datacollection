#include <string>
#include <vector>
#include <sstream> 
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int v[2000];
int q[100000];
int g[2000][2000];
int l,r;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	int c;
	cin>>c;
	for (int t=0;t<c;t++){
		int n;
		cin>>n;
		for (int i=0;i<n;i++){
			v[i]=0;
			for (int j=0;j<n;j++) g[i][j]=0;
		}
		l=0;r=0;
		for (int i=0;i<n;i++){
			int m;
			cin>>m;
			for (int j=0;j<m;j++){
				int b;
				cin>>b;
				g[i][b-1] = 1;
				//cout<<i<<"*"<<b-1<<endl;
			}
		}
		bool ans =false;
		for (int i=0;i<n;i++){
			//cout<<"---"<<endl;
			for (int j=0;j<n;j++) v[j]=0;
			v[i] = 1;
			q[0] = i;
			l=0;
			r=0;
			while (l<=r){
				for (int j=0;j<n;j++){
					if (g[q[l]][j]==1){
						if (v[j]==1) {
							ans = true;
							//cout<<j<<"*"<<endl;
						}
						if (v[j]==0){
						//cout<<j<<endl;
							r++;
							q[r]=j;
							v[j]=1;
						}
					}
				}
				l++;
			}
			
		}
		cout<<"Case #"<<t+1<<": ";
		if (ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
