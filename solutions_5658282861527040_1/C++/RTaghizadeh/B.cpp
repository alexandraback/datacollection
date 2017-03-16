#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	long long int t,te;
	long long int i,j,l,pp;
	long long int a,b,k;
	long long int x[3],y[3];
	char c[3][33][33];
	cin>>t;

	for(te=1;te<=t;te++){
		cin>>x[0]>>x[1]>>x[2];
		int n[3][32];
		for(i=0;i<3;i++)
		{
			x[i]--;
			for(j=0;j<32;j++){
				n[i][j]=x[i]%2;
				x[i]=x[i]/2;
			}
		}
		char ch00[2]="0",ch11[2]="1",chxx[2]="x";
		for(i=0;i<3;i++)
		{

			char ch[33];
			ch[0]='\0';
			y[i]=0;
			for(j=31;j>=0;j--){
				if(n[i][j]==0)
				{
					strcat(ch,ch00);
				}
				else{
					char ch2[33];
					strcpy(ch2,ch);
					strcat(ch2,ch00);
					while(strlen(ch2)<32)
						strcat(ch2,chxx);
					y[i]++;
					strcpy(c[i][y[i]-1],ch2);
					strcat(ch,ch11);

				}
			}
			y[i]++;
			strcpy(c[i][y[i]-1],ch);


		}
		long long int ans=0;
		for(i=0;i<y[0];i++){
			for(j=0;j<y[1];j++){
				for(k=0;k<y[2];k++){
					long long int an=1;
					for(l=0;l<32 && an>0;l++)
					{
						if(c[0][i][l]=='0'){
							if(c[1][j][l]=='0'){
								if(c[2][k][l]=='0'){
								}
								else if(c[2][k][l]=='1'){
									an=0;
								}
								else
								{
								}
							}
							else if(c[1][j][l]=='1'){
								if(c[2][k][l]=='0'){
								}
								else if(c[2][k][l]=='1'){
									an=0;
								}
								else
								{
								}
							}
							else
							{
								if(c[2][k][l]=='0'){
									an*=2;
								}
								else if(c[2][k][l]=='1'){
									an=0;
								}
								else
								{
									an*=2;
								}
							}
						}
						else if(c[0][i][l]=='1'){
							if(c[1][j][l]=='0'){
								if(c[2][k][l]=='0'){
								}
								else if(c[2][k][l]=='1'){
									an=0;
								}
								else
								{
								}
							}
							else if(c[1][j][l]=='1'){
								if(c[2][k][l]=='0'){
									an=0;
								}
								else if(c[2][k][l]=='1'){
								}
								else
								{
								}
							}
							else
							{
								if(c[2][k][l]=='0'){
								}
								else if(c[2][k][l]=='1'){
								}
								else
								{
									an*=2;
								}
							}
						}
						else
						{
							if(c[1][j][l]=='0'){
								if(c[2][k][l]=='0'){
									an*=2;
								}
								else if(c[2][k][l]=='1'){
									an=0;
								}
								else
								{
									an*=2;
								}
							}
							else if(c[1][j][l]=='1'){
								if(c[2][k][l]=='0'){
								}
								else if(c[2][k][l]=='1'){
								}
								else
								{
									an*=2;
								}
							}
							else
							{
								if(c[2][k][l]=='0'){
									an*=3;
								}
								else if(c[2][k][l]=='1'){
								}
								else
								{
									an*=4;
								}
							}
						}
					}
					ans+=an;


				}
			}
		}




		cout<<"Case #"<<te<<": "<<ans<<endl;

	}
	return 0;
}