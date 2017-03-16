#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
double a[2][1003];

int main(){

	freopen("I:\\D-large.in","r",stdin);
	freopen("I:\\D-large.out","w",stdout);
	int T,N;
	double* pt1,*pt2;
	int s1,s2;
	cin>>T;
	for(int cs=0;cs<T;++cs){
		cin>>N;
		for(int k=0;k<2;++k)
			for(int i=0;i<N;++i)
				cin>>a[k][i];
		std::sort(a[0],a[0]+N);
		std::sort(a[1],a[1]+N);
		s1=s2=0;

		for(pt1=a[0],pt2=a[1];pt1!=a[0]+N;++pt1){
			while(*pt1>*pt2&&pt2!=a[1]+N)
				++pt2;
			if(pt2!=a[1]+N)
				++pt2;
			else
				++s1;
		}

		for(pt1=a[0],pt2=a[1];pt1!=a[0]+N;){
			if(*pt1>*pt2){
				++s2;
				++pt1;
				++pt2;
			}else{
				++pt1;
			}
		}

		cout<<"Case #"<<cs+1<<": "<<s2<<' '<<s1<<endl;

	}
	return 0;
}
