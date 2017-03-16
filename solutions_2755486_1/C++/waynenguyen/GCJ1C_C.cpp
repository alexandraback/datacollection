#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DR(i,a) for(int i = (a)-1; i >=0; i--)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define sqr(x) ((x)*(x))
#define oo 1000000009
using namespace std;

struct Attack {
    long long L, R, D, S;
    Attack() {}
    Attack(long long L, long long R, long long D, long long S): L(L),R(R),D(D),S(S) {}
};
vector< Attack > attack_list;
int nTribe;
vector<long long> ds_node;
long long Tree[25000400], Sign[25000400];

bool cmp(Attack A, Attack B) {
    return (A.D < B.D);
}
void modify(int node, long long value) {
    Sign[node] = max(Sign[node],value);
    Tree[node] = max(Tree[node],value);
}
long long get_value(int node, int first, int last, int dau, int cuoi) {
    if (cuoi < first || last < dau) return oo;
    if (dau <= first && last <= cuoi) return Tree[node];
    if (Sign[node]) {
        modify(node*2, Sign[node]);
        modify(node*2+1,Sign[node]);
        Sign[node] = 0;
    }
    int mid = (first + last) / 2;
    long long val = min(get_value(node*2,first,mid,dau,cuoi),
                        get_value(node*2+1,mid+1,last,dau,cuoi));
    Tree[node] = min(Tree[node*2],Tree[node*2+1]);
    return val;
}
void set_value(int node, int first, int last, int dau, int cuoi, long long Strength) {
    if (cuoi < first || last < dau) return;
    if (dau <= first && last <= cuoi) {
        Sign[node] = max(Sign[node], Strength);
        Tree[node] = max(Tree[node], Strength);
        return;
    }

    if (Sign[node]) {
        modify(node*2, Sign[node]);
        modify(node*2+1,Sign[node]);
        Sign[node] = 0;
    }
    int mid = (first + last) / 2;
    set_value(node*2,first,mid,dau,cuoi,Strength);
    set_value(node*2+1,mid+1,last,dau,cuoi,Strength);
    Tree[node] = min(Tree[node*2],Tree[node*2+1]);
}
void solve() {
    sort(attack_list.begin(), attack_list.end(),cmp);
    ds_node.clear();
    FR(i,attack_list.size()) {
        ds_node.push_back(attack_list[i].L);
        ds_node.push_back(attack_list[i].R);
        ds_node.push_back(attack_list[i].L+1);
        ds_node.push_back(attack_list[i].R+1);
        ds_node.push_back(attack_list[i].L-1);
        ds_node.push_back(attack_list[i].R-1);
    }
    sort(ds_node.begin(),ds_node.end());

    ds_node.resize( unique(ds_node.begin(), ds_node.end()) - ds_node.begin());
    int M = ds_node.size();

    FR(i,attack_list.size()) {
        attack_list[i].L = lower_bound(ds_node.begin(),ds_node.end(), attack_list[i].L) - ds_node.begin() + 1;
        attack_list[i].R = lower_bound(ds_node.begin(),ds_node.end(), attack_list[i].R) - ds_node.begin() + 1;
    }
    memset(Tree,0,sizeof(Tree));
    memset(Sign,0,sizeof(Sign));
    long long res = 0;
    int cur_attack = 0, next_attack, cur_day;


    /***********TESTING*************/
    /*
    cout << "TESTING" << endl;
    FR(i,ds_node.size()) cout << ds_node[i] << " ";
    cout << endl;
    FR(i,attack_list.size()) cout << attack_list[i].L << " " << attack_list[i].R << " " << attack_list[i].D << " " << attack_list[i].R << endl;
*/
    /*****************************/
    while (cur_attack < attack_list.size()) {
        cur_day = attack_list[cur_attack].D;
        next_attack = cur_attack + 1;
        while (next_attack < attack_list.size() && attack_list[next_attack].D == cur_day) next_attack++;

        FOR(i,cur_attack,next_attack-1) {
            long long Strength = get_value(1,1,M, attack_list[i].L, attack_list[i].R);
            if (Strength < attack_list[i].S) res++;
        }

        FOR(i,cur_attack,next_attack-1) {
            long long Strength = get_value(1,1,M, attack_list[i].L, attack_list[i].R);
            if (Strength < attack_list[i].S) {
                set_value(1,1,M, attack_list[i].L, attack_list[i].R, attack_list[i].S);
            }

                set_value(1,1,M, attack_list[i].L, attack_list[i].R, attack_list[i].S);
        }
        cur_attack = next_attack;
    }
    cout << res << endl;
}
int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> nTribe;
        long long si,di,wi,ei,delta_d,delta_p,delta_s,nAttack;
        attack_list.clear();
        FOR(i,1,nTribe) {
            cin >> di >> nAttack >> wi >> ei >> si >> delta_d >> delta_p >> delta_s;
            FOR(j,1,nAttack) {
                attack_list.push_back(
                                      Attack(wi,ei-1,di,si)
                                      );
                wi += delta_p;
                ei += delta_p;
                di += delta_d;
                si += delta_s;
            }
        }
        solve();
    }
    return 0;
}
