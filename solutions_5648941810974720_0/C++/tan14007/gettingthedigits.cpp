#include <bits/stdc++.h>
#define X first
#define Y second
#define PI pair<int,int>
using namespace std;
int a,b,c,d,e,f,g,h,i,j,k,l,m,o,p,q,r,s,t,u,v,w,x,y,z;
int ct[100100];
int ma[1010];
string str;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf(" %d",&t);
	for(l=1;l<=t;l++){
		printf("Case #%d: ",l);
		cin>>str;
		memset(ct,0,sizeof(ct));
		memset(ma,0,sizeof(ma));
		for(i=0;i<str.length();i++){
			ct[str[i]]++;
		}
		if(ct['Z']){
			while(ct['Z']){
				ct['Z']--;
				ct['E']--;
				ct['R']--;
				ct['O']--;
				ma[0]++;
			}
		}
		if(ct['W']){
			while(ct['W']){
				ct['T']--;
				ct['W']--;
				ct['O']--;
				ma[2]++;
			}
		}
		if(ct['U']){
			while(ct['U']){
				ct['F']--;
				ct['O']--;
				ct['U']--;
				ct['R']--;
				ma[4]++;
			}
		}
		if(ct['R']){
			while(ct['R']){
				ct['T']--;
				ct['H']--;
				ct['R']--;
				ct['E']--;
				ct['E']--;
				ma[3]++;
			}
		}
		if(ct['F']){
			while(ct['F']){
				ct['F']--;
				ct['I']--;
				ct['V']--;
				ct['E']--;
				ma[5]++;
			}
		}
		if(ct['V']){
			while(ct['V']){
				ct['S']--;
				ct['E']--;
				ct['V']--;
				ct['E']--;
				ct['N']--;
				ma[7]++;
			}
		}
		if(ct['X']){
			while(ct['X']){
				ct['S']--;
				ct['I']--;
				ct['X']--;
				ma[6]++;
			}
		}
		if(ct['H']){
			while(ct['H']){
				ct['E']--;
				ct['I']--;
				ct['G']--;
				ct['H']--;
				ct['T']--;
				ma[8]++;
			}
		}
		if(ct['I']){
			while(ct['I']){
				ct['N']--;
				ct['I']--;
				ct['N']--;
				ct['E']--;
				ma[9]++;
			}
		}
		if(ct['O']){
			while(ct['O']){
				ct['O']--;
				ct['N']--;
				ct['E']--;
				ma[1]++;
			}
		}
		for(i=0;i<=9;i++){
			while(ma[i]){
				printf("%d",i);ma[i]--;
			}
		}
		printf("\n");
	}
	return 0;
}