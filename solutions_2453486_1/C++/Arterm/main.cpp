#include <fstream>

#define M 10

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

char a[M][M];
bool fi;

bool equ(char ch, char a){
	return ch==a || a=='T';
}

void read(void){
	for (int i=0; i<4; ++i)
	for (int j=0; j<4; ++j)
	cin>>a[i][j];
	
	fi=1;
	
	for (int i=0; i<4; ++i)
	for (int j=0; j<4; ++j)
	fi&=(a[i][j]!='.');
}

void kill(void){
	bool winx=0,wino=0,wx,wo;
	for (int i=0; i<4; ++i){
		wx=wo=1;
		for (int j=0; j<4; ++j)
		wx&=equ('X',a[i][j]),wo&=equ('O',a[i][j]);
		winx|=wx;
		wino|=wo;
	}
	
	for (int j=0; j<4; ++j){
		wx=wo=1;
		for (int i=0; i<4; ++i)
		wx&=equ('X',a[i][j]),wo&=equ('O',a[i][j]);
		winx|=wx;
		wino|=wo;
	}
	
	wx=wo=1;
	
	for (int i=0; i<4; ++i)
	wx&=equ('X',a[i][i]),wo&=equ('O',a[i][i]);
	
	winx|=wx;
	wino|=wo;
	
	wx=wo=1;
	
	for (int i=0; i<4; ++i)
	wx&=equ('X',a[i][3-i]),wo&=equ('O',a[i][3-i]);
	
	winx|=wx;
	wino|=wo;
	
	if (winx){
		cout<<"X won\n";
		return;
	}
	
	if (wino){
		cout<<"O won\n";
		return ;
	}
	
	if (fi)
	cout<<"Draw\n";
	else
	cout<<"Game has not completed\n";
	
}

int main()
{
	int t;
	cin>>t;
	for (int i=1; i<=t; ++i){
		read();
		cout<<"Case #"<<i<<": ";
		kill();
	}
	
	return 0;
}

