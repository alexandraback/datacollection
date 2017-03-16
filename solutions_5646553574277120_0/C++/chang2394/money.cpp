#include <bits/stdc++.h>
#define  each(v,c)  for(typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define  sync(x)    ios_base::sync_with_stdio(x)
#define  pb         push_back
#define  mp         make_pair
#define  sz(a)      ((int)(a.size()))
#define  all(a)     (a).begin(), (a).end()
#define  fi         first
#define  se         second

using namespace std;

#define debug(a,n)    cerr << "["; for(int i = 0; i < n; ++i) cerr << a[i] << " ";cerr << "\b]\n";
#define dbg(args...)  {debug1,args; cerr<<endl;}
#define pause()       cin.get();cin.get();

struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<" "; return *this;
    }
} debug1;

template <typename T1, typename T2>
inline ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
inline ostream &operator << (ostream & os,const vector<T>& v) {
    bool first = true; os << "[";
    for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii; first = false;
    }
    return os << "]";
}

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;

void solve(int tc){
    int c,d,v,num;
    cin >> c >> d >> v;

    set<int> ss;
    int temp = 1000;
    for(int i = 0; i < d; ++i){
        cin >> num;
        ss.insert(num);
        if ((num + num-1) >= v)
            temp = min(num,temp);
    }

    if (temp != 1000) 
        v = temp-1;

    int x = 1, sum = 0;
    int cnt = 0;
    while(sum < v){
        sum += x;
        cnt += (ss.find(x) != ss.end());
        x++;
    }

    int ans = x-1-cnt;
    cout << "Case #" << tc << ": " << ans << endl; 
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i)
        solve(i);
    return 0;    
}
