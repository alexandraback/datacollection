#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ALL(x) x.begin(),x.end()
#define TEST int t;scanf("%d",&t);while(t--)

long long tt = 10*9*8*7*6*5*4*3*2;
int tpow[5] = {1,10,100,1000,10000};

int main(int argc, char const *argv[])
{
	freopen("ins.txt","r",stdin);
	freopen("outs.txt","w",stdout);
	
	int t;
	cin >> t;
	for(int a = 1 ; a <= t ; a++){
		cout << "Case #" << a <<": ";
		string c,j;
		cin >> c >> j;
		
		int mindif = INT_MAX;
		int minc = INT_MAX;int minj = INT_MAX;
		string outc,outj,ac = c,aj = j;
		for(int i = 0 ; i < 1000000 ; i++){
			int curdif = 0,curc=0,curj=0;
			int b = i ;
			outc = c;outj=j;
			for(int kk = 0 ; kk < c.length() ; kk++)
				if(c[kk] == '?'){
					curc += (b%10)*tpow[c.length() - 1 - kk];
					b/=10;
				}
				else
					curc += (int)(c[kk]-'0')*tpow[c.length() - 1 - kk];


			for(int kk = 0 ; kk < j.length() ; kk++)
				if(j[kk] == '?'){
					curj += (b%10)*tpow[j.length() - 1 - kk];
					b/=10;
				}
				else
					curj += (int)(j[kk]-'0')*tpow[c.length() - 1 - kk];
			curdif = abs(curc - curj);
			if(curdif < mindif){
				mindif = curdif;
				minc = curc;
				minj = curj;
				ac = outc;
				aj = outj;

			}
			else if(curdif == mindif && curc < minc){
				mindif = curdif;
				minc = curc;
				minj = curj;
				ac = outc;
				aj = outj;
			}
			else if(curdif == mindif && curc == minc && curj < minj){
				mindif = curdif;
				minc = curc;
				minj = curj;
				ac = outc;
				aj = outj;
			}
		}
		for(int l = c.length()-1 ; l >=0 ; l--){
			if(minc/tpow[l] == 0)
				cout << 0;
		}
		if(minc!=0)
			cout << minc;
		cout << " ";
		for(int l = c.length()-1 ; l >=0 ; l--){
			if(minj/tpow[l] == 0)
				cout << 0;
		}
		if(minj!=0)
		cout << minj;
		cout << "\n";		
	}
	return 0;
}
