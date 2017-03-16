#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <cstdio>
#include <math.h>
#include <bitset>
#include <fstream>
#include <assert.h>
#include <iomanip>
#include <ctime>
using namespace std;

char alpha[] = {
'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
};

int main(){
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz_gcj.txt","w",stdout);
    int tests; scanf("%d",&tests);
    char c;
    scanf("%c",&c);
    for (int t = 1; t <= tests; ++t){
        string w;
        getline(cin, w);

        printf("Case #%d: ",t);
        for (int i = 0; i < w.size(); ++i){
            if(w[i] == ' '){
                printf(" ");
                continue;
            }

            printf("%c",alpha[w[i]-'a']);
        }printf("\n");
    }
    return 0;
}
