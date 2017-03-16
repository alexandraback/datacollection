#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	//freopen("1.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-smmall-out.txt","w",stdout);
	//freopen("B-large.in","r",stdin);
	//freopen("B-large-out.txt","w",stdout);
	int T;
	cin>>T;
	for(int at=0;at<T;at++){
		printf("Case #%d: ",at+1);
		int n,m;
		cin>>n>>m;
		vector<vector<int> > a(n,vector<int> (m));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		vector<int> N(n),M(m);
		for(int i=0;i<n;i++){
			N[i]=a[i][0];
			for(int j=0;j<m;j++)
				N[i]=max(N[i],a[i][j]);
		}
		for(int j=0;j<m;j++){
			M[j]=a[0][j];
			for(int i=0;i<n;i++)
				M[j]=max(M[j],a[i][j]);
		}

		string ans="YES";
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j]<N[i] && a[i][j]<M[j])
					ans="NO";
		printf("%s\n",ans.c_str());
	}
}