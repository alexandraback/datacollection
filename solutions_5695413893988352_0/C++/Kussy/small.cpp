#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;

int c, j;
int m;
string C, J;
priority_queue< pair< int, pair< int, int> > > Q;

int prec(int x) {
    int t=0;
    while(x>0) {
        x/=10;
        t++;
    }
    return t;
}

void check(vector<int> &V) {
    int cx=0, jx=0;
    int cp=0, jp=c;
    int d=1;
    for(int i=C.length()-1; i>=0; i--)
    {
        if(C[i]=='?') {
            cx+=d*V[cp];
            cp++;
        } else {
            cx+=(C[i]-'0')*d;
        }
        d*=10;
    }
    d=1;
    for(int i=J.length()-1; i>=0; i--)
    {
        if(J[i]=='?') {
            jx+=d*V[jp];
            jp++;
        } else {
            jx+=(J[i]-'0')*d;
        }
        d*=10;
    }
    int a = max(cx,jx) - min (cx, jx);
  //  cout<<" "<<a<<endl;
    if(a <= m) {
        m = a;
        pair<int, int> S (-cx, -jx);
        pair<int, pair<int, int> > P (-a, S);
        Q.push(P);
    }

}

void get(int l, vector<int> &V) {
    if(l == 0) {
        check(V);
        return;
    }
    for(int i=0; i<10; i++) {
        V.push_back(i);
        get(l-1, V);
        V.pop_back();
    }
}

int main() {
      int T;
    cin>>T;
    for(int tt=1; tt<=T; tt++) {
        cin>>C>>J;
        c=j=0;
        m = 999999;
        int L = C.length();
        vector<int> V;
        for(int i=0; i<C.length(); i++)
        {
            if(C[i] == '?') c++;
            if(J[i] == '?') j++;
        }
        get(c+j, V);

        cout<<"Case #"<<tt<<": ";
        //cout<<Q.top().first<<" ";
        int A = Q.top().second.first*(-1);
        int p = L - prec(A);
        while(p-- > 0) cout<<0;
        if( A!= 0) cout<<A;
        cout<<" ";
        int B = Q.top().second.second*(-1);
        p = L - prec(B);
        while(p-- > 0) cout<<0;
        if(B!=0) cout<<B;
        //cout<<Q.top().second.first*(-1)<<" "<<Q.top().second.second*(-1);
        cout<<endl;

        V.clear();
        while(!Q.empty())
            Q.pop();
    }
    return 0;

}
