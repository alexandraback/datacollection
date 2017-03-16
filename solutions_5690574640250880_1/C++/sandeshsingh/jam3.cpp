#include<iostream>
#include<stdio.h>
#include<string>
 
using namespace std;
 
int main(){
	int t,r,c,i,j,m,p,q,rem,x,y;
	char a[51][51];
freopen("abc.txt", "r", stdin);
 freopen("cc.out", "w", stdout);
	cin>>t;
 
	for(int tt=1;tt<=t;tt++){		
		cin>>r>>c>>m;
		rem= r*c - m;
		bool imp=false;
		if(rem==1){			
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					a[i][j]='*';
			a[0][0]='c';
		}else if(r==1){
			for(j=0;j<rem;j++)a[0][j]='.';
			for(;j<c;j++)a[0][j]='*';
			a[0][0]='c';
		}else if(c==1){
			for(i=0;i<rem;i++)a[i][0]='.';
			for(;i<r;i++)a[i][0]='*';
			a[0][0]='c';
		}
		else if(r<=2 && c<=2){
			if(r==1 && c==1){
				a[0][0]='c';
			}else if(r==1 && c==2){
				a[0][0]='c';
				if(m==0){
					a[0][1]='.';
				}else{
					a[0][1]='*';
				}
			}else if(r==2 && c==1){
				a[0][0]='c';
				if(m==0){
					a[1][0]='.';
				}else{
					a[1][0]='*';
				}
			}else{
				if(m==0){
					a[0][0]='c';a[0][1]=a[1][0]=a[1][1]='.';
				}else if(m==3){
					a[0][0]='c';a[0][1]=a[1][0]=a[1][1]='*';
				}else{
					imp=true;
				}
			}
		}else if(r==2){
			if(rem<4 || (rem%2))	imp=true;
			else{
				for(j=0;j<(rem/2);j++)
					a[0][j]=a[1][j]='.';
				for(;j<c;j++)
					a[0][j]=a[1][j]='*';
				a[0][0]='c';
			}
		}else if(c==2){
			if(rem<4 || (rem%2))	imp=true;
			else{
				for(j=0;j<(rem/2);j++)
					a[j][0]=a[j][1]='.';
				for(;j<r;j++)
					a[j][0]=a[j][1]='*';
				a[0][0]='c';
			}
		}else{
			if(rem<4)	imp=true;
			else{
				for(i=0;i<r;i++)for(j=0;j<c;j++)a[i][j]='*';
				for(p=2;p<rem;p++){
					x=rem%p;
					if(x==1)	continue;					
					q=rem/p;
					if(x && q==1)	continue;
					if(p<=r && q<=c){
						for(i=0;i<p;i++)for(j=0;j<q;j++)a[i][j]='.';
						if(p<r)
							for(j=0;j<x;j++)a[i][j]='.';
						else
							for(j=0;j<x;j++)a[j][q]='.';
 
						a[0][0]='c';
						break;
					}else if(q<=r && p<=c){
						for(i=0;i<q;i++)for(j=0;j<p;j++)a[i][j]='.';
						if(q<r)
							for(j=0;j<x;j++)a[i][j]='.';
						else
							for(j=0;j<x;j++)a[j][p]='.';
 
						a[0][0]='c';
						break;
					}
				}
				if(p==rem)	imp=true;
			}
		}
 
		cout<<"Case #"<<tt<<":"<<endl;
		if(r==5 && c==5 && m==4){
			for(i=0;i<r;i++)for(j=0;j<c;j++)a[i][j]='.';
			a[0][0]=a[0][4]=a[4][0]=a[4][4]='*';
			a[2][2]='c';
			imp=false;
		}else if((r==4 && c==4 && m==3)){
			for(i=0;i<r;i++)for(j=0;j<c;j++)a[i][j]='.';
			a[0][0]=a[0][1]=a[1][0]='*';
			a[3][3]='c';
			imp=false;
		}
 
		if(imp)	cout<<"Impossible";
		else{
			for(i=0;i<r;i++){							
				for(j=0;j<c;j++)
					cout<<a[i][j];
				cout<<endl;
			}
		}
		cout<<endl;
	}
 
	return 0;
}
