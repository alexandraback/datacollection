#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
 char back[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w','j', 'p', 'f', 'm', 'a', 'q'};
 char str[1000];
 int N, i, j, len;

 cin >> N;
 gets(str);
 for(i=0;i<N;i++)
 {
  gets(str);
  len = strlen(str);

  cout << "Case #" << i+1 << ": ";

  for(j=0;j<len;j++)
   if(str[j] >= 'a' && str[j] <= 'z')
    cout << back[str[j]-'a'];
   else
    cout << str[j];

  cout << endl;
 }

}
