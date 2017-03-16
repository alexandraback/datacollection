#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int X,Y,xx,yy,cnt,test;
bool oX,oY;
vector<char>res;

int main(){
	freopen("i.txt","r",stdin);
	
	cnt=1;
	for (scanf("%d",&test);test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d%d",&X,&Y);
		oX=oY=false;
		xx=yy=0;
		if (X<0){
			X=-X;
			oX=true;
		}
		if (Y<0){
			Y=-Y;
			oY=true;
		}
		res.clear();
		int step=1;
		bool p=false,q=false;
		for (;xx!=X;step++){
			if (X>=xx+step && !q){
				res.push_back('E');
				xx+=step;
			}
			else{
				q=true;
				if (p){
					res.push_back('E');
					p=false;
					xx+=step;
				}
				else{
					res.push_back('W');
					p=true;
					xx-=step;
				}
			}
		}
		
		p=false;q=false;
		for (;yy!=Y;step++){
			if (Y>=yy+step && !q){
				res.push_back('N');
				yy+=step;
			}
			else{
				q=true;
				if (p){
					res.push_back('N');
					p=false;
					yy+=step;
				}
				else{
					res.push_back('S');
					p=true;
					yy-=step;
				}
			}
		}
		
		int len=res.size();
		for (int i=0;i<len;i++){
			if (res[i]=='E' || res[i]=='W'){
				if (oX){
					if (res[i]=='E') putchar('W');
						else putchar('E');
				}
				else putchar(res[i]);
			}
			if (res[i]=='N' || res[i]=='S'){
				if (oY){
					if (res[i]=='N') putchar('S');
						else putchar('N');
				}
				else putchar(res[i]);
			}
		}
		puts("");
	}
	return 0;
}
