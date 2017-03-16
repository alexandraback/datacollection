#include<bits/stdc++.h>
#define md 1000000007
#define ll  long long
#define gc getchar//_unlocked
using namespace std;
char s[100000];
char temp[10010];
int further(int i,int j){
	if(i==j)
		return -1;
	if(i==2 && j==3)
		return 4;
	if(i==2 && j==4)
		return -3;
	if(i==3 && j==2)
		return -4;
	if(i==3 && j==4)
		return 2;
	if(i==4 && j==2)
		return 3;
	if(i==4 && j==3)
		return -2;
}
int check(int i,int j){
	if(i==1)
		return j;
	if(i==-1)
		return -j;
	if(i<0){
		return -further(-i,j);
	}
	else{
		return further(i,j);
	}
}
int main()
{
	
    int test;
	ll l,x;
	scanf("%d",&test);
	for(int j=1;j<=test;j++){
		strcpy(s,"");
		scanf("%lld%lld",&l,&x);
		scanf("%s",temp);
		int len2=strlen(temp);
		int mm=min(x,(ll)4);
		for(int i=1;i<=mm;i++)
			strcat(s,temp);
		int f=0;
		int len=strlen(s);
		
		int ct=1;
		int ct2;
		int f2=-1;
		for(int i=0;i<len;i++){
			ct=check(ct,s[i]-'g');
			if(i==len2-1)
				ct2=ct;
			if(f==0 && ct==2)
				f++;
			else if(f==1 && ct==4){
				f++;
			
				
			}
			if(ct==3 && f2==-1 && !f){
				f2=i;
			}
		}
		
		if(f==1 && f2!=-1){
			if((ll)len+(ll)(f2+1)<=(l*x))
				f++;
		}
		if(ct2!=-1 && ct2!=1 && x%2==0 && x%4)
			f++;
		else if(ct2==-1 && x%2)
			f++;
		
		
		printf("Case #%d: ",j);
		if(f==3)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	
    
    return 0;
}