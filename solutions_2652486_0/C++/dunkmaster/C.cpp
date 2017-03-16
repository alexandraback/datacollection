#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	srand(time(NULL));
	int T,R,N,M,K;
	cin >> T >> R >> N >> M >> K;
	cout<<"Case #1:"<<endl;
	for(int z=1;z<=R;z++){
		int p[K];
		for(int i=0;i<K;i++)
			cin >> p[i];
		bool div5 = false;
		bool div3 = false;
		bool div4 = false;
		bool div2 = false;
		int num = 0;
		for(int i=0;i<K;i++){
			if(p[i]==125){
				cout<<555<<endl;goto end;
			}
			if(p[i]==36){
				cout<<334<<endl;goto end;
			}
			if(p[i]==45){
				cout<<533<<endl;goto end;
			}
			if(p[i]==60){
				cout<<543<<endl;goto end;
			}
			if(p[i]==80){
				cout<<544<<endl;goto end;
			}
			if(p[i]==100){
				cout<<554<<endl;goto end;
			}
			if(p[i]==40){
				cout<<542<<endl;goto end;
			}
			if(p[i]==27){
				cout<<333<<endl;goto end;
			}
			if(p[i]==18){
				cout<<332<<endl;goto end;
			}
			if(p[i]==48){
				cout<<443<<endl;goto end;
			}
			if(p[i]==64){
				cout<<444<<endl;goto end;
			}
			if(p[i]==24){
				cout<<234<<endl;goto end;
			}
			if(p[i]%5==0) div5 = true;
			if(p[i]%3==0) div3 = true;
			if(p[i]%4==0) div4 = true;
			if(p[i]%2==0&&p[i]%4!=0) div2 = true;
		}


		if(div5){ cout<<5;num++;}
		if(div3){ cout<<3;num++;}
		if(div4){ cout<<4;num++;}
		if(div2){ cout<<2;num++;}

		while(num<3){
			int r = (rand()%4) + 2;
			cout<<r;
			num++;
		}
		cout<<endl;
		end:;
	}
}