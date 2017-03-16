#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int am[100];
int bm[100];
int km[100];
int aa[100];
int ba[100];
int ka[100];
int min(int x,int y){
	if(x>y)
		return x;
	else
		return y;
}
int t(long long int x,int i){
	return ((x>>i)&1);

}

int main(){
	int TT;
	cin>>TT;

	long long int a;
	long long int b;
	int ans;
	long long int k;

	for(int T=1;T<=TT;++T){
		
		cin>>a;
		cin>>b;
		cin>>k;
		int count=0;
		for(int i=0;i<32;++i){
			if(((a>>i)&1)==0){
				am[i]=1;
			}
			am[i]=0;
			if(((b>>i)&1)==0){
				bm[i]=1;
			}
			bm[i]=0;
			if(((k>>i)&1)==0){
				km[i]=1;
			}
			km[i]=0;

		}
		long long int ta;
		long long int tb;
		long long int tc;
		long long int tot=0;
		long long int c=k;
		for(int i=0;i<32;++i){
			if(t(a,i)==0)
				continue;
			ta=a;
			ta-=(1<<i);
			for (int j=0;j<32;++j){
				if(t(b,j)==0)
					continue;
				tb=b;
				tb-=(1<<j);
				for(int n=0;n<32;++n){
					if(t(c,n)==0)
						continue;
					tc=c;
					tc-=(1<<n);
					long long int tmp=1;
					for(int m=32;m>=0;--m){
						if(m>=n){
							if(m>=i){
								if(m>=j){
									if( (t(ta,m)&t(tb,m))!=t(tc,m))
										tmp=0;
								}
								else{
									if(t(tc,m)==1&&t(ta,m)==0){
										tmp=0;
									}
									else if(t(tc,m)==0&&t(ta,m)==0){
										tmp*=2;
									}
									
								}
							}
							else{
								if(m>=j){
									if(t(tc,m)==1&&t(tb,m)==0){
										tmp=0;
									}
									else if(t(tc,m)==0&&t(tb,m)==0){
										tmp*=2;
									}
								}
								else{
									if(t(tc,m)==0){
										tmp*=3;
									}
								}
							}
						}
						else{
							if(m>=i){
								if(m>=j){
								}
								else{
									tmp*=2;
								}
							}
							else{
								if(m>=j){
									tmp*=2;
								}
								else{
									tmp*=4;
								}
							}
						}
					}
					tot+=tmp;
				}
			}
		}

		
		
		cout<<"Case #"<<T<<": "<<tot<<"\n";



	}
	return 0;
}
