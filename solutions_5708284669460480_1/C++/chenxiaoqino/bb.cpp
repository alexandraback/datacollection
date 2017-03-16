#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
	 offset = str.find(sub, offset + 1))
    {
        ++count;
    }
    return count;
}


int findSelfOffset(const std::string& str)
{
    int count = 0;
	for(int i=1;i<str.size();i++)
	{
		if(str.substr(i)==str.substr(0,str.size()-i))return i;
		//if(str.find(str.substring(0,str.size()-i), i)!=std::string::npos)
	}
	return -1;
}

int K,L,S; 
string keyboard,target_word;
long double dp[200][200];

long double iprob(char o)
{
	int p=0,l=keyboard.size();
	for(int i=0;i<l;i++)
		if(keyboard[i]==o)p++;
	return p*1.0/l;
}

long double calc()
{
	cin>>K>>L>>S;
	cin>>keyboard;
	if(keyboard.size()!=K)cerr<<"error keyboard size"<<endl;
	
	cin>>target_word;
	if(target_word.size()!=L)cerr<<"error target_word size"<<endl;
	
	//cerr<<"fso"<<findSelfOffset(target_word)<<endl;
	int fso=findSelfOffset(target_word);
	int maxc;long double avgc=0;
	if(fso<0)
	{
		maxc=S/L;
	}
	else
	{
		maxc=1+(S-L)/fso;
	}
	for(int i=0;i<L;i++)
		if(iprob(target_word[i])==0)
			maxc=0;
		
	memset(dp,0,sizeof(dp));
	for(int i=0;i<S;i++)
		for(int j=0;j<L;j++)
		{
			//dp[i][j]=pr( s[i] is word[j] )
			if(j==0)dp[i][j]=iprob(target_word[j]);
			else if(i>=1)
			{
				dp[i][j]=dp[i-1][j-1]*iprob(target_word[j-1]);
			}
			//cerr<<"ij"<<i<<":"<<j<<":"<<dp[i][j]<<endl;
		}
	//for(int i=0;i<S;i++)cerr<<"pos"<<i<<":"<<dp[i][L-1];
	for(int i=0;i<S;i++)avgc+=dp[i][L-1];
	return maxc-avgc;
}

int main()
{
	cout<<setprecision(10);
	//cout<<calc();return 0;
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}