#include<fstream>
#include<string.h>
using namespace std;

int main(){
	ifstream fin("D-small-attempt1.in");
	ofstream fout("D-small-attempt1.out");

	int t,x,r,c;
	fin>>t;
	bool mark;
	for(int k=1;k<=t;k++){
		mark=false;
		fin>>x>>r>>c;
		if(r>c){
			int tmp=r;
			r=c;
			c=tmp;
		}
		if((r*c)%x==0&&x<7&&x<=c&&x<=2*r){
			if(x<=3)mark=true;
			else if(x==4){
				if(r!=2)mark=true;
			}
			else if(x==5){
				if(r!=3)mark=true;
			}
			else if(x==6){
				if(r!=3)mark=true;
			}
		}
		if(mark)
			fout<<"Case #"<<k<<": GABRIEL"<<endl;
		else
			fout<<"Case #"<<k<<": RICHARD"<<endl;
	}
	return 0;
}