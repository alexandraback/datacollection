#include<iostream>
using namespace std;
int cs;
int* cs2;
int ks[201];
int ls[201];

int t[201];
int k[201][401];
int kk[201];
	
int N;
int K;
int sto;

bool dfs(int l){
//	if(
//			//l==11&&
//		 ls[0]==0&&ls[1]==8&&ls[2]==1&&ls[3]==9
//		 &&ls[4]==2&&ls[5]==3&&ls[6]==4
//		 &&ls[7]==5&&ls[8]==7&&ls[9]==11
//		 &&ls[10]==13
//		 ){
//		cout<<"!";
//		for(int i=0;i<l;++i){
//			cout<<ls[i]<<" ";
//		}
//		cout<<" <"<<cs<<" "<<cs2[cs]<<" >";
//		cout<<endl;
//		sto=1;
//	}
//	else
//		sto=0;

	//if(cs==11263){
	//	cout<<l<<" ?";
	//	for(int i=0;i<l;++i){
	//		cout<<ls[i]<<" ";
	//	}
	//	cout<<endl;
	//}
	if(l==N){
		return true;
	}
	if(cs2[cs])
		return false;

	int s=1;
	for(int i=0;i<N;++i){
		if((cs&(1<<i))==0&&ks[t[i]]>0){
			s=0;
		}
	}
	if(s)
		return false;

	for(int i=0;i<N;++i){
		if((cs&(1<<i))==0&&ks[t[i]]>0){
			ls[l]=i;
			cs|=(1<<i);
			--ks[t[i]];
			for(int j=0;j<kk[i];++j){
				++ks[k[i][j]];
			}
			if(dfs(l+1))
				return true;
			cs^=(1<<i);
			++ks[t[i]];
			for(int j=0;j<kk[i];++j){
				--ks[k[i][j]];
			}
		}
	}

	//if(sto){
	//	cout<<" ?"<<cs<<" "<<cs2[cs]<<endl;
	//}

	cs2[cs]=1;
	return false;
}

int main(){
	int e20=1<<20;
	cs2=new int [e20+1];

	int T;
	cin>>T;
	
	for(int Ti=1;Ti<=T;++Ti){

		for(int i=0;i<e20;++i){
			cs2[i]=0;
		}

		cout<<"Case #"<<Ti<<": ";
		cin>>K>>N;
		for(int i=0;i<=200;++i){
			ks[i]=0;
		}
		int tmp;

		for(int i=0;i<K;++i){
			cin>>tmp;
			++ks[tmp];
		}

		cs=0;
		//for(int i=0;i<N;++i){
		//	cs[i]=0;
		//}

		for(int i=0;i<N;++i){
			cin>>t[i];
			cin>>kk[i];
			for(int j=0;j<kk[i];++j){
				cin>>k[i][j];
			}

		}
		if(dfs(0)){
			for(int i=0;i<N-1;++i){
				cout<<ls[i]+1<<" ";
			}
			cout<<ls[N-1]+1<<"\n";
		}
		else{
			cout<<"IMPOSSIBLE\n";
		}

	}

	return 0;
}
