#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

long long lbitmap[64];
long long keys[50];
int numkey;

class key
{
public:
	bool get;
	vector<int> pre;
	int after;
	long long k;
};

class box
{
public:
	int type;
	long long k;
};

box b[20];

key k[1050000];

int bitmap[30];

int K, N;

int findkey(long long status, int type)
{
	for(int i=0;i<numkey;i++)
	{
		if((status & lbitmap[i]) && keys[i] == type)
			return i;
	}
	return -1;
}

int main()
{
	//ios::sync_with_stdio(false);
	bitmap[0] = 1;
	lbitmap[0] = 1;
	for(int i=1;i<30;i++)
		bitmap[i] = bitmap[i-1] << 1;
	for(int i=1;i<64;i++)
		lbitmap[i] = lbitmap[i-1] << 1;
	int T;
	cin >> T;
	for(int c=1;c<=T;c++)
	{
		cin >> K >> N;
		numkey = 0;
		for(int i=0;i<bitmap[N];i++) k[i].get = false;
		k[0].get = true;
		k[0].k = 0;
		for(int i=0;i<K;i++)
		{
			int type;
			cin >> type;
			keys[numkey] = type;
			k[0].k = k[0].k | lbitmap[numkey++];
		}
		for(int i=0;i<N;i++)
		{
			int boxtype;
			cin >> boxtype;
			b[i].type = boxtype;
			int num;
			cin >> num;
			b[i].k = 0;
			for(int j=0;j<num;j++)
			{
				int keytype;
				cin >> keytype;
				keys[numkey] = keytype;
				b[i].k = b[i].k | lbitmap[numkey++];
			}
		}
		for(int i=0;i<bitmap[N];i++)
		{
			if(k[i].get == false) continue;
			for(int j=0;j<N;j++)
			{
				if(i & bitmap[j]) continue;
				int newb = i | bitmap[j];
				int mykey = findkey(k[i].k, b[j].type);
				if(mykey != -1)
				{
					if(k[newb].get == false)
					{
						k[newb].get = true;
						k[newb].k = k[i].k | b[j].k;
						k[newb].k = k[newb].k ^ lbitmap[mykey];
						k[newb].pre.clear();
					}
					k[newb].pre.push_back(i);
				}
			}
		}
		cout << "Case #" << c << ":";
		if(k[bitmap[N]-1].get)
		{
			for(int i=0;i<bitmap[N];i++) k[i].get = false;
			k[bitmap[N]-1].get = true;
			for(int i=bitmap[N]-1;i>=0;i--)
			{
				if(k[i].get == false) continue;
				for(int j=0;j<k[i].pre.size();j++)
				{
					k[k[i].pre[j]].get = true;
					k[k[i].pre[j]].after = i;
				}
			}
			int status = 0;
			while(status != bitmap[N]-1)
			{
				int newstaus = k[status].after;
				int statusdiff = newstaus ^ status;
				int count = 0;
				while(statusdiff)
				{
					count++;
					statusdiff>>=1;
				}
				cout << " " << count;
				status = newstaus;
			}
			cout << endl;
		}
		else
		{
			cout << " IMPOSSIBLE" << endl;
		}
	}
}