#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>
#include<cmath>
using namespace std;

int qcompare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

bool compare(int a,int b){
	return a<b;
}
//syntax for qsort => qsort (array, n, sizeof(int), qcompare);
//c++ sort => sort(v.begin(),v.end(),mycompare)

int main(){
	int T;
	cin>>T;
	double t[3000],x[3000];
	for(int cas=1;cas<=T;cas++){
		double D;
		int N,A;
		cin>>D;
		cin>>N>>A;
		int i,j,k;
		double flimit=N;
		for(i=0;i<N;i++){
			cin>>t[i]>>x[i];
			if(flimit==N && x[i]>D)flimit=i;
		}
		cout<<"Case #"<<cas<<":"<<endl;

		for(j=0;j<A;j++){
			double a;
			cin>>a;
			double ans=0.0,tdiff,tdist,maxdist,u=0.0,v=0.0,tm=0;
			for(i=0;i<N;i++){//follow limit
				tdiff=t[i]-tm;
				maxdist=u*tdiff+0.5*a*tdiff*tdiff;
				if(tdist+maxdist>=x[i]){
					tdist=x[i];
					v=0;
				}
				else{
					tdist=tdist+maxdist;
					v=u+a*tdiff;
				}

				if(tdist==D){
					ans=tm+t[i];
					break;
				}
				else if(tdist>D){
					//roll back

					double distLeft=D-x[i-1];
					double rtm;
					double z,y;
					z=(-u+sqrt(u*u+2*a*distLeft))/a;
					y=(-u-sqrt(u*u+2*a*distLeft))/a;
					
					//cout<<z<<" case first and "<<y<<endl;
					//cout<<"Roll back dist rem"<<distLeft<<endl;

					if(z>=0)rtm=z;
					else rtm=y;
					tm=tm+rtm;
					tdist=D;
					ans=tm;
					

					//now it shd not hit the other vehice

					double spd=(x[i]-x[i-1])/(t[i]-t[i-1]);
					double btm=distLeft/spd;

					ans=max(btm,ans);
					//cout<<"Roll back total time"<<ans<<endl;
					break;
				}

				u=v;
				tm=t[i];
			}
			if(tdist!=D){
					//cout<<" see "<<u<<endl;
					double distLeft=D-tdist;
					double rtm;
					double z,y;
					z=(-u+sqrt(u*u+2*a*distLeft))/a;
					y=(-u-sqrt(u*u+2*a*distLeft))/a;
					//cout<<z<<" and "<<y<<endl;
					//cout<<"distance "<<distLeft<<endl;
					if(z>=0)rtm=z;
					else rtm=y;
					tm=tm+rtm;
					ans=tm;//-0.446506;
			
			}
			printf("%.8lf\n",ans);
		}
	}
	return 0;
}
