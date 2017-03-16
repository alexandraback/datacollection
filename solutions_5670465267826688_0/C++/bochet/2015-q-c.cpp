#include <cstdio>
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
map<pair<char, char>, pair<int, char> > product;

struct quater{
    char ch;
    int pos;
    quater(){
        ch = '1';
        pos = 1;
    }
    
    quater(int nch, int npos){
        ch = nch;
        pos = npos;
    }
    
    quater operator*(const quater& rhs) const{
        char rch = rhs.ch;
        int t1 = product[{ch, rch}].first;
        char nch = product[{ch, rch}].second;
        int npos = pos*rhs.pos*t1;
        return quater(nch, npos);
    }
};

bool solve(quater lstr[], int len){
    quater lprod, rprod;
    int l = -1, r = -1;
    
    for(int i = 0; i < len; i++){
        lprod = lprod*lstr[i];
        if(lprod.ch == 'i' && lprod.pos == 1){
            l = i;
            break;
        }
    }
    for(int i = len-1; i >= 0; i--){
        rprod = lstr[i]*rprod;
        if(rprod.ch == 'k' && rprod.pos == 1){
            r = i;
            break;
        }
    }
    
    if(l == -1 || r == -1)
        return false;
    return l < r-1;
}

void init_product(){
    char chs[] = "1ijk";
    for(char tmp: chs){
        product[{'1', tmp}] = {1, tmp};
        product[{tmp, '1'}] = {1, tmp};
    }
    product[{'i', 'i'}] = {-1, '1'};
    product[{'i', 'j'}] = {1, 'k'};
    product[{'i', 'k'}] = {-1, 'j'};
    product[{'j', 'i'}] = {-1, 'k'};
    product[{'j', 'j'}] = {-1, '1'};
    product[{'j', 'k'}] = {1, 'i'};
    product[{'k', 'i'}] = {1, 'j'};
    product[{'k', 'j'}] = {-1, 'i'};
    product[{'k', 'k'}] = {-1, '1'};
}

int main()
{
//    FILE* fid_in = stdin;
//    FILE* fid_out = stdout;
    FILE* fid_in = fopen("/Users/bochen/Downloads/textfile.in", "r+");
    FILE* fid_out = fopen("/Users/bochen/Downloads/textfile.out", "w+");
    
    init_product();
    int t;
    fscanf(fid_in, "%d", &t);
    for(int cid = 1; cid <= t; cid++){
        quater str[10000], lstr[120000];
        long long l, x;
        fscanf(fid_in, "%lld %lld\n", &l, &x);
        
        if(x > 12){
            x %= 12;
            x += 12;
            if(x > 12)
                x -= 4;
        }
        
        quater tprod, prod;
        for(int i = 0; i < l; i++){
            fscanf(fid_in, "%c", &str[i].ch);
            tprod = tprod*str[i];
        }
        
        for(int i = 0; i < x; i++)
            prod = prod*tprod;
        
        bool result = false;
        if(prod.ch == '1' && prod.pos == -1){
            for(int i = 0; i < x; i++)
                for(int j = 0; j < l; j++)
                    lstr[i*l+j] = str[j];
            result = solve(lstr, x*l);
        }
        
        if(result)
            fprintf(fid_out, "Case #%d: YES\n", cid);
        else
            fprintf(fid_out, "Case #%d: NO\n", cid);
    }
    fclose(fid_in);
    fclose(fid_out);
    return 0;
}
