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

vector<pair<int,int> > vec;
vector<int> niveles;
int res,parcial;

int main()
{
    #ifdef ACMTUYO
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
    #endif
    int casos;
    cin >> casos;
    for(int casito=1;casito<=casos;casito++)
    {
        cout << "Case #" << casito << ": ";
        int n;
        cin >> n;
        vec.resize(3*n);
        forn(i,n)
        {
            cin >> vec[3*i+1].first >> vec[3*i].first;
            vec[3*i+2].first = vec[3*i].first;
            vec[3*i].second = 0;
            vec[3*i+2].second = 3;
            vec[3*i+1].second = 1;
            if(vec[3*i+1].first>=vec[3*i].first)
                vec[3*i+1].first = 3200;
        }
        forn(i,3*n)
            vec[i].first = vec[i].first*3100+i;
        sort(all(vec));
        forn(i,3*n)
            vec[i].first /= 3100;
        //forn(i,vec.size())
        //cerr << vec[i].first << " "<< vec[i].second << endl;
        forn(i,vec.size())
        if(vec[i].second==3)
            vec[i].second = 0;
        else if(vec[i].second==0)
            vec[i].second = 2;
        vector<pair<int,int> > vec2;
        forn(i,vec.size())
        if(vec[i].second==2)
            vec2.push_back(make_pair(i,vec[i].first));
        int res = 3*n,ahorro=0;
        bool b = false;
        forn(i,vec2.size())
        if(vec2[i].first<vec2[i].second)
        {
            cout << "Too bad"<< endl;
            b = true;
            break;
        }
        if(b==false)
        forn(i,vec2.size())
        {
            //cerr << ahorro << " ";
            if(i==0)
            {
                ahorro = max(0,(vec2[i].first-vec2[i].second));
            }
            else
            {
                ahorro += max(vec2[i].first-vec2[i-1].first-2-max(vec2[i].second-2*i-vec2[i-1].second,0),0);
                //cerr << vec2[i].first - vec2[i-1].first - 2 << " "<< vec2[i].second-2-vec2[i-1].second << " "<< ahorro <<  endl;
            }
            res = vec2[i].first+1;
        }
        //cerr << res << " ";
        res -= n-1;
        //cerr << res << " "<< ahorro << endl;
        res-=ahorro;
        if(b==false)
            cout << res <<endl;
    }
    return 0;
}
