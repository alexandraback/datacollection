#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <string.h>
#define abs(X) (((X)<0)?-(X):(X))
using namespace std;
typedef pair<int,int> PI;
typedef long long ll;
vector<int> ADJ[1000];
int N, CC;
bool V[1000];
bool foo(int s, int e, bool m){
	if (CC==2)
		return true;
	if (s==e){
		CC++;
		/*cout<<"!";
		for (int i = 0; i < N; i++)
			cout<<V[i];
		cout<<endl;*/
		V[s] = 0;
		return true;
	}
	for (vector<int>::iterator it = ADJ[s].begin();	it!=ADJ[s].end(); it++)
		if (!V[*it]){
			V[*it] = 1;
			//cout<<"\t"<<s<<"->"<<*it<<"->"<<e<<endl;
			if (foo(*it,e,0)){
				if (!m)
					return true;
			} else
				V[*it] = 0;
		}
}
bool check(){
	for (int j = 0; j < N; j++)
		for (int k = 0; k < N; k++)
			if (j!=k){
				//cout<<"TRY "<<j<<" "<<k<<" ";
				memset(V,0,sizeof(V));
				CC = 0;
				foo(j,k,true);
				//cout<<CC<<endl;
				if (CC==2){
					//cout<<j<<"->"<<k<<endl;
					return true;
				}
			}
	return false;
}
#define DEBUG -1
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int mi, tmp;
	for (int i = 0; i < T; i++){
		scanf("%d",&N);
		if (i==DEBUG)
			cout<<N<<endl;
		for (int j = 0; j < N; j++){
			ADJ[j].clear();
			scanf("%d",&mi);
			if (i==DEBUG)
				cout<<mi<<":";
			for (int k = 0; k < mi; k++){
				scanf("%d",&tmp), ADJ[j].push_back(tmp-1);
				if (i==DEBUG)
					cout<<tmp<<" ";
			}
			if (i==DEBUG)
				cout<<endl;
		}
		printf("Case #%d: ",i+1);
		if (check())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
