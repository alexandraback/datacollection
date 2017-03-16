#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll Gcd(ll a,ll b){
	ll r;
	while(1) {
		r=b%a;if(r==0) return a;
		b=a;a=r;
	}
}

ll Pow(ll a ,int b ,int Mo){
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mo)
        if (b&1) ans = ans * a % Mo;
    return ans;
}

long solve() {
	int J,P,S,K;
	cin>>J>>P>>S>>K;
	int s=0;
	std::vector<string> v;
	map<pair<int,int>,int > jp,ps,js;
	map<pair<pair<int,int>,int>,int > jps;
	for (int i = 0; i < J; ++i)
	{
		for (int j = 0; j < P; ++j)
		{
			for (int k = 0; k < K; ++k)
			
               {
               	int ns = -1;
               	for (int z = 0; z < S; ++z)
               	{
               	if(jp[make_pair(i,j)]<K && ps[make_pair(j,z)]<K && js[make_pair(i,z)]<K && jps[make_pair(make_pair(i,j),z)]==0)
               		{
               			ns = z;
               			break;
               		}
               	}
               	if(ns!=-1)
               	{
               		s=ns;
                    string str = "1 1 1";
                    str[0]=i+'1';
                    str[2]=j+'1';
                    str[4]=s+'1';
                    jps[make_pair(make_pair(i,j),s)]=1;
                     jp[make_pair(i,j)]++;
                    ps[make_pair(j,s)]++;
                    js[make_pair(i,s)]++;
                   
                    
                    v.push_back(str);
                } 
                //s=(s+1)%S;


			}
		}
	}

	cout<<v.size()<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i];
		if(i!=v.size()-1)
			cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	
	
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
			cout<<"Case #"<<i+1<<": ";
			solve();
			cout<<endl;
	}
	

	return 0;
}

