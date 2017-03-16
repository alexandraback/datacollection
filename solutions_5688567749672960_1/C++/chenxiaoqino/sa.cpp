#include <iostream>
#include <string>
using namespace std;


string reverse(string a)
{
	string ret(a);
	int l=a.length();
	for(int i=0;i<l;i++)
		ret[i]=a[l-i-1];
	return ret;
}

int reverse(long long a)
{
	return atoi(reverse(to_string(a)).c_str());
}
int len(long long a)
{
	return to_string(a).length();
}
//int dp[10001000];
//int rec[10001000];
int calc()
{
	//int n;
	//cin>>n;
	//memset(dp,0,sizeof(dp));
	int acc=0;
	long long n;
	cin>>n;
	if(n<10)return n;
	while(n>=10)
	{
		if(n%10==0)
		{
			acc++;
			n-=1;
			continue;
		}
		int l=len(n);
		if(l==1)break;
		int hl=(l+1)/2;
		int mo=pow(10,hl);
		int minus=(n%mo)-1;
		n-=minus;acc+=minus;
		int mn=reverse(n);
		if(mn==n)
		{
			acc++;
			n-=1;
			continue;	
		}
		n=mn;acc++;
	}
	
	return acc+n;//return search(s);
}

int main()
{
	//string a("12354");
	//cout<<calc();return 0;
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}