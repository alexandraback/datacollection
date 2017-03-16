#include<fstream>
#include<iostream>
using namespace std;
int main(int args,char* argv[] ){
	ifstream in(argv[1]);
	ofstream out("c.output");
int T;
	int a,b;
	int count;
	in>>T;
	int tmp;
	int th;
	int pow;
	int x;
	for(int i=1;i<=T;++i){
		in>>a>>b;
		count=0;
		for(int j=a;j<=b;++j){
			for(int k=j+1;k<=b;++k){
				tmp=k;
				th=0;
				pow=1;
				while(tmp){
					++th;
					tmp/=10;
					pow*=10;
				}
				pow/=10;
				tmp=k;
				for(int l=1;l<th;++l){
					x=tmp%10;
					tmp/=10;
					tmp+=x*pow;
//					cout<<tmp<<" ";
					if(x&&tmp==j){
						++count;
						break;
					}
				}
//				cout<<endl;
			}
		}
		out<<"Case #"<<i<<": "<<count<<"\n";
	}
return 0;
}
