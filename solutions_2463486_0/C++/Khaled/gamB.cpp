#include<stdio.h>
#include<vector>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 1000
#define pb push_back
vector<int> vc;

char s[20];
int check(int n){

	sprintf(s,"%d",n);
	int i=0,j=strlen(s)-1;
	
	while(i<j){
		if(s[i]!=s[j]) return 0;
		i++;
		j--;
	}
	
	return 1;
}

void gen(){
	int p=(int)sqrt(MAX);
	int i;
	
	for(i=1;i<=p;i++){
		
		if(check(i) && check(i*i)) vc.pb(i);
	}
}

int main(){
	int t,i,x,y,k;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	gen();
	for(k=1;k<=t;k++){
		scanf("%d%d",&x,&y);
		y = (int)sqrt(y);
		x = (int)ceil(sqrt(x));
		x = upper_bound(vc.begin(),vc.end(),y) - lower_bound(vc.begin(),vc.end(),x);
		
		printf("Case #%d: %d\n",k,x);
	}
	return 0;
}
