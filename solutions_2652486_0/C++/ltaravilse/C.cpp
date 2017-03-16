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

bool calc(vector<int> vec, int t)
{
    forn(i,vec.size())
    if(vec[i]%t==0)
        return true;
    return false;
}

int main()
{
	#ifdef ACMTUYO
	freopen("C-small1.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	cout << "Case #1:"<< endl;
	cin >> R >> N >> M >> K;
	forn(i,R)
	{
	    vector<int> vec(K);
	    forn(j,K)
            cin >> vec[j];
        forn(j,10)
            cuantos[j] = 0;
        forn(j,K)
        {
            if(vec[j]%125==0)
                cuantos[5] = 3;
            else if(vec[j]%25==0)
                cuantos[5] = 2;
            else if(vec[j]%5==0)
                cuantos[5] = 1;
            if(vec[j]%27==0)
                cuantos[3] = 3;
            else if(vec[j]%9==0&&!calc(vec,27))
                cuantos[3] = 2;
            else if(vec[j]%3==0&&!calc(vec,9))
                cuantos[3] = 1;
            if(vec[j]%64==0)
                cuantos[4] = 3;
            else if(vec[j]%32==0&&!calc(vec,64))
            {
                cuantos[4] = 2;
                cuantos[2] = 1;
            }
            else if(vec[j]%16==0&&!calc(vec,32))
            {
                if(cuantos[5]+cuantos[3]==0)
                {
                    cuantos[2] = 2;
                    cuantos[4] = 1;
                }
                else
                    cuantos[4] = 2;
            }
            else if(vec[j]%8==0&&!calc(vec,16))
            {
                if(cuantos[5]+cuantos[3]==0)
                    cuantos[2] = 3;
                else
                {
                    cuantos[4] = 1;
                    cuantos[2] = 1;
                }
            }
            else if(vec[j]%4==0&&!calc(vec,8))
            {
                if(cuantos[5]+cuantos[3]<=1)
                    cuantos[2] = 2;
                else
                    cuantos[4] = 1;
            }
            else if(vec[j]%2==0&&!calc(vec,4))
            {
                cuantos[2] = 1;
            }
        }
        while(cuantos[2]+cuantos[3]+cuantos[4]+cuantos[5]<3)
            cuantos[2]++;
        while(cuantos[2]+cuantos[3]+cuantos[4]+cuantos[5]>3)
        {
            if(cuantos[2]>0)
                cuantos[2]--;
            else if(cuantos[4]>0)
                cuantos[4]--;
            else if(cuantos[3]>0)
                cuantos[3]--;
            else if(cuantos[5]>0)
                cuantos[5]--;
        }
        forn(t,10)
        forn(j,cuantos[t])
            cout << t;
        cout << endl;
	}
}
