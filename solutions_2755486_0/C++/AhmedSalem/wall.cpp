#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

const long long MAXLEN = 1000;
const long long ALPHA = 500;

class Interval
{
public:
	long long s,e;
	long long day,strength;
	Interval(){}
	Interval(long long s,long long e,long long day,long long strength):s(s),e(e),day(day),strength(strength){}
	bool operator < (const Interval& that) const
	{
		return this->day < that.day;
	}
};

vector<Interval> arr;
long long height[MAXLEN+5];

long long getMinimum(long long s,long long e)
{
	s+=ALPHA;
	e+=ALPHA;
	long long ret = height[s];
	for (long long c=s;c<e;c++)
		ret = min(ret, height[c]);
	return ret;
}
void updateRangeToMaximum(long long s,long long e,long long h)
{
	s+=ALPHA;
	e+=ALPHA;
	for (long long c=s;c<e;c++)
		height[c] = max(height[c], h);
	return ;
}


int main()
{
	freopen("wall.in","r",stdin);
	freopen("wall.out","w",stdout);
	long long c,c2;
	long long tests;
	scanf("%lld",&tests);
	for (long long test=1;test<=tests;test++){
		printf("Case #%lld: ",test);
		arr.clear();
		long long N;
		scanf("%lld",&N);
		for (c=0;c<N;c++){
			long long day,n,w,e,strength,deltaDay,deltaDist,deltaStrength;
			scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&day,&n,&w,&e,&strength,&deltaDay,&deltaDist,&deltaStrength);
			for (c2=0;c2<n;c2++){
				arr.push_back(Interval(w,e,day,strength));
				strength+=deltaStrength;
				e+=deltaDist;
				w+=deltaDist;
				day+=deltaDay;
			}
		}
		memset(height,0,sizeof(height));
		sort(arr.begin(),arr.end());
		long long ret=0;
		for (c=0;c<arr.size();){
			long long to = c;
			for (to = c;to<arr.size();to++)
				if (arr[to].day != arr[c].day)break;
			for (c2=c;c2<to;c2++)
				if (getMinimum(arr[c2].s,arr[c2].e) < arr[c2].strength){
					//printf("day %2d: [%lld, %lld] height %lld\n",arr[c2].day,arr[c2].s,arr[c2].e,arr[c2].strength);
					ret++;
				}
			for (c2=c;c2<to;c2++)
				updateRangeToMaximum(arr[c2].s,arr[c2].e,arr[c2].strength);
			c = to;
		}
		printf("%lld\n",ret);
	}
	
	
	
	return 0;
}
