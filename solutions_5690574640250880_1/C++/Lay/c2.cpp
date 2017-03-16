#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>

using namespace std;

//#define _DEBUG 1

int main()
{
	int T,possible=0;
	cin>>T;

	for(int i=1;i<=T;i++){
		int r,c,m,r0,c0,m0;
		char b[100][100];

		cin>>r>>c>>m;
		r0=r,c0=c,m0=m;


#ifdef _DEBUG
//		if(r<=2 || c<=2) continue;
		cout<<endl<<"r= "<<r<<" c="<<c<<" m="<<m<<endl;
#endif
//		if(r>2 && c>2) continue;

		if(r*c-m==1){
//continue;
			printf("Case #%d:\n",i);
			for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){
					if(x==0 && y==0) printf("c");
					else printf("*");
				}
				cout<<endl;
			}
			continue;
		}

		if(r==1){
//continue;
			printf("Case #%d:\n",i);
			printf("c");
			for(int j=0;j<c-m-1;j++) printf(".");
			for(int j=0;j<m;j++) printf("*");
			cout<<endl;

			continue;
		}
		if(c==1){
//continue;
			printf("Case #%d:\n",i);
			printf("c\n");
			for(int j=0;j<r-m-1;j++) printf(".\n");
			for(int j=0;j<m;j++) printf("*\n");
			continue;
		}
		if(r==2){
//continue;
			printf("Case #%d:\n",i);
			if(m%2==1 || r*c-4<m) cout<<"Impossible"<<endl;
			else{
				printf("c");
				for(int j=0;j<c-m/2-1;j++) printf(".");
				for(int j=0;j<m/2;j++) printf("*");
				cout<<endl;

				for(int j=0;j<c-m/2;j++) printf(".");
				for(int j=0;j<m/2;j++) printf("*");
				cout<<endl;
			}

			continue;
		}
		if(c==2){
//continue;
			printf("Case #%d:\n",i);
			if(m%2==1 || r*c-4<m) cout<<"Impossible"<<endl;
			else{
				printf("c.\n");
				for(int j=0;j<r-m/2-1;j++) printf("..\n");
				for(int j=0;j<m/2;j++) printf("**\n");
			}

			continue;
		}

//		if(m>(r-2)*(c-2) && (m-(r-2)*(c-2))%2==1){cout<<"Impossible?"<<endl;}

		if((r-2)*(c-2)>m){
			printf("Case #%d:\n",i);
			for(int y=r-1;y>=0;y--){
				for(int x=c-1;x>=0;x--){
					if(m!=0 && y>1 && x>1){b[y][x]='*'; m--;}
					else b[y][x]='.';
				}
			}
			b[0][0]='c';

			int num=0;
			for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){if(b[y][x]=='*'){num++;} printf("%c",b[y][x]);}
				cout<<endl;
			}
//			if(num==m0) cout<<"OK"<<endl;

			continue;
		}

		if((r-2)*(c-2)<=m && r*c-4>=m && (m-(r-2)*(c-2))%2==0){
			printf("Case #%d:\n",i);

			int rest=m-(r-2)*(c-2);
			for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){
					if(y<=1 || x<=1) b[y][x]='.';
					else b[y][x]='*';
				}
			}
			b[0][0]='c';

			for(int y=r-1;y>1 && rest!=0;y--) {b[y][0]=b[y][1]='*'; rest-=2;}
			for(int x=c-1;x>1 && rest!=0;x--) {b[0][x]=b[1][x]='*'; rest-=2;}

			int num=0;
			for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){if(b[y][x]=='*'){num++;} printf("%c",b[y][x]);}
				cout<<endl;
			}
//			if(num==m0) cout<<"OK"<<endl;

			continue;
		}


		printf("Case #%d:\n",i);

		for(int j=0;j<r;j++){
			for(int k=0;k<c;k++){
				b[j][k]='.';
			}
		}

		b[0][0]='c';

		bool finish=false;

		for(int j=0;m-r*j>=0 && j<=c-2 && !finish;j++){

			for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){
					b[y][x]='.';
				}
			}
			b[0][0]='c';

			int tmp=m-r*j;
			if(tmp/(c-j)<=(r-2)){
				for(int k=0;k<j;k++){
					for(int y=0;y<r;y++){m--; b[y][c-1-k]='*';}
				}
				for(int k=0;k<tmp/(c-j);k++){
					for(int x=0;x<c-j;x++){m--; b[r-1-k][x]='*';}
				}

				if(m==0){
					int num=0;
					for(int y=0;y<r0;y++){
						for(int x=0;x<c0;x++){if(b[y][x]=='*'){num++;} printf("%c",b[y][x]);}
						cout<<endl;
					}
//					if(num==m0) cout<<"OK"<<endl;
					finish=true;
				}
			}
#ifdef _DEBUG
				cout<<"j="<<j<<endl;
				for(int y=0;y<r0;y++){
					for(int x=0;x<c0;x++) printf("%c",b[y][x]);
					cout<<endl;
				}
#endif

			tmp/=(c-j);
			c-=j; r-=tmp;
			if((r-2)*(c-2)>m && !finish){
				for(int y=r-1;y>=0;y--){
					for(int x=c-1;x>=0;x--){
						if(m!=0 && y>1 && x>1){b[y][x]='*'; m--;}
						else b[y][x]='.';
					}
				}
				b[0][0]='c';


					int num=0;
					for(int y=0;y<r0;y++){
						for(int x=0;x<c0;x++){if(b[y][x]=='*'){num++;} printf("%c",b[y][x]);}
						cout<<endl;
					}
//					if(num==m0) cout<<"OK"<<endl;

				finish=true;
			}

			if((r-2)*(c-2)<=m && r*c-4>=m && (m-(r-2)*(c-2))%2==0 && !finish){

				int rest=m-(r-2)*(c-2);
				for(int y=0;y<r;y++){
					for(int x=0;x<c;x++){
						if(y<=1 || x<=1) b[y][x]='.';
						else b[y][x]='*';
					}
				}
				b[0][0]='c';

				for(int y=r-1;y>1 && rest!=0;y--) {b[y][0]=b[y][1]='*'; rest-=2;}
				for(int x=c-1;x>1 && rest!=0;x--) {b[0][x]=b[1][x]='*'; rest-=2;}

				for(int y=0;y<r0;y++){
					for(int x=0;x<c0;x++) printf("%c",b[y][x]);
					cout<<endl;
				}
					int num=0;
					for(int y=0;y<r0;y++){
						for(int x=0;x<c0;x++){if(b[y][x]=='*'){num++;} printf("%c",b[y][x]);}
						cout<<endl;
					}
//					if(num==m0) cout<<"OK"<<endl;

				finish=true;
			}
			r=r0; c=c0; m=m0;

		}


		for(int j=0;m-c*j>=0 && j<=r-2 && !finish;j++){
			for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){
					b[y][x]='.';
				}
			}

			b[0][0]='c';

			int tmp=m-c*j;
			if(tmp/(r-j)<=(c-2)){
				for(int k=0;k<j;k++){
					for(int x=0;x<c;x++){m--; b[r-1-k][x]='*';}
				}
				for(int k=0;k<tmp/(r-j);k++){
					for(int y=0;y<r-j;y++){m--; b[y][c-1-k]='*';}
				}
			}
			if(m==0){
				for(int y=0;y<r0;y++){
					for(int x=0;x<c0;x++) printf("%c",b[y][x]);
					cout<<endl;
				}
					int num=0;
					for(int y=0;y<r0;y++){
						for(int x=0;x<c0;x++){if(b[y][x]=='*'){num++;} printf("%c",b[y][x]);}
						cout<<endl;
					}
//					if(num==m0) cout<<"OK"<<endl;

				finish=true;
			}
			tmp/=(r-j);
			r-=j; c-=tmp;
			if((r-2)*(c-2)>m && !finish){
				for(int y=r-1;y>=0;y--){
					for(int x=c-1;x>=0;x--){
						if(m!=0 && y>1 && x>1){b[y][x]='*'; m--;}
						else b[y][x]='.';
					}
				}
				b[0][0]='c';


				for(int y=0;y<r0;y++){
					for(int x=0;x<c0;x++) printf("%c",b[y][x]);
					cout<<endl;
				}
					int num=0;
					for(int y=0;y<r0;y++){
						for(int x=0;x<c0;x++){if(b[y][x]=='*'){num++;} printf("%c",b[y][x]);}
						cout<<endl;
					}
//					if(num==m0) cout<<"OK"<<endl;

				finish=true;
			}

			if((r-2)*(c-2)<=m && r*c-4>=m && (m-(r-2)*(c-2))%2==0 && !finish){

				int rest=m-(r-2)*(c-2);
				for(int y=0;y<r;y++){
					for(int x=0;x<c;x++){
						if(y<=1 || x<=1) b[y][x]='.';
						else b[y][x]='*';
					}
				}
				b[0][0]='c';

				for(int y=r-1;y>1 && rest!=0;y--) {b[y][0]=b[y][1]='*'; rest-=2;}
				for(int x=c-1;x>1 && rest!=0;x--) {b[0][x]=b[1][x]='*'; rest-=2;}

				for(int y=0;y<r0;y++){
					for(int x=0;x<c0;x++) printf("%c",b[y][x]);
					cout<<endl;
				}
					int num=0;
					for(int y=0;y<r0;y++){
						for(int x=0;x<c0;x++){if(b[y][x]=='*'){num++;} printf("%c",b[y][x]);}
						cout<<endl;
					}
//					if(num==m0) cout<<"OK"<<endl;

				finish=true;
			}
			r=r0; c=c0; m=m0;

		}

		if(!finish) cout<<"Impossible"<<endl;
	}
	return 0;
}
