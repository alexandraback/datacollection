#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


long A,B,K;
/*
long long search(long prA, long prB, long prK, int pos)
{
	if(pos==0)return 1;
	char da=(A & (1<<pos) >0);
	char db=(B & (1<<pos) >0);
	char dk=(K & (1<<pos) >0);
	if((da&db&dk)==0)
	return search(prA,prB,prK,pos-1);
	
	long long cura=0;
	//if((prA | (1<<pos)) < A)
		//cura+=search(prA | (1<<pos), prB, pos-1);
	//if((prB | (1<<pos)) < B)
		//cura+=search(prA, prB | (1<<pos),  pos-1);
}*/

int main()
{
int T,ti;
cin>>T;
for(ti=0;ti<T;ti++)
{
	long long ans=0;
	cin>>A>>B>>K;
	
	int i,j,k;
	for(i=0;i<A;i++)
	for(j=0;j<B;j++)
	for(k=0;k<K;k++)
		if((i&j)==k)ans++;
	
	//ans=search(0,0,0,32);

	
	cout<<"Case #"<<(ti+1)<<": ";
	cout<<ans;
	cout<<endl;
}
return 0;
}