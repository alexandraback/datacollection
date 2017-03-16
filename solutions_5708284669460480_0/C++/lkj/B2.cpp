#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

//FILE* randin;

/*unsigned getrandnum() {
  static unsigned x = 314159265;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return x;
}*/

//inline unsigned getrandnum(){
    /*unsigned n;
    fscanf(randin, "%i", &n);
    return n;*/
//}

unsigned overlapcatind(char* target){
    char tmp[256] = "";
    strcat(tmp, target);
    tmp[strlen(tmp)-1] = '\0';
    unsigned off=1;
    for(off=1; off<strlen(target); ++off){
        if(!strcmp(target+off, tmp))
            break;
        tmp[strlen(tmp)-1] = '\0';
    }
    return off;
}

int getmax(char* target, unsigned length){
    char tmp[256] = "";
    strcat(tmp, target);
    int cnt = 1;
    const int off = overlapcatind(target);
    int ind = off;
    while(strlen(tmp) < length){
        strcpy(tmp+ind, target);
        ind += off;
        if(strlen(tmp) <= length){
            cnt++;
            //cout << tmp << " " << cnt << endl;
        }
    }
    return cnt;
}

inline int samplescore(char* kstr, int lks, char* lstr, int s){
    //cout << "sampling... ";
    char sample[128];
    //int lks = strlen(kstr);
    for(int i=0; i<s; ++i)
        sample[i] = kstr[rand()%lks];
    sample[s] = '\0';
    int score = 0;
    for(char* tmp=sample; ; ){
        tmp = strstr(tmp, lstr);
        //printf("tmp=%p ", tmp);
        if(tmp == NULL)
            break;
        else{
            ++tmp;
            ++score;
        }
    }
    //cout << "finished: " << score << endl;
    //cout << "sample: " << sample << ", target: " << lstr << ", score: " << score << endl;
    return score;
}

double sample(char* kstr, char* lstr, int s, int samplenum){
    int lks = strlen(kstr);
    unsigned long long score=0;
    for(int i=0; i<samplenum; ++i){
        score += samplescore(kstr,lks,lstr,s);
    }
    double expected = ((double)score)/(double)samplenum;
    //cout << "Sampled " << samplenum << " times. Score: " << score << ", E: " << expected << endl;
    return expected;
}

int main(){
    //randin = fopen("randnums.txt", "r");
    srand(time(NULL));
    int t;
    cin >> t;
    for(int tc=1; tc<=t; ++tc){
        int k,l,s;
        char kstr[128], lstr[128];
        cin >> k >> l >> s;
        cin >> kstr >> lstr;
        //cout << kstr << " " << lstr << " " << getmax(lstr, s) << endl;
        if(strspn(lstr, kstr) != strlen(lstr)){
            cout << "Case #" << tc << ": 0.0" << endl;
            continue;
        }
        printf("Case #%i: %.6f\n", tc, ((double)getmax(lstr,s))-sample(kstr,lstr,s,15000000));
        //cout << "Case #" << tc << ": " << ((double)getmax(lstr,s))-sample(kstr,lstr,s,1000) << endl;
    }
    //fclose(randin);
    return 0;
}
