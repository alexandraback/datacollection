#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<cmath>
#define EPS 0.00000001
using namespace std;
typedef long long ll;
int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int h,w;
double d;
char st[35][35];
bool eq(double a, double b){
	return (a<b+EPS && b<a+EPS);
}
int main(){
	int t;
	cin>>t;
	int x,y;
	ll nd;
	int xr,yr;
	double pt;
	int xl,yl;
	double sx,sy;
	double dt;
	double dy;
	for(int z=1;z<=t;z++){
		cin>>h>>w>>d;
		d*=2;
		nd=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>st[i][j];
			}
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(st[i][j]=='X'){
					x=j;
					y=i;
				}
			}
		}
		nd=4;
		for(int i=0;st[y][x+i]!='#';i++){
			if(i*4>d+EPS-2){
				nd--;
				break;
			}
		}
		for(int i=0;st[y][x-i]!='#';i++){
			if(i*4>d+EPS-2){
				nd--;
				break;
			}
		}
		for(int i=0;st[y+i][x]!='#';i++){
			if(i*4>d+EPS-2){
				nd--;
				break;
			}
		}
		for(int i=0;st[y-i][x]!='#';i++){
			if(i*4>d+EPS-2){
				nd--;
				break;
			}
		}
		for(int sxr=-1;sxr<=1;sxr+=2){
			for(int syr=-1;syr<=1;syr+=2){
				for(int xp=1;xp<=50;xp++){
					for(int yp=1;yp<=50;yp++){
						if(gcd(xp,yp)!=1)
							continue;
						xr=sxr;
						yr=syr;
						pt=0;
						xl=x;
						yl=y;
						sx=0;
						sy=0;
						
						while(pt<d+EPS){
							if(st[yl][xl]=='X' && pt>0.3){
								dt=-sx*xr;
								if(dt>0-EPS){
									dy=dt*yp/xp*yr;
									if(eq(sy+dy,0)){
										dy=sqrt(dt*dt*(1+((double)yp/xp)*((double)yp/xp)));
										if(pt+dy<d+EPS){
											nd++;
										/*	if(z==6){
										double xd=(pt+dy)/sqrt(1+((double)yp/xp)*((double)yp/xp));
										double yd=(pt+dy)/sqrt(1+((double)xp/yp)*((double)xp/yp));
										cout<<(xp*sxr)<<" "<<(yp*syr)<<" "<<(pt+dy)<<" "<<xd<<" "<<yd<<endl;
										
										}*/
											break;
										}
									}
								}
							}
							dt=1-sx*xr;
							sy+=dt*yp/xp*yr;
							if(eq(sy,yr)){
								if(st[yl+yr][xl+xr]=='#'){
									pt+=sqrt(dt*dt*(1+((double)yp/xp)*((double)yp/xp)));
									if(st[yl+yr][xl]=='.' && st[yl][xl+xr]=='.')
										break;
									if(st[yl][xl+xr]=='#')
										xr*=-1;
									else
										xl+=xr;
									if(st[yl+yr][xl]=='#')
										yr*=-1;
									else
										yl+=yr;
									sy=-yr;
									sx=-xr;
								}
								else{
									
									pt+=sqrt(dt*dt*(1+((double)yp/xp)*((double)yp/xp)));
									/*if(z==6){
										double xd=(pt)/sqrt(1+((double)yp/xp)*((double)yp/xp));
										double yd=(pt)/sqrt(1+((double)xp/yp)*((double)xp/yp));
										cout<<(xp*sxr)<<" "<<(yp*syr)<<" "<<(pt+dy)<<" "<<xd<<" "<<yd<<" k"<<endl;
										
									}*/
									xl+=xr;
									yl+=yr;
									sx=-xr;
									sy=-yr;
								}
							}
							else if(sy*sy>1){
								sy-=dt*yp/xp*yr;
								dt=1-sy*yr;
								sx+=dt*xp/yp*xr;
								pt+=sqrt(dt*dt*(1+((double)xp/yp)*((double)xp/yp)));
								if(st[yl+yr][xl]=='#'){
									yr*=-1;
								}
								else
									yl+=yr;
								sy=-yr;
							}
							else{
								pt+=sqrt(dt*dt*(1+((double)yp/xp)*((double)yp/xp)));
								if(st[yl][xl+xr]=='#'){
									xr*=-1;
								}
								else
									xl+=xr;
								sx=-xr;
							}
						}
					}
				}
			}
		}
		cout<<"Case #"<<z<<": "<<nd;
		cout<<endl;
	}
	return 0;
}
