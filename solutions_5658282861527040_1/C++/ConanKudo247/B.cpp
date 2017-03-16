#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i = (a); i <= (b);i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
int A,B,K;
vector<int> a,b,k;
long long f[35][2][2][2];
void get(int nh, int a, vector<int>& pa) {
    pa.clear();
    if (nh == 1) {
        pa.push_back(0);
        pa.push_back(1);
    } else {
        FOR(i,0,a) pa.push_back(i);
    }
}

void update(int a, int lima, int nh, int &new_nh) {
    if (nh == 1) {
        new_nh = 1;
        return;
    }
    if (a == lima) new_nh = 0;
    else new_nh = 1;
}
void update(int a1,int b1,int k1,int lima, int limb, int limk, int nh1,int nh2,int nh3,int &new_nh1,int &new_nh2,int &new_nh3) {
    update(a1,lima,nh1,new_nh1);
    update(b1,limb,nh2,new_nh2);
    update(k1,limk,nh3,new_nh3);
}
long long go(int i, int nh1, int nh2, int nh3) {
    if (i == -1) return 1;
    if (f[i][nh1][nh2][nh3] != -1) return f[i][nh1][nh2][nh3];
    long long &res = f[i][nh1][nh2][nh3];
    res = 0;
    vector<int> pa;
    vector<int> pb;
    get(nh1,a[i],pa);
    get(nh2,b[i],pb);
    
    FR(i1,pa.size())
    FR(j1,pb.size()) {
        int a1 = pa[i1], b1 = pb[j1];
        int k1 = a1 & b1;
        if (nh3 == 1) {
            //ok anything
        } else {
            if (k1 > k[i]) continue;
        }
        int new_nh1,new_nh2,new_nh3;
        update(a1,b1,k1,a[i],b[i],k[i],nh1,nh2,nh3,new_nh1,new_nh2,new_nh3);
        res += go(i-1,new_nh1,new_nh2,new_nh3);
    }
    return res;
}
int main() 
{
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> A >> B >> K;
        A--, B--, K--;
        a.clear();
        b.clear();
        k.clear();
        FR(i,35) {
            a.push_back(A % 2); A /= 2;
            b.push_back(B % 2); B /= 2;
            k.push_back(K % 2); K /= 2;
        }
        memset(f,-1,sizeof(f));
        cout << go(34,0,0,0) << endl;
        
    }
    return 0;
}
