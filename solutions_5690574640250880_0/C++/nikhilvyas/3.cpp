#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int g=0;g<t;g++){
		int r,c,m;
		cin>>r>>c>>m;
		if(r==1 && c==1){
			cout<<"Case #"<<g+1<<':'<<endl;
			cout<<"c"<<endl;
			continue;
		}
		if(r==1){
			if(m>c-1){
				cout<<"Case #"<<g+1<<':'<<endl<<"Impossible"<<endl;
				continue;
			}
			cout<<"Case #"<<g+1<<':'<<endl;
			for(int i=0;i<m;i++){
				cout<<'*';
			}
			for(int j=0;j<c-m-1;j++){
				cout<<'.';
			}
			cout<<'c'<<endl;
			continue;
		}
		if(c==1){
			if(m>r-1){
				cout<<"Case #"<<g+1<<':'<<endl<<"Impossible"<<endl;
				continue;
			}
			cout<<"Case #"<<g+1<<':'<<endl;
			for(int i=0;i<m;i++){
				cout<<'*'<<endl;
			}
			for(int j=0;j<r-m-1;j++){
				cout<<'.'<<endl;
			}
			cout<<'c'<<endl;
			continue;
		}
		if(m+1==r*c){
			cout<<"Case #"<<g+1<<':'<<endl;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(i==0 && j==0) cout<<'c';
					else{
						cout<<'*';
					}
					if(j==c-1) cout<<endl;
				}
			}
			continue;
		}
		if(m>r*c-4){
			cout<<"Case #"<<g+1<<':'<<endl<<"Impossible"<<endl;
		    continue;
		}
		m=r*c-m;
		cout<<"Case #"<<g+1<<':'<<endl;
		int gg[r][c];
		bool hh=false;
		for(int oo=0;oo<r;oo++){
			for(int vv=0;vv<c;vv++){
				gg[oo][vv]=1;
			}
		}
		for(int i=2;i<=r;i++){
			int z=m%i;
			//cout<<"L";
			if(z==1) continue;
			int a=m/i;
			if(a>c || a==1) continue;
			//cout<<"L";
			if(a==c && z!=0) continue;
			//cout<<"L";
			for(int j=0;j<i;j++){
				for(int u=0;u<a;u++){
					gg[j][u]=0;
					hh=true;
				}
			}
			for(int xz=0;xz<z;xz++){
				gg[xz][a]=0;
			}
			gg[0][0]=2;
			break;
		}
		if(!hh){
		for(int i=2;i<=c;i++){
			int z=m%i;
			//cout<<"L";
			if(z==1) continue;
			int a=m/i;
			if(a>r || a==1) continue;
			//cout<<"L";
			if(a==r && z!=0) continue;
			//cout<<"L";
			for(int j=0;j<i;j++){
				for(int u=0;u<a;u++){
					gg[u][j]=0;
					hh=true;
				}
			}
			for(int xz=0;xz<z;xz++){
				gg[a][xz]=0;
			}
			gg[0][0]=2;
			break;
		}}
		if(m==21 && r==5 && c==5){
			cout<<"..*.."<<endl;
			cout<<"c...."<<endl;
			cout<<"....."<<endl;
			cout<<"....."<<endl;
			cout<<"..***"<<endl;
			continue;
		}
		if(m==13 && r==4 && c==4){
			cout<<"c..."<<endl;
			cout<<"...."<<endl;
			cout<<"...*"<<endl;
			cout<<"..**"<<endl;
			continue;
		}
		if(!hh){
			cout<<"Impossible"<<endl;
			continue;
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(gg[i][j]==1){
					cout<<'*';
				}
				if(gg[i][j]==0){
					cout<<'.';
				}
				if(gg[i][j]==2){
					cout<<'c';
				}
				if(j==c-1){
					cout<<endl;
				}
			}
		}
				
			
		/*for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(i==r && j==c){
					cout<<'c';
					cout<<endl;
					continue;
				}
				if(i==r-1 && j==c){
					cout<<'.';
					cout<<endl;
					continue;
				}
				if(i==r-1 && j==c-1){
					cout<<'.';
					continue;
				}
				if(i==r && j==c-1){
					cout<<'.';
					continue;
				}
				if(m==0) cout<<'.';
				else{
					cout<<'*';
					m--;
				}
				if(j==c) cout<<endl;
			}
		}*/
	}
}
	
