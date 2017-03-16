#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class info{
public:
	int l_1,l_2;
	info(int l_1,int l_2):l_1(l_1),l_2(l_2){};
	info(){};
};

bool operator < (info a,info b){
	if(a.l_2!=b.l_2) return a.l_2>b.l_2;
	else return a.l_1<b.l_1;
}

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		int N;
		cin>>N;
		vector<info> I(N);
		for(int i=0;i<N;i++){
			int a,b; cin>>a>>b;
			I[i]=info(a,b);
		}
		int num=0;
		int star=0;

		bool ok1[1000],ok2[1000];
		memset(ok1,false,sizeof(ok1));
		memset(ok2,false,sizeof(ok2));

		sort(I.begin(),I.end());

		bool update=true;
		int ans=0;
		while(update){
//			cout<<"star "<<star<<endl;
			if(num==I.size()) break;
			update=false;
			for(int i=0;i<N;i++){
				if(!ok1[i] && !ok2[i] && I[i].l_2<=star){
					ok2[i]=true;
					ok1[i]=true;
					star+=2;
					num++;
					update=true;
					ans++;
//					cout<<"clear direct2 "<<i<<endl;
					break;
				}
			}
			if(update) continue;
			for(int i=0;i<N;i++){
				if(ok1[i] && !ok2[i] && I[i].l_2<=star){
					ok2[i]=true;
					ok1[i]=true;
					star++;
					num++;
					update=true;
					ans++;
//					cout<<"clear 2 "<<i<<endl;
					break;
				}
			}
			if(update) continue;

			for(int i=0;i<N;i++){
				if(!ok1[i] && !ok2[i] && I[i].l_1<=star){
					ok1[i]=true;
					star++;
					ans++;
					update=true;
//					cout<<"clear 1 "<<i<<endl;
					break;
				}
			}
		}

		if(num==I.size()){
			cout<<"Case #"<<t<<": "<<ans<<endl;
		}
		else
			cout<<"Case #"<<t<<": "<<"Too Bad"<<endl;
	}
}