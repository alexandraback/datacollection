#include<iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int t[105];
//int s[100];
int main(){
	freopen("test_input.txt","r",stdin);
	freopen("B-out.txt","w",stdout);
	int T,N,S,p,res;
	scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		res=0;
		memset(t,0,sizeof(t));
		//memset(s,0,sizeof(s));
		scanf("%d%d%d",&N,&S,&p);
		int c=0;
		for(int i=0;i<N;i++,c++){
			scanf("%d",&t[c]);
			if(ceil((double)t[c]/3.00)>=p){
				res+=1;
				c--;
			}
		}
		t[c]=-1;
		sort(t,t+N,cmp);
		for(int i=0,j=0;j<S;i++){
			if(t[i]==-1)
				break;
			if(t[i]>=2){
				if((ceil((double)t[i]/3.00)+(t[i]%3 ==1?0:1))>=p){
					res+=1;
					j++;
				}
			}
			else{
				if(t[i]>=p){
					res==1;
					j++;
				}
			}
		}
		printf("Case #%d: %d\n",_T,res);
	}
	return 0;
}