#include <iostream>
using namespace std;

int main()
{
int T,i,j,ao[4][4],ax[4][4],count=16,Case=1;
char a[4][4];

cin>>T;
while(T--){
count=16;
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		cin>>a[i][j];
		if(a[i][j]=='.'){
			ao[i][j]=ax[i][j]=0;
                        count--;
		} else if(a[i][j]=='T')
			ao[i][j]=ax[i][j]=1;
		else if(a[i][j]=='X'){
			ax[i][j]=1;
			ao[i][j]=0;
		}
		else{
			ao[i][j]=1;
			ax[i][j]=0;
		}
	}
}
int frx=0,fro=0;
//check row
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		fro += ao[i][j];
		frx += ax[i][j];
	}
//cout<<fro<<" "<<frx<<endl;
	if(fro==4)
		break;
	else if(frx==4)
		break;
	else
		fro=frx=0;
}
//cout<<"end row "<<fro<<" "<<frx<<endl;

int fcx=0,fco=0;
//check column
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		fco += ao[j][i];
		fcx += ax[j][i];
	}
//cout<<fco<<" "<<fcx<<endl;
	if(fco==4)
		break;
	else if(fcx==4)
		break;
	else
		fco=fcx=0;
}
//cout<<"end column "<<fco<<" "<<fcx<<endl;
int fx1=0,fx2=0,fo1=0,fo2=0;

for(i=0;i<4;i++){
	fx1 += ax[i][i];
	fo1 += ao[i][i];
}
for(i=0;i<4;i++){
	fx2 += ax[i][3-i];
	fo2 += ao[i][3-i];
}

//cout<<"o flags "<<fo1<<" "<<fo2<<" "<<fro<<" "<<fco<<endl;
cout<<"Case #"<<Case++<<": ";
if(fx1==4 || fx2==4 || frx==4 || fcx==4){
	cout<<"X won\n";
}
else if(fo1==4 || fo2==4 || fro==4 || fco==4){
	cout<<"O won\n";
}else if(count==16){
	cout<<"Draw\n";
}else
	cout<<"Game has not completed\n";
}//end while loop
return 0;
}
