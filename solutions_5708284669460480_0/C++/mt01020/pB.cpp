#include<cstdio>
#include<unordered_map>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
    int T;
    int K, L, S;
    char kb[10];
    char target[10];
    scanf(" %d ", &T);
    for(int t=1; t<=T; ++t){
	scanf(" %d %d %d ", &K, &L, &S);
	scanf("%s", kb);
	scanf("%s", target);
	unordered_map<char, int> kbmap;
	for(int i=0; i<K; ++i){
	    if(kbmap.find(kb[i]) == kbmap.end())    kbmap[kb[i]] = 0;
	    ++kbmap[kb[i]];
	}
	// check possibility
	bool poss = true;
	for(int i=0; i<L; ++i){
	    if(kbmap[target[i]] == 0){
		poss = false;
		break;
	    }
	}
	if(!poss){
	    printf("Case #%d: 0.0\n", t);
	    continue;
	}

	int reuse = 0;
	for(int i=L-1; i>0; --i){
	    bool match = true;
	    int s = L-i;
	    for(int j=s; j<L; ++j){
		if(target[j] != target[j-s]){
		    match = false;
		    break;
		}
	    }
	    if(match){
		reuse = i;
		break;
	    }
	}
	int max = (S-L) / (L-reuse) + 1;
	double expect = 1.0;
	double fK = (double)K;
	// L
	for(int i=0; i<L; ++i){
	    expect *= (kbmap[target[i]] / fK);
	}
	// reuse complement
	double comexp = 1.0;
	for(int i=reuse; i<L; ++i){
	    comexp *= (kbmap[target[i]] / fK);
	}
	printf("Case #%d: %.7lf\n", t, max - (expect*1.0+pow(comexp, max-1)*(max-1)));
    }
    return 0;
}
