#include<bits/stdc++.h>
using namespace::std;

const int  Max = 1e5+1;
const int  Mod = 1e9+7;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define PI  M_PI
#define pb push_back
#define pp pop_back
#define sz size
#define ln length
#define ff first
#define ss second

#define mset(a,v) 		memset(a,v,sizeof(a))
#define mcpy(a,b)  		memcpy(a,b,sizeof(a))
#define mcmp(a,b)   	memcmp(a,b,sizeof(a))
#define CountSetBits(x) __builtin_popcount(x)
#define SetBit(x,pos)   x=((x) | (1<<pos))
#define UnsetBit(x,pos) x=((x) & ~(1<<pos))
#define CheckBit(x,pos) ((x)&(1<<(pos)))?1:0
#define all(a) 			a.begin(),a.end()
#define vsort(a) 		sort(all(a))
#define vfind(a,e) 		bs(all(a),e)
#define ModVal(a,M)	    (a%M+M)%M
#define lbnd(A, x)		(lower_bound(all(A), x) - A.begin())
#define ubnd(A, x) 		(upper_bound(all(A), x) - A.begin())


/* Code Starts Here */
int to_number(string s)
{
	int num=0;
	for(int i=0;i<s.sz();i++)
	{
		num=num*10+s[i]-'0';
	}
	return num;
}
void Solve()
{
	string a,b;
	cin >> a >> b;
	int i,j,p,k,Res;
	string Num1,Num2;
	int Maxi = INT_MAX;
	vector< pair<int,int> > MyVec;
	string tostr[]={"0","1","2","3","4","5","6","7","8","9"};
	
	vector<string> Res1,Res2;

	if(a.sz()==1)
	{

		    for(i=0;i<=9;i++)
			{
				Num1="";
				Num2="";

				if(a[0]=='?')
					Num1=Num1+tostr[i];
				else if(a[0]!='?')
					Num1=Num1+a[0];

				if(b[0]=='?')
					Num2=Num2+tostr[i];
				else if(b[0]!='?')
					Num2=Num2+b[0];

				Res1.push_back(Num1);
				Res2.push_back(Num2);
			}
	}
	

	else if(a.sz()==2)
	{
		for(i=0;i<=9;i++)
		{
			for(j=0;j<=9;j++)
			{
				Num1="";
				Num2="";

				if(a[0]=='?')
					Num1=Num1+tostr[i];
				else if(a[0]!='?')
					Num1=Num1+a[0];

				if(a[1]=='?')
					Num1=Num1+tostr[j];
				else if(a[1]!='?')
					Num1=Num1+a[1];

				if(b[0]=='?')
					Num2=Num2+tostr[i];
				else if(b[0]!='?')
					Num2=Num2+b[0];

				if(b[1]=='?')
					Num2=Num2+tostr[j];
				else if(b[1]!='?')
					Num2=Num2+b[1];

				Res1.push_back(Num1);
				Res2.push_back(Num2);
			}
		}
	}

	else if(a.sz()==3)
	{

		for(i=0;i<=9;i++)
		{
			for(j=0;j<=9;j++)
			{
				for(k=0;k<=9;k++)
				{
					Num1="";
					Num2="";

					if(a[0]=='?')
						Num1=Num1+tostr[i];
					else if(a[0]!='?')
						Num1=Num1+a[0];

					if(a[1]=='?')
						Num1=Num1+tostr[j];
					else if(a[1]!='?')
						Num1=Num1+a[1];

					if(a[2]=='?')
						Num1=Num1+tostr[k];
					else if(a[2]!='?')
						Num1=Num1+a[2];

					if(b[0]=='?')
						Num2=Num2+tostr[i];
					else if(b[0]!='?')
						Num2=Num2+b[0];

					if(b[1]=='?')
						Num2=Num2+tostr[j];
					else if(b[1]!='?')
						Num2=Num2+b[1];

					if(b[2]=='?')
						Num2=Num2+tostr[k];
					else if(b[2]!='?')
						Num2=Num2+b[2];

					Res1.push_back(Num1);
					Res2.push_back(Num2);
				}
			}
		}
	}

	for(i=0;i<Res1.sz();i++)
	{
		for(j=0;j<Res2.sz();j++)
		{
			Res = abs(to_number(Res1[i]) - to_number(Res2[j]));
			if(Res<Maxi)
			{
				MyVec.clear();
				MyVec.push_back(mp(to_number(Res1[i]),to_number(Res2[j]) ));
				Maxi=Res;
			}
			else if(Res==Maxi)
			{
				MyVec.push_back(mp(to_number(Res1[i]),to_number(Res2[j])));
			}
		}
	}

	sort(MyVec.begin(),MyVec.end());
	if(a.sz()==1)
	{
		cout << MyVec[0].first << " " << MyVec[0].second << endl;

	}
	else if(a.sz()==2)
	{
		if(MyVec[0].first <10)
		{
			cout << "0";
			cout << MyVec[0].first << " ";
		}
		else
			cout << MyVec[0].first << " ";
		if(MyVec[0].second <10)
		{
			cout << "0";
			cout << MyVec[0].second;
			cout << endl;
		}
		else
			cout << MyVec[0].second << endl;
	}
	else if(a.sz()==3)
	{
		if(MyVec[0].first <10)
		{
			cout << "00";
			cout << MyVec[0].first << " ";
		}
		else if(MyVec[0].first <100)
		{
			cout << "0";
			cout << MyVec[0].first << " ";
		}
		else
			cout << MyVec[0].first << " ";

		if(MyVec[0].second <10)
		{
			cout << "00";
			cout << MyVec[0].second;
			cout << endl;
		}

		else if(MyVec[0].second <100)
		{
			cout << "0";
			cout << MyVec[0].second;
			cout << endl;
		}
		else
			cout << MyVec[0].second << endl;
	}
}


void FileIO()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("BSMALL.txt","w",stdout);
}

int main()
{
	FileIO();
	int i,T=1;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		Solve();
	}
	return 0;
}
