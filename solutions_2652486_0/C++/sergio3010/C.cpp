#include <bits/stdc++.h>



using namespace std;




#define fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;



set<int> s[100];
vector<int> vet[100];
int ns;
int arr[100];
int r,n,m,k,t;

void bt(int onde, int ult){
	if(onde == n){
		s[ns].insert(1);
		fr(i,0,n) vet[ns].push_back(arr[i]), s[ns].insert(arr[i]);
		fr(i,0,n) fr(j,i+1,n) s[ns].insert(arr[i]*arr[j]);
		fr(i,0,n) fr(j,i+1,n) fr(k,j+1,n) s[ns].insert(arr[i]*arr[j]*arr[k]);
		ns++;
		return;
	}
	fr(i,ult,m+1){
		arr[onde] = i;
		bt(onde+1,i);
	}
}



int main(){
	srand(time(0));
	scanf("%d",&t);
	printf("Case #1:\n");
	scanf("%d %d %d %d",&r,&n,&m,&k);
	ns = 0;
	bt(0,2);
	int v[100];
	int fu = 0;
	fr(i,0,r){
		fr(j,0,n){
			scanf("%d",&v[j]);
		}
		bool foi = false;
		vector<int> resps;
		fr(j,0,ns){
			bool pode = true;
			fr(k,0,n){
				if(s[j].find(v[k]) == s[j].end()) pode = false;
			}
			if(pode){
				resps.push_back(j);
			}
		}
		if(resps.empty()) resps.push_back(rand()%ns);
		int x = rand()%resps.size();
		fr(k,0,n) printf("%d",vet[resps[x]][k]);
		puts("");
	}
//	printf("%d>>\n",fu);
	sai:
	return 0;
}




































