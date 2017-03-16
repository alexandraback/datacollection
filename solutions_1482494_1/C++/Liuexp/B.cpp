#include "mylib.h"
//#define SMALL
#define LARGE
int A,B;
int N;
int a[ 1001],b[ 1001];
//int m[12];
bool done1[1001],done2[1001];
ull stoi(string &t)
{
    ull ret=0;
    sscanf(t.c_str(),"%lld",&ret);
    return ret;
}
string itos0(ull t)
{
    stringstream sout;
    sout<<t;
    return sout.str();
}

int solve(){
	bool done=false;
	memset(done1,0,sizeof(done1));
	memset(done2,0,sizeof(done2));
	int curScore=0;
	int ret=0;
	while(!done){
		bool hasPassed1=false,canAdd1by1=false,canAdd2=false,canAdd1by2=false;
		int max2=0;
		for(int i=0;i<N;i++){
			if(done2[i])continue;
			if(done1[i]){
				hasPassed1=true;
				if(curScore>=b[i])canAdd1by2=true;
			}
			else if(curScore>=b[i])canAdd2=true;
			else if(curScore>=a[i]){
				canAdd1by1=true;
				max2=max(max2,b[i]);
			}
		}

		if(canAdd2){
			for(int i=0;i<N;i++){
				if(done2[i])continue;
				if(!done1[i]&&curScore>=b[i]){
					curScore+=2;
					done2[i]=true;
					break;
				}
			}
		} else if(canAdd1by2){
			for(int i=0;i<N;i++){
				if(done2[i])continue;
				if(done1[i]&&curScore>=b[i]){
					curScore+=1;
					done2[i]=true;
					break;
				}
			}
		}else if(canAdd1by1){
			for(int i=0;i<N;i++){
				if(done1[i]||done2[i])continue;
				if(curScore>=a[i]&&max2==b[i]){
					curScore+=1;
					done1[i]=true;
					break;
				}
			}
		}else{
			done=true;
			break;
		}
		ret++;
	}
	for(int i=0;i<N;i++){
		if(!done2[i])return -1;
	}
	return ret;

}
void init(){
//	int cur=3;
//	for(int i=0;i<12;i++){
//		m[i]=cur;
//		cur<<=2;
//	}
}

int main() {
#ifdef SMALL
	freopen("B-small-attempt1.in","rt",stdin);
	freopen("B-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
#endif
	init();
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>a[i]>>b[i];
		}
		int ans = solve();	
		//cout.setprecision(9);
		cout<<"Case #"<<t<<": ";
		if(ans>=0)cout<<ans<<endl;
		else cout<<"Too Bad"<<endl;
	}

	return 0;
}
