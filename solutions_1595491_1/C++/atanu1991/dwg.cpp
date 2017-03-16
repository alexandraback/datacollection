#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
int T;
cin>>T;
int tc;
for(tc=1;tc<=T;tc++){
	int n,s,p;
	cin>>n>>s>>p;
	int a[n];
	int b[n+1][3];
	int i=0;
	for(i=0;i<n;i++)
 		cin>>a[i];
 	sort(a,a+n);
 	
 		int j=0;
 		int crit;
 			if(p==1) crit=1;
 			else if(p==0) crit=0;
 			else crit=(p-2)*3+2;
 		
 		for(j=0;j<n;j++){
 			if(a[j]>=crit) break;
 		}
 		for(i=0;i<s&&j<n;i++){
 		if(a[j]==0){
 			b[j][0]=a[j];
 			b[j][1]=a[j];
 			b[j][2]=a[j];
 		}
 		else if(a[j]%3==0){
 			b[j][0]=a[j]/3-1;
 			b[j][1]=a[j]/3;
 			b[j][2]=a[j]/3+1;
 		}
 		else if(a[j]%3==1){
 			b[j][0]=a[j]/3-1;
 			b[j][1]=a[j]/3+1;
 			b[j][2]=a[j]/3+1;
 		}
 		else if(a[j]%3==2){
 			b[j][0]=a[j]/3;
 			b[j][1]=a[j]/3;
 			b[j][2]=a[j]/3+2;
 		}
 		a[j]=-1;
 		j++;
 	}
 	for(i=0;i<n;i++){
 		if(a[i]==-1) continue;
 		if(a[i]==0){
 			b[i][0]=a[i];
 			b[i][1]=a[i];
 			b[i][2]=a[i];
 		}
 		else if(a[i]%3==0){
 			b[i][0]=a[i]/3;
 			b[i][1]=a[i]/3;
 			b[i][2]=a[i]/3;
 		}
 		else if(a[i]%3==1){
 			b[i][0]=a[i]/3;
 			b[i][1]=a[i]/3;
 			b[i][2]=a[i]/3+1;
 		}
 		else if(a[i]%3==2){
 			b[i][0]=a[i]/3;
 			b[i][1]=a[i]/3+1;
 			b[i][2]=a[i]/3+1;
 		}
 	}
 	int ans=0;
 	for(i=0;i<n;i++){
 		if(b[i][2]>=p) ans++;
 	}
 	printf("Case #%d: %d\n",tc,ans);
}
return 0;
}
