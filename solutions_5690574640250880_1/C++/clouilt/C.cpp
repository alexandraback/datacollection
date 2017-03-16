#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("I:\\C-large.in","r",stdin);
	freopen("I:\\C-large.out","w",stdout);
	int T;
	cin>>T;
	char map[53][53];
	int R,C,M;
	int M0;
	for(int cs=1;cs<=T;++cs){
		cout<<"Case #"<<cs<<':'<<endl;
		cin>>R>>C>>M;

		for(int i=0;i<R;++i)
			map[i][C]=0;
		M0=R*C-M;

		//cout<<R<<' '<<C<<' '<<M<<' '<<M0<<endl;
		for(int i=0;i<R;++i)
			for(int j=0;j<C;++j)
				map[i][j]='*';

		if(R==1||C==1){
			if(R==1)
				for(int i=0;i<M0;++i)
					map[0][i]='.';
			else
				for(int i=0;i<M0;++i)
					map[i][0]='.';
			map[0][0]='c';

		}else if((R==2||C==2)&&M0%2==1&&M0!=1){
			cout<<"Impossible"<<endl;
			goto nxt;
		}else{

			switch(M0){
				case 2:
				case 3:
				case 5:
				case 7:
					cout<<"Impossible"<<endl;
					goto nxt;
				default:


					map[0][0]='c';
					if(M0==1)
						break;

					map[0][1]=map[1][0]=map[1][1]='.';
					M0-=4;
					if( (M0/2 <= (R-2)+(C-2)) ){
						if(M0%2==1)
							map[2][2]='.';
						M0/=2;
						if(R>2&&M0){
							map[2][0]=map[2][1]='.';
							--M0;
						}
						for(int i=2;i<C&&M0;++i,--M0)
							map[0][i]=map[1][i]='.';
						for(int i=3;i<R&&M0;++i,--M0)
							map[i][0]=map[i][1]='.';
					}else{
						for(int i=2;i<C;++i)
							map[0][i]=map[1][i]='.';
						for(int i=2;i<R;++i)
							map[i][0]=map[i][1]='.';

						M0-=(R-2+C-2)*2;
						for(int i=2;i<R;++i)
							for(int j=2;j<C;++j){
								if(M0==0)
									goto dis;
								map[i][j]='.';
								--M0;
							}
					}
			}
		}
		dis:
		for(int i=0;i<R;++i)
			cout<<map[i]<<endl;
		nxt:;
	}
	return 0;
}
