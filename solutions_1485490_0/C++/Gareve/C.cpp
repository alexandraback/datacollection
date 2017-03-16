/**
* @author Gareve
*/
#define DEBUGs
#ifndef NDEBUG	
	#define DBG(a) cout<<__LINE__<<": "<<#a<<"= "<<a<<endl;
#else
	#define DBG(a) ;
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <set>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)
#define L long long
#define P pair<int,L>

using namespace std;

int N,M;
P A[109],B[109];
L sum;

L h(int x){
	if(N < 3)return 0LL;
	L res = 0;
	L q = A[2].second;
	while(x<M and q>0){
		if(B[x].first == A[2].first){
			if(B[x].second > q){
				res+=q;
				q = 0;
				break;
			}else{
				res += B[x].second;
				q -= B[x].second;
			}
		}
		x++;
	}
	return res;
}
L g(L q,int x){
	if(N < 2)return 0LL;
	L qq = q;
	int xx =x;
	L res = 0;

	int lastx = x;
	while(x<M and q>0LL){
		if(B[x].first == A[1].first){
			lastx = x;
			if(B[x].second > q){
				res+=q;
				q = 0;
				break;
			}else{
				res += B[x].second;
				q -= B[x].second;
			}
		}
		x++;
	}
	//printf("+%lld(x = %d) = %lld\n",qq,xx,res);
	return res + h(lastx);
}
L f(L q){	
	if(q > A[0].second)
		return q;
	int x = 0;
	L res = 0;
	L qq= q;
	int lastx=0;
	while(x<M and q>0){
		if(B[x].first == A[0].first){
			lastx = x;
			if(B[x].second >= q){
				res+=q;
				lastx++;
				q = 0;
				break;
			}else{
				res += B[x].second;
				q -= B[x].second;
			}
		}
		x++;
	}
	if(N == 1)return res;
	

	L a = 0,d = A[1].second,m,tmp;	
	L resa = 0;
	/*while(a < d){
		m = (a + d) / 2;
		tmp = g(m,lastx);
		if(tmp >= resa){
			a = m+1;
			resa = tmp;
		}else{
			d = m;
		}
	}
	*/
	L aa,bb;
	L c,b;
	L fb,fc;
	while(a < d){
		aa = a;
		bb = d;
		b=(2*a+d)/3;
		c=(a+2*d)/3;

		fb = g(b,lastx);
		fc = g(c,lastx);
		resa = max(resa,fb);
		resa = max(resa,fc);
		if(fb>fc)
			a=b;
		else
			d=c;

		if(a == aa and d == bb)
			break;
	}
	resa = max(resa,g(A[1].second,lastx));
	resa = max(resa,g(d,lastx));
	resa = max(resa,g(0,lastx));

	//printf("+%lld = %lld + %lld, x = %d\n",qq,res,resa,lastx);

	return res + resa;
}

L proc(){
	L a=0,d = sum,m,tc,tb;
	L res = 0;
	/*while(a < d){
		m = (a + d) / 2LL;
		tc = f(m);
		if(tc >= res){
			res = tc;
			a = m+1;
		}else{
			d = m;
		}
	}*/
	L b,c,fc,fb;
	L aa,bb;
	while(a < d){
		aa = a;
		bb = d;
		b=(2*a+d)/3;
		c=(a+2*d)/3;

		fb = f(b);
		fc = f(c);
		res = max(res,fb);
		res = max(res,fc);
		if(fb>fc)
			a=b;
		else
			d=c;

		if(a == aa and d == bb)
			break;
	}
	
	res = max(res,f(0));
	res = max(res,f(sum));

	return res;
}
void resuelva(){
	scanf("%d %d",&N,&M);
	int tp;
	L cant;

	vector<P > vc;
	set<int> types;
	sum = 0;
	for(int i=1;i<=N;i++){
		scanf("%lld %d",&cant,&tp);
		sum += cant;
		if(vc.empty() or vc.back().first != tp)
			vc.push_back(P(tp,cant));
		else
			vc[vc.size()-1].second += cant;
		types.insert(tp);
	}
	N = vc.size();
	for(int i=0;i<vc.size();i++)A[i] = vc[i];

	vc.clear();
	for(int i=1;i<=M;i++){
		scanf("%lld %d",&cant,&tp);
		if(types.find(tp) == types.end())
			continue;
		if(vc.empty() or vc.back().first != tp)
			vc.push_back(P(tp,cant));
		else
			vc[vc.size()-1].second += cant;
	}
	for(int i=0;i<vc.size();i++)B[i] = vc[i];	
	M = vc.size();

	sum = A[0].second;
	if(N == 3 and A[2].first == A[0].first)
		sum += A[2].second;
	L res = proc();
	printf("%lld\n",res);
}
int main(){
	int nc;
	scanf("%d",&nc);
	for(int i=1;i<=nc;i++){
		printf("Case #%d: ",i);
		resuelva();
	}
}