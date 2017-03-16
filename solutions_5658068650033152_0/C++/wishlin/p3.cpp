#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int cas, lenx, leny, num, res;
int arr[100][100];

int block(int p, int q) {
  if (arr[p][q]) return 1;
  int cnt=0;
  for (int i=p-1; i>=0; --i)
    if (arr[i][q]) {++cnt; break;}
  for (int i=p+1; i<lenx; ++i)
    if (arr[i][q]) {++cnt; break;}
  for (int i=q-1; i>=0; --i)
    if (arr[p][i]) {++cnt; break;}
  for (int i=q+1; i<leny; ++i)
    if (arr[p][i]) {++cnt; break;}
  return cnt==4;
}

int count_map() {
  int ret=0;
  for (int i=0; i<lenx; ++i)
  for (int j=0; j<leny; ++j)
    ret+=block(i,j);
  return ret;
}

int sol(int less) {
  vector<int> marks;
  for (int i=0; i<lenx; ++i)
  for (int j=0; j<leny; ++j)
    marks.push_back(0);
  for (int i=0; i<less; ++i) marks[i]=1;

  sort(marks.begin(), marks.end());
  do { //for (int i=0; i<marks.size(); ++i) cout<<marks[i]<<" "; cout<<endl;
    int idx=0;
    for (int i=0; i<lenx; ++i)
    for (int j=0; j<leny; ++j)
      arr[i][j]=marks[idx++];
    if (count_map()==num) return 1;
  } while ( next_permutation(marks.begin(), marks.end()) );

  return 0;
}

int main() {
  scanf("%d",&cas);
  for (int k=1; k<=cas; ++k) {
    scanf("%d %d %d",&lenx,&leny,&num);
    res=num;
    while (res>1 && sol(res-1)) --res;
    printf("Case #%d: %d\n",k,res);
  }
  return 0;
}
