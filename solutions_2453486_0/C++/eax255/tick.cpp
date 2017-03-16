#include <fstream>
#include <iostream>
#include <stdint.h>
using namespace std;
uint16_t chk[10]={
	0x8888,//horisontal 0
	0x4444,//horisontal 1
	0x2222,//horisontal 2
	0x1111,//horisontal 3
	0x000f,//vertical 0
	0x00f0,//vertical 1
	0x0f00,//vertical 2
	0xf000,//vertical 3
	0x8421,//diagonal 0
	0x1248//diagonal 1
};
char message[4][30]={
	": Game has not completed\n",
	": X won\n",
	": O won\n",
	": Draw\n"
};
int bcnt(uint16_t a){
	int r=0;
	while(a){
		r+=a&1;
		a>>=1;
	}
	return r;
}
int tick(istream& in,ostream& out){
	int n;
	in>>n;
	for(int i=1;i<=n;i++){
		uint16_t X=0;
		uint16_t O=0;
		uint16_t B=0;
		for(int x=0;x<4;x++){
			string v;
			in>>v;
			for(int y=0;y<4;y++){
				if(v[y]=='X') X|=1<<(y+x*4);
				else if(v[y]=='O') O|=1<<(y+x*4);
				else if(v[y]=='T') B|=1<<(y+x*4);
			}
		}
		X|=B;
		O|=B;
		B=X|O;
		int st=0;
		if(B==0xffff) st=3;
		for(int j=0;j<10;j++){
			uint16_t x=X&chk[j];
			uint16_t o=O&chk[j];
			if(bcnt(x)==4){st=1;break;}
			if(bcnt(o)==4){st=2;break;}
		}
		out<<"Case #"<<i<<message[st];
	}
	return 0;
}
int main(){
	ifstream fin("tick.in");
	ofstream fout;
	if(fin.is_open()){
		fout.open("tick.out");
		return tick(fin,fout);
	}
	return tick(cin,cout);
}

