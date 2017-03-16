#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct Node{
    int v, add;
    Node* lc, *rc;
    int l, r;

    Node(int l, int r){
        this->l = l;
        this->r = r;
        this->v = 0;
        this->add = 0;
        if (l < r){
            int mid = (l + r) >> 1;
            lc = new Node(l, mid);
            rc = new Node(mid + 1, r);
        } else lc = rc = 0;
    }

    bool push(){
        if (lc){
            lc->add = max(lc->add, add);
            rc->add = max(rc->add, add);
            v = max(v, add);
            return true;
        } else {
            v = max(v, add);
            return false;
        }
    }

    void update(){
        if (push())
        v = min(lc->v, rc->v);
    }

    int ask(int l, int r){
        push();
        if (l == this->l && r == this->r){
            return this->v;
        }
        int mid = (this->l + this->r) >> 1;
        if (l <= mid && r > mid){
            return min(lc->ask(l, mid), rc->ask(mid + 1, r));
        } else if (l <= mid)
            return lc->ask(l, r);
        else return rc->ask(l, r);
    }

    void modify(int l, int r, int v){
        push();
        if (l == this->l && r == this->r){
            this->add = max(v, add);
            return;
        }
        int mid = (this->l + this->r) >> 1;
        if (l <= mid && r > mid){
            lc->modify(l, mid, v);
            rc->modify(mid + 1, r, v);
        } else if (l <= mid)
            lc->modify(l, r, v);
        else rc->modify(l, r, v);
        this->update();
    }
} *tr;


struct attack {
    int day, l, r, power;
    attack(int a, int b, int c, int d){
        day = a; l = b; r = c; power = d;
    }


    bool operator < (attack r) const {
        return day < r.day;
    }

    void print() {
        printf("day: %d ; %d-%d ; power: %d\n", day, l, r, power);

    }
};
vector<attack> data;
int n; 

void init() {
    data.clear();
    tr = new Node(-1000000, 100000);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int day, num, w, e, power, dday, dp, dpower;
        scanf("%d%d%d%d%d%d%d%d", &day, &num, &w, &e, &power, &dday, &dp, &dpower);
        for (int j = 0; j < num; j++) {
            data.push_back(attack(day + dday * j, w + dp * j, e + dp * j - 1, power + dpower * j));
        }
    }
    sort(data.begin(), data.end());
    //for (int i = 0; i < data.size(); i++) data[i].print();
}
int a[100000], *t = a;

int ask(int l, int r) {
  int ans = 19931008;
  for (int i = l; i <= r; i++) ans = min(ans, t[i]);
  return ans;
}

void modify(int l, int r, int p) {
  for (int i = l; i <= r; i++) t[i] = max(t[i], p);
  
}

void solve() {
    int ans = 0, i, j;
    t = t + 500;
    for (i = 0; i < (int)data.size(); i = j) {
        for (j = i; data[j].day == data[i].day; j++) {
            int t = ask(data[j].l, data[j].r);
            //data[j].print();
            //printf("%d\n", t);
            if (t < data[j].power)
                ans++;
        }
        for (j = i; data[j].day == data[i].day; j++) 
            modify(data[j].l, data[j].r, data[j].power);
    }
    cout << ans << endl;

}

/*
void solve() {
    int ans = 0;
    int i, j;
    for (i = 0; i < (int)data.size(); i = j) {
        for (j = i; data[j].day == data[i].day; j++) {
            int t = tr->ask(data[j].l, data[j].r);
            data[j].print();
            printf("%d\n", t);
            if (t < data[j].power)
                ans++;
        }
        for (j = i; data[j].day == data[i].day; j++) 
            tr->modify(data[j].l, data[j].r, data[j].power);
    }
    cout << ans << endl;
}
*/
int main() {
//    freopen("data.in","r",stdin);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        init();
        printf("Case #%d: ", i);
        solve();
    }

}

