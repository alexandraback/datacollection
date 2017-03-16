#include <iostream>
#include <string>
#define C 30

using namespace std;

const string no="NO";
const string yes="YES";
int v[5][5]={
	0,0,0,0,0,
	0,1,2,3,4,
	0,2,-1,4,-3,
	0,3,-4,-1,2,
	0,4,3,-2,-1
};
unsigned long long int t,X,L;
typedef unsigned long long int llu;
string s;
inline llu MIN(llu a,llu b)
{
	return (a>b)?b:a;
}

bool Compute()
{
	bool ifound=false;
	bool jfound=false;
	int current=1;
	int sign=1;
	for(int i=0;i<MIN(X,C);++i)
	{
		for(int j=0;j<L;++j)
		{
			current=v[current][s[j]-'i'+2];
			if(current<0)
			{
				sign=-sign;
				current=-current;
			}
			if(current>0 && sign>0)
			{
				if(current==2 && !ifound)
				{
					ifound=true;
					current=1;
				}
				if(current==3 && !jfound && ifound)
				{
					jfound=true;
					return true;
					current=1;
				}
			}
		}
	}
	return false;
}

int ResString()
{
	int current=1;
	int sign=1;
	for(int i=0;i<L;++i)
	{
		current=v[current][s[i]-'i'+2];
		if(current<0)
		{
			current=-current;
			sign=-sign;
		}
	}
	return current*sign;
}

// linear .. not good eh 
int ResRepeat(int stringValue)
{
	int res=1;
	int sign=1;
	for(int i=0;i<X;++i)
	{
		if(stringValue<0)
		{
			sign=-sign;
			res=v[res][-stringValue];
			if(res<0)
			{
				sign=-sign;
				res=-res;
			}
		}
		else
		{
			res=v[res][stringValue];
			if(res<0)
			{
				sign=-sign;
				res=-res;
			}	
		}
	}
	return res*sign;
}

//logarithmic solution
int ResRepeatLog(int stringValue)
{
	int res=1;
	int futureSign=1;
	int sign=1;
	if(stringValue<0)
	{
		futureSign=-futureSign;
		stringValue=-stringValue;
	}
	for(int i=0;(1<<i)<=X;++i)
	{
		if(((1<<i)&X))
		{
			sign*=futureSign;
			res=v[res][stringValue];
			if(res<0)
			{
				sign=-sign;
				res=-res;
			}			
		}
		futureSign=1;
		stringValue=v[stringValue][stringValue];
		if(stringValue<0)
		{
			futureSign=-futureSign;
			stringValue=-stringValue;
		}
	}
	return res*sign;
}

int CountDif()
{	
	int counti=0,countj=0,countk=0;
	for(int i=0;i<L;++i)
	{
		if(s[i]=='i')
			counti++;
		if(s[i]=='j')
			countj++;
		if(s[i]=='k')
			countk++;
	}
	int count=0;
	if(counti)
		count++;
	if(countj)
		count++;
	if(countk)
		count++;
	return count;
}

int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>L>>X;
		cin>>s;
		int stringValue=ResString();
		int repeatValue= ResRepeatLog(stringValue);
		int countDif=CountDif();
		cout<<"Case #"<<i<<": "; 
		if(repeatValue==-1 && countDif>=2)
		{
			if(Compute())
			{
				//cout<<"Case #"<<i<<": ";
				cout<<yes<<endl;
			}
			else cout<<no<<endl;
		}
		else
		cout<<no<<endl;	
	}	
	return 0;
}