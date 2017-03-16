#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

int main(){
	int T;
	int a[2000];
	int b[2000];
	int am[2000];
	int bm[2000];
	int n;
	int c;
	bool g;
	int count=0;
	int s;
	int m;
	bool sp;
	cin>>T;
	int mi;
	int max;
	while(T--){
		++count;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i]>>b[i];
			am[i]=0;
			bm[i]=0;
		}
		g=true;
		s=0;
		m=0;
		while(s<2*n){
			g=false;
			sp=true;
			while(sp){
				sp=false;
				for(int i=0;i<n;++i){
					if(bm[i]==0&&s>=b[i]){
						if(am[i]==0)
							s+=2;
						else
							++s;
						sp=true;
						bm[i]=1;
						am[i]=1;
						++m;
					}
				}
			}
			max=0;
			mi=-1;
			for(int i=0;i<n;++i){
				if(am[i]==0&&s>=a[i]){
					if(b[i]>=max){
						max=b[i];
						mi=i;
					}
				}
			}
			if(mi>=0){
				am[mi]=1;
				++s;
				++m;
			}
			else if(s<2*n){
//				cout<<s;
				cout<<"Case #"<<count<<": Too Bad\n";
				break;
			}
		}

		if(s==2*n)
			cout<<"Case #"<<count<<": "<<m<<"\n";


		//		printf("%.6f",1.0);

	}
	return 0;
}
