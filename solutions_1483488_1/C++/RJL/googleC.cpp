#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <stdbool.h>
#include <vector>

using namespace std;

bool val_in_vector(const vector<int>& seen, int v) {
    for (unsigned int i = 0; i < seen.size(); i++) {
        if (seen[i] == v) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    vector<int>   seen;
    FILE         *f;
    unsigned int  t;
    unsigned int  i;
    unsigned int  a;
    unsigned int  b;
    unsigned int  n;    
    unsigned int  m;    
    char          bbuf[10];    
    char          nbuf[10];
    char          mbuf[20];
    unsigned int  len;   
    int                 copy_point;
    unsigned long long  count;
    
    f = fopen("test_case", "r");

    fscanf(f, "%u", &t);
     
    for (i = 1; i <= t; i++) {
        fscanf(f, "%u %u", &a, &b);
        
        // find the length of b
        snprintf(bbuf, sizeof(bbuf), "%u", b);
        len = strlen(bbuf);
        count = 0;
        
        for (n = a; n < b; n++) {
            snprintf(nbuf, sizeof(nbuf), "%u", n);
            strcpy(&mbuf[10], nbuf);
            
            seen.clear();
            for (copy_point = len - 1; copy_point > 0; copy_point--) {
                mbuf[10 + copy_point - len] = mbuf[10 + copy_point];
                mbuf[10 + copy_point] = '\0';
                m = atoi(&mbuf[10 + copy_point - len]);
                
                if (m > n && m <= b && !val_in_vector(seen, m)) {
                    seen.push_back(m);
                    count += 1;                    
                }
            } 
            
        }
        printf("Case #%u: %llu\n", i, count);
    }
}

