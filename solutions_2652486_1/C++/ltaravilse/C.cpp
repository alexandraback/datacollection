#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()

using namespace std;

int R,N,M,K;

int cuantos[10];

int calcMax(vector<long long> vec, int t)
{
    int res = 0;
    forn(i,vec.size())
    {
        int aux = 0;
        while(vec[i]%t==0)
        {
            aux++;
            vec[i]/=t;
        }
        res = max(res,aux);
    }
    return res;
}

int main()
{
	#ifdef ACMTUYO
	freopen("C-small2.in","r",stdin);
	freopen("C2.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	cout << "Case #1:"<< endl;
	cin >> R >> N >> M >> K;
	forn(i,R)
	{
	    vector<long long> vec(K);
	    forn(j,K)
            cin >> vec[j];
        forn(j,10)
            cuantos[j] = 0;
        cuantos[5] = calcMax(vec,5);
        cuantos[7] = calcMax(vec,7);
        cuantos[6] = max(calcMax(vec,6)-1,0);
        cuantos[3] = max(calcMax(vec,3)-1,0);
        int r = N-cuantos[5]-cuantos[7]-cuantos[6]-cuantos[3];
        int potDos = calcMax(vec,2)+1;
        while(r>0)
        {
            int aux = r;
            if(potDos>1)
            {
                cuantos[2]++;
                r--;
                potDos--;
            }
            if(potDos>2)
            {
                cuantos[4]++;
                r--;
                potDos-=2;
            }
            if(potDos>3)
            {
                cuantos[8]++;
                r--;
                potDos-=3;
            }
            if(aux==r)
                break;
        }
        while(cuantos[2]+cuantos[3]+cuantos[4]+cuantos[5]+cuantos[6]+cuantos[7]+cuantos[8]<N)
            cuantos[2]++;
        while(cuantos[2]+cuantos[3]+cuantos[4]+cuantos[5]+cuantos[6]+cuantos[7]+cuantos[8]>=N)
        {
            if(cuantos[2]>0)
                cuantos[2]--;
            else if(cuantos[4]>0)
                cuantos[4]--;
            else if(cuantos[8]>0)
                cuantos[8]--;
            else if(cuantos[3]>0)
                cuantos[3]--;
            else if(cuantos[6]>0)
                cuantos[6]--;
            else if(cuantos[5]>0)
                cuantos[5]--;
            else if(cuantos[7]>0)
                cuantos[7]--;
        }
        forn(t,10)
        forn(j,cuantos[t])
            cout << t;
        cout << endl;
	}
}
