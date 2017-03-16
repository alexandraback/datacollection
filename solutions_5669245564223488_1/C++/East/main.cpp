#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

string segment[105];
string segment2[105];
string tmpseg[105];
char buffer[256];
int order[105];

bool checkvalid(const char* train)
{
	char tmp[30];
	int freq[26];
	for(int i=0;i<26;i++)
		freq[i]=0;
	tmp[0] = train[0];
	freq[train[0]-'a']++;
	int segcount = 1;
	for(int i=1;train[i]!=NULL;i++)
	{
		if(train[i]!=tmp[segcount-1])
		{
			tmp[segcount] = train[i];
			freq[train[i]-'a']++;
			if(freq[train[i]-'a']>1)
				return false;
			++segcount;
		}
	}
	return true;
}

int countpermutation(int N)
{
	string tmp;
	int res=0;
	do 
	{
		tmp="";
		for(int i=0;i<N;i++)
			tmp+=segment[order[i]];
		if(checkvalid(tmp.c_str()))
			++res;
	} 
	while ( next_permutation(order,order+N) );
	return res;
}

string removeconsecutive(const char str[])
{
	char res[256];
	res[0] = str[0];
	int segcount = 1;
	for(int i=1;str[i]!=NULL;i++)
	{
		if(str[i]!=res[segcount-1])
		{
			res[segcount] = str[i];
			++segcount;
		}
	}
	res[segcount] = NULL;
	return res;
}

long long fak(long long n)
{
	long long result = 1;

	for(long long i=2;i<=n;i++)
		result = (result * i) % 1000000007;
	return result;
}

long long countpermutationbigdata(int N)
{
	int freqbase[26];
	for(int i=0;i<26;i++)
		freqbase[i]=0;
	int segcount = 0;
	int tmpcount = 0;
	for(int i=0;i<N;i++)
	{
		if(segment[i].length()==1)
			freqbase[segment[i].c_str()[0]-'a']++;
		else
			tmpseg[tmpcount++] = segment[i];
	}
	char base[2];
	base[1]=NULL;
	for(int i=0;i<26;i++)
	{
		if(freqbase[i]>0)
		{
			base[0] = 'a'+i;
			segment2[segcount++] = base;
		}
	}
	for(int i=0;i<tmpcount;i++)
		segment2[segcount++] = tmpseg[i];
	bool repeat = false;

	do
	{
		repeat = false;
		tmpcount = 0;

		for(int i=0;i<segcount;i++)
		{
			if(segment2[i]!="")
			{
				for(int j=0;j<segcount;j++)
				{
					if(i!=j && segment2[j]!="")
					{
						int l = segment2[i].length();
						if(segment2[i].c_str()[l-1] == segment2[j].c_str()[0])
						{
							segment2[i]+=segment2[j];
							segment2[j]="";
							repeat = true;
						}
					}
				}
			}
		}

		for(int i=0;i<segcount;i++)
		{
			if(segment2[i]!="")
				tmpseg[tmpcount++] = segment2[i];
		}

		segcount = tmpcount;
		for(int i=0;i<segcount;i++)
			segment2[i] = tmpseg[i];
	}while(repeat);

	for(int i=0;i<segcount;i++)
		segment2[i] = removeconsecutive( tmpseg[i].c_str());

	int freqseg[26];
	for(int i=0;i<26;i++)
		freqseg[i]=0;

	for(int i=0;i<segcount;i++)
	{
		int l = segment2[i].length();
		const char* stri = segment2[i].c_str();
		for(int i=0;i<l;i++)
		{
			freqseg[stri[i]-'a']++;
			if(freqseg[stri[i]-'a']>1)
				return 0;
		}
	}

	long long result = 1;

	for(int i=2;i<=segcount;i++)
		result = (result * i) % 1000000007;

	for(int i=0;i<26;i++)
	{
		if(freqbase[i]>0)
			result = (result * fak(freqbase[i])) % 1000000007;
	}

	return result;
}



void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,N;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			order[i]=i;
		if(cs==32)
		{
			cs=32;
		}
		for(int i=0;i<N;i++)
		{
			scanf("%s",buffer);
			segment[i] = removeconsecutive(buffer);
		}
		
		printf("Case #%d: %lld\n",cs,countpermutationbigdata(N));
	}
}