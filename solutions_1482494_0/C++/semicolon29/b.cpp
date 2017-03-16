
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	int t,cs,i,j;
	cin>>t;
	for(cs=1;cs<=t;cs++){
		int n,a[1001],b[1001],ca[1001],cb[1001];
		cin>>n;
		for(i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			ca[i]=a[i];
			cb[i]=b[i];
		}
		int cnt=0,f=0,in,st=0,fl=0;
		bool visa[1001],visb[1001];
		memset(visa,false,sizeof visa);
		memset(visb,false,sizeof visb);
		while(st<2*n){
			f=0;
			for(i=0;i<n;i++){
				if(visb[i]==false){
					if(b[i]<=st){
//						cout<<i<<"s"<<endl;
						cnt++;
						visb[i]=true;
						if(visa[i]==true)
							st++;
						else
							st+=2;
						f=1;
					}
				}
			}
			if(f==0){
				int mina=1e9,maxb=0;
				for(i=0;i<n;i++){
					if(visa[i]==false && visb[i]==false){
						if(a[i]<mina){
							mina=a[i];
							maxb=b[i];
							in=i;
						}
						if(a[i]==mina){
							if(b[i]>maxb){
								maxb=b[i];
								in=i;
							}
						}
					}
				}
				if(a[in]<=st && visa[in]==false){
//					cout<<in<<"f"<<endl;
					cnt++;
					st++;
					visa[in]=true;
				}
				else{
					cout<<"Case #"<<cs<<": Too Bad\n";
					fl=1;
					break;
				}
			}
		}
		if(fl==0)
			cout<<"Case #"<<cs<<": "<<cnt<<endl;
	}
	return 0;
}
