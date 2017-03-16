#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

unordered_map< char, unordered_map<char, char> > t;
unordered_map< char, unordered_map<char, int> > ft;

void init(){
  t['1']['1'] = '1';
  t['1']['i'] = 'i';
  t['1']['j'] = 'j';
  t['1']['k'] = 'k';

  t['i']['1'] = 'i';
  t['i']['i'] = '1';
  t['i']['j'] = 'k';
  t['i']['k'] = 'j';

  t['j']['1'] = 'j';
  t['j']['i'] = 'k';
  t['j']['j'] = '1';
  t['j']['k'] = 'i';

  t['k']['1'] = 'k';
  t['k']['i'] = 'j';
  t['k']['j'] = 'i';
  t['k']['k'] = '1';


  ft['1']['1'] = 1;
  ft['1']['i'] = 1;
  ft['1']['j'] = 1;
  ft['1']['k'] = 1;

  ft['i']['1'] = 1;
  ft['i']['i'] = -1;
  ft['i']['j'] = 1;
  ft['i']['k'] = -1;

  ft['j']['1'] = 1;
  ft['j']['i'] = -1;
  ft['j']['j'] = -1;
  ft['j']['k'] = 1;

  ft['k']['1'] = 1;
  ft['k']['i'] = 1;
  ft['k']['j'] = -1;
  ft['k']['k'] = -1;
}

int main(){
  /* freopen("C-my.in", "r", stdin); */
  /* freopen("C-large.in", "r", stdin); */
  /* freopen("C-large.ans", "w", stdout); */

  init();

  int T;
  cin >> T;

  for(int x = 1; x <= T; x++){
    long long L, X;
    string S;

    cin >> L >> X;
    cin >> S;

    vector<char> f(L);
    vector<int> ff(L);
    vector<char> b(L);
    vector<int> fb(L);

    f[0] = S[0];
    ff[0] = 1;
    for(int i = 1; i < L; i++){
      ff[i] = ff[i - 1] * ft[ f[i - 1] ][ S[i] ];
      f[i] = t[ f[i - 1] ][ S[i] ];
    }

    b[L - 1] = S[L - 1];
    fb[L - 1] = 1;
    for(int i = L - 2; i >= 0; i--){
      fb[i] = fb[i + 1] * ft[ S[i] ][ b[i + 1] ];
      b[i] = t[ S[i] ][ b[i + 1] ];
    }

    char circle = f[L - 1];
    int fcircle = ff[L - 1];

    /* cout << "circle = " << circle << "\tfcircle = " << fcircle << endl; */

    int iLen = -1, iCnt = -1;
    bool foundi = false;
    for(int cnt = 0; cnt < 10 && !foundi; cnt++){
      char pre = '1';
      int fpre = 1;
      /* cout << fpre << " " << fcircle << " " << ft[ pre ][ circle ] << endl; */
      for(int i = 0; i < cnt; i++){
        fpre = fpre * fcircle * ft[ pre ][ circle ];
        pre = t[pre][circle];
      }
      /* cout << "pre = " << pre << "\tfpre = " << fpre << endl; */
      for(int i = 0; i < L; i++){
        int flag = fpre * ff[i] * ft[ pre ][ f[i] ];
        /* cout << "test " << cnt << "\t" << i << "\t"; */
        /* cout << t[pre][ f[i] ] << "\t" << flag << endl; */
        if(t[pre][ f[i] ] == 'i' && flag == 1){
          iLen = cnt * L + i + 1;
          iCnt = cnt;
          foundi = 1;
          break;
        }
      }
    }

    int kLen = -1, kCnt = -1;
    bool foundk = false;
    for(int cnt = 0; cnt < 10 && !foundk; cnt++){
      char suf = '1';
      int fsuf = 1;
      for(int i = 0; i < cnt; i++){
        fsuf = fsuf * fcircle * ft[ circle ][ suf ];
        suf = t[suf][circle];
      }
      for(int i = L - 1; i >= 0; i--){
        int flag = fsuf * fb[i] * ft[ b[i] ][ suf];
        /* cout << "test " << cnt << "\t" << i << "\t"; */
        /* cout << t[ b[i] ][ suf ] << "\t" << flag << endl; */
        if(t[ b[i] ][suf] == 'k' && flag == 1){
          kLen = cnt * L + L - i;
          kCnt = cnt;
          foundk = 1;
          break;
        }
      /* cout << "" << cnt << "\t" << i << endl; */
      }
    }

/* cout << "iLen = " << iLen << "\tjLen = " << kLen << endl; */
    if(foundi && foundk && ((long long)iLen + kLen < ((long long) L * X))){
      char mid = '1';
      int fmid = 1;

      if(iCnt + kCnt + 2 < X){
        for(int i = iLen % L; i != 0 && i < L; i++){
          fmid = fmid * ft[mid][ S[i] ];
          mid = t[mid][ S[i] ];
/* cout << "mid = " << mid << "\tfmid = " << fmid << endl; */
        }
        long long loopTimes = X - iCnt - kCnt - 2;
        char pcircle = '1';
        char tcircle = circle;
        int pfcircle = 1;
        int tfcircle = fcircle;

        while(loopTimes){
          if(loopTimes & 1){
            pfcircle = pfcircle * tfcircle * ft[pcircle][tcircle];
            pcircle = t[pcircle][tcircle];
          }

          tfcircle = ft[tcircle][tcircle];
          tcircle = t[tcircle][tcircle];
          loopTimes >>= 1;
        }
/* cout << "loop mid = " << mid << "\tfmid = " << fmid << endl; */
        fmid = fmid * pfcircle * ft[mid][ pcircle ];
        mid = t[mid][pcircle];

        for(int i = 0; i < (L - (kLen % L)) % L; i++){
          fmid = fmid * ft[mid][ S[i] ];
          mid = t[mid][ S[i] ];
/* cout << "mid = " << mid << "\tfmid = " << fmid << endl; */
        }
      }else if(iCnt + kCnt + 2 == X){
        for(int i = iLen % L; i < L; i++){
          fmid = fmid * ft[mid][ S[i] ];
          mid = t[mid][ S[i] ];
/* cout << "mid = " << mid << "\tfmid = " << fmid << endl; */
        }
        for(int i = 0; i < (L - (kLen % L)) % L; i++){
          fmid = fmid * ft[mid][ S[i] ];
          mid = t[mid][ S[i] ];
/* cout << "mid = " << mid << "\tfmid = " << fmid << endl; */
        }

      }else{
        for(int i = iLen; i < L - (kLen % L); i++){
          fmid = fmid * ft[mid][ S[i] ];
          mid = t[mid][ S[i] ];
/* cout << "mid = " << mid << "\tfmid = " << fmid << endl; */
        }
      }
/* cout << "mid = " << mid << "\tfmid = " << fmid  << "\t" << (mid == 'j' && fmid == 1)<< endl; */
      if(mid == 'j' && fmid == 1){
        cout << "Case #" << x << ": YES" << endl;
      }else{
        cout << "Case #" << x << ": NO" << endl;
      }
    }else{
      cout << "Case #" << x << ": NO" << endl;
    }
  }
}

