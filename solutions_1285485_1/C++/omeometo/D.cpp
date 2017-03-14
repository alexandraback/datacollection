#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

char board[40][40];
char lboard[80][80];

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ci,cj;

int doit(int p,int q,int d,int sp,int sq){
	vector<pair<int,int> > ev;
	//printf("direction %d %d\n",p*sp,q*sq);
	for(int c=1;c<=2*d;c++)ev.push_back(make_pair(c*q,0));
	for(int c=1;c<=2*d;c++)ev.push_back(make_pair(c*p,1));
	sort(ev.begin(),ev.end());
	int di=sp,dj=sq;
	int i=ci*2+(sp==1?1:0);
	int j=cj*2+(sq==1?1:0);
	for(int k=0;k<ev.size();k++){
		//printf("square %d %d, dir=%d %d\n",i,j,di,dj);
		int t=ev[k].first;
		if((long long)t*t*((long long)p*p+(long long)q*q)>4*(long long)d*d*p*p*q*q)break;
		if(ev[k].first==ev[k+1].first){
			//puts("corner");
			if(ci*2+1==i+(di==1?1:0) && cj*2+1==j+(dj==1?1:0)){/*puts("ok");*/return 1;}
			char c1=lboard[i+di][j+dj];
			char c2=lboard[i+di][j];
			char c3=lboard[i][j+dj];
			if(c1=='.'){i+=di;j+=dj;}
			if(c1=='#' && c2=='.' && c3=='.'){/*puts("ng");*/return 0;}
			if(c1=='#' && c2=='.' && c3=='#'){i+=di;dj*=-1;}
			if(c1=='#' && c2=='#' && c3=='.'){di*=-1;j+=dj;}
			if(c1=='#' && c2=='#' && c3=='#'){di*=-1;dj*=-1;}
			k++;
		}else if(ev[k].second==0){
			//puts("tate edge");
			if(lboard[i+di][j]=='#')di*=-1; else i+=di;
		}else{
			//puts("yoko edge");
			if(lboard[i][j+dj]=='#')dj*=-1; else j+=dj;
		}
	}
	/*puts("ng");*/return 0;
}

main(){
	int cases;
	scanf("%d ",&cases);
	for(int casenum=1;casenum<=cases;casenum++){
		printf("Case #%d: ",casenum);
		int tate,yoko;
		scanf("%d%d ",&tate,&yoko);
		int d;
		scanf("%d ",&d);
		for(int i=0;i<tate;i++){
			gets(board[i]);
			for(int j=0;j<yoko;j++)if(board[i][j]=='X'){ci=i;cj=j;board[i][j]='.';}
		}
		//	puts("hjoge");
		for(int i=0;i<tate;i++)for(int j=0;j<yoko;j++)lboard[2*i][2*j]=lboard[2*i][2*j+1]=lboard[2*i+1][2*j]=lboard[2*i+1][2*j+1]=board[i][j];
		int ans=0;
		for(int p=1;p<=52;p++){
			for(int q=1;q<=52;q++){
				if(gcd(p,q)>1)continue;
				ans+=doit(p,q,d,1,1);
				ans+=doit(p,q,d,1,-1);
				ans+=doit(p,q,d,-1,1);
				ans+=doit(p,q,d,-1,-1);
			}
		}
		
		for(int i=ci+1;i<tate;i++)if(board[i][cj]=='#' && (i-ci)*2-1<=d){ans++;break;}
		for(int i=ci-1;i>=0;i--)if(board[i][cj]=='#' && (ci-i)*2-1<=d){ans++;break;}
		for(int j=cj+1;j<yoko;j++)if(board[ci][j]=='#' && (j-cj)*2-1<=d){ans++;break;}
		for(int j=cj-1;j>=0;j--)if(board[ci][j]=='#' && (cj-j)*2-1<=d){ans++;break;}
		printf("%d\n",ans);
		fprintf(stderr,"Case #%d: %d\n",casenum,ans);
	}
}