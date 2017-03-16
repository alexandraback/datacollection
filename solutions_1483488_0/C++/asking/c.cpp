#include <iostream>
#include <stdio.h>
#include <cstring> //for strlen, memcpy and memset.
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i(a), _n(b); i<=_n; i++)
#define FORD(i,a,b) for(int i(a), _n(b); i>=_n; i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define PR(c,x) ((c).find(x) != (c).end()) 
#define CP(c,x) (find(all(c),x) != (c).end()) 
#define SZ(a) int((a).size())a
#define X first
#define Y second
#define pb push_back
#define MEMST(a,i) memset(a,i,sizeof(a))
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> PII; 
//#define ONLINE_JUDGE

char e[8];

int s2i(int idx, int bits)
{
	if(e[idx] == 0)
		return 0;
		
	int num = 0;
	FOR(i, 0, bits-1)
	{
		num *= 10;
		num += e[(idx + i) % bits];
	}
	
	return num;
}

void reverse(int bits)
{
	for(int i=0, j=bits-1; i<j; i++, j--)
		swap(e[i], e[j]);
}

int i2s(int cur)
{
	int i = 0;
	for(; cur>9; i++)
	{
		e[i] = cur % 10;
		cur /= 10;
	}
	e[i] = cur;
	i ++;
	
	reverse(i);
	return i;
}

int cntRec(int cur, int min, int max)
{
	int cnt = 0;
	
	int bits = i2s(cur);
	FOR(i, 1, bits-1)
	{
		int tmp = s2i(i, bits);
		if (tmp == cur)
			break;
		if (tmp >= min && tmp < cur)
		{
			// printf("%d %d\n", cur, tmp);
			cnt ++;
		}
	}
	
	return cnt;
}

int main()
{
    
    #ifndef ONLINE_JUDGE 
    freopen("C-small-attempt0.in","r",stdin); 
    freopen("cout.txt","w",stdout); 
    #endif

    int case_n;
    int max, min;
    
    scanf("%d ", &case_n);
    FOR(case_i, 1, case_n)
    {
		int cnt = 0;
		
		scanf("%d %d ", &min, &max);
		
		FOR(i, min, max)
		{
			cnt += cntRec(i, min, max);
		}
		
        printf("Case #%d: %d\n", case_i, cnt);
    }

    #ifndef ONLINE_JUDGE 
    fclose(stdin); 
    fclose(stdout); 
    #endif
    
    return 0;
}
