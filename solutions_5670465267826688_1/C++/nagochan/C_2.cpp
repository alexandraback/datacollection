#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef long long LL;
typedef pair<int,int>            PI;
typedef map<PI, int> MPI;
typedef vector<int>	VI;
typedef vector< vector<int> >	VII;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair

//#define DEBUG

int array[256][256];

void init_array(void)
{
  char ci = 'i';
  char cj = 'j';
  char ck = 'k';
  array[ 1][ 1] = 1;
  array[ 1][ci] = ci;
  array[ 1][cj] = cj;
  array[ 1][ck] = ck;
  array[ci][ 1] = ci;
  array[ci][ci] = -1;
  array[ci][cj] = ck;
  array[ci][ck] = -cj;
  array[cj][ 1] = cj;
  array[cj][ci] = -ck;
  array[cj][cj] = -1;
  array[cj][ck] = ci;
  array[ck][ 1] = ck;
  array[ck][ci] = cj;
  array[ck][cj] = -ci;
  array[ck][ck] = -1;
}
int multiple(int a, int b)
{
  int flag = 1;
  if(a<0) {
    a = -a;
    flag = -flag;
  }
  if(b<0) {
    b = -b;
    flag = -flag;
  }
#ifdef DEBUG
//cout<<"multiple:"<<a<<","<<b<<","<<array[a][b]<<endl;
#endif
  return array[a][b];
}

int sub_small(int &flag, int &cal, LL L, LL X, string &s)
{
    int pos = 0;
    int yes = 1;
    /* stage 1 */
    while(pos < L && cal != 'i'){
      cal = multiple(cal, s[pos]);
      if(cal < 0) {
        cal = -cal;
        flag = -flag;
      }
      pos++;
    }
    if(pos==L) {
      yes = 0;
    }
#ifdef DEBUG
cout<<"stage1:"<<pos<<","<<yes<<endl;
#endif

    /* stage 2 */
    cal = 1;
    while(pos < L && cal != 'j'){
      cal = multiple(cal, s[pos]);
      if(cal < 0) {
        cal = -cal;
        flag = -flag;
      }
      pos++;
    }
    if(pos==L) {
      yes = 0;
    }
#ifdef DEBUG
cout<<"stage2:"<<pos<<","<<yes<<endl;
#endif
    /* stage 3 */
    cal = 1;
    while(pos < L){
      cal = multiple(cal, s[pos]);
      if(cal < 0) {
        cal = -cal;
        flag = -flag;
      }
      pos++;
    }
#ifdef DEBUG
cout<<"stage3:"<<pos<<","<<yes<<endl;
#endif
    if(yes == 1 && cal == 'k' && flag == 1) {
      return 1;
    }
    return 0;
}

int main(void)
{
  int T,t;
  init_array();
  cin>>T;
  for(t=1;t<=T;t++)
  {
    LL X, Lin, L;
    string sin;
    cin>>Lin>>X>>sin;
    string s;
    int yes = 0;
    if(X*Lin <= 40000){
      L = 0;
      for(LL x=0;x<X;x++){
        s+=sin;
        L += Lin;
      }
      X = 1;
      int flag = 1;
      int cal = 1;
      yes = sub_small(flag, cal, L, X, s);
    } else {
      s = sin;
      L = Lin;
      /* 少なくともL>=4かつX>=4 */
      /* まずはL1つ分の計算結果を求める */
      int flag = 1;
      int cal = 1;
      for(int pos=0;pos<L;pos++){
        cal = multiple(cal, s[pos]);
        if(cal < 0) {
          cal = -cal;
          flag = -flag;
        }
      }
#ifdef DEBUG
cout<<"stage2-1:"<<cal<<","<<flag<<endl;
#endif
      int flag_1 = 1;
      int cal_1 = 1;
      int flag_2 = flag;
      int cal_2 = cal;
      int find_flag1 = 0;
      int find_flag2 = 0;
      int post, posb;
      /* 先頭からiになる部分があるか計算
         最大でL 2つ分まで見ればよい */
      for(post=0;post<L;post++){
        cal_1 = multiple(cal_1, s[post]);
        if(cal_1 < 0) {
          cal_1  = -cal_1;
          flag_1 = -flag_1;
        }
        if(cal_1=='i'){
          find_flag1 = 1;
          break;
        }
        cal_2 = multiple(cal_2, s[post]);
        if(cal_2 < 0) {
          cal_2  = -cal_2;
          flag_2 = -flag_2;
        }
        if(cal_2=='i'){
          find_flag2 = 1;
          break;
        }
      }
#ifdef DEBUG
cout<<"stage2-2:"<<cal_1<<","<<flag_1<<","<<cal_2<<","<<flag_2<<endl;
#endif
      /* 後ろからkになる部分があるか計算
         最大でL 2つ分まで見ればよい */
      int flag_b_1 = 1;
      int cal_b_1 = 1;
      int flag_b_2 = flag;
      int cal_b_2 = cal;
      int find_flagb_1 = 0;
      int find_flagb_2 = 0;
      for(posb=L-1;posb>=0;posb--){
        cal_b_1 = multiple(s[posb], cal_b_1);
        if(cal_b_1 < 0) {
          cal_b_1  = -cal_b_1;
          flag_b_1 = -flag_b_1;
        }
        if(cal_b_1=='k'){
          find_flagb_1 = 1;
          break;
        }
        cal_b_2 = multiple(s[posb], cal_b_2);
        if(cal_b_2 < 0) {
          cal_b_2  = -cal_b_2;
          flag_b_2 = -flag_b_2;
        }
        if(cal_b_2=='k'){
          find_flagb_2 = 1;
          break;
        }
      }
#ifdef DEBUG
cout<<"stage2-3:"<<cal_b_1<<","<<flag_b_1<<","<<cal_b_2<<","<<flag_b_2<<endl;
#endif
      if(((find_flag1==1) || (find_flag2 == 1)) && ((find_flagb_1==1) || (find_flagb_2 == 1)))
      {
         LL L_rest = L;
        if(find_flag1){
          L_rest -= 1;
        } else {
          L_rest -= 2;
          flag_1 = flag_2;
        }
        if(find_flagb_1){
          L_rest -= 1;
        } else {
          L_rest -= 2;
          flag_b_1 = flag_b_2;
        }
        int cal_for_j = 1;
        /* iを計算したあとのLのあまり計算 */
        int i;
        for(i=post+1;i<L;i++){
          cal_for_j = multiple(cal_for_j, s[i]);
          if(cal_for_j < 0) {
            cal_for_j  = -cal_for_j;
            flag_1 = -flag_1;
          }
        }
        /* 真ん中のL全体が残っているところ */
        /* 4で割った余りで値が決まる(4回繰り返すと値が1になる) */
        L_rest %= 4;
        for(i=0;i<L_rest;i++){
          cal_for_j = multiple(cal_for_j, cal);
          flag_1 = flag_1 * flag;
          if(cal_for_j < 0) {
            cal_for_j  = -cal_for_j;
            flag_1 = -flag_1;
          }
        }
        /* kを計算したあとのLのあまり計算 */
        post++;
        for(i=0;i<posb;i++){
          cal_for_j = multiple(cal_for_j, s[i]);
          if(cal_for_j < 0) {
            cal_for_j  = -cal_for_j;
            flag_1 = -flag_1;
          }
        }
        flag_1 *= flag_b_1;
        if(cal_for_j == 'j' && flag_1 == 1){
          yes = 1;
        }
      }
    }


    if(yes == 1) {
      cout<<"Case #"<<t<<": "<<"YES"<<endl;
      yes = 0;
    } else {
      cout<<"Case #"<<t<<": "<<"NO"<<endl;
    }
  }
  return 0;
}

