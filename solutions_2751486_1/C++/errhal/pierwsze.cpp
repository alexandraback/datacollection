#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define FOR(x,b,e) for(long long x=b;x<e;x++)
#define FORD (x,b,e) for(int x=b-1;x>=e;x--)
typedef long long LL;
void wczytaj(LL *z)
{
		register char c=0;
		while(c<33) c=getc_unlocked(stdin);
		(*z)=0;
		while(c>32) {(*z)=(*z) *10LL+(c-'0');c=getc_unlocked(stdin);}
}
using namespace std;
struct ulamek{
	LL licznik;
	LL mianownik;
};
	LL tab[1100000];

int main()
{
	LL t,n;
	string str;
	cin>>t;
	FOR(i,0,t)
	{
		cin>>str>>n;
		FOR(j,0,str.size())
		{
			if(str[j]=='a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j] == 'u')
			{
				tab[j]=0;
			}
			else tab[j]=1;
		}
		LL suma=0,suma1=0,suma2=0;
		LL zapas=0;
		LL licznik=0;
		FOR(j,0,str.size())
		{
			suma1=0;
			suma2=0;
			suma=suma+tab[j];
			if(suma<n && tab[j]== 0 ) suma=0;
			else if(suma==n) 
			{
				licznik++;
				suma1=(j+1-n-zapas);
				suma2=str.size()-1-j;
				licznik=licznik+(suma1*suma2);
				licznik=licznik+suma1+suma2;
				zapas=j+1-n+1;
				//cout<<suma1<<endl<<suma2<<endl;
				suma--;
			}
		}
		cout<<"Case #"<<i+1<<": "<<licznik<<endl;
	}
    return 0;
}
     
