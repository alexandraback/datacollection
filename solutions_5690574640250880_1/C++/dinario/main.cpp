#include <iostream>
#include <fstream>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;
#define re return
#define ll  long long

const ll MOD=1E9+7;

void print(int w,int h,int platform,int count,int top,int count2){
	int i,j;
	for(i=0;i<h;++i){
		for(j=0;j<w;++j){
			if(i==0&&j==0)cout<<"c";
			else{
				if(j<platform&&i<count)cout<<".";
				else if(j<top&&i<count+count2)cout<<".";
				else cout<<"*";
			}
		}
		cout<<endl;
	}
}

char res[60][60];

int main(){
	freopen("C-large.in","rt",stdin);
	//freopen("input.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	ll i,j,n,k=0,T,t;
	cin>>T;
	for(t=0;t<T;++t){
		int h,w,m,free;
		cin>>h>>w>>m;
		free=h*w-m;
		bool bOk=false;
		cout<<"Case #"<<t+1<<":"<<endl;
		if(free<1){
			bOk=false;
		}
		else if(free==1){
			bOk=true;
			print(w,h,1,1,0,0);
		}else if(w==1||h==1){
			bOk=true;
			if(w==1)
				print(w,h,0,0,1,free);
			else
				print(w,h,free,1,0,0);
		}else if(w==2||h==2){
			if(free%2==0&&free/2>1){
				bOk=true;
				if(w==2)
					print(w,h,0,0,2,free/2);
				else
					print(w,h,free/2,2,0,0);
			}
		}else if(free<5){
			if(free==4){
				bOk=true;
				print(w,h,2,2,0,0);
			}
		}
		else{
			for(i=0;i<w;++i)
				for(j=0;j<h;++j)
					res[i][j]='*';
			for(int x=2;x<=w&&!bOk;++x)
				for(int y=0;y<=h-2&&!bOk;++y)
				{
					if(2*(x+y)<=free){
						int remain=free-2*(x+y);
						if(!(remain==1&&y==0)){
							if((x-2)*y>=remain){
								remain=free-2*(x+y);
								for(i=0;i<x;++i)res[i][0]='.',res[i][1]='.';
								for(i=0;i<y;++i)res[0][i+2]='.',res[1][i+2]='.';

								for(i=0;i<y&&remain>0;++i){
									for(j=0;j<x-2&&remain>0;++j){
										res[2+j][2+i]='.';
										remain-=1;
									}
								}
								bOk=true;
							}
						}
					}
				}
			if(bOk){
				for(i=0;i<h;++i){
					for(j=0;j<w;++j){
						if(i==0&&j==0)cout<<"c";
						else cout<<res[j][i];
					}
					cout<<endl;
				}
			}
		}
		if(!bOk){
			cout<<"Impossible"<<endl;k++;
		}
	}
	re 0;
}