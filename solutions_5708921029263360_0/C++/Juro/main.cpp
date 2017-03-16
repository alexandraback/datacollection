/* 
 * File:   main.cpp
 * Author: juro
 *
 * Created on May 8, 2016, 12:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

/*
 * 
 */

class Outfit {
public:
    int j;
    int p;
    int s;
    int viojp;
    int viops;
    int viojs;
    
    Outfit();
    Outfit(int jj, int pp, int ss) : j(jj), p(pp), s(ss) {}
    Outfit(int jj, int pp, int ss, int vjp, int vjs, int vps) : j(jj), p(pp), s(ss), viojp(vjp), viops(vps), viojs(vjs) {}
    
    int violates() {
        return viojp + viops + viojs;
    }
    
    bool is_alike(Outfit* another) {
        if (((this->j == another->j) && (this->p == another->p)) ||
           ((this->j == another->j) && (this->s == another->s)) ||
           ((this->p == another->p) && (this->s == another->s))) return true;
        return false;
    }
    
    void rem_match(Outfit* another) {
        if ((this->j == another->j) && (this->p == another->p)) this->viojp--;
        if ((this->j == another->j) && (this->s == another->s)) this->viojs--;
        if ((this->p == another->p) && (this->s == another->s)) this->viops--;
    }
    
    bool violates_over(int k) {
        return (viojp > k) || (viops > k) || (viojs > k);
    }
    
    string to_string() {
        return std::to_string(this->j) + " " + std::to_string(this->p) + " " + std::to_string(this->s);
    }
};

Outfit* find_max(set<Outfit*> &violators) {
    int maxv = -1;
    Outfit* ofit = NULL;
//    cout << "start " << endl;
    for (Outfit* o : violators) {
        if (o->violates() > maxv) {
            maxv = o->violates();
            ofit = o;
        }
    }
    return ofit;
}

void remove_outfit(set<Outfit*> &outfits, Outfit* ofit) {
    for (Outfit* o : outfits) {
        if (ofit == o) continue;
        o->rem_match(ofit);
    }
    outfits.erase(ofit);
}

void check_violators(set<Outfit*> &violators, int k) {
    set<Outfit*> to_remove;
    for (Outfit* o : violators) {
        if (!o->violates_over(k)) to_remove.insert(o);
    }
    for (Outfit* o: to_remove) {
        violators.erase(o);
    }
}

int main(int argc, char** argv) {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        set<Outfit*> outfits;
        set<Outfit*> violators;
        int j, p, s, k;
        cin >> j >> p >> s >> k;
        for (int jj = 1; jj <= j; jj++) {
            for (int pp = 1; pp <= p; pp++) {
                for (int ss = 1; ss <= s; ss++) {
                    Outfit* ofit = new Outfit(jj, pp, ss, s, p, j);
                    if (ofit->violates_over(k)) {
                        violators.insert(ofit);
                    }
                    outfits.insert(ofit);
                }
            }
        }
//        cout << " IN " << j << " " << p << " " << s << " " << k << endl;
        while(violators.size() > 0) {
            Outfit* vio = find_max(violators);
//            cout << " MAX " << vio->violates() << endl;
            remove_outfit(outfits, vio);
            check_violators(violators, k);
            violators.erase(vio);
        }
        printf("Case #%d: %lu\n", i+1, outfits.size());
        for (Outfit* o : outfits) {
            cout << o->to_string() << endl;
        }
    }
    
    return 0;
}

