#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define MAX 100000007

vector<lld> store(50);

lld gcd(lld a,lld b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

lld getValue(lld a,int base)
{
	if(a==0)
		return 0;
	
	if(a&(1ll))
		return getValue(a>>1ll,base)*base + 1ll;
	else
		return getValue(a>>1ll,base)*base;
}

int main()
{
	
	freopen("output.txt","r",stdin);
	freopen("ans3.txt","w",stdout);

	
	for(int i = 0;i<50;i++)
		cin>>store[i];

	int t=1;
	lld n=32,limit=500;
	

//	cout<<n<<" "<<j<<endl;
	cout<<"Case #1:\n";
	
	for(int i = 0;i<store.size() && (limit>0);i++)
	{
		for(int  j= 0;j<store.size() && (limit>0);j++)
		{
			lld num1 = store[i];
			lld num2 = store[j];
			
			//cout<<num1<<" "<<num2<<endl;
			
			vector<lld> aux;
			
			for(int base = 2;base<=10;base++)
			{
				lld temp = gcd(getValue(num1,base),getValue(num2,base));
				
			//	cout<<temp<<endl;
				if(temp!=1)
					aux.push_back(temp);
				else
					break;
			}
			//cout<<store.size()<<endl;
			if(aux.size()==9)
			{
				limit--;
				cout<<getValue(num1,10)<<getValue(num2,10)<<" ";
				for(int l = 0;l<9;l++)
					cout<<aux[l]<<" ";
				cout<<endl;
			}
			
			//cout<<limit<<endl;
		}
	}
	
		
	return 0;
}
