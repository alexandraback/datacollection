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



	bool found[1001][1001];
	int counti[1001];
	bool done[1001];
	int paths[1001][10];
//	int curpath[1001];
	int n;
	bool foundatleastone = false, resultfound = false;
	
	
void doexplore(int curnode)
{
	// cout << "doing for curnode = " << curnode << " with count = " << counti[curnode] << endl;
	
	//curpath[pathlength] = curnode;
	F(i,counti[curnode])
	{
		int curnext = paths[curnode][i];
		if(!done[curnext])
		doexplore(curnext);
		if(resultfound)
		return;
		Fi(j,1,n+1)
		{
			if(found[curnode][j] && found[curnext][j])
			{
				resultfound = true;
				return;
			}
			else if(!found[curnode][j])
			found[curnode][j] = found[curnext][j];
		}
		
	//	if(curnode == 1)
	//	cout << "val is: " << found[1][5] << endl;
	}
	done[curnode] = true;
	return;
}

int main()
{
	int test;
	ifstream in("in.txt");
	ofstream out("out.txt");
	
	in >> test;
	
	Fi(testi,1,test+1)
	{
	//	cout << "case : " << testi << endl;
		in >> n;
		memset(&found[0][0], 0, (n+1)*1001*sizeof(bool));
		memset(&done[0],0,(n+1)*sizeof(bool));
		memset(&counti[0],0,(n+1)*sizeof(int));
		Fi(i,1,n+1)
		{
			int temp;
			in >> temp;
			counti[i] = temp;
			F(j,temp)
			{
				int temp1;
				in >> temp1;
				paths[i][j] = temp1;
				found[i][temp1] = true;
			}
		}
		foundatleastone = false;
		resultfound = false;
		do{
			foundatleastone = false;
			Fi(i,1,n+1)
			if(!done[i])
			{
				foundatleastone = true;
				doexplore(i);
				
			}
		}while(foundatleastone && !resultfound);
		out<< "Case #" << testi << ": ";
		if(resultfound)
		out << "Yes" << endl;
		else
		out << "No" << endl;
	}
	return 0;
}
