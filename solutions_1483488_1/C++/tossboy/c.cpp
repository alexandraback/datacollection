#include<iostream>
#include<cstring>
using namespace std;

int T,A,B;
int tag[2000001];
int base[100];

int len(int x){
	int l=1;
	while(x/10>0){
		l++;
		x = x/10;
	}
	return l;
}

int main(){
	base[0] = 1;
	for(int i=1; i<8; i++)
		base[i] = base[i-1]*10;

	cin>>T;
	for(int ca=1; ca<=T; ca++){
		cout<<"Case #"<<ca<<": ";
		cin>>A>>B;
		memset(tag,0,sizeof(tag));
		int sum =0;
		for(int x=A; x<=B; x++){
			int cnt=0;
			int l = len(x);
			while(tag[x] ==	0){
				tag[x] = 1;
				if(x>=A && x<=B)
					cnt++;
				while(len(x=x/10+x%10*base[l-1]) != l);
			}
			if(cnt>=2)
				sum += cnt*(cnt-1)/2;
		}
		cout<<sum<<endl;
	}
	return 0;
}
