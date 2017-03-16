#include <cstdio>
#include <bitset>
#include <set>
#include <cassert>

#define D if(0)


using namespace std;

int n;
int a[1024], b[1024];
int ms = 0; //, star;

struct St {
    // level, a, b
    set<int> as;
    set<int> bs;
    mutable int lastc;
    int star() const { 
        if (lastc >= 0) return lastc;
        int r = bs.size() * 2; 
        for(int i : as) {
            if (bs.count(i) == 0) r++;
        }

        lastc = r;
        return r;
    }
    // < are better
    bool operator < (const St& rhs) const {
        // assert(star() == rhs.star());
        if (as.size() < rhs.as.size()) return true;
        if (as.size() > rhs.as.size()) return false;

        if (bs.size() < rhs.bs.size()) return true;
        if (bs.size() > rhs.bs.size()) return false;

        if (as < rhs.as) return true;
        if (as > rhs.as) return false;
        if (bs < rhs.bs) return true;
        if (bs > rhs.bs) return false;

        return false;
    }
    void comp(int i, int isa) {
        if (isa) {
            as.insert(i);
            lastc = -1;
        } else {
            bs.insert(i);
            lastc = -1;
        }
    }
    int steps() const {
        return as.size() + bs.size();
    }
    bool fin()  const {
        return (int)bs.size() == ::n;
    }

    void p() const {
        for (int i: as) printf("%d", i) ;
        printf(" | ");
        for (int i: bs) printf("%d", i) ;

    }
};

set<St> sts[5000];
set<St> psts;

int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ++ti) {
       printf("Case #%d: ", ti); 
       D printf("\n");
       scanf("%d", &n);
       ms = 0;
       for (int i = 0; i < n; ++i) {
           scanf("%d%d", a+i, b+i);
           if (a[i] > ms) ms=a[i];
           if (b[i] > ms) ms=b[i];
       }

       for (int i = 0; i < (int) (sizeof(sts) / sizeof(sts[0])); ++i) {
           sts[i].clear();
       }
       psts.clear();
       int res = 100000;

       sts[0].insert(St());
       D printf("ms = %d\n", ms);
       ms += 2;
       for (int star = 0; star <= ms; ++star) {
           if (sts[star].size() == 0) continue;
           D {
               printf("star = %d\n", star);
           }
           // int mas = sts[star].begin()->as.size();
           for(size_t c = 0; c != sts[star].size(); ) {
               c =  sts[star].size();

               for (const auto& ost : sts[star]) {
                   if (psts.count(ost)) continue;
                   psts.insert(ost);
                   // if (ost.as.size() > mas) break;

                   D {
                       ost.p();
                       printf("\n");
                   }
                   for (int i = 0; i < n; ++i) {
                       if (star >= b[i] && ost.bs.count(i) == 0) {
                           St st = ost;
                           st.comp(i, 0);
                           if (st.fin() && st.steps() < res) res = st.steps();
                           sts[st.star()].insert(st);
                       } else if (star >= a[i] && ost.as.count(i) == 0 && ost.bs.count(i) == 0) {
                           // complete A
                           St st = ost;
                           st.comp(i, 1);
                           sts[st.star()].insert(st);
                       }
                   }
               }
           }
       }
       if (res >= 100000) {
           puts("Too Bad");
       } else printf("%d\n", res);
    }

    return 0;
}

       /*
       pst.clear();
       // init 0 score
       s[0].insert(St());

       for (int running = 1; (running & 1) || (running && res >= 100000); ) {
           running = 0;
           for (star = 0; star <= ms; ++star) {
               for (const St& old_st : s[star]) {
                   if (old_st.complete()) continue;
                   
                   int isas = 1;
                   if (old_st.proced()) {
                       isas = 2;
                   } else {
                       pst.insert(old_st);
                       assert(old_st.proced());
                   }

                   St st = old_st;
                   D {
                       printf("S: %d  ", star);
                       st.print();
                       printf(" %c\n", st.complete() ? 'C' : ' ');
                   }
                   for (int i = 0; i < n; ++i) {
                       for (int isa = isas; isa <= 2; ++isa) {
                           if (isa == 1 && star < ::a[i]) continue; 
                           if (isa == 2 && star < ::b[i]) continue; 
                           int x = st.bonus(i, isa);
                           if (isas == 2 && x == 2) continue;
                           if (x > 0) {
                               St new_st = st;
                               new_st.finish(i, isa); 
                               if (new_st.complete()) {
                                   if (new_st.steps() < res) res = new_st.steps();
                               }
                               D {
                                   printf("  N: %3d+%d  ", star, x);
                                   new_st.print();
                                   printf(" %c\n", new_st.complete() ? 'C' : ' ');
                               }
                               s[star+x].insert(new_st);
                               if (isas == 2) running |= 2;
                               else if (isas == 1) running |= 1;
                           }
                       }
                   } // for i n
               }
           }
       } // running

struct St;
set<St> pst;


struct St {
    bitset<2048> s;
    int c1, c2;
    St() : s(0), c1(0), c2(0) {}
    bool proced() const {
        if (::pst.count(*this)) return 1;
        return 0;
    }
    bool complete() const { return c2 >= n; }
    int bonus(int i, int a = 1) {
        if (a == 1) {
            return (s.test(i) || s.test(1024+i)) ? 0 : 1; 
        } else {
            if (s.test(1024+i)) return 0;
            if (s.test(i)) return 1; else return 2;
        }
    }
    void finish(int i, int a = 1) {
        if (a== 1) {
            if (s.test(i)) return; s.set(i); ++c1;
        } else {
            if (s.test(1024+i)) return; s.set(1024+i); ++c2; 
        }
    }
    int steps() { return c1 + c2; }

    bool operator <(const St& rhs) const {
        if (c1 < rhs.c1) return 1;
        else if (c1 > rhs.c1) return 0;

        if (c2 < rhs.c2) return 1;
        else if (c2 > rhs.c2) return 0;

        for (int i = 0; i < ::n; ++i) {
            if (s.test(i)) {
                if (!rhs.s.test(i)) return 0;
            } else if (rhs.s.test(i)) return 1;
            if (s.test(i+1024)) {
                if (!rhs.s.test(i+1024)) return 0;
            } else if (rhs.s.test(i+1024)) return 1;
        }
        return 0;
    }
    // bool operator ==(const St& rhs) const {
    //     if (c1 != rhs.c1) return 0;
    //     if (c2 != rhs.c2) return 0;

    //     for (int i = 0; i < ::n; ++i) {
    //         if ((s.test(i)) ^ (rhs.s.test(i)) ) return 0;
    //         // if ((s.test(i+1024)) ^ (rhs.s.test(i+1024)) ) return 0;
    //     }
    //     return 1;
    // }
    void print() {
        for (int i = 0; i < n; ++i) {
            int x = 0;
            if (s.test(i)) x |= 1;
            if (s.test(i+1024)) x |= 2;
            printf("%d", x);
        }
        printf("  [%d,%d]", c1, c2);
    }
};

set<St> s[7000];

       */

