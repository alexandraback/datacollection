#include <stdio.h>
#include <string.h>

//#define DEBUG

char str[1000010];
int a[1000100], all, len , n;
long long p = 0;

char vowl[] = "aeiou";

bool isconsonant(char c) {
     for (int i = 0; vowl[i] != 0; ++i) {
         if (vowl[i] == c) return false;
     }
     return true;
}

int findnum(int v) {
    if (all == 0 || a[all-1] < v) {
       return 0;
    }
    int head = 0, tail = all-1;
    while (head < tail) {
          int mid = (head+tail)/2;
          if (a[mid] < v) {
             head = mid+1;
          }
          else {
               tail = mid;
          }
    }
    return len-a[head]-n+1;
}


int main () {
#ifndef DEBUG
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif

//start code
    int kase;
    int h = 1;

    scanf("%d", &kase);
    while (kase--) {
          long long ans=0;
          scanf("%s %d", str, &n);
          len = strlen(str);
          int count = 0;
          all = 0;
          for (int i = 0; i < len; ++i) {
              if ( isconsonant(str[i]) ) {
                 count++;
                 if (count >= n) {
                    a[all++] = i-n+1;
                 }
              }
              else {
                  count = 0;
              }
          }
         // printf("%d\n",all);
          for (int i = 0; str[i] != 0; ++i) {
              int num = findnum(i);
              ans = ans+num;
          }
          printf("Case #%d: %lld\n", h++, ans);
          
    }
    return 0;
}
