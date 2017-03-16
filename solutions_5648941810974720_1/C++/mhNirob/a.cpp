#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<sstream>
#include<utility>
#include<climits>
#include<fstream>
#include<bitset>

using namespace std;

#define lli long long int
#define max 1000005

char str[3000];
lli fre[32];

vector<lli> v;


int main()
{
	freopen("input","r",stdin);
	freopen("output","w",stdout);

	lli n,t,i,j,k,ans,kase,len;

	scanf("%lld",&kase);

	for(i=1;i<=kase;i++){
		scanf("%s",str);
		len = strlen(str);
		memset(fre,0,sizeof(fre));
		v.clear();

		for(j=0;j<len;j++){
			fre[str[j]-'A']++;
		}

		printf("Case #%lld: ",i);

		//for(j=0;j<len;){
			while(fre['Z'-'A']>0 && fre['E'-'A']>0 &&fre['R'-'A']>0 &&fre['O'-'A']>0){
				//printf("0");
				v.push_back(0);
				fre['Z'-'A']--;
				fre['E'-'A']--;
				fre['R'-'A']--;
				fre['O'-'A']--;
				j+=4;
			}


			while(fre['T'-'A']>0 && fre['W'-'A']>0 &&fre['O'-'A']>0){
				v.push_back(2);
				//printf("2");
				fre['T'-'A']--;
				fre['W'-'A']--;
				fre['O'-'A']--;
				j+=3;
			}

			while(fre['X'-'A']>0 && fre['I'-'A']>0 &&fre['S'-'A']>0){
				//printf("6");
				v.push_back(6);
				fre['X'-'A']--;
				fre['I'-'A']--;
				fre['S'-'A']--;
				j+=3;
			}

			while(fre['E'-'A']>0 && fre['I'-'A']>0 &&fre['G'-'A']>0 &&fre['H'-'A']>0 && fre['T'-'A']>0){
				//printf("8");
				v.push_back(8);
				fre['E'-'A']--;
				fre['I'-'A']--;
				fre['G'-'A']--;
				fre['H'-'A']--;
				fre['T'-'A']--;
				j+=5;
			}

			while(fre['E'-'A']>1&&fre['R'-'A']>0 &&fre['H'-'A']>0 && fre['T'-'A']>0){
				//printf("3");
				v.push_back(3);
				fre['E'-'A']--;
				fre['E'-'A']--;
				fre['R'-'A']--;
				fre['H'-'A']--;
				fre['T'-'A']--;
				j+=5;
			}

			while(fre['F'-'A']>0 && fre['U'-'A']>0 &&fre['R'-'A']>0 &&fre['O'-'A']>0){
				//printf("4");
				v.push_back(4);
				fre['F'-'A']--;
				fre['U'-'A']--;
				fre['R'-'A']--;
				fre['O'-'A']--;
				j+=4;
			}

			while(fre['F'-'A']>0 && fre['E'-'A']>0 &&fre['I'-'A']>0 &&fre['V'-'A']>0){
				//printf("5");
				v.push_back(5);
				fre['F'-'A']--;
				fre['E'-'A']--;
				fre['I'-'A']--;
				fre['V'-'A']--;
				j+=4;
			}

			while(fre['E'-'A']>1&&fre['V'-'A']>0 &&fre['S'-'A']>0 && fre['N'-'A']>0){
				//printf("7");
				v.push_back(7);
				fre['E'-'A']--;
				fre['E'-'A']--;
				fre['V'-'A']--;
				fre['S'-'A']--;
				fre['N'-'A']--;
				j+=5;
			}


			

			while(fre['N'-'A']>0 && fre['E'-'A']>0 &&fre['I'-'A']>0 &&fre['N'-'A']>0){
				//printf("9");
				v.push_back(9);
				fre['N'-'A']--;
				fre['E'-'A']--;
				fre['I'-'A']--;
				fre['N'-'A']--;
				j+=4;
			}

			while(fre['N'-'A']>0 && fre['E'-'A']>0 &&fre['O'-'A']>0){
				//printf("1");
				v.push_back(1);
				fre['E'-'A']--;
				fre['N'-'A']--;
				fre['O'-'A']--;
				j+=3;
			}
			/*
			for(j=0;j<26;j++){
				if(fre[j]>0){
					printf("NO\n");
				}
			}
			*/

			lli sz=v.size();
			sort(v.begin(),v.end());
			for(j=0;j<sz;j++){
				printf("%lld",v[j]);
			}
			printf("\n");			

		//}

		//printf("Case #%lld: %lld\n",i,ans);
	}
	return 0;
}