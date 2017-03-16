#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int hibas10;
int pangkat;

int func(int A, int i, int B){
  int bas10 = 1;
  int mov;
  int ctr = 0;
  int temp;
  int arr[10], idxarr=0;
  bool add;
  
  for(int j=0; j<pangkat; j++){
    bas10 *= 10;
    temp = i;
    mov = temp%bas10;
    temp /= bas10;
    //if(i==1212)printf("bas10=%d mov=%d temp=%d\n", bas10, mov, temp);
    temp += (mov*(hibas10/bas10));
    //if(i==1212)printf("hibas=%d temp=%d ctr=%d\n", hibas10, temp, ctr);
    add = true;
    for(int k=0; k<idxarr; k++){
      //if(i==1212) printf("idxarr = %d, arr=%d\n", idxarr, arr[0]);
      if(arr[k] == temp) {
        add = false; 
        break;
      }
    }
    if(temp <= B && temp >= A && temp!=i && add) ctr++;
    arr[idxarr] = temp;
    idxarr++;
  }
  
  //if(i==1212)printf("i=%d, ctr=%d\n", i, ctr);
  return ctr;
}

int main(){
  int jcase;
  int A, B;
  long long count;
  int temp;
  
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase < jcase; icase++){
    scanf("%d %d", &A, &B);
    
    count = pangkat = 0;
    temp = A;
    hibas10 = 10;
    while(temp >= 10){
      temp /= 10;
      hibas10 *= 10;
      pangkat++;
    }
    
    for(int i=A; i<=B; i++){
      count = count + func(A, i, B);
    }
    
    printf("Case #%d: %lld\n", icase+1, count/2);
  }
  return 0;
}
