#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <complex>
#include <valarray>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>

using namespace std;

#define f(i,n) for(int i=0; i <n;i++)
#define fi(i,s,n) for(int i=s; i<n;i++)

typedef long long ll;

struct it{
	double s,e,h;
};

struct at{
	ll time;
	ll strength;
	ll wi, ei;
};


bool comp (at i,at j) { return (i.time<j.time); }

int main(){
	int tc;
	scanf("%d",&tc);
	f(i,tc){
		printf("Case #%d: ",i+1);
		int n;
		scanf("%d",&n);
		vector<at> v;
		vector<it> ints;
		f(j,n){
			ll di, ni, wi, ei, si, dtad, dtap, dtas;
			scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&di,&ni,&wi,&ei,&si,&dtad,&dtap,&dtas);
			f(k,ni){
				at a;
				a.time = di;
				a.strength = si;
				a.wi = wi;
				a.ei = ei;
				v.push_back(a);
				di+=dtad;
				wi+=dtap;
				ei+=dtap;
				si+=dtas;
				//printf("si %lld\n",si);
				if(si<0)break;
			}
		}

		sort(v.begin(),v.end(),comp);
		
		ll time = -1;
		vector<it> pend;
		ll num=0;
		f(j,v.size()){
			at a = v[j];
			//printf("time: %lld\n",a.time);
			if(a.time>time){
				//printf("adding %d to ints\n",pend.size());
				f(k,pend.size()){
					ints.push_back(pend[k]);
				}
				time = a.time;
				pend.clear();
			}
			
			vector<it> intsNow;
			it first;
			first.s = a.wi;
			first.e = a.ei;
			first.h = a.strength;
			intsNow.push_back(first);
			//printf("first %lf %lf %lf\n",first.s,first.e,first.h);
			
			f(k,ints.size()){
				f(l,intsNow.size()){
					it one = ints[k];
					it two = intsNow[l];
					//printf("two ints: %lld %lld %lld ::: %lld %lld %lld\n",one.s,one.e,one.h,two.s,two.e,two.h);
					if(one.s<=two.s && one.e>=two.s && two.h<=one.h){
						//printf("con lower\n");
						intsNow[l].s = min(one.e+.0001,two.e+.0001);
					}
					else if(one.s<=two.e && one.e>=two.e && two.h<=one.h){
						//printf("con higher");
						intsNow[l].e = max(one.s-.0001,two.e-.0001);
					}
					else if(one.s>=two.s && one.e <= two.e && two.h<=one.h){
						//printf("con in\n");
						it ne;
						ne.s = one.e+.0001;
						ne.e = two.e;
						ne.h = two.h;
						intsNow[l].e = one.s-.00001;
						intsNow.push_back(ne);
					}
				}
			}

			bool suc =false;
			f(k,intsNow.size()){
				//printf("checking %lf %lf %lf\n",intsNow[k].s,intsNow[k].e,intsNow[k].h);
				if(intsNow[k].s>intsNow[k].e)
					continue;
				suc = true;
				pend.push_back(intsNow[k]);
			}

			if(suc)
				num++;
		}

		printf("%lld\n",num);
	}

	return 0;
}
