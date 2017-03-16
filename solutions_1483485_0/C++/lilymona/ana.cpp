#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;

double freq[128];

void getfreq()
{
	FILE *fin=fopen("map.txt","r");
	char u[3],v[3];
	double w;
	for(int i=0;i<26;i++)
	{
		fscanf(fin,"%s%s%lf",u,v,&w);
		freq[u[0]]=w;
	}
	fclose(fin);
}


int main()
{
	getfreq();

	int t;
	string word;
	map<string,int> freqw[3];
	map<string,int>::iterator p;
	cin>>t;
	while(cin>>word)
	{
		int len=word.length();
		if(len<=3)
		{
			p=freqw[len-1].find(word);
			if(p==freqw[len-1].end()) freqw[len-1][word]=1;
			else p->second++;
		}
	}
	for(int len=1;len<=3;len++)
	{
		vector< pair<int,string> > a;
		for(p=freqw[len-1].begin();p!=freqw[len-1].end();p++)
		{
			a.push_back(make_pair(p->second,p->first));
		}
		sort(a.rbegin(),a.rend());
		for(int i=0;i<a.size();i++)
		{
			string s=a[i].second;
			cout<<s<<" "<<a[i].first<<" ";
			for(int j=0;j<s.length();j++) printf(" %lf",freq[s[j]]);
			printf("\n");
		}
	}
	return 0;
}

