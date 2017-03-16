#include<iostream>
#include<algorithm>
using namespace std;

struct cases{
int N;
unsigned int s[200];
float m[200];
float thingers;
unsigned int X;
//int counter;
};

int main()
{
	int T;
	cin>>T;
	cases str[50];

	for(int i=0;i<T;++i)
	{	cin>>str[i].N;
		str[i].X = 0;
		
		for(int j=0;j<str[i].N;++j)
			{cin>>str[i].s[j];
			str[i].X += str[i].s[j];
			str[i].m[j] = 0;}	
		str[i].thingers = str[i].X;
	}
////////////////////////////////////////////////////////////////////////
//	taking average of that thingy

for(int i=0;i<T;++i)
{	for(int j=0; j<str[i].N;++j)
	{
		str[i].thingers+=float(str[i].X - str[i].s[j])/(float((str[i].N)-1));
	}

		str[i].thingers /= str[i].N;
//		cout<<' '<<str[i].thingers;
}
for(int i=0 ; i<T; ++i)
{	for(int j=0; j<str[i].N;++j)
	{
		str[i].m[j] = (float(str[i].thingers) - float(str[i].s[j]))/float(str[i].X);
	}
}
for(int i=0;i<T;++i)
{	int counter = 0;
	float negativa = 0;
	for(int j=0; j<str[i].N;++j)
		{
		if(str[i].m[j]<0)
		{
		negativa += str[i].m[j];
		str[i].m[j] = 0; 
		counter++;
		}
		}
	negativa /=  float(str[i].N-counter);
	for(int j=0; j<str[i].N;++j)
		{
		if(str[i].m[j]>0)
		str[i].m[j] += negativa;
		}
}
///////////////////////////////////////////////////////////////////////
	for(int i=0;i<T;++i)
		{cout<<"\nCase #"<<i+1<<": ";
		for(int j=0;j<str[i].N;++j)
		 cout<<str[i].m[j]*100<<' ';}
}
