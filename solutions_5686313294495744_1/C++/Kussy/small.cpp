#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

vector< pair<string, string> > V;
vector<int> O;
int N;

/*int check(vector< pair<string, string> >& V) {
    int r = 0;
    set< string > A;
    set< string > B;
   // set<int>::iterator a;
   // set<int>::iterator b;

    for(int i=0; i<V.size(); i++) {
        if(A.find( V[i].first ) != A.end() && B.find( V[i].second ) != B.end()) {
            r++;
            continue;
        }
        if(A.find( V[i].first ) == A.end()) {
            A.insert(V[i].first);
        }
        if(B.find( V[i].second ) == B.end()) {
            B.insert(V[i].second);
        }
    }
    return r;
}

int generateAllPermutations(vector< pair<string, string> >& toBePermuted, int nextIndex)
{
    int f = 0;
    if (nextIndex==toBePermuted.size())
        return check(toBePermuted);
    for (int i=nextIndex; i<toBePermuted.size(); i++)
    {
        swap(toBePermuted[i], toBePermuted[nextIndex]);
        f = max(f, generateAllPermutations(toBePermuted, nextIndex+1));
        swap(toBePermuted[i], toBePermuted[nextIndex]);
    }
    return f;
}*/


int randomize() {
    int r=0;
    for(int t = 0; t <100; t++){
            int f = 0;
            for(int i = 0; i < N; i++){
                bool first, second;
                first=second=false;
                for(int j = 0; j < i; j++){
                    if(V[O[j]].first==V[O[i]].first)
                        first=true;
                    if(V[O[j]].second==V[O[i]].second)
                        second=true;
                }
                if(first && second ) f++;
            }
            r= max(r, f);
            random_shuffle(O.begin(), O.end());
        }
    return r;
}



int main() {
    int T;
    cin>>T;
    for(int tt=1; tt<=T; tt++) {
        cin>>N;

        pair< string , string> p;
        for(int i=0; i<N; i++) {
            cin>>p.first>>p.second;
            V.push_back(p);
            O.push_back(i);
        }

        cout<<"Case #"<<tt<<": "<<randomize()<<endl;
        V.clear();
        O.clear();
    }
    return 0;

}
