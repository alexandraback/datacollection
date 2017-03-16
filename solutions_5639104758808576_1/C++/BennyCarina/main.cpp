#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<set>
using namespace std;

#define d_pi 57.2957795
#define LL __int64
#define LarN 100000

template<class T> inline void ReMin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ReMax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}

int buf[1005];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T_case;
	string read;
	int L;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		printf("Case #%d: ",i_case);
		scanf("%d", &L);
		int ans = 0, acc = 0;
		cin>>read;
		for(int i = 0; i <= L;i ++){
			buf[i] = read[i] - '0';
		}
		for(int i = 0; i <= L; i ++){
			if(buf[i] == 0)continue;
			else if( acc >= i){
				acc += buf[i];
			}
			else{
				ans += i - acc;
				acc = i + buf[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
