#include <stdio.h>

int tc, cases, k, l, s, i, j, over, temp;
char a[30], target[105], str[105];
char c;
bool b;
double res, exp, exp2, maxi;

int rec(int pos) {
    int i,j,temp2;
    if(pos == s) {
        str[pos] = 0;
        temp2 = 0;
        for(i=0; i<=s-l; i++) {
            if(str[i]==target[0]) {
                temp = 1;
                b = true;
                for(j=i+1; j<l&&b; j++,temp++) {
                    if(str[j]!=target[temp]) b = false;
                }
                if(b) {
                    res += 1.0;
                    temp2++;
                }
            }
        }
        if(maxi<temp2) maxi = temp2;
        //printf("%s\n", str);
    } else {
        for(i=0; i<k; i++) {
            str[pos] = a[i];
            rec(pos+1);
        }
    }
}

int main() {
    cases = 1;
    scanf("%d\n", &tc);
    while(tc--) {
        scanf("%d %d %d\n", &k, &l, &s);
        for(i=0; i<30; i++) {
            a[i] = 0;
        }
        /*
        for(i=0; i<k; i++) {
            scanf("%c\n", &c);
            a[c-'A']++;
        }
        */
        gets(a);
        gets(target);
        res = 0.0;
        maxi = 0.0;
        rec(0);
        //printf("res = %lf\n", res);
        exp = 1.0;
        for(i=0; i<s; i++) {
            exp *= k;
        }
        //printf("%lf\n", exp);
        res /= exp;
        /*
        over = l;
        for(i=1; i<l; i++) {
            if(target[i] == target[0]) {
                temp = 1;
                b = true;
                for(j=i+1; j<l&&b; j++,temp++) {
                    if(target[j]!=target[temp]) b = false;
                }
                if(b) {
                    over = i;
                    break;
                }
            }
        }
        //printf("over = %d\n", over);
        res = 1 + ((s-l)/over);
        for(i=0; i<l; i++) {
            if(a[target[i]-'A']==0) res = 0.0;
        }
        //printf("res = %lf\n", res);
        exp = 1.0;
        for(i=0; i<l; i++) {
            exp *= 1.0*a[target[i]-'A']/k;
        }
        for(i=0; i<temp; i++) {
            res *= (s-l)*exp;
        }
        //printf("exp = %lf\n", exp);
        exp2 = 1.0;
        for(i=over; i<l; i++) {
            exp2 *= 1.0*a[target[i]-'A']/k;
        }
        //printf("exp2 = %lf\n", exp2);
        temp = ((s-l)/over);
        //printf("temp = %d\n", temp);
        for(i=0; i<temp; i++) {
            exp *= exp2;
        }
        //printf("exp = %lf\n", exp);
        res -= res*exp;
        */
        printf("Case #%d: %.7lf\n", cases++, maxi-res);
    }
    return 0;
}
