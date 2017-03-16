#include <iostream>
using namespace std;


int main()
{
	int t,q=0;
	cin>>t;
	while(t--){
		q++;
		int n=4;
		char a[4][4];
		int vo[4];
		int ho[4];
		int vx[4];
		int hx[4];
		int x=5,y=10;
		int dx[2];
		int d[2];
		
		dx[0]=0;d[0]=0;dx[1]=0;d[1]=0;
		for(int i=0;i<4;i++){
			vo[i]=0;
			ho[i]=0;
			vx[i]=0;
			hx[i]=0;
		}
		
		int flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				if(a[i][j]=='O'){
					ho[i]++;
					vo[j]++;
				}
				else if(a[i][j]=='X'){
					hx[i]++;
					vx[j]++;
				}	
				else if(a[i][j]=='.')
					flag=1;
				else if(a[i][j]=='T')
					{x=i;y=j;}
				if(i+j==3){
					if(a[i][j]=='O'){
						d[1]++;
					}
					if(a[i][j]=='X')
						dx[1]++;
				}
				if(i==j){
					if(a[i][j]=='O'){
						d[0]++;
					}
					if(a[i][j]=='X')
						dx[0]++;
				}
			}
		}
		if(d[0]==4 || d[1]==4 || (d[0]==3 && x==y) || (d[1]==3 && x+y==3)){
			cout<<"Case #"<<q<<": "<<"O won"<<endl;
			continue;
		}
		if(dx[0]==4 || dx[1]==4 || (dx[0]==3 && x==y) || (dx[1]==3 && x+y==3)){
			cout<<"Case #"<<q<<": "<<"X won"<<endl;
			continue;
		}
		int f=0;
		for(int i=0;i<n;i++){
			if(ho[i]==4 || vo[i]==4 ||(ho[i]==3 && x==i) || (vo[i]==3 && y==i)){
				cout<<"Case #"<<q<<": "<<"O won"<<endl;
				f=1;
				break;
				
			} 
			if(hx[i]==4 || vx[i]==4 ||(hx[i]==3 && x==i) || (vx[i]==3 && y==i)){
				cout<<"Case #"<<q<<": "<<"X won"<<endl;
				f=1;
				break;
			} 
		}
		if(f==0 && flag==0){
			cout<<"Case #"<<q<<": "<<"Draw"<<endl;
		}
		else if(f==0 && flag==1)
			cout<<"Case #"<<q<<": "<<"Game has not completed"<<endl;
	}
	return 0;
}
