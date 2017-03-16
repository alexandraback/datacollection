#include<bits/stdc++.h>
#define M 500
#define NM 10000000
using namespace std;
vector < string > all;
int j , n;
bool np[NM + 5];
vector < int > prime;
bool ck(string t,int x,int base){
	int ret = 0 , mul = 1;
	for(int i = 0 ; i < t.size() ; i++){
		if(t[i] == '1')	ret = (ret + mul)%x;
		mul = 1ll*mul*base%x;
	}
	return (ret == 0);
}
bool is_equal(int x,string t){
	string xx;
	while(x > 0){
		xx += ('0' + x%2);
		x /= 2;
	}
	return (xx == t);
}
void eratos(){
	for(int i = 2 ; i <= M ; i++)
		if(!np[i]){
			prime.push_back(i);
			for(int j = i + i ; j <= M ; j += i)	np[j] = true;
		}
}	
void back(int k,string t){
	if(all.size() >= j)	return ;
	if(k == n){
		for(int base = 2 ; base <= 10 ; base++){
			bool ok = false;
			for(int i = 0 ; i < 50 ; i++)	if(ck(t , prime[i] , base) && !is_equal(prime[i] , t)){
				ok = true;
				break;
			}
			if(!ok)	return ;
		}
		all.push_back(t);
	}
	else{
		k++;
		for(int i = 0 ; i < 2 ; i++){
			if( (k == 1 || k == n) && i == 0)	continue;
			back(k , t + (char) (i + '0'));
			if(all.size() >= j)	return ;
		}
	}
}
main(){
	freopen("test.inp","w",stdout);
	scanf("%d %d",&n,&j);
	eratos();
	back(0 , "");
	printf("Case #%d:\n",1);
	for(int i = 0 ; i < all.size() ; i++){
		string tmp = all[i];
		reverse(tmp.begin() , tmp.end());
		cout<<tmp<<' ';
		for(int base = 2 ; base <= 10 ; base++){
			bool ok = false;
			for(int it = 0 ; it < 50 ; it++){
				if(ck(all[i] , prime[it] , base)){
					ok = true;
					cout<<prime[it]<<' ';
					break;
				}
			}
			assert(ok);
		}
		cout<<'\n';
	}
}
