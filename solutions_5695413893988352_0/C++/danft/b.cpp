#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<bool> vb;
const int INF=0x3f3f3f3f;

string a, b;

int ra, rb, rra, rrb;
int ansx;

void f2(int u) {
    if(u==b.size()) {
        //cout<<ra<<" "<<rb<<"@\n";
        if(abs(ra-rb)<ansx) {
            ansx=abs(ra-rb);
            rra=ra;
            rrb=rb;
        }
        else if(abs(ra-rb)==ansx) {
            if(ra<rra) {
                rra=ra;
                rrb=rb;
            }
            else if(ra==rra && rb<rrb) {
                rra=ra;
                rrb=rb;
            }
        }
        return ;
    }
    if(b[u]!='?') {
        rb*=10;
        rb+=b[u]-'0';
        f2(u+1);
        rb/=10;
        return ;
    }
    for(int j=0;j<10;j++) {
        rb*=10;
        rb+=j;
        f2(u+1);
        rb/=10;
    }

}

void f(int u) {
    if(u==a.size()) {
        f2(0);
        return ;
    }
    if(a[u]!='?') {
        ra*=10;
        ra+=a[u]-'0';
        f(u+1);
        ra/=10;
        return ;
    }
    //cout<<a[u]<<"!!\n";
    for(int j=0;j<10;j++) {
        ra*=10;
        ra+=j;
        //cout<<ra<<"#\n";
        f(u+1);
        ra/=10;
    }
}


int main(void) {
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    For(tt, 0, T) {
        cin>>a>>b;
        ansx=INF;
        rra=rrb=ra=rb=0;
        f(0);
    
        cout<<"Case #"<<tt+1<<": ";
        cout<<setfill('0')<<setw(a.size())<<rra;
        cout<<' ';
        cout<<setfill('0')<<setw(a.size())<<rrb;
        cout<<endl;
    }
	
	
	return 0;
}
