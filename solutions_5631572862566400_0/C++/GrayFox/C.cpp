#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

int p[2000];
bool v[2000];
bool r[2000];
int f[2000];
int d[2000];
bool cc[2000];
int best_chain[2000];
int best_cicle;



int find(int x){
  if(p[x] == x){
    return x;
  }
  p[x] = find(p[x]);
  return p[x];
}

void unite(int x, int y){
  p[x] = find(y);
}

int compute_dist(int x){
  if(d[x] == -1){
    d[x] = compute_dist(f[x])+1;
    best_chain[find(x)] = max(best_chain[find(x)], d[x]+1);
  }
  return d[x];
}


int main(){

  int t;
  cin >> t;
  for(int tt =1;tt<=t;tt++){
    int n;
    cin >> n;
    int k;
    for(int i=0;i<n;i++){
      p[i]=i;
    }
    best_cicle = 2;
    memset(v, 0, sizeof v);
    memset(r, 0, sizeof r);
    memset(d, -1, sizeof d);
    for(int i=0;i<n;i++){
        cin >>k;
        k--;
        f[i]=k;
    }
    for(int i=0;i<n;i++){
      if(f[f[i]] != i){
        unite(i, f[i]);
      }
    }

    for(int i=0;i<n;i++){
      if(f[f[i]] == i){
        DBL(i)
        r[find(i)]=true;
        best_chain[find(i)]=1;
        d[i]=0;
      }
    }
    for(int i=0;i<n;i++){
      if(r[find(i)]){
        compute_dist(i);
      }
      else if(!cc[find(i)]){
        int c = i;
        int cd = 1;
        while(!v[c]){
          d[c] = cd++;
          v[c] = true;
          c = f[c];
        }
        cc[find(i)] = true;
        best_cicle = max(cd-d[c], best_cicle);
      }
    }
    int all_chains = 0;
    for(int i=0;i<n;i++){
      if(r[i]){
        DB(i) DBL(best_chain[i]);
        all_chains += best_chain[i];
      }
    }

    int ans = max(all_chains, best_cicle);

    cout<<"Case #"<<tt<<": "<<ans<<endl;
  }

  return 0;
}
