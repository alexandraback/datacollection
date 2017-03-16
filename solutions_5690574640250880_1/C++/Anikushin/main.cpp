#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define hash hash_asdjkhasjkdh
#define se second
#define next next_aslkjdhasmnhd
#include<string>
#include <iomanip>
#include <queue>
#include<string>
using namespace std;

bool check(vector<vector<int> > a, int x, int y, int n, int m, int fr) {
  vector<vector<int> > b(a);
  if (b[x][y] == 0)
    return false;
   queue<int> och;
   och.push(x*m+y);
   int u = 0;
   b[x][y] = 2;
   while(och.size() > 0) {
     u += 1;
     int k = och.front();
     och.pop();
     int i = k / m;
     int j = k % m;
     int mines = 0;
     for (int dx = -1; dx < 2; dx++){
       for (int dy = -1; dy < 2; dy++){
         if (i+dx >=0 && i+dx < n && j+dy>=0 && j+dy < m){
           mines += (b[i+dx][j+dy] == 0);
         }
       }
     }
     if (mines==0){
       for (int dx = -1; dx < 2; dx++){
         for (int dy = -1; dy < 2; dy++){
           if (i+dx >=0 && i+dx < n && j+dy>=0 && j+dy < m){
             if (b[i+dx][j+dy] == 1) {
               och.push((i+dx)*m+j+dy);
               b[i+dx][j+dy] = 2;
             }
           }
         }
       }
     }
   }
   return (u == fr);
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("outputLarge.txt", "w", stdout);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++){ 
    string ans;
    int n,m,k;
    cin >> n >> m >> k;
    int fr = n*m - k;
    if (fr == 1) {
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          ans += "*";
        }
        ans += "#";
      }
      ans[0] ='c';
    }
    else if (n+m != n*m + 1 && fr < 4)
       ans = "Impossible#";
    else {
      if (n+m == n*m + 1) {
        if (n == 1) {
          ans = "c";
          for (int i=0;i<fr-1;i++) {
            ans += '.';
          }
          for(int i=0;i<k;i++) {
            ans += '*';
          }
          ans += '#';
        }
        else {
          ans = "c#";
          for (int i=0;i<fr-1;i++) {
            ans += ".#";
          }
          for(int i=0;i<k;i++) {
            ans += "*#";
          }
        }
      }
      else {
        vector<vector<int> > a(max(n,m), vector<int> (max(n,m),0));
        bool trans = false;
        trans = n < m;
        if (n < m) {
          swap(n,m);
        }
        if (m == 2) {
          if (fr % 2 == 1) {
            ans = "Impossible#";
          }
          else {
            for (int i = 0; i < fr/2;i++) {
              a[i][0] = 1;
              a[i][1] = 1;
            }
          }          
        }
        else{
          if (fr % 2 == 1 && fr < 9) {
            ans = "Impossible#";
          }
          else if (fr < 11) {
            a[0][0] = a[0][1] = a[1][0] = a[1][1] = 1;
            if (fr > 4) {
              a[0][2] = a[1][2] = 1;
            }
            if (fr > 6) {
              a[2][0] = a[2][1] = 1;
            }
            if (fr == 9) {
              a[2][2] = 1;
            }
            else if (fr == 10) {
              a[3][0] = a[3][1] = 1;
            }
          }
          else {
            a[0][0] = a[0][1] = a[1][0] = a[1][1] = 1;
            a[0][2] = a[1][2] = a[2][0] = a[2][1] = 1;
            a[2][2] = 1;
            int w = min(fr / 3 , m);
            int ww = fr % 3;
            for (int i = 0; i < w; i ++) {
              a[0][i]=a[1][i]=a[2][i] = 1;
            }
            int other = fr - w*3;
            int l = 2;
            while (other > m) {
              l++;
              for(int i=0; i<m; i++) {
                a[l][i] = 1;
              }
              other -=  m;
            }
            if (other == 1) {
              a[l+1][0] = a[l+1][1] =1;
              a[l][w-1] = 0;
            }
            else {
              for(int i=0; i<other; i++) {
                a[l+1][i] = 1;
              }
            }
          }
        }
        if (ans.size() == 0) {
          if (!check(a,0,0,n,m,fr)){
            cerr << t+1 << endl;
          }
          if (trans) {
            for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                char c = '*';
                if (a[j][i] == 1)
                  c = '.';
                ans += c;
              }         
              ans += "#";
            }
          }
          else {
            for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                char c = '*';
                if (a[i][j] == 1)
                  c = '.';
                ans += c;
              }         
              ans += "#";
            }
          }
          ans[0] = 'c';
        }
      }
    }
    cout << "Case #" << t + 1 << ":\n";
    for (int i=0; i < ans.size();i++){
      if (ans[i] == '#') {
        cout << endl;
      }
      else
        cout << ans[i];
    }
  }
  return 0;
}