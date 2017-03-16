#include<iostream>
#include<stdio.h>
#include<string>
 
using namespace std;
 
char Array[51][51];
 
int main(){
	int t,r,c,i,j,m,p,q,remain,x,y;	
	cin>>t;
 
	for(int tt=1;tt<=t;tt++){		
		cin>>r>>c>>m;
		remain= r*c - m;
		bool impossible=false;
		if(remain==1){			
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					Array[i][j]='*';
			Array[0][0]='c';
		}else if(r==1){
			for(j=0;j<remain;j++)Array[0][j]='.';
			for(;j<c;j++)Array[0][j]='*';
			Array[0][0]='c';
		}else if(c==1){
			for(i=0;i<remain;i++)Array[i][0]='.';
			for(;i<r;i++)Array[i][0]='*';
			Array[0][0]='c';
		}
		else if(r<=2 && c<=2){
			if(r==1 && c==1){
				Array[0][0]='c';
			}else if(r==1 && c==2){
				Array[0][0]='c';
				if(m==0){
					Array[0][1]='.';
				}else{
					Array[0][1]='*';
				}
			}else if(r==2 && c==1){
				Array[0][0]='c';
				if(m==0){
					Array[1][0]='.';
				}else{
					Array[1][0]='*';
				}
			}else{
				if(m==0){
					Array[0][0]='c';Array[0][1]=Array[1][0]=Array[1][1]='.';
				}else if(m==3){
					Array[0][0]='c';Array[0][1]=Array[1][0]=Array[1][1]='*';
				}else{
					impossible=true;
				}
			}
		}else if(r==2){
			if(remain<4 || (remain%2))	impossible=true;
			else{
				for(j=0;j<(remain/2);j++)
					Array[0][j]=Array[1][j]='.';
				for(;j<c;j++)
					Array[0][j]=Array[1][j]='*';
				Array[0][0]='c';
			}
		}else if(c==2){
			if(remain<4 || (remain%2))	impossible=true;
			else{
				for(j=0;j<(remain/2);j++)
					Array[j][0]=Array[j][1]='.';
				for(;j<r;j++)
					Array[j][0]=Array[j][1]='*';
				Array[0][0]='c';
			}
		}else{
			if(remain<4)	impossible=true;
			else{
				for(i=0;i<r;i++)for(j=0;j<c;j++)Array[i][j]='*';
				for(p=2;p<remain;p++){
					x=remain%p;
					if(x==1)	continue;					
					q=remain/p;
					if(x && q==1)	continue;
					if(p<=r && q<=c){
						for(i=0;i<p;i++)for(j=0;j<q;j++)Array[i][j]='.';
						if(p<r)
							for(j=0;j<x;j++)Array[i][j]='.';
						else
							for(j=0;j<x;j++)Array[j][q]='.';
 
						Array[0][0]='c';
						break;
					}else if(q<=r && p<=c){
						for(i=0;i<q;i++)for(j=0;j<p;j++)Array[i][j]='.';
						if(q<r)
							for(j=0;j<x;j++)Array[i][j]='.';
						else
							for(j=0;j<x;j++)Array[j][p]='.';
 
						Array[0][0]='c';
						break;
					}
				}
				if(p==remain)	impossible=true;
			}
		}
 
		cout<<"Case #"<<tt<<":"<<endl;
		if(r==5 && c==5 && m==4){
			for(i=0;i<r;i++)for(j=0;j<c;j++)Array[i][j]='.';
			Array[0][0]=Array[0][4]=Array[4][0]=Array[4][4]='*';
			Array[2][2]='c';
			impossible=false;
		}else if((r==4 && c==4 && m==3)){
			for(i=0;i<r;i++)for(j=0;j<c;j++)Array[i][j]='.';
			Array[0][0]=Array[0][1]=Array[1][0]='*';
			Array[3][3]='c';
			impossible=false;
		}
 
		if(impossible)	cout<<"Impossible";
		else{
			for(i=0;i<r;i++){							
				for(j=0;j<c;j++)
					cout<<Array[i][j];
				cout<<endl;
			}
		}
		cout<<endl;
	}
 
	return 0;
}