#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#define pb push_back
typedef long long int LL;
using namespace std;

int main(){
        int t,n,m;
        scanf("%d",&t);
        for(int i=1;i<=t;i++){
        	bool flag=false;
		double d;
		int n,a;
		cin>>d>>n>>a;
		double tixi[n][2];
		for(int j=0;j<n;j++){
			cin>>tixi[j][0]>>tixi[j][1];
		}
		double speed,time,ans;
		if(n==1){
			if(tixi[0][1]>=d){
				flag=true;
			}
			else{
				;//dont know what to do here
			}
		}
		else if(n==2){
			speed=(tixi[1][1]-tixi[0][1])/(tixi[1][0]-tixi[0][0]);
			time=(d-tixi[0][1])/speed;
		}
		cout<<"Case #"<<i<<":"<<endl;
		for(int k=0;k<a;k++){
			double accel;
			cin>>accel;
			if(flag){
				ans=sqrt(2*d/accel);
			}
			else{
				double comp = sqrt(2*d/accel);
				if(comp<=time) ans=time;
				else ans=comp;
			}
			printf("%0.7lf\n",ans);
		}
		
		
        }
        return 0;
}
