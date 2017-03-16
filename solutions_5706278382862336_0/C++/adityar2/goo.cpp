#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctype.h>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<fstream>

#define min(a,b) a<b?a:b;

using namespace std;

//ifstream inx("ad.txt");
ofstream onx("o.txt");
	 
int  gcdr ( int a, int b )
{
  if ( a==0 ) return b;
  return gcdr ( b%a, a );
}

void low(float& p,float& q)
{int P=p;int Q=q;
 int g=gcdr(P,Q);
 P=P/g;
 Q=Q/g;
 //cout<<P<<endl<<Q;
 p=P;
 q=Q;
}
void check(float p,float q,int &ans)
{
	low(p,q);
	int c=q;
	//system("pause");
	while(c>0){
		if(c%2!=0 &&c!=1){ans=-1;return;}
		c/=2;
	}}
int level(float P,float Q)
{ int ans=0;
   float i=2;
   while(1)
   {ans++;
   if(i*P/Q>=1.0){check(P,Q,ans);               return ans; }
   i*=2;
   }
		
}
int main()
{
	
	int ntc
		;
	cin>>ntc;
	
	float P,Q;
   int cas=1;
	while(ntc--)
	{
		scanf("%f/%f",&P,&Q);
		//cout<<P<<Q;
		//system("pause");
		int ans=level(P,Q);
		onx<<"Case #"<<cas++<<": ";
		if(ans!=-1)
		onx<<  ans << '\n';
		else
			onx<<"impossible\n";
	}
	system("pause");
}