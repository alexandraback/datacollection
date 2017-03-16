#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<vector>
#include<cctype>
#include<iomanip>
#include<cmath>
#include<fstream>

# define F(i, n) 	for( int i = 0; i < (n); i++)
# define Fi(i, m, n) 	for( int i = (m); i < (n); i++)
# define Fr(i, n) 	for( int i = (n); i > 0; i-- )
# define Fri(i, m, n)	for( int i = (m); i > n; i-- )
# define P 		printf
# define Pd(x) 		printf("%d" , x )
# define PN 		printf("\n")
# define S 		scanf
# define Sd(x) 		scanf("%d",&x)
# define PB 		push_back
# define SZ(x) 		((int)((x).size()))
# define VI		vector<int>
# define SI		set<int>

typedef long long ll;

ll mod = (ll)1000000007;

using namespace std;


int main()
{
	
	int test;
	ifstream in("in.txt");
	ofstream out("out.txt");
	
	bool done[1000001];
	
	in >> test;
	Fi(i,1,test+1)
	{
		memset(done, 0, 1000001*sizeof(bool));
		
		int a, b;
		in >> a >> b;
		int nodig = 0;
		int temp = a;
		int multi = 1;
		int totalcount = 0;
		while( temp != 0)
		{
			nodig ++;
			multi *= 10;
			temp /= 10;
		}
		multi /= 10;
		
		Fi(j,a,b+1)
		if(!done[j-a])
		{
			done[j-a] = true;
			int ori = j;
			int curr = j;
			int norot = 0;
			int currcount = 1;
			while(norot < nodig)
			{
				while((curr % 10)== 0)
				{
					curr /= 10;
					norot ++;
				}
				int tomul = (curr%10);
				curr /= 10;
				norot++;
				if( norot >= nodig) break;
				curr = tomul*multi + curr;
				if( curr > ori && curr <= b)
				{
					//cout << "curr = " << curr << " for ori: " << ori << endl;
					if(!done[curr-a])
					{
					//cout << "curr = " << curr << " for ori: " << ori << endl;
					done[curr-a] = true;
					currcount ++;
					}
				}
			}
			totalcount += ((currcount*(currcount-1))/2);
			
		}
		
		out << "Case #" << i << ": " << totalcount << endl;
	}
	in.close();
	out.close();
	return 0;
}
