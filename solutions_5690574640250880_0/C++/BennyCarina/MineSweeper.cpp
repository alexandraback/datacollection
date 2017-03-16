#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

#define d_pi 57.2957795
#define LL long long
#define LarN 50
char map[LarN+5][LarN+5];
int R,C,M;
bool getans(){
	int k=R*C-M;
	if(k==R*C){
		for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)map[i][j]='.';
		map[1][1]='c';
		return true;
	}
	if(k==1){
		for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)map[i][j]='*';
		map[1][1]='c';
		return true;
	}
	if(R==1){
		map[1][1]='c';
		for(int i=2;i<=k;i++)map[1][i]='.';
		for(int i=k+1;i<=R*C;i++)map[1][i]='*';
		return true;
	}
	if(C==1){
		map[1][1]='c';
		for(int i=2;i<=k;i++)map[i][1]='.';
		for(int i=k+1;i<=R*C;i++)map[i][1]='*';
		return true;
	}
	if(R==2){
		if(k%2==1 || k<4)return false;
		for(int i=1;i<=k/2;i++)map[1][i]=map[2][i]='.';
		for(int i=k/2+1;i<=R*C/2;i++)map[1][i]=map[2][i]='*';
		map[1][1]='c';
		return true;
	}
	if(C==2){
		if(k%2==1 || k<4)return false;
		for(int i=1;i<=k/2;i++)map[i][1]=map[i][2]='.';
		for(int i=k/2+1;i<=R*C/2;i++)map[i][1]=map[i][2]='*';
		map[1][1]='c';
		return true;
	}
	if(k<4||k==5||k==7)return false;
	int a,b,l;
	for(a=2;a<=C;a++){
		for(l=2;l<R;l++){
			b=k-a*l;
			if(b==0 || (b>=2 && b<=a)){
				for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)map[i][j]='*';
				for(int i=1;i<=l;i++)for(int j=1;j<=a;j++)map[i][j]='.';
				for(int i=1;i<=b;i++)map[l+1][i]='.';
				map[1][1]='c';
				return true;
			}
			else if(b==1 && a>2 && l>2){
				for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)map[i][j]='*';
				for(int i=1;i<=l;i++)for(int j=1;j<=a;j++)map[i][j]='.';
				map[l][a]='*';
				for(int i=1;i<=2;i++)map[l+1][i]='.';
				map[1][1]='c';
				return true;
			}
			else if(b==1 && a>=4){
				for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)map[i][j]='*';
				for(int i=1;i<=l;i++)for(int j=1;j<a;j++)map[i][j]='.';
				for(int i=1;i<=3;i++)map[l+1][i]='.';
				map[1][1]='c';
				return true;
			}
		}
	}
	return false;
	
}

int main(){
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T_case;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		cin>>R>>C>>M;
		printf("Case #%d:\n",i_case);
		if(!getans()){
			printf("Impossible\n");
		}
		else{
			for(int i=1;i<=R;i++){
				map[i][C+1]='\n';
				map[i][C+2]='\0';
			}
			for(int i=1;i<=R;i++)printf("%s",&map[i][1]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}