#include <iostream>
#include <fstream>


using namespace std;

char game[20];

int main(){
	ifstream cin("A-large.in");
	ofstream cout("A-large.out");
	int ncase;
	cin>>ncase;
	int  xh,xv,xd1,xd2,oh,ov,od1,od2;
	bool xwin,owin,filled;
	int x,y,index;
	for(int i=1;i<=ncase;i++){
		cout<<"Case #"<<i<<": ";
		xwin=0;owin=0;filled=1;
		xh=0;xv=0;xd1=0;xd2=0;
		oh=0;ov=0;od1=0;od2=0;
		for(int j=0;j<16;j++)cin>>game[j];
		for(int j=0;j<16;j++){
			x=j%4;y=j/4;
			if('X'==game[j]){
				xh++;
				if(x==y) xd1++;
				if(3==x+y) xd2++;
			}
			else if('O'==game[j]){
				oh++;
				if(x==y) od1++;
				if(3==x+y) od2++;
			}
			else if('.'==game[j]){
				filled=0;
			}
			else if('T'==game[j]){
				xh++;
				oh++;
				if(x==y){
					od1++;xd1++;
				}
				if(3==x+y){
					od2++;xd2++;
				}
			}
			if(3==x){
				if(4==xh){
					xwin=1;
					break;
				}
				else if(4==oh){
					owin=1;
					break;
				}
				xh=0;oh=0;
			}
		}
		if(4==od1||4==od2){
			owin=1;
		}
		if(4==xd1||4==xd2){
			xwin=1;
		}
		for(x=0;x<4;x++){
			for(y=0;y<4;y++){
				index = y*4+x;
				if('X'==game[index])xv++;
				if('O'==game[index])ov++;
				if('T'==game[index]){xv++;ov++;};
				if(3==y){
					if(4==xv){
						xwin=1;
						break;
					}
					else if(4==ov){
						owin=1;
						break;
					}
					xv=0;ov=0;
				}
			}
			if( xwin||owin) break;
		}

		if(xwin)cout<<"X won"<<endl;
		else if(owin)cout<<"O won"<<endl;
		else if(1==filled && 0==xwin && 0==owin) cout<<"Draw"<<endl;
		else cout<<"Game has not completed"<<endl; 
	}
	return 0;
}