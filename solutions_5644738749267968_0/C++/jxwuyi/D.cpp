#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<random>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

char str[100];
int pw[10];
int getint() {
  scanf("%s", str);
  int l = strlen(str);
  while(l < 7) str[l ++] = '0';
  str[l] = str[l + 1] = 0;
  int d;
  sscanf(str + 2, "%d", &d);
  return d;
}

int N;

int main() {
  pw[0] = 1;
  for(int i=1;i<10;++i)
    pw[i] = pw[i - 1] * 10;
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
  ofstream fout("log.txt");
  int test;
  scanf("%d", &test);
  for(int no = 1; no <= test; ++ no) {
    scanf("%d", &N);
    vector<int>A,B;
    vector<pair<int,int> > R;
    for(int i=0;i<N;++i){
      A.push_back(getint());
      
    //  fout << A.back() / 100 << " ";
      
      R.push_back(make_pair(A.back(), 1));
    }
    //fout << endl;
    for(int i=0;i<N;++i){
      B.push_back(getint());
      
    //  fout << B.back() / 100 << " ";
      R.push_back(make_pair(B.back(), -1));
    }
    //fout << endl;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    /*
    for(auto i: A)
      fout << i/100<<" ";fout<<endl;
    for(auto i: B)
      fout << i/100<<" ";fout<<endl;
    */
    sort(R.begin(), R.end());
    
    int ans = 0;
    int l = 0, r = N - 1;
    for(int i = 0; i < N; ++ i) {
      int x = A[i];
      if(x > B[l]){
        ++ ans; ++ l;
      } else {
        -- r;
      }
    }
    int old = 0;
    int sum = 0;
    for(int i=R.size()-1;i>=0;--i){
      sum += R[i].second;
      if(sum > old) old = sum;
    }
    printf("Case #%d: %d %d\n", no, ans, old);
  }
}
