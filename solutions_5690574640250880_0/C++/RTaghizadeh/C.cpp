#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	int t,te;
	cin>>t;
	int r,c,m,i,j,k,d;
	char b[50][50];
	bool ans;
	for(te=1;te<=t;te++){
		ans=false;
		bool reverse=false;
		cin>>r>>c>>m;
		d=r*c-m;
		if(r>c){
			swap(r,c);
			reverse=true;
		}
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				b[i][j]='*';
		if(r==1){
			ans = true;
			for(i=0;i<d;i++)
				b[0][i]='.';
		}
		else if(r==2){
			if(d==1){
				ans=true;
			}
			else if(d>3 && d%2==0){
				ans = true;
				for(i=0;i<d/2;i++){
					b[0][i]=b[1][i]='.';
				}
			}
			else
			{
				ans=false;
			}
		}
		else{
			if(d==1){
				ans=true;
			}
			else if(d==2 || d==3|| d==5||d==7){
				ans=false;
			}
			else
			{
				ans=true;
				int h=0,w[50];
				for(i=0;i<r;i++)
					w[i]=0;
				if(d<=2*c){
					if(d%2==0)
					{
						h=2;
						w[0]=w[1]=d/2;
					}
					else
					{
						h=3;
						w[0]=w[1]=(d-3)/2;
						w[2]=3;
					}
				}
				else{
					h=d/c;
					for(i=0;i<h;i++)
						w[i]=c;
					if(d>h*c)
					{
						w[h]=d-h*c;
						if(w[h]==1)
						{
							if(h>2){
								w[h]=2;
								w[h-1]=c-1;
							}
							else
							{
								w[h]=3;
								w[h-1]=w[h-2]=c-1;
							}
						}
						h++;
					}
				}
				for(i=0;i<h;i++)
					for(j=0;j<w[i];j++)
						b[i][j]='.';
			}
		}
		b[0][0]='c';
		
		cout<<"Case #"<<te<<":"<<endl;
		if(ans==false){
			cout<<"Impossible"<<endl;
		}
		else if(reverse){
			for(j=0;j<c;j++){
				for(i=0;i<r;i++)
					cout<<b[i][j];
				cout<<endl;
			}
		}
		else{
			for(i=0;i<r;i++){
				for(j=0;j<c;j++)
					cout<<b[i][j];
				cout<<endl;
			}
		}



		
		
	}
	return 0;
}