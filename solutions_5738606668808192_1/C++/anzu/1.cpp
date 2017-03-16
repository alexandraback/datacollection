#include<iostream>
#include<set>
#include<fstream>

using namespace std;

int check(int n,int o){
	int res=0;
	int power=1;
	while(n){
		res = res +power*(n%2);
		power*=o;
		//cout<<power<<' '<<res<<'\n';
		n/=2;
	}
	return res;
}

bool prime(int n){
	for(int i=2;i*i<=n;++i)
		if(n%i==0)return 0;
	return 1;
}

string tr(int a){
	string s;
	while(a){
		s =  (char)(a%2+'0') + s;
		a/=2;
	}
	return s;

}
string s[]=
{
"10000001","10000111","10001101","10010011",
"10011001","10011111","10100101","10110001",
"10110111","10111101","11000011","11001001",
"11001111","11011011","11100001","11100111",
"11101101","11110011","11111001","11111111"};

int main(){
	//ifstream cin("ff.in");
	//ofstream cout("1.txt");
	
	int t,n,cq;
	cin>>t>>n>>cq;
//	int p1=256,
//		p2=256*256,
//		p3=256*256*256;
	cout<<"Case #1:\n";
	if(n==16){
		for(int i=0;i<16 && cq;++i)
			for(int j=0;j<16&&cq;++j)
			{
				cout<<s[i]<<s[j]<<' '<<"3 2 5 2 7 2 9 2 11\n";
				--cq;
			}
	}
	else {
		for(int i=0;i<16 && cq;++i)
			for(int j=0;j<16&&cq;++j)
				for(int g=0;g<16&&cq;++g)
					for(int k=0;k<16&&cq;++k)
					{
						cout<<s[i]<<s[j]<<s[g]<<s[k]<<' '<<"3 2 5 2 7 2 9 2 11\n";
						--cq;
					}
	}
	
}