#include <stdio.h>
#include <string.h>

const long long MOD = 1000000007;

char s[101][101];
int len[101];
int dif[101];
bool rec[26];
int set[26];

long long fac(int n){
   long long ret = 1LL;
   for(int i=1; i<=n; ++i) ret = (ret*i) % MOD;
   return ret;
}

void Init(){
   for(int i=0; i<26; ++i) set[i] = i;
}
bool Same(int a, int b){ return set[a] == set[b]; }
void Merge(int a, int b){
   int c = set[b];
   for(int i=0; i<26; ++i){
      if(set[i] == c) set[i] = set[a];
   }
}

int main(){
   int T, n;
   long long ans;
   bool flg;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      scanf("%d", &n);
      for(int i=0; i<n; ++i){
         scanf("%s", s[i]);
         len[i] = strlen(s[i]);
      }

      printf("Case #%d: ", t);

      flg = false;
      for(int i=0; i<26; ++i) rec[i] = false;
      for(int i=0; i<n; ++i){
         int cnt = 1;
         for(int j=1; j<len[i] ;++j){
            if(s[i][j] != s[i][j-1]) cnt++;
         }
         if(cnt>2){
            int id = 1;
            for(int j=1; j<len[i]; ++j){
               if(s[i][j] != s[i][j-1] && id != cnt-1){
                  id++;
                  if(rec[s[i][j]-'a']) flg = true;
                  rec[s[i][j]-'a'] = true;
               }
            }
         }
         dif[i] = cnt;
      }
      if(flg){
         printf("0\n");
         continue;
      }
      
      ans = 1LL;
      flg = false;
      int spare = n;
      Init();
      for(char c='a'; c<='z'; ++c){
         bool head = false;
         bool rear = false;
         char h, r;
         int same = 0;
         for(int i=0; i<n; ++i){
            if(dif[i] == 1){
               if(s[i][0] == c) same++;
               continue;
            }
            if(s[i][0] == c){
               if(head) flg = true;
               h = s[i][len[i]-1];
               head = true;
            }
            if(s[i][len[i]-1] == c){
               if(rear) flg = true;
               r = s[i][0];
               rear = true;
            }
         }
         if(same == 0){
            if(head && rear) spare--;
         }
         else{
            ans = (ans*fac(same)) % MOD;
            spare -= (same-1);
            if(head) spare--;
            if(rear) spare--;
         }
         if(rec[c-'a'] && (same!=0 || head || rear)) flg = true;
         if(head){
            if(Same(h-'a', c-'a')) flg = true;
            else Merge(h-'a', c-'a');
         }
         /*
         if(rear){
            if(r<c && Same(r-'a', c-'a')) flg = true;
            else Merge(r-'a', c-'a');
         }
         */
      }
      if(flg){
         printf("0\n");
         continue;
      }

      ans = (ans*fac(spare)) % MOD;
      printf("%lld\n", ans);
   }

   return 0;
}
