#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#define INF 2000000000
#define pii pair<int, int>

using namespace std;

int arr[25],n;
vector<pii> vec;

void cetak(int x)
{
    bool first=false;
    for (int i=0;i<n;i++) {
        if(((1 << i) & x))
        {
            if(first) printf(" ");
            printf("%d",arr[i]);
        	first=true;
		}
    }
    puts("");
}
 
void gen(int x)
{
    int jum = 0;
    for (int i=0;i<n;i++)
    {
        if((1 << i) & x) jum += arr[i];
	}
    vec.push_back(pii(jum,x));
}
 
 
int main()
{
    int ntc;
    scanf("%d",&ntc);
    for (int tc=1;tc<=ntc;tc++) {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&arr[i]);
        
		vec.clear();
		
		for (int i=1;i<(1<<n);i++) gen(i);
        sort(vec.begin(),vec.end());
        int resPos = -1;
        
        for (int i=0;i<vec.size()-1;i++)
        {
            if(vec[i].first == vec[i+1].first) 
            {
                resPos = i; break;
            }
        }
        
        printf("Case #%d:\n",tc);
        if(resPos != -1) 
        {
            cetak(vec[resPos].second); cetak(vec[resPos+1].second);
        }
        else {
			printf("Impossible\n");
		}
		
    }
    return 0;
}
