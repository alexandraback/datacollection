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

int K,L,S; 
string target_word;
string keyboard;
int maxc,tot;long long totc;
void naive_search( int pos,string prev )
{
	if(pos>=S)
	{
		int count=countSubstring(prev,target_word);
		//cerr<<"count:"<<count<<" of:"<<prev<<":"<<target_word<<endl;
		maxc=max(maxc,count);
		tot+=1;
		totc+=count;
		return;
	}
	else
		for(int i=0;i<K;i++)
		{
			naive_search(pos+1,prev+keyboard[i]);
		}
}

double calc()
{
	cin>>K>>L>>S;
	cin>>keyboard;
	if(keyboard.size()!=K)cerr<<"error keyboard size"<<endl;
	
	cin>>target_word;
	if(target_word.size()!=L)cerr<<"error target_word size"<<endl;
	
	maxc=totc=tot=0;
	naive_search(0,string(""));
	for(int i=2;i<=K;i++)
		while((totc%i==0) && (tot%i==0))
		{
			totc/=i;
			tot/=i;
		}
	double ans=maxc-1.0*totc/tot;
	return ans;
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