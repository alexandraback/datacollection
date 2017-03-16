#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int l[1001];
int s[1001];
float nao[1001];
float ken[1001];

int main(){
	int t, i, j, k, n, w, d;

	cin>>t;
	for (i = 0; i < t; ++i){
		cin>>n;

		for (j=0; j<n; ++j){
			cin>>nao[j];
		}
		for (j=0; j<n; ++j){
			cin>>ken[j];
		}

		sort(ken, ken+n);
		sort(nao, nao+n);
		memset(s, 0, sizeof(int)*n);

		j=0; k=0;
		while(j<n && k<n){
			if (nao[j]>ken[k]){
				++k;
			} else {
				s[j++] = k;
			}
		}
		while(j<n) s[j++]=k;

		j=0; k=0;
		while(j<n && k<n){
			if (nao[j]<ken[k]){
				++j;
			} else {
				l[k++] = j;
			}
		}
		while(k<n) l[k++]=j;

		w=0; d=0;
		for (j=0; j<n; ++j) {
			if (l[j]>w){++w;}
			if (s[j]>d){++d;}
		}
		w = n-w;

		// for (j=0; j<n; ++j) cout<<" "<<s[j];
		// cout<<endl;
		// for (j=0; j<n; ++j) cout<<" "<<l[j];
		// cout<<endl;
		cout<<"Case #"<<i+1<<": "<<d<<" "<<w<<endl;
	}
	
	return 0;
}