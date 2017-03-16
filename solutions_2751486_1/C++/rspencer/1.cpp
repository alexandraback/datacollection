#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

#define FORI(_q) for(int i = 0; i<(_q);i++)
#define FORJ(_q) for(int j = 0; j<(_q);j++)
#define FORK(_q) for(int k = 0; k<(_q);k++)
#define PUHEAP(_q) push_heap((_q).begin(),(_q).end())
#define POHEAP(_q) pop_heap((_q).begin(),(_q).end())
#define SORT(_q)sort((_q).begin(),(_q).end())
#define DEBUG cout<<"DEBUG"<<endl;

using namespace std;
typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))

bool isVowel(char c)
{
	return (c!='a') and (c!='e') and (c!='i') and (c!='o') and (c!='u');
}

int main()
{
	int T;
	cin>>T;
	for (int t= 0;t<T;t++)
	{
		int ans = 0;
		string name;
		int n;
		cin>>name>>n;
		vector<int> endIndexes;
		int cnt = 0;
		FORI(name.length())
		{
			if (isVowel(name[i]))
				cnt++;
			else
				cnt = 0;
			if (cnt>=n)
				endIndexes.push_back(i);
		}
		int end = name.length();
		for (int i = endIndexes.size()-1;i>=0;i--)
		{
			ans += (end-endIndexes[i]) * (endIndexes[i]-n+2);
			end = endIndexes[i];
		}
		
		
		
		cout<<"Case #"<<t+1<<": "<<ans<<endl;
	}
}