#include<bits/stdc++.h>
using namespace std;
#define ii  pair<int,int>
#define limit (0x7f7f7f7f)
template<class T> T fpwr(T b, T p)
{
T r=1,x=b;
while(p)
{
if(p&1)
r*=x;
x*=x;
p=(p>>1);
}
return r;
}
int a,b,c;
string input;
string word;
ii func(int index,string inp)
{
    if(index==c)
    {
        int retval = 0;
	for(int i=0;i<=c-b;++i)
        {
            if(!inp.compare(i,b,word))
		retval++;
        }
        return make_pair(retval,retval);
    }
   ii sec= make_pair(0,-limit);
    for(int i=0;i<=a-1;++i)
    {
        ii inter = func(index+1,inp+input[i]);
        sec.second = max(sec.second,inter.second);
        sec.first += inter.first;
    }
    return sec;
}
 
int main()
{
	freopen("input.in","r",stdin);
	freopen("outputs.txt","w",stdout);    
int t,cases=1;
    cin>>t;
    while(t--)
    {
	
        cin>>a>>b>>c;
        cin>>input;
        cin>>word;
        ii result = func(0,"");
        double ver = (double)result.second-double(result.first)/double(fpwr(a,c));
	int temp=ver;
	double ress=ver-temp;
	if(ress==0)
	{
		cout<<"Case #"<<cases++<<": "<<setprecision(8)<<ver<<".0"<<endl;
	}
	else
	{
        cout<<"Case #"<<cases++<<": "<<setprecision(8)<<ver<<endl;
	}
    }
    return 0;
}
