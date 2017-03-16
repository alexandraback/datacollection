#include <cstdio>
#include <iostream>
using namespace std;
int t,i,j,x,y,z,o;
char s[4][4];
bool X,O,E;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>t;
	while(t--){
		o++;
		X=O=E=false;
		for(i=0;i<4;i++)cin>>s[i];
		for(i=0;i<4;i++){
			x=y=z=0;
			for(j=0;j<4;j++)
				if(s[i][j]=='X')x++;
				else
				if(s[i][j]=='O')y++;
				else
				if(s[i][j]=='T')z++;
			if(x>=3&&x+z==4)X=true;
			if(y>=3&&y+z==4)O=true;
			if(x+y+z<4)E=true;
		}
		for(j=0;j<4;j++){
			x=y=z=0;
			for(i=0;i<4;i++)
				if(s[i][j]=='X')x++;
				else
				if(s[i][j]=='O')y++;
				else
				if(s[i][j]=='T')z++;
			if(x>=3&&x+z==4)X=true;
			if(y>=3&&y+z==4)O=true;
		}
		x=y=z=0;
		for (i=0;i<4;i++)
			if(s[i][i]=='X')x++;
			else
			if(s[i][i]=='O')y++;
			else
			if(s[i][i]=='T')z++;
		if(x>=3&&x+z==4)X=true;
		if(y>=3&&y+z==4)O=true;
		x=y=z=0;
		for (i=0;i<4;i++)
			if(s[i][3-i]=='X')x++;
			else
			if(s[i][3-i]=='O')y++;
			else
			if(s[i][3-i]=='T')z++;
		if(x>=3&&x+z==4)X=true;
		if(y>=3&&y+z==4)O=true;
		cout<<"Case #"<<o<<": ";
		if(X)cout<<"X won";
		else
		if(O)cout<<"O won";
		else
		if(E)cout<<"Game has not completed";
		else
		cout<<"Draw";
		cout<<endl;
	}
	return 0;
}
