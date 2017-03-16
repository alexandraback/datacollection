#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

char name[1000000+10];
int n;
int L;
int compo;  // components count
int cons[1000000+10]; // the length of consecutive consonant/vowel, start with conso
int chartype[256];  // 0 is vowel, 1 is conso

void readData() {
  scanf("%s %d",&name,&n);

  //printf("read [%s] [%d]\n",name,n);
  L = strlen(name);
/*

  //gen len
  int prev,curr;
  int count = 0;
  curr = 1;
  compo = 0;
  for (int i = 0;i < L;i++) {
    if (chartype[name[i]] != curr) {
      //write current
      cons[compo] = count;
      compo++;
      curr = chartype[name[i]];
      count = 0;
    }
    count++;
  }
  cons[compo] = count;
  compo++;

  printf("compo \n");
  for (int i = 0;i < compo;i++) {
    printf("%d ",cons[i]);
  }
  printf("\n");
  */

}

/*
unsigned long long int process() {
  unsigned long long int  sum = 0;
  unsigned long long int  curr = 0;
  int start = 0;
  for (int i = 0; i < compo;i++) {
    printf("calc at str pos %d (compo = %d)\n",start,i);
    if (cons[i] >= n) {
      curr = 0;
      int pos;
      for (int j = 0;j <= cons[i]-n;j++) {
        pos = start + j;
        curr += (pos + 1) * (L - (pos + n - 1));
      }
    }
    printf("got %d\n",curr);
    sum+= curr;
    start += cons[i];
    i++;
    start += cons[i];
  }
  return sum;
}
*/

unsigned long long int process() {
  unsigned long long int  sum = 0;
  unsigned long long int startable = 0;

  //gen len
  int curr;
  int count = 0;
  int lastStartable;
  lastStartable = -1;
  curr = 1;
  for (int i = 0;i < L;i++) {
    if (chartype[name[i]] != curr) {
      curr = chartype[name[i]];
      count = 0;
    }
    count++;

    if (curr == 1 && count >= n) { //is conso
      startable++;
      lastStartable = i;

      //try end here
      sum += i-n+2;
    } else {
      if (lastStartable != -1)
        sum += lastStartable - n + 2;
    }
  }

  return sum;
}


int main()
{
  freopen("A-small-attempt0(2).in","r",stdin);


  //preprocess

  for (int i = 0;i < 256;i++) {
    chartype[i] = 1;
  }
  chartype['a'] = chartype['e'] = chartype['i'] = chartype['o'] = chartype['u']=0;
  int t,T;
  scanf("%d",&T);
  for (int t = 1;t <= T;t++) {
    readData();
    unsigned long long int ans;
    ans = process();
    printf("Case #%d: %llu\n",t,ans);
  }

}
