#define __STDC_LIMIT_MACROS
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <list>
#include <time.h>
#include <bitset>
#include <algorithm>
#include <stdint.h>
#include <limits.h>
#include <iomanip>
#include <set>
#include <deque>

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define REP(i,n) rep(i,0,n)
#define getInt(i) int i;scanf("%d",&i)
#define getDouble(i) double i;scanf("%lf",&i)
#define getUll(i) ull i;scanf("%llu",&i)
#define getLl(i) ll i;scanf("%lld",&i)
#define getChar(c) char c; scanf("%c", &c);
#define getString(s) std::string s;std::getline(cin, s);
#define getWord(w) char w[100]; scanf("%s",w);
#define newLine(tmp) std::getline(cin, tmp);
#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
#define __STDC_LIMIT_MACROS

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<int> VI;

int mod = 1000000007;

//Use this one if mod is an int
int mult_mod(ull a, ull b){
    return (a*b)%mod;
}

int pow_mod(ull a, ull x)
{
  int r=1;

  while ( x ) {
    if ( (x & 1) == 1 ){
       r = mult_mod(a,r);
    }

    x >>= 1;
    a = mult_mod(a,a);
  }

  return r;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ull fact[1500];
    fact[0]=1;
    for(int i=1;i<1000;i++)fact[i]=(fact[i-1]*1LL*i)%mod;
    int ans =0;
    getInt(T);
    REP(tt,T){
        getInt(N);
        vector<string> cars;
        getString(TTT);
        REP(i,N){
            getWord(line);
            cars.push_back(line);
        }

        int ans=1;
        REP(i,26){
            char c = i+97;
            vector<string> starts;
            vector<string> ends;
            vector<string> mids;
            int sx;
            int ex;
            bool justmid = false;
            REP(j,cars.size()){
                if(cars[j][0]==c) {
                    starts.push_back(cars[j]);
                    sx=j;
                }
                if(cars[j][cars[j].size()-1]==c) {
                    ends.push_back(cars[j]);
                    ex=j;
                }
                bool ismid = true;
                REP(k,cars[j].size()){
                    if(cars[j][k]!=c) ismid = false;
                    else if(!justmid && !ismid){
                        rep(mmm,k+1,cars[j].size()){
                            if(cars[j][mmm]!=c) justmid=true;
                        }
                    }
                }
                if(ismid) {
                    mids.push_back(cars[j]);
                    starts.pop_back();
                    ends.pop_back();
                }
                else if(cars[j][0]==c && cars[j][cars[j].size()-1]==c) ans=0;
            }
            if(starts.size()>1 || ends.size()>1) ans=0;
            else if(justmid && (starts.size()>0 || ends.size()>0)) ans=0;
            else if(mids.size()==0){
                if(starts.size()==1 && ends.size()==1){
                    string nw = ends[0] + starts[0];
                    vector<string>::iterator it = cars.begin();
                    while(it != cars.end())
                    {
                        string cr = *it;
                        if(cr == starts[0] || cr == ends[0])
                        {
                            it = cars.erase(it);
                        }
                        else
                        {
                            ++it;
                        }
                    }
                    cars.push_back(nw);
                }
            }
            else if(mids.size()>0){
                //merge
                string nw = ends.size()>0 ? ends[0] : "";
                REP(mm, mids.size()){
                    nw += mids[mm];
                    vector<string>::iterator it = cars.begin();
                    while(it != cars.end())
                    {
                        string cr = *it;
                        if(cr == mids[mm])
                        {
                            it = cars.erase(it);
                            break;
                        }
                        ++it;
                    }
                }
                nw+= starts.size() >0 ? starts[0] : "";
                vector<string>::iterator it = cars.begin();
                while(it != cars.end())
                {
                    string cr = *it;
                    if((starts.size()>0 &&cr == starts[0]) || (ends.size() >0&&cr == ends[0]))
                    {
                        it = cars.erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }

                cars.push_back(nw);
                ans = mult_mod(ans, fact[mids.size()]);
            }
        }

        cout << "Case #" << (tt+1) << ": ";
        if(ans==0) cout << ans;
        else{
            //check cars
            map<char,int> test;
            REP(i,cars.size()){
                char st = cars[i][0];
                if(test[st]>0) ans=0;
                else test[st]++;
                rep(j,1,cars[i].size()){
                    if(cars[i][j]!=st){
                        st = cars[i][j];
                        if(test[st]>0) ans=0;
                        else test[st]++;
                    }
                }
            }


            ans = mult_mod(ans, fact[cars.size()]);
            cout << ans;
        }

        cout << '\n';
    }
    return 0;
}
