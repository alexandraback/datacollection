#include <cstdio>
#include <vector>

using namespace std;

const int tab[5][5] = 
{//	 0 1 i j k
	{0,0,0,0,0},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1}
};

struct q {
	int v;
	
	q(int _v): v(_v) {}
	q() {}
	
	void operator*=(const q& a) {
		int i1 = v<0?-v:v;
		int i2 = a.v<0?-a.v:a.v;
		
		v = (v*a.v)<0?-tab[i1][i2]:tab[i1][i2];
	}
};

char in[11000];

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		
		long long L,X;
		scanf("%lld %lld", &L, &X);
		
		vector<q> st;
		
		q seg(1);
		
		for(int i = 0; i < L; i++) {
			char c;
			scanf(" %c", &c);
			q nu((int)c-'i'+2);
			st.push_back(nu);
			seg*=nu;
		}
		
		q ans(1);
		
		bool i_found = false;
		bool k_found = false;
		
		int l = 0;
		int count = 0;
		
		while(count < 8 && count < X) {
			
			ans*=st[l];
			if(ans.v == 2) i_found = true;
			if(i_found && ans.v == 4) k_found = true;
			
			l++;
			if(l == L) {
				l = 0;
				count++;
			}
		}
		
		long long u = X%4;
		
		q pot(1);
		while(u--) {
			pot*=seg;
		}
		
		if(pot.v == -1 && i_found && k_found) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}

/*
i2=j2=k2=-1

ij = k
ji = -k
jk = i
kj = -i
ki = j
ik = -j
*/

