/*
by george_cheng
*/
#include<iostream>
#include<vector>
using namespace std;
long long max(long long x,long long y){
	if (x>y)return x;
	return y;
}

int main(){

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);	
	
	int z;
	cin>>z;
	int r,n,m,k;
	cin>>r>>n>>m>>k;
	vector<int> v;
	for (int i=0;i<r;++i){
		int s1[8];
		int s2[8];
		int ans=0,aa,bb,cc;
		aa=0;
		bb=0;
		cc=0;
		for (int j=0;j<k;++j)cin>>s2[j];
		for (int a=2;a<6;++a)
			for (int b=2;b<6;++b)
				for (int c=2;c<6;++c){
					int posi=0;
					s1[0]=1;
					s1[1]=a;
					s1[2]=b;
					s1[3]=c;
					s1[4]=a*b;
					s1[5]=a*c;
					s1[6]=b*c;
					s1[7]=a*b*c;
					for (int j=0;j<7;++j){
						bool flag=false;
						for (int k=0;k<8;++k)
							if (s2[j]==s1[k]){
								++posi;
								flag=true;
							}
						if (flag==false)posi=-1000;
					}

					if (posi>ans){
						ans=posi;
						aa=a;bb=b;cc=c;
					}
				}
			cout<<aa<<bb<<cc<<endl;
	}
}