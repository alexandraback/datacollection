#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

int myhypot(int a,int b){
	return a*a+b*b;
}

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int sign(int x){
	if(x>0)return 1;
	if(x==0)return 0;
	if(x<0)return -1;
}

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		int xx,yy,d;
		int sx,sy;
		scanf("%d %d %d",&yy,&xx,&d);
		for(int j=0;j<yy;j++){
			char ch[100];
			scanf("%s",ch);
			for(int i=0;i<xx;i++){
				if(ch[i]=='X'){
					sx=i-1;
					sy=j-1;
				}
			}
		}
		xx-=2;
		yy-=2;

		vector<pair<int,int> > pos;
		for(int i=-60;i<=60;i++){
			for(int j=-60;j<=60;j++){
				if(i==0 && j==0)continue;
				int tx=sx,ty=sy;
				if(abs(i)%2==1)tx=xx-1-sx;
				if(abs(j)%2==1)ty=yy-1-sy;
				tx+=i*xx;
				ty+=j*yy;
				if(myhypot(tx-sx,ty-sy)<=d*d){
					pos.push_back(MP(tx-sx,ty-sy));
				}
			}
		}

		vector<bool> dame(pos.size());
		for(int i=0;i<pos.size();i++){
			for(int j=i+1;j<pos.size();j++){
				int x1=pos[i].first;
				int y1=pos[i].second;
				int x2=pos[j].first;
				int y2=pos[j].second;
				if(sign(x1)!=sign(x2) || sign(y1)!=sign(y2))continue;
				x1=abs(x1);
				y1=abs(y1);
				x2=abs(x2);
				y2=abs(y2);
				int g1=gcd(x1,y1);
				int g2=gcd(x2,y2);
				x1/=g1;
				y1/=g1;
				x2/=g2;
				y2/=g2;
				if(x1==x2 && y1==y2)dame[j]=true;
			}
		}

		int ans=0;
		for(int i=0;i<pos.size();i++){
			if(!dame[i])ans++;
		}

		printf("Case #%d: %d\n",casecnt,ans);
		fflush(stdout);
	}

	return 0;
}
