#include <bits/stdc++.h>




using namespace std;







#define fr(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp make_pair
typedef pair<int,int> pii;

int t,n;

int war(vector<double> v, vector<double> v2){
	int pnt1 = 0, pnt2 = n-1;
	int ret = 0;
	for(int i = n-1; i >= 0; --i){
		if(v[i] > v2[pnt2]){
			pnt1++;
			ret++;
		}
		else{
			pnt2--;
		}
	}
	return ret;
}


int decwar(vector<double> v, vector<double> v2){
	int pnt1 = 0, pnt2 = n-1, pnt3 = n-1;
	int ret = 0;
	fr(i,0,n){
		if(v[pnt2] > v2[pnt3]){
			pnt2--;
			pnt3--;
			ret++;
		}
		else{
			pnt1++;
			pnt3--;
		}
	}
	return ret;
}

vector<double> v, v2;

int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%d",&n);
		v = vector<double>(n), v2 = vector<double>(n);
		fr(i,0,n) scanf("%lf",&v[i]);
		fr(i,0,n) scanf("%lf",&v2[i]);
		sort(v.begin(),v.end());
		sort(v2.begin(),v2.end());
		int pnt = 0;
		printf("Case #%d: %d %d\n",cas,decwar(v,v2), war(v,v2));
	}
	return 0;
}