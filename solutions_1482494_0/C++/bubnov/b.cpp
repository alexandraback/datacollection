#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t1,t;
int n;
int a[2001],b[2001];
bool st1[2001], st2[2001];
int i,j;
long ans;
int star;

class Level
{
public:
	int a;
	int num;
	Level(int a1, int num1){a=a1;num=num1;}
	bool operator <(const Level & l2) const
	{
		return a<l2.a;
	}
};

class Level1
{
public:
	int a,b;
	int num;
	Level1(int a1,int b1, int num1){a=a1;num=num1;b=b1;}
	bool operator <(const Level1 & l2) const
	{
		if(a<l2.a){return 1;}
		//return 0;
		if(a==l2.a && b>l2.b){return 1;}
		return 0;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
        freopen("B-small-attempt1.in","r",stdin);
		//freopen("input.txt","r",stdin);	

        freopen("output2.txt","w",stdout);
#endif
	cin >> t;

	for(t1=1;t1<=t;t1++)
	{
		cin >> n;
		vector <Level1> a1;
		vector <Level> b1;
		for(i=0;i<n;i++)
		{
			cin >> a[i] >> b[i];
			a1.push_back(Level1(a[i],b[i],i));
			b1.push_back(Level(b[i],i));
			st1[i]=0;
			st2[i]=0;
		}
		int ai,bi;
		ans=0;
		ai=0;
		bi=0;
		star=0;
		sort(a1.begin(),a1.end());
		sort(b1.begin(),b1.end());


/*		if(t1==8)
		{
			for(i=0;i<a1.size();i++)
			{
				cout << a1[i].a << " " << a1[i].b << "\n";
 			}
			for(i=0;i<b1.size();i++)
			{
				cout << b1[i].a << "\n";
			}
			cout << "***\n";
		}*/

		while(ai<a1.size() || bi<b1.size())
		{
			if(bi<b1.size())
			{
				if(star>=b1[bi].a)
				{
					if(st1[b1[bi].num]==0){star++;st1[b1[bi].num]=1;}
					star++;
					bi++;
					ans++;
					continue;
				}
			}
			if(ai<a1.size())
			{
				while(ai<a1.size() && st1[a1[ai].num]==1)
				{
					ai++;
				}
				if(ai==a1.size()){continue;}
				if(ai<a1.size() && star>=a1[ai].a)
				{
					st1[a1[ai].num]=1;
					star++;
					ai++;
					ans++;
					continue;
				}
			}
			if(star<2*n){ans=-1;break;}
			//ans=-1;break;
		}

		//cout << star << " ";
		cout << "Case #" << t1 << ": ";
		if(ans!=-1){cout << ans;} else {cout << "Too Bad";}
		cout << "\n";
		//cout << "\n\n\n";
	}
    return 0;
}
