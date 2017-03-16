#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 100
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

using namespace std;

void quick_sort(int *array,int low,int high) {  
   int pivot_point,pivot_item,i,j,temp;  
   if(high<=low){return;}  
  
   pivot_item = array[low];  
   j=low;  
     
   for(i=low+1; i<=high; i++) {  
       if(array[i]>=pivot_item){continue;}  
  
       j++;  
       temp = array[i];  
       array[i] = array[j];  
       array[j] = temp;  
   }  
  
   pivot_point=j;  
   temp = array[low];  
   array[low] = array[pivot_point];  
   array[pivot_point] = temp;  
  
   quick_sort(array,low,pivot_point-1);  
   quick_sort(array,pivot_point+1,high);  
  
   return;  
}  

bool atLeaseP(const int P, const int p1, const int p2, const int p3)
{
  if(p1 >= P)
    return true;
  else if(p2 >= P)
    return true;
  else if(p3 >= P)
    return true;
  return false;
}

int main() {
  int T;
  int tc = 1;
  scanf("%d", &T);
  while(tc <= T)
  {
    int N; // nb of Googlers
    int S; // target nb of surprising
    int P; // threshold
    scanf("%d %d %d", &N, &S, &P);
    int nbS = 0; // nb of suprising
    int nbP = 0; // nb of Googlers who got at least one score of P or better.
    int ALLTI[MAX] = {0};
    for(int i = 0; i < N; ++i) 
    {
      int ti; // personal score
      scanf("%d", &ti);
      ALLTI[i] = ti;
    }
    quick_sort(ALLTI, 0, N - 1); 
    for(int i = N - 1; i >= 0; --i)
    {
      int ti = ALLTI[i];
      int r = ti % 3;
      int q = ti / 3;
      int p1 = 0;
      int p2 = 0;
      int p3 = 0;
      if(0 == r) {
        p1 = q;
        p2 = q;
        p3 = q;
        if(atLeaseP(P, p1, p2, p3)) {
          // if we can exceed threashold without using surprising
          ++ nbP;
        } else {
          p1 = q - 1;
          p2 = q;
          p3 = q + 1;
          if((p1 >= 0) && (p3 <= 10) && atLeaseP(P, p1, p2, p3) && (nbS < S)) {
            // don't exceed threashold  
            // could over threashold
            // and can use surprising
            // -> we use surprising to exceed threashold
            ++ nbP;
            ++ nbS;
          } else {
            // can not exceed threashold
          }
        }
      } else if(1 == r) {
        p1 = q;
        p2 = q;
        p3 = q + 1;
        if(atLeaseP(P, p1, p2, p3)) {
          // if we can exceed threashold without using surprising
          ++ nbP;
        } else {
          p1 = q - 1;
          p2 = q + 1;
          p3 = q + 1;
          if((p1 >= 0) && (p3 <= 10) && atLeaseP(P, p1, p2, p3) && (nbS < S)) {
            // don't exceed threashold  
            // could over threashold
            // and can use surprising
            // -> we use surprising to exceed threashold
            ++ nbP;
            ++ nbS;
          } else {
            // can not exceed threashold
          }
        }
      } else {
        p1 = q;
        p2 = q + 1;
        p3 = q + 1;
        if(atLeaseP(P, p1, p2, p3)) {
          // if we can exceed threashold without using surprising
          ++ nbP;
        } else {
          p1 = q;
          p2 = q;
          p3 = q + 2;
          if((p1 >= 0) && (p3 <= 10) && atLeaseP(P, p1, p2, p3) && (nbS < S)) {
            // don't exceed threashold  
            // could over threashold
            // and can use surprising
            // -> we use surprising to exceed threashold
            ++ nbP;
            ++ nbS;
          } else {
            // can not exceed threashold
          }
        }
      }
    }
    printf("Case #%d: %d\n", tc, nbP);
    ++tc;
  }
}
