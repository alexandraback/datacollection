#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 111;
char keys[MAXN];
char word[MAXN];

double dp[MAXN][MAXN][MAXN];

int cnt[26];

int K, L, S;

// struct AhoCorasick {
//   static const int MAXMEM = 1001;
//   static const int CHARSET = 27;
//   struct node {
//     int cnt; //该点加了几次
//     int id; //该点的id
//     bool forbid;
//     node *fail, *next[CHARSET];
//   } *root, *null, mem[MAXMEM], *top;

//   node* newnode() {
//     memset(top, 0, sizeof(*top));
//     top->id = top - mem;
//     return top++;
//   }

//   void init() {
//     top = mem;
//     null = newnode();
//     root = newnode();
//   }

//   int id(node * nd) {
//     return nd - mem;
//   } 

//   void insert(char* s, int id) {
//     node *p = root;
//     for (int i; *s; p = p->next[i]) {
//       i = *s++ - 'a';
//       if (!p->next[i]) {
//         p->next[i] = newnode();
//       }
//     }
//     p->id = id;
//     p->cnt++;
//     p->forbid = true;
//   }

//   void build() {
//     typedef node* pnode;
//     static pnode queue[MAXMEM], *l, *r;
//     node *p, *q;
//     l = r = queue;
//     *r++ = root;
//     for (int i = 0; i < CHARSET; i++) {
//       null->next[i] = root;
//     }
//     root->fail = null;
//     while (l != r) {
//       p = *l++;
//       if (p->fail->forbid) p->forbid = true;//注意这句，有禁止的要加这个
//       for (int i = 0; i < CHARSET; i++) {
//         q = p->fail;
//         if (p->next[i]) {
//           p->next[i]->fail = q->next[i];
//           *r++ = p->next[i];
//         } else {
//           p->next[i] = q->next[i];
//         }
//       }
//     }
//   }

//   int query(char* s) {//字典里的串出现几个/次
//     int ans = 0;
//     node *p = root, *q;
//     while (*s) {
//       int i = *s++ - 'a';
//       p = p->next[i];
//       for (q = p; q != root && q->cnt != -1; q = q->fail) {
//         ans += q->cnt;
//         q->cnt = -1;//出现次数重复计算的时候去掉
//       }
//     }
//     return ans;
//   }

//   void doit() {
//     memset(dp, 0, sizeof(dp));
//     dp[id(root)][0][0] = 1.0;
//     int all = id(top);
//     for (int i = 0; i < S - 1; ++i) {
//       for (int p = 1; p < all; ++p) {
//         for (int j = 0; j < 100; ++j) {
//           node *q = mem[p];
//           int cnt = 0;
//           for (q = p; q != root && q->cnt != -1; q = q->fail) {
//             ans += q->cnt;
//           }
//           dp[id(p->next[j])][i + 1][j + ans] += dp[p][i][j] * ;
//         }
//       }
//     }
//   }
// } ac;

// const int MAXLEN = 1000001;
// char s[MAXLEN];

// char word[51];
// int main() {
//   int n, cas;
//   scanf("%d", &cas);
//   while (cas--) {
//     ac.init();
//     scanf("%d", &n);
//     gets(s);
//     for (int i = 0;i < n;i++) {
//       gets(word);
//       ac.insert(word, i);
//     }
//     ac.build();
//     gets(s);
//     printf("%d\n", ac.query(s));
//   }
// }

char cmd[111];
int ans = 0;
int maxv;

void dfs(int dep) {
  if (dep == S) {
    int cnt = 0;
    for (int i = 0; i <= S - L; ++i) {
      bool match = true;
      for (int j = 0; j < L; ++j) {
        match &= word[j] == cmd[i + j];
      }
      if (match) {
        ++cnt;
      }
    }
    ans += cnt;
    maxv = max(maxv, cnt);
  } else {
    for (int i = 0; i < K; ++i) {
      cmd[dep] = keys[i];
      dfs(dep + 1);
    }
  }
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    // int ans = 0;
    scanf("%d %d %d", &K, &L, &S);
    getchar();
    gets(keys);
    gets(word);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < K; ++i) {
      cnt[keys[i]]++;
    }
    ans = 0;
    maxv = 0;
    dfs(0);

    printf("Case #%d: %.10lf\n", T, maxv - ans / pow(K, S));
  }
}