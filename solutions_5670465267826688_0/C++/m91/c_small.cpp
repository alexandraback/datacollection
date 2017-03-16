#include<vector>
#include <utility>
#include<iostream>
#include <algorithm>
#include<cmath>

int X,L;
int trasf[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int sign[4][4]={{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};

int mult(int a,int b){//-4,-1;-,4
int iA=abs(a)-1,iB=abs(b)-1;
int sA=a>0?1:-1,sB=b>0?1:-1;

int s=sA*sB*sign[iA][iB];
return s*(trasf[iA][iB]+1);
}


using namespace std;
int quat[10100];
char s[10100];

int getInd(long pos){
	return pos%L;
}



int main(){
int T,i,j;

cin>>T;

for(i=0;i<T;i++){
	
	cin>>L>>X;
	long max=L*X;
	cin>>s;
	
	for(j=0;j<L;j++)quat[j]=(s[j]-'i'+2);
	long sup1=0;
	int t1=1;
	int esci=0;
	
	for(sup1=0;sup1<max && t1!=2;sup1++){
		t1=mult(t1,quat[getInd(sup1)]);
		//cout<<t1<<endl;	
		if(t1==2)break;
	}
	if(t1!=2)esci=1;
	
	long inf3,t3=1;
	for(inf3=max-1;inf3>sup1 && t3!=4 && esci==0;inf3--){
		t3=mult(quat[getInd(inf3)],t3);
		//cout<<"3^ "<<t3<<endl;
		if(t3==4)break;
	}
	if(t3!=4)esci=1;

	long inf2,t2=1;
	for(inf2=sup1+1;inf2<inf3 && esci==0;inf2++){
		t2=mult(t2,quat[getInd(inf2)]);
		//cout<<"2^ "<<t3<<endl;
	}
	if(t2!=3)esci=1;

	cout<<"Case #"<<(i+1)<<": ";
	cout<<((esci==1)?"NO":"YES")<<endl;
	//cout<<t1<<" "<<t2<<" "<<t3<<endl;
	}






return 0;
}
