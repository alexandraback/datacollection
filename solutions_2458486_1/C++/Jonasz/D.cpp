#define debug if(0)
#include<cstdio>
#include<ctime>
#include<cassert>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

struct Chest{
    int type;
    int id;
    vector<int>keys;
    Chest(){}
    explicit Chest(int type_, int id_):type(type_),id(id_) {
        //printf("type %d, id %d\n", type, id);
        assert(id!=-1);
    }
    void add_key(int k){
        keys.push_back(k);
    }
};

void input(multiset<int>&keys, map<int, Chest>&chests){
    int k,n; scanf("%d %d", &k, &n);
    for(int i=0; i<k; i++){
        int key; scanf("%d", &key);
        keys.insert(key);
    }
    for(int i=1; i<=n; i++){
        int ti,ki; scanf("%d %d", &ti, &ki);
        //printf("ti %d, i %d\n",ti,i);
        chests[i] = Chest(ti,i);
        for(int j=0; j<ki; j++) {
            int key; scanf("%d", &key);
            chests[i].add_key(key);
        }
    }
}

const int N = 201;

vector<int>prev;
int dfs(
        vector<vector<Chest> >&chests,
        vector<int>&keys,
        int looking_for,
        int type,
        int pr){

    if(prev[type]!=-1) return -1;
    debug printf("type %d, pr %d\n", type, pr);
    prev[type]=pr;

    for(int i=0; i<chests[type].size(); i++){
        Chest &c = chests[type][i];
        for(int j=0; j<c.keys.size(); j++){
            int key = c.keys[j];
            assert(c.id!=-1);
            if(key==looking_for) return c.id;
            int ret = dfs(chests,keys,looking_for,key,c.id);
            if(ret!=-1) return ret;
        }
    }

    return -1;
}

int explore(
        vector<vector<Chest> >&chests,
        vector<int>&keys,
        int type){
    prev.clear(); prev.resize(N, -1);
    debug printf("looking for %d\n", type);
    int v = dfs(chests,keys,type,type,-1);
    debug printf("found chest %d\n",v);
    return v;
}

void remove_keys(vector<int>&keys, multiset<int>&s){
    for(int i=0; i<keys.size(); i++){
        if(s.count(keys[i])>0){
            s.erase(s.find(keys[i]));
            keys[i] = keys.back();
            i--;
        }
    }
}

void remove_set(vector<Chest>&chests, set<int>&to_remove, vector<int>&keys, set<int>&types_used){
    multiset<int>keys_to_remove;
    for(int i=0; i<chests.size(); i++) {
        Chest &c = chests[i];
        if(to_remove.count(c.id)>0){
            keys.insert(keys.end(), c.keys.begin(), c.keys.end());
            keys_to_remove.insert(c.type);

            types_used.insert(c.type);

            chests[i] = chests.back();
            chests.pop_back();
            i--;
        }
    }
    remove_keys(keys, keys_to_remove);
}

void remove_set(vector<vector<Chest > >&chests, set<int>&to_remove, vector<int>&keys, set<int>&types_used){
    for(int i=0; i<chests.size(); i++) remove_set(chests[i], to_remove, keys, types_used);
}


bool possible(
        map<int,Chest>&chests_map,
        vector<int>&keys,
        vector<Chest>&chests_){
    set<int>types_used;
    vector<vector<Chest> >chests; //chests[i] = chests of type i
    chests.resize(N);
    for(int i=0; i<chests_.size(); i++){
        Chest &c = chests_[i];
        chests[c.type].push_back(c);
    }
    for(int i=0; i<chests.size(); i++){
        random_shuffle(chests[i].begin(), chests[i].end());
    }

    while(true){
        debug {
            printf("\n");
            printf("poss: "); for(int i=0; i<keys.size(); i++) printf("%d ", keys[i]); printf("\n");
        }
        bool changed = false;
        random_shuffle(keys.begin(), keys.end());
        while(keys.empty()==false){
            int k = keys.back(); keys.pop_back();
            debug printf("trying key %d\n", k);
            if(chests[k].empty()==false){
                changed = true;
                Chest c = chests[k].back(); chests[k].pop_back();
                debug printf("opening chest %d\n", c.id);
                keys.insert(keys.end(), c.keys.begin(), c.keys.end());
                types_used.insert(k);
            }
        }
        for(int i=0; i<chests.size(); i++) if(types_used.count(i)>0) {
            int v = explore(chests, keys, i);
            if(v==-1) continue;
            set<int>to_remove;

            while(v!=-1){
                to_remove.insert(v);
                v = prev[chests_map[v].type];
            }
            debug printf("REMOVING\n");

            remove_set(chests, to_remove, keys, types_used);

            changed = true;
            break;
        }


        if(!changed) break;
    }
    for(int i=0; i<chests.size(); i++){
        if(chests[i].empty()==false) {
            debug printf("theres still %d\n", chests[i][0].id);
            return false;
        }
    }
    return true;
}

void open_chest(
        const multiset<int>&keys,
        map<int,Chest>&chests,
        vector<Chest>&C,
        vector<int>&K,
        int id){
    int used_key = chests[id].type;
    for(multiset<int>::const_iterator it = keys.begin(); it!=keys.end(); it++){
        if(*it == used_key){
            used_key = -1;
        } else {
            K.push_back(*it);
        }
    }
    for(map<int,Chest>::const_iterator it = chests.begin(); it!=chests.end(); it++){
        if(it->first == id){
            for(int i=0; i<it->second.keys.size(); i++){
                K.push_back(it->second.keys[i]);
            }
        } else {
            C.push_back(it->second);
        }
    }
}

void solve(){
    multiset<int>keys;
    map<int, Chest>chests; // id->chest
    input(keys, chests);
    vector<int>res;
    int n = chests.size();
    for(int i=0; i<n; i++){
        int id = -1;
        for(id=1; id<=n; id++) {
            if(chests.count(id)==0) continue;
            if(keys.count(chests[id].type)==0) continue;

            vector<Chest>C; vector<int>K;
            open_chest(keys, chests, C, K, id);
            if(possible(chests, K, C)) break;
        }
        if(id==n+1){
            printf("IMPOSSIBLE\n");
            return;
        }
        //types_used.insert(chests[id].type);
        Chest c = chests[id]; chests.erase(id);
        keys.erase(keys.find(c.type));
        keys.insert(c.keys.begin(), c.keys.end());

        res.push_back(id);
    }
    for(int i=0; i<res.size(); i++) printf("%d ", res[i]); printf("\n");
}

main(){
    int seed = time(0)%10000;
    //seed = 7845;
    fprintf(stderr, "seed %d\n",seed);
    srand(seed);
    int t; scanf("%d", &t);
    for(int i=1; i<=t; i++){
        printf("Case #%d: ", i);
        solve();
        //break;
    }
}
