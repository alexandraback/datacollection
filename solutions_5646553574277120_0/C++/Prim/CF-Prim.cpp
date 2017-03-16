#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define ii pair <int, int>
#define vii vector < ii >
#define vll vector <ll>
#define hash1 10000000000000061ll
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define na(x) ((x)<P?(x):(x)-P)
#define X first
#define Y second
using namespace std;
//__________________________

int n, t,c,d,v, ans, r, j, s;
vi vec;

//_________________________________________
int main(){

	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

	cin>>t;
	for(int t1 = 1; t1 <= t; ++t1){

		scanf("%d%d%d",&c,&d,&v);
		//cout<<c<<" "<<d<<" "<<v<<endl;
		vec.clear();
		vec.resize(d);
		for(int i = 0; i < d; i++) cin>>vec[i];
		sort(vec.begin(), vec.end());
		r = 1;
		j = 0;
		while(r <= v){
			//cout<<r<<endl;
			while(j < d && vec[j] <= r){
				r += vec[j];
				j++;
			}
			if(r <= v){
				ans ++;
				r += r;
			}
		}
		printf("Case #%d: %d\n", t1, ans);
		ans = 0;
	}

    return 0;
}
