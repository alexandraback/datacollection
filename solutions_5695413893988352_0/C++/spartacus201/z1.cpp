#include<bits/stdc++.h>

using namespace std;

char str[3][2000007];
vector<string> v[3];
string temp;
int getnum(string s)
{
	int ans = 0,i;
	for(i=0;i<s.size();i++)
	{
		ans =ans*10 + (s[i]-'0');
	}
	return ans;
}
void func(int i,int len,int idx)
{
	int j;
	if(i==len)
	{
		string te;
		te="";
		for(j=0;j<len;j++)
		te = te + temp[j];
		v[idx].push_back(te);
		return ;
	}
	if(str[idx][i] == '?')
	{
		for(j=0;j<=9;j++)
		{
			temp[i] = '0' + j;
			func(i+1,len,idx);
		}
		return ;
	}
	else
	{
		temp[i] = str[idx][i];
		func(i+1,len,idx);
	}
}
int main()
{
	int t,k,i,j,len,top1,top2,n1,n2,mindiff,INF = 100000000;
	string a1,a2;
	temp = "hkfbvkdfbvkhbfkjdfkjvbkjdfbvkjdfbvkdfvkjbdbvkdfbvkdfbvkjdfbvkjdfbvkdbvjbvbkdbvkdb";
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(k=1;k<=t;k++)
	{
		cin>>str[1]>>str[2];
		len = strlen(str[1]);
		top1 = 0;
		func(0,len,1);
		/*
		for(i=0;i<v[1].size();i++)
		{
			cout<<v[1][i]<<"\n";
		}
		*/
		top2 = 0;
		func(0,len,2);
		mindiff=INF;
		top1 = v[1].size();
		top2 = v[2].size();
		for(i=0;i<top1;i++)
		{
			for(j=0;j<top2;j++)
			{
				n1 = getnum(v[1][i]);
				n2 = getnum(v[2][j]);
				if(abs(n2-n1 )< mindiff)
				{
					mindiff = abs(n2-n1);
					a1 = v[1][i];
					a2 = v[2][j];
				}
				else if(abs(n2-n1) == mindiff)
				{
					if(n1 < getnum(a1))
					{
						a1 = v[1][i];a2=v[2][j];
					}
					else if(n1 == getnum(a1) && n2 < getnum(a2))
					{
						a1 = v[1][i];a2=v[2][j];
					}
				}
			}
		}
		
		cout<<"Case #"<<k<<": ";
		cout<<a1<<" "<<a2;
		cout<<"\n";
		v[1].clear();
		v[2].clear();
	}
	return 0;
}
