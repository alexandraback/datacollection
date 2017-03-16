#include <stdio.h>
#include <string.h>
#define LEN 2600
char a[50], b[50];
char aa[50], bb[50];
int test(int x, char *l, char *r, char *ll, char *rr){
    if(x < 0)
        return 0;
    if(l[x] == '?' && r[x] == '?'){
        ll[x] = '0', rr[x] = '1';
        return 1;
    }
    else if(l[x] == '?' && r[x] != '?'){
        if(r[x] != '0'){
            rr[x] = r[x], ll[x] = rr[x] - 1;
            return 1;
        } else {
            if(test(x - 1, l, r, ll, rr)){
              ll[x] = '9', rr[x] = '0';
              return 1;
            } else {
                return 0;
            }
        }
    } else if(l[x] != '?' && r[x] == '?'){
        if(l[x] != '9'){
            ll[x] = l[x], rr[x] = ll[x] + 1;
            return 1;
        } else {
            if(test(x - 1, l, r, ll, rr)){
              ll[x] = '9', rr[x] = '0';
              return 1;
            } else {
              return 0;
            }
        }
    } else {
        return 0;
    }
    return 0;
}
int match(char *a, char *b){
    if(strlen(a) != strlen(b))
        return 0;
    else{
        for(int i = 0; a[i] != 0; i++)
            if(a[i] != b[i] && a[i] != '?')
                return 0;
        return 1;
    }
}
int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    /*
    for(int i = 0; i < t; i++){
        fscanf(fp1, "%s %s", a, b);
        int rel = 0;
        memset(aa, 0, sizeof(aa));
        memset(bb, 0, sizeof(bb));
        for(int j = 0; a[j] != '\0'; j++){
            if(rel == 0){
                if(a[j] == '?' && b[j] == '?')
                    aa[j] = bb[j] = '0';
                else if(a[j] != '?' && b[j] == '?')
                    bb[j] = aa[j] = a[j];
                else if(a[j] == '?' && b[j] != '?')
                    aa[j] = bb[j] = b[j];
                else{
                    char *l, *r, *ll, *rr;
                    if(a[j] > b[j])
                        rel = 1, l = a, r = b, ll = aa, rr = bb;
                    else if(a[j] < b[j])
                        rel = -1, l = b, r = a, ll = bb, rr = aa;
                    aa[j] = a[j], bb[j] = b[j];
                    if(l[j] - r[j] > r[j] + 10 - l[j]){
                        if(test(j - 1, l, r, ll, rr))
                            rel = -rel;
                    }
                }
            } else {
                aa[j] = a[j], bb[j] = b[j];
                char *l, *r;
                if(rel == 1)
                    l = aa, r = bb;
                else
                    l = bb, r = aa;
                if(l[j] == '?')
                    l[j] = '0';
                if(r[j] == '?')
                    r[j] = '9';
            }
        }
        fprintf(fp2, "Case #%d:", i + 1);
        fprintf(fp2, " %s %s", aa, bb);
        fprintf(fp2, "\n");
    }
    */
     for(int i = 0; i < t; i++){
        fscanf(fp1, "%s %s", a, b);
        int rel = 0;
        int l1, l2;
        l1 = strlen(a);
        l2 = strlen(b);
        int diff = 100000, p1, p2;
        for(int j = 0; j < 999; j++){
            if(l1 == 1)
                sprintf(aa, "%d", j);
            else if(l1 == 2) 
                sprintf(aa, "%02d", j);
            else if(l1 == 3) 
                sprintf(aa, "%03d", j);
            if(!match(a, aa))
                continue;
            for(int k = 0; k < 999; k++){
                if(l1 == 1)
                    sprintf(bb, "%d", k);
                else if(l1 == 2) 
                    sprintf(bb, "%02d", k);
                else if(l1 == 3) 
                    sprintf(bb, "%03d", k);
                if(!match(b, bb))
                    continue;
                int tmp = (j > k? j - k: k - j);
                if(tmp < diff || 
                       (tmp == diff && p1 > j) ||
                       (tmp == diff && p1 == j && p2 > k))
                    diff = tmp, p1 = j, p2 = k;

            }
        }
        fprintf(fp2, "Case #%d: ", i + 1);
        if(l1 == 1)
            fprintf(fp2, "%d %d\n", p1, p2);
        else if(l1 == 2)
            fprintf(fp2, "%02d %02d\n", p1, p2);
        else if(l1 == 3)
            fprintf(fp2, "%03d %03d\n", p1, p2);
    } 
    return 0;
}
