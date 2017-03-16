#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int lim = 7;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

struct Compare{
   bool operator()(pii a, pii b){
      if (a.second != b.second) return a.second < b.second;
      return a.first < b.first;
   }
};

bool custom(pii a, pii b){
   if (a.second != b.second) return a.second<b.second;
   return a.first < b.first;
}

set<vector<pii> > sol[8];

vector<pii> flipLR(vector<pii> v){
   for(int i=0; i<v.size(); i++) v[i].first *= -1;
   return v;
}

vector<pii> flipUD(vector<pii> v){
   for(int i=0; i<v.size(); i++) v[i].second *= -1;
   return v;
}

vector<pii> flip_diag(vector<pii> v){
   for(int i=0; i<v.size(); i++) swap(v[i].first,v[i].second);
   return v;
}

vector<pii> flip_diag2(vector<pii> v){
   for(int i=0; i<v.size(); i++){
      swap(v[i].first,v[i].second);
      v[i].first *= -1; v[i].second *= -1;
   }
   return v;
}

void rotate(vector<pii>& v){
   for(int i=0; i<v.size(); i++){
      swap(v[i].first,v[i].second);
      v[i].first *= -1;
   }
}

pii operator-(pii a, pii b){
   return pii(a.first - b.first,a.second-b.second);
}

vector<pii> norm(vector<pii> v){
   sort(v.begin(),v.end(),Compare());
   pii p = v[0];
   for(int i=0; i<v.size(); i++) v[i] = v[i] - p;
   return v;
}

void process(set<pii,Compare> v, pii curr){
   if (v.size() == lim){
      vector<pii> w(v.begin(),v.end());
      bool ok = true;
      for(int i=0; i<4; i++){
         if (sol[lim].find(norm(w)) != sol[lim].end()) return;
         rotate(w);
      }
      
      if (sol[lim].find(norm(flipLR(w))) != sol[lim].end()) return;
      if (sol[lim].find(norm(flipUD(w))) != sol[lim].end()) return;
      if (sol[lim].find(norm(flip_diag(w))) != sol[lim].end()) return;
      if (sol[lim].find(norm(flip_diag2(w))) != sol[lim].end()) return;
      
      sol[lim].insert(norm(w));
      
      return;
   }
   
   vector<pii> tmp(v.begin(),v.end());
   for(int i=0; i<tmp.size(); i++){
      for(int j=0; j<4; j++){
         pii nxt(tmp[i].first+dx[j],tmp[i].second+dy[j]);
         if (nxt.second<0) continue;
         if (v.find(nxt) != v.end()) continue;
         v.insert(nxt);
         process(v,curr);
         v.erase(nxt);
      }
   }
}

ostream& operator<<(ostream& os, pii p){
   os<<"("<<p.first<<","<<p.second<<")";
   return os;
}

ostream& operator<<(ostream& os, vector<pii> v){
   os<<"[";
   for(int i=0; i<v.size(); i++){
      if (i) os<<" ";
      os<<v[i];
   }
   os<<"]";
   return os;
}

bool ok(vector<pii> v, int r, int c, int x, int y){
   int inside = 0;
   for(int i=0; i<v.size(); i++){
      pii nxt(x+v[i].first,y+v[i].second);
      if (nxt.first<0 || nxt.first>=r || nxt.second<0 || nxt.second>=c) continue;
      inside++;
   }
   return inside == (int)v.size();
}

int poly_size;

bool ok_tile(vector<pii> v, int r, int c, int x, int y){
   int grid[r][c];
   for(int i=0; i<r; i++) fill(grid[i],grid[i]+c,0);
   
   for(int i=0; i<v.size(); i++){
      pii nxt(x+v[i].first,y+v[i].second);
      grid[nxt.first][nxt.second]=1;
   }
   // all components must be divisible by poly_size
   for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
         if (grid[i][j]) continue;
         int area = 0;
         queue<pii> q; q.push(pii(i,j));
         grid[i][j] = 1;
         area++;
         
         while(!q.empty()){
            pii curr=q.front(); q.pop();
            for(int k=0; k<4; k++){
               pii nxt(curr.first+dx[k],curr.second + dy[k]);
               if (nxt.first<0 || nxt.first>=r || nxt.second<0 || nxt.second>=c) continue;
               if (grid[nxt.first][nxt.second]) continue;
               grid[nxt.first][nxt.second] = 1;
               q.push(nxt);
               area++;
            }
         }
         if (area % poly_size != 0) return false;
      }
   }
   return true;
}

int main(){
   for(int i=1; i<=6; i++){
      lim = i;
      set<pii,Compare> v;
      v.insert(pii(0,0));
      process(v,pii(0,0));
   }
   
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int x,r,c; scanf("%d%d%d",&x,&r,&c);
      poly_size = x;
      if (x>=7 || (r*c)%poly_size != 0){
         printf("Case #%d: RICHARD\n",cs+1);
         continue;
      }
      bool found = false;
      for(set<vector<pii> >::iterator it = sol[x].begin(); it != sol[x].end(); it++){
         vector<vector<pii> > v;
         vector<pii> w = *it;
         for(int i=0; i<4; i++){
            v.push_back(norm(w));
            rotate(w);
         }
         v.push_back(norm(flipLR(w)));
         v.push_back(norm(flipUD(w)));
         v.push_back(norm(flip_diag(w)));
         v.push_back(norm(flip_diag2(w)));
         
         bool flag = true;
         bool canFit = false;
         for(int z = 0; z < v.size(); z++){
            for(int i=0; i<r; i++){
               for(int j=0; j<c; j++){
                  if (ok(v[z],r,c,i,j)){
                     canFit = true;
                     if (ok_tile(v[z],r,c,i,j)){
                        flag = false; break;
                     }
                  }
               }
               if (!flag) break;
            }
            if (!flag) break;
         }
         // cout<<cs+1<<endl;
         // cout<<w<<endl;
         // for(int i=0; i<v.size(); i++) cout<<"\t"<<v[i]<<endl;
         // cout<<flag<<endl<<endl;
         if (flag){
            found = true;
            break;
         }
      }
      if (found) printf("Case #%d: RICHARD\n",cs+1);
      else printf("Case #%d: GABRIEL\n",cs+1);
   }
}