#include <stdio.h>

using namespace std;

#include <algorithm>

typedef struct {
  int st;
  int st2;
  int level;
}rating;

FILE *fin = fopen ("B-large.in","r");
FILE *fout = fopen ("b.out","w");

int n;
int stars;
int two_index;
int one_index;      
int counter;  

rating one_ls[1000];
rating two_ls[1000];

bool marked[1000];

bool operator<(const rating& p1 , const rating& p2){
  return p1.st < p2.st;
}

bool getOneLevel () {
  int max = -1;
  int result = -1;
  
  int one_index = 0;
  
  while (one_index < n) {
    int l = one_ls[one_index].level;
    
    if (!marked[l]) {
      if (one_ls[one_index].st <= stars && one_ls[one_index].st2 > max) {
        max = one_ls[one_index].st2;
        result = one_index;
      }
    }    
    one_index++;    
  }
  
  if (result != -1) {
    int l = one_ls[result].level;
    stars++;    
    marked[l]=true;
    counter++;
    return true;
  }
  
  return false;
}

int main () {
  int t;
  fscanf (fin,"%d",&t);    
        
  for (int i = 1; i <= t; i++) {
    fscanf (fin,"%d",&n);
  
    for (int j = 0; j < n; j++) {                
      int a,b;
      fscanf (fin,"%d%d",&a,&b);
      
      marked[j] = false;
    
      one_ls[j].st = a; one_ls[j].level = j;
      one_ls[j].st2 = b;
      
      two_ls[j].st = b; two_ls[j].level = j;      
    }
    
    stars = 0;
    counter = 0;
    two_index = 0;          
    
    sort (one_ls,one_ls+n);
    sort (two_ls,two_ls+n);
    
    while (two_index < n) {
      if (two_ls[two_index].st <= stars) {
        int l = two_ls[two_index].level;
        if (marked[l]) stars++;
        else {stars += 2; marked[l]=true;}
        
        two_index++; counter++;
      }
      else {
        if (!getOneLevel()) break;
      }
    }
    
    if (two_index < n)
      fprintf (fout,"Case #%d: Too Bad\n",i);    
    else
      fprintf (fout,"Case #%d: %d\n",i,counter);
  }
  
  return 0;
}
