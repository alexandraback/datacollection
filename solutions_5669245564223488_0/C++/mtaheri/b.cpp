#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<List>
#include<vector>
#include<queue>
#include<set>
#include<math.h>

using namespace std;
#define pii pair<int,int>
#define pid pair<int,double>
#define pqType int
#define num 1000000007
int fact[1000000];
int pr;
class PQComp
{public:
	bool operator()(pqType& a,pqType& b)
	{return a>b;}
};

template<class type>
int comp(const type* pa,const type*pb)
{
	type a=*(type*)pa;type b=*(type*)pb;
	return a-b;
}
int N;
string strs[200];
int prs[200];
int dc;

bool possible(char c)
{
	int first=-1;
	int last=-1;
	int both=0;
	int cnt=0;
	int f=-1;
	for(int i=0;i<N;i++)
	{
		if(strs[i]=="")
			continue;
		string s=strs[i];
		int state=0;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]!=c)
			{
				if(state==1)
					state=2;
			}else
			{
				if(state==2)
					return false;
				state=1;
			}
		}
		if(s[0]==c && s[s.length()-1]==c)
		{
			both++;
			prs[i]=0;
			f=i;
		}
		else if(s[0]==c)
		{
			
			if(first!=-1)
				return false;
			first=i;
		}else if(s[s.length()-1]==c)
		{
			if(last!=-1)
				return false;
			last=i;
		}else
		{
			if(state>0)
				cnt++;
		}
	}
	int tcnt=cnt;
	cnt-=both;
	if(first!=-1)cnt--;
	if(last!=-1)cnt--;
	if(tcnt>1 && cnt>0)
		return false;

	if(first==-1 && last==-1)
	{
		if(both>0)
		{
			pr=((_int64)pr*fact[both]%num);
			prs[f]=1;
		}
		return true;
	}
	if(first==-1)
	{
		pr=((_int64)pr*fact[both]%num);
		return true;
	}
	if(last==-1)
	{
		pr=((_int64)pr*fact[both]%num);
		return true;
	}
	pr=((_int64)pr*fact[both]%num);
	strs[first]=strs[last]+strs[first];
	strs[last]="";
	prs[last]=0;

	return true;
}

void solve()
{
	pr=1;
	for(char c='a';c<='z';c++)
	{
		if(!possible(c))
		{
			cout<<0<<endl;
			return;
		}
	}
	
	int s=0;
	for(int i=0;i<N;i++)
	{
		if(prs[i]==0)continue;
		//pr=(((_int64)pr*prs[i])%num);
		s++;
	}
	pr=((_int64)pr*fact[s]%num);
	cout<<pr<<endl;

}

void main()
{
	fstream fin("b2.in",fstream::in);
	fstream fout("b2.out",fstream::out);
	cin.rdbuf(fin.rdbuf());
	cout.rdbuf(fout.rdbuf());

	fact[0]=fact[1]=1;
	for(int i=2;i<1000000;i++)
	{
		fact[i]=((_int64)i*fact[i-1])%num;
		
	}
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>strs[i];
			prs[i]=1;
		}
		solve();
	}

}