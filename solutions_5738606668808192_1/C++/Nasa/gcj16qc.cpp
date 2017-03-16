#include <iostream>
using namespace std;

#define MAXD (1<<26)
#define MAXTRY 100
#define MAXSEARCH 32
#define MAXMATCH 500

typedef long long Long;

Long x[MAXSEARCH+1][MAXMATCH+1];
int c[MAXSEARCH+1],v[MAXSEARCH+1][MAXMATCH+1][11];//,divisor[MAXD];

/*int findDiv(Long x){
	if (x<MAXD && divisor[x]>0) return divisor[x];
	int d=0;
	if (x%2==0) d=2;
	for (Long i=3; i*i<=x && i<MAXTRY; i+=2){
		if (x%i==0){ 
			d=i;
			break;
		}
	}
	if (x<MAXD) divisor[x]=d;
	return d;
}*/

Long atBase(Long i, int b, int &d){
	Long i2=0, m=1;
	for (d=0; i; i/=2, m*=b, d++) i2+=(i&1)*m;
	return i2;
}

int modAtBase(Long i, int b, int k){
	Long i2=0, m=1;
	for (; i; i/=2, m=(m*b)%k) i2=(i2+(i&1)*m)%k;
	return (int)i2;
}

int findDivAtBase(Long x, int b){
	int d=0;
	//x=atBase(x,b,d);
	//d=0;
	//return d=findDiv(x);
	if (modAtBase(x,b,2)==0) d=2;
	for (int i=3; i<MAXTRY; i+=2) if (modAtBase(x,b,i)==0){ d=i; break;}
	return d;
}

void printbin(Long n){
	int v[100],c=0;
	while(n){ v[c++]=(n&1); n/=2;}
	for(c--; c>=0; c--) cout<<v[c];
}

void gen(){
	int b,dd,div;
	for (Long i=3; i<(1LL<<MAXSEARCH); i+=2){
		atBase(i,2,dd);
		for (b=2; b<=10; b++){
			if ((div=findDivAtBase(i,b))==0) break;
			v[dd][c[dd]][b]=div;
		}
		if (b>10){
			x[dd][c[dd]++]=i;
			/*cout<<dd<<"("<<c[dd]<<")"<<" ";
			printbin(i); for (int b=2; b<=10; b++) cout<<" "<<v[dd][c[dd]-1][b];
			cout<<endl;
			*/
			if (c[dd]>=MAXMATCH) i=(1LL<<(dd))+1;
		}
	}
	//for (int i=0; i<MAXSEARCH; i++) cout<<i<<":"<<c[i]<<endl;
}

int main(){
	int n,q,t,u;
	gen();
	cin>>t;
	for (u=0; u<t; u++){
		cin>>n>>q;
		cout<<"Case #"<<(u+1)<<":"<<endl;
		while(q){
			q--;
			printbin(x[n][q]);
			for (int b=2; b<=10; b++) cout<<" "<<v[n][q][b];
			cout<<endl;
		}
	}
	return 0;
}
