#include <iostream>
#include <set>
#include <map>
#include <sstream>
using namespace std;

int toi(const string &s,int st) {
    int ret = 0;
    for(int i=0; i<s.length(); ++i) {
        ret += s[(i+st)%((int)s.length())] - '0';
        if(i < s.length()-1) ret *= 10;
    }
    return ret;
}

int main() {
    int t,a,b;
    cin>>t;

    for(int tc=1; tc<=t; ++tc) {
        cin>>a>>b;

        set<pair<int,int> > h;
        for(int k=a; k<=b; ++k) {
            stringstream ss;
            ss << k;
            string s = ss.str();

            for(int i=1; i<s.length(); ++i) {
                int l = toi(s,i);

                if(l <= b && l > k)
                    h.insert(make_pair(k,l));
            }
        }

        cout<<"Case #"<<tc<<": "<<h.size()<<endl;
    }
}
