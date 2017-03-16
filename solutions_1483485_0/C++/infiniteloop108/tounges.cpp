#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void convert(char arr[100])
{for(int i=0;arr[i]!='\0';i++)
{
switch(arr[i])
{
case 'a' : arr[i]='y';break; 
case 'b' : arr[i]='h';break;
case 'c' : arr[i]='e';break;
case 'd' : arr[i]='s';break;
case 'e' : arr[i]='o';break;
case 'f' : arr[i]='c';break;
case 'g' : arr[i]='v';break;
case 'h' : arr[i]='x';break;
case 'i' : arr[i]='d';break;
case 'j' : arr[i]='u';break;
case 'k' : arr[i]='i';break;
case 'l' : arr[i]='g';break;
case 'm' : arr[i]='l';break;
case 'n' : arr[i]='b';break;
case 'o' : arr[i]='k';break;
case 'p' : arr[i]='r';break;
case 'q' : arr[i]='z';break;
case 'r' : arr[i]='t';break;
case 's' : arr[i]='n';break;
case 't' : arr[i]='w';break;
case 'u' : arr[i]='j';break;
case 'v' : arr[i]='p';break;
case 'w' : arr[i]='f';break;
case 'x' : arr[i]='m';break;
case 'y' : arr[i]='a';break;
case 'z' : arr[i]='q';break;
}
}
}
int main()
{
ifstream fin("s.in");
ofstream fout("s.out");
int t;
fin>>t;
fin.get();
char a[1000];
for(int i=0;i<t;++i)
{
fin.getline(a,1000,'\n');
convert(a);
fout<<"Case #"<<i+1<<": "<<a<<endl;
}
return 0;
}
