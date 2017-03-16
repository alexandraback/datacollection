#include<iostream>
#include<algorithm>
#include<utility>
#define N 2000
using namespace std;
pair<int,int> ones[N];
pair<int,int> twos[N];
int xx[N];
int yy[N];
bool used[N];
int main() {
  int cas;
  cin>>cas;
  for(int ca=1; ca<=cas; ++ca){
    int n,x,y;
    cin>>n;
    for(int i=0; i<n; ++i){
      cin>>x>>y;
      xx[i] = x;
      yy[i] = y;
      ones[i] = make_pair(x,i);
      twos[i] = make_pair(y,i);
    }
    sort(ones, ones+n);
    sort(twos, twos+n);

    memset(used, 0, sizeof(used));
    int ctn = 0;
    int stars = 0;
    int on = 0;
    int tn = 0;
    bool hul = false;
    while(tn < n) {
      if (twos[tn].first > stars) {
        if (on >= n || ones[on].first > stars) {
          hul = true;
          break;
        } else {
          bool found = !used[ones[on].second];
          int Fon = on+1;
          int use = on;
          int cy = found ? yy[ones[on].second] : 0;
          while(Fon < n && ones[Fon].first<=stars){
            int id = ones[Fon].second;
            if( !used[id]) {
              found = true;
              if (yy[id] > cy) {
                use = Fon;
                cy = yy[id];
              }
            }
            ++Fon;
          }

          if (found){
            pair<int, int> tmp = ones[use];
            ones[use] = ones[on];
            ones[on] = tmp;
            used[ones[on].second] = true;
            stars++;
            on++;
            ctn++;
          } else {
            on++;
          }
        }
      } else {
        if (used[twos[tn].second]) {
          stars++;
        } else {
          used[twos[tn].second] = true;
          stars+=2;
        }
        tn++;
      }
    }

    cout<<"Case #"<<ca<<": ";
    if (hul) cout<<"Too Bad"<<endl;
    else cout<<(ctn+n)<<endl;
  }

}
