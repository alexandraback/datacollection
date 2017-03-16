#include<iostream>
#include<cstdio>
using namespace std;

char s[3000];
void work()
{
  scanf("%s", s);
  int n = strlen(s);
  int p = n;
  string head, tail;
  while (p> 0){
    char max = 0;
    int pos;
    for (int i = 0; i < p;i++){
      if(s[i] > max){
	max = s[i];
	pos = i;
      }
    }

    string temptail;
    for(int i = pos; i <p; i++){
      if (s[i] == max)
	head += s[i];
      else
	temptail += s[i];
    }
    tail = temptail + tail;
    p = pos;
  }
  cout << head << tail << endl;
}
int main()
{
  int T;
  scanf("%d",&T);
  for(int i =1; i <=T; i++){
    printf("Case #%d: ", i);
    work();
  }
}
