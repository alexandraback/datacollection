#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> dict;
char tmp[200], s[100];
string ss;
int mem[100];
map<string, int> mapa;

int ok(string rijec) {
    if(mapa.count(rijec) > 0) return mapa[rijec];
    //printf("%s\n", rijec.c_str());
    int min_suma = -1;
    for(int i = 0; i < (int)dict.size(); ++i) {
        if(rijec == dict[i]) return 0;
        if(rijec.length() != dict[i].length()) continue;
        int suma = 0;
        int zadnja_promjena = -1;
        for(int j = 0; j < (int)rijec.length(); ++j) {
            if(rijec[j] != dict[i][j] && (zadnja_promjena != -1 && j - zadnja_promjena < 5)){ suma = -1; break; };
            if(rijec[j] != dict[i][j]) {
                suma++;
                zadnja_promjena = j;
            }
        }
        if(suma != -1 && (suma < min_suma || min_suma == -1)) min_suma = suma;
    }
    if(min_suma != -1) return mapa[rijec] = min_suma;
    return mapa[rijec] = -1;
}

int f(int pos) {
    if(mem[pos] != -1) return mem[pos];
    if(pos == ss.length()) return 0;
    //    printf("%d\n", pos);
    int sol = 1000000000;
    for(int i = 1; i < (int)ss.length() - pos + 1; ++i) {
        int nesto = ok(ss.substr(pos, i));
        if(nesto > -1) {
            int k = f(pos + i);
            if(k == 1000000000) continue;
            //  printf("%d\n", k);
            if(nesto + k < sol) sol = nesto + k;
        }
    } 
    return mem[pos] = sol;
}

int main() {
    FILE *dictionary = fopen("garbled_email_dictionary.txt", "r");
    while(fscanf(dictionary, "%s", tmp) == 1) {
        dict.push_back(tmp);
    }
    fclose(dictionary);
    int t;
    scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        memset(mem, -1, sizeof(mem));
        scanf("%s", s);
        ss = s;
        printf("Case #%d: %d\n", test+1, f(0));
        //break;
    }
    return 0;
}
