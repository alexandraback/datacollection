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
void Solve()
{
	string K;
	bool isOk=1;
	vector<int> Number;
	int Count[257];
	memset(Count,0,sizeof(Count));
	cin >> K;
	for(int i=0;i<K.sz();i++)
		Count[K[i]]++;
	while(isOk)
	{
		isOk=0;
		for(int i=0;i<256;i++)
		{
			if(Count[i]){ isOk=1;}

		}
		if(Count['Z'] && Count['E'] && Count['R'] && Count['O'])
		{
			Number.push_back(0);
			Count['Z']--; Count['E']--; Count['R']--; Count['O']--;
		}

		else if(Count['T'] && Count['W'] && Count['O'])
		{
			Number.push_back(2);
			Count['T']--;  Count['W']--; Count['O']--;
		}

		else if(Count['S'] && Count['I'] && Count['X'])
		{
			Number.push_back(6);
			Count['S']--;  Count['I']--;
			Count['X']--;
		}

		else if(Count['E'] && Count['I'] && Count['G'] && Count['H'] && Count['T'])
		{
			Number.push_back(8);
			Count['E']--;  Count['I']--; Count['G']--;
			Count['H']--;  Count['T']--;
		}

		else if(Count['F'] && Count['O'] && Count['U'] && Count['R'])
		{
			Number.push_back(4);
			Count['F']--;  Count['O']--;
			Count['U']--;  Count['R']--;
		}

		else if(Count['F'] && Count['I'] && Count['V'] && Count['E'])
		{
			Number.push_back(5);
			Count['F']--;  Count['I']--;
			Count['V']--;  Count['E']--;
		}


        else if(Count['I'] && Count['N']>=2 && Count['E'])
		{
			Number.push_back(9);
			Count['I']--;  Count['N']-=2;
			Count['E']--;
		}

	
		
		else if(Count['O'] && Count['N'] && Count['E'])
		{
			Number.push_back(1);
			Count['O']--; Count['N']--; Count['E']--;
		}

		else if(Count['T'] && Count['H'] && Count['R'] && Count['E']>=2)
		{
			Number.push_back(3);
			Count['T']--;  Count['H']--;
			Count['R']--;  Count['E']-=2;
		}



		else if(Count['S'] && Count['E']>=2 && Count['V'] && Count['N'])
		{
			Number.push_back(7);
			Count['S']--;  Count['E']-=2;
			Count['V']--;  Count['N']--;
		}

		

	}
	sort(Number.begin(),Number.end());
	for(int i=0;i<Number.sz();i++)
		printf("%d",Number[i]);
	printf("\n");
}


void FileIO()
{
	freopen("A-large.in","r",stdin);
	freopen("largeoutput.txt","w",stdout);
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
