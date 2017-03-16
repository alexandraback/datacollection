#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

using namespace std;

typedef long long ll;

ll arr[50];


void precalc() {
	arr[0] = 1LL;
	arr[1] = 4LL;
	arr[2] = 9LL;
	arr[3] = 121LL;
	arr[4] = 484LL;
	arr[5] = 10201LL;
	arr[6] = 12321LL;
	arr[7] = 14641LL;
	arr[8] = 40804LL;
	arr[9] = 44944LL;
	arr[10] = 1002001LL;
	arr[11] = 1234321LL;
	arr[12] = 4008004LL;
	arr[13] = 100020001LL;
	arr[14] = 102030201LL;
	arr[15] = 104060401LL;
	arr[16] = 121242121LL;
	arr[17] = 123454321LL;
	arr[18] = 125686521LL;
	arr[19] = 400080004LL;
	arr[20] = 404090404LL;
	arr[21] = 10000200001LL;
	arr[22] = 10221412201LL;
	arr[23] = 12102420121LL;
	arr[24] = 12345654321LL;
	arr[25] = 40000800004LL;
	arr[26] = 1000002000001LL;
	arr[27] = 1002003002001LL;
	arr[28] = 1004006004001LL;
	arr[29] = 1020304030201LL;
	arr[30] = 1022325232201LL;
	arr[31] = 1024348434201LL;
	arr[32] = 1210024200121LL;
	arr[33] = 1212225222121LL;
	arr[34] = 1214428244121LL;
	arr[35] = 1232346432321LL;
	arr[36] = 1234567654321LL;
	arr[37] = 4000008000004LL;
	arr[38] = 4004009004004LL;
}

int main() {
	int tc; cin>>tc; ++tc;
	precalc();
	fr(_,1,tc) {
		printf("Case #%d: ",_);
		ll a,b;
		cin>>a>>b;
		int ct = 0;
		bool ok = 0;
		fr(i,0,39) {
			if(arr[i]>=a)ok=1;
			if(arr[i]>b)ok=0;
			if(ok)++ct;
		}
		cout<<ct<<endl;
	}
	return 0;	
}
