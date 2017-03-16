//#include <bits/stdc++.h>
// author - Sameer Makker 
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
//#include<set>
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second 
#define si(a) scanf("%d",&a)
#define sil(a) scanf("%lld",&a)
#define pi(a) printf("%d ",a)
#define pil(a) printf("%lld",a)
#define MOD 1000000007
using namespace std ;
vector<pii> v ;
int cnt[26]={0};
void set(char ch,int sub){
	cnt[ch-'A']-=sub;
}
int main(){
	string s;
	int t,i,j,k,n,z;
	si(t);
	for(i=1;i<=t;i++){
		for(k=0;k<26;k++){
			cnt[k]=0;
		}
		int ans[10];
		cin>>s;
		for(j=0;j<s.length();j++){
			cnt[s[j]-'A']++;
		}
		ans[6]=cnt['X'-'A'];
		set('S',ans[6]);set('I',ans[6]);set('X',ans[6]);
		ans[7]=cnt['S'-'A'];
		set('S',ans[7]);set('E',ans[7]);set('V',ans[7]);set('E',ans[7]);set('N',ans[7]);
		ans[5]=cnt['V'-'A'];
		set('F',ans[5]);set('I',ans[5]);set('V',ans[5]);set('E',ans[5]);
		ans[4]=cnt['F'-'A'];
		set('R',ans[4]);set('U',ans[4]);set('O',ans[4]);set('F',ans[4]);
		ans[0]=cnt['Z'-'A'];
		set('Z',ans[0]);set('E',ans[0]);set('R',ans[0]);set('O',ans[0]);
		ans[2]=cnt['W'-'A'];
		set('O',ans[2]);set('W',ans[2]);set('T',ans[2]);
		ans[1]=cnt['O'-'A'];
		set('E',ans[1]);set('N',ans[1]);set('O',ans[1]);
		ans[8]=cnt['G'-'A'];
		set('T',ans[8]);set('H',ans[8]);set('G',ans[8]);set('I',ans[8]);set('E',ans[8]);
		ans[9]=cnt['N'-'A']/2;
		set('E',ans[9]);set('N',ans[9]);set('I',ans[9]);set('N',ans[9]);
		ans[3]=cnt['T'-'A'];
		set('E',ans[3]);set('E',ans[3]);set('R',ans[3]);set('H',ans[3]);set('T',ans[3]);
		printf("Case #%d: ",i);
		for(k=0;k<=9;k++){
			while(ans[k]>0){
				printf("%d",k);
				ans[k]--;
			}
		}
		printf("\n");
	}
	
		return 0;

}