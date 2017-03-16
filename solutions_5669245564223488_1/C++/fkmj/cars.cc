#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_CAR_LEN  1000
#define MAX_N  100
#define MOD 1000000007

int n;
char cars[MAX_N][MAX_CAR_LEN];
char clen[MAX_N];
bool is_impossible;
char cstart[MAX_N], cend[MAX_N];
int startidx[26];
bool is_singleletter[MAX_N];
bool cmiddle[MAX_N][26];
int startcount[26], endcount[26], middlecount[26], singlecount[26];

bool used[MAX_N];
int trainused;
int blockcount;
long long middletraincombi[MAX_N];

//#define DEBUG 1

void read_input()
{
  scanf("%d",&n);
  for(int i=0; i<n; i++) {
    scanf("%s",cars[i]);
    clen[i] = strlen(cars[i]);
  }
}

void preprocess()
{
  is_impossible = false;

  for(int i=0; i<26; i++) {
    startcount[i] = endcount[i] = middlecount[i] = singlecount[i] = 0;
  }

  for(int i=0; i<n; i++) {
    cstart[i]=cars[i][0];
    cend[i]=cars[i][clen[i]-1];

    for(int j=0; j<26; j++)
      cmiddle[i][j] = false;

    char *p = cars[i];
    char lastchar = cars[i][0];
    int numchar = 1;
    bool fromstart = true;

    for(int j=0; j<clen[i]; j++) {
      char currchar = *p;
      p++;

      if(currchar == lastchar)
        continue;
      numchar++;

      if(!fromstart) {
        cmiddle[i][lastchar - 'a'] = true;
        middlecount[lastchar - 'a']++;
      }
      
      fromstart = false;
      lastchar = currchar;
    }
    is_singleletter[i] = (numchar == 1);

    if(!is_singleletter[i]) {
      startcount[cstart[i]-'a']++;
      startidx[cstart[i]-'a'] = i;
      endcount[cend[i]-'a']++;

      if(cstart[i] == cend[i])
        is_impossible = true;
    } else {
      singlecount[cstart[i]-'a']++;
    }
  }
  
  for(int i=0; i<26; i++) {
    if(startcount[i] > 1)
      is_impossible = true;
    if(endcount[i] > 1)
      is_impossible = true;
    if((middlecount[i] > 0) &&
       ((singlecount[i] > 0) || (endcount[i] > 0) || (singlecount[i] > 0)))
      is_impossible = true;
  }
}

bool find_blocks()
{
  blockcount = 0;
  trainused = 0;
  for(int i=0; i<n; i++)
    used[i] = false;

  for(int i=0; i<26; i++) {
    if((singlecount[i] > 0) && (startcount[i]==0) && (endcount[i]==0)) {
      //printf("taking all single %c\n",i+'a');
      int mcount = 0;
      for(int j=0; j<n; j++)
        if(is_singleletter[j] && (cstart[j] == 'a' + i)) {
          used[j] = true;
          trainused++;
          mcount++;
        }
      middletraincombi[blockcount] = 1;
      for(int k=0; k<mcount; k++) {
        middletraincombi[blockcount] *= (k+1);
        middletraincombi[blockcount] %= MOD;
      }
      blockcount++;
    }
  }
    
  for(int i=0; i<n; i++)
    if(!used[i] && (endcount[cstart[i] - 'a']==0) && (!is_singleletter[i])) {
      middletraincombi[blockcount] = 1;
      int u = i;
      used[u] = true;
      trainused++;

#ifdef DEBUG      
      printf("started at %d\n",u);
#endif
      
      if(singlecount[cstart[i] - 'a'] > 0) {

#ifdef DEBUG     
        printf("kill start combi\n");
#endif
        int mcount = 0;
        for(int j=0; j<n; j++)
          if(is_singleletter[j] && cstart[j]==cstart[u]) {
            used[j] = true;
            trainused++;
            mcount++;
            middletraincombi[blockcount] *= mcount;
            middletraincombi[blockcount] %= MOD;
          }
      }

      while(true) {
        char next = cend[u];

#ifdef DEBUG     
        printf("u = %d, next = %c\n",u,next);
#endif
        
        int mcount = 0;
        
        if(singlecount[next - 'a'] > 0) {
          //printf("taking singles: %d\n",singlecount[next - 'a']);
          for(int j=0; j<n; j++)
            if(is_singleletter[j] && cstart[j]==next) {
              used[j] = true;
              trainused++;
              mcount++;
              middletraincombi[blockcount] *= mcount;
              middletraincombi[blockcount] %= MOD;
            }
        }

        if(startcount[next - 'a'] > 0) {
          u = startidx[next - 'a'];
          used[u] = true;
          trainused++;

          //printf("moved to %d\n",u);
        } else
          break;
      }

      //printf("ended\n----\n");
      blockcount++;
    }
  if(trainused!=n)
    return false;
  else
    return true;
}

void solve(int t)
{
  read_input();
  preprocess();
  if(is_impossible) {
    printf("Case #%d: 0\n",t+1);
    return;
  }

  if(find_blocks()) {
    long long res = 1;
    //printf("%d\n",blockcount);
    for(int i=0; i<blockcount; i++) {
      res *= (i+1);
      res %= MOD;
      res *= middletraincombi[i];
      res %= MOD;
    }
    printf("Case #%d: %lld\n",t+1,res);
  } else {
    printf("Case #%d: 0\n",t+1);
  }
}

main()
{
  int tt;
  scanf("%d",&tt);
  for(int i=0; i<tt; i++)
    solve(i);
}
