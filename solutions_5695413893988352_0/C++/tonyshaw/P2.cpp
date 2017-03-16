#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;

char str1[4], str2[4];
int best1, best2;
char ret1[4], ret2[4];
void dfs(int now) {
  if (now==strlen(str1)) {
    int num1;
    int num2;
    num1=atoi(str1);
    num2=atoi(str2);
    if (abs(num1-num2)<abs(best2-best1)) {
      best1=num1;
      best2=num2;
      memcpy(ret1,str1,sizeof(str1));
      memcpy(ret2,str2,sizeof(str2));
      return;
    }
    if (abs(num1-num2)==abs(best1-best2)) {
      if (num1<best1) {
	best1=num1;
	best2=num2;
	memcpy(ret1,str1,sizeof(str1));
	memcpy(ret2,str2,sizeof(str2));
	return;
      }
      if (num1==best1) {
	if (num2<best2) {
	  best1=num1;
	  best2=num2;
	  memcpy(ret1,str1,sizeof(str1));
	  memcpy(ret2,str2,sizeof(str2));
	  return;
	}
      }
    }
    return;
  }
  if (str1[now]=='?') {
    for (int i=0;i!=10;i++) {
      if (str2[now]=='?') {
	for (int j=0;j!=10;j++) {
	  str1[now]=i+'0';
	  str2[now]=j+'0';
	  dfs(now+1);
	}
	str2[now]='?';
      } else {
	str1[now]=i+'0';
	dfs(now+1);
      }
    }
    str1[now]='?';
  } else if (str2[now]=='?') {
    for (int i=0;i!=10;i++) {
      str2[now]=i+'0';
      dfs(now+1);
    }
    str2[now]='?';
  } else {
    dfs(now+1);
  }
}
      

int main() {
  int t;
  scanf("%d\n",&t);
  for (int i=0;i!=t;i++) {
    scanf("%s",str1);
    scanf("%s\n",str2);
    best1=0;
    best2=10000;
    dfs(0);
    int cnt=0;
    printf("Case #%d: %s %s\n",i+1,ret1,ret2);
  }
}
