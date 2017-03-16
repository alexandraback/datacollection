#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;

#define maxN 1000
char s[maxN];
char f[maxN];

void init(){
    f['a']='y';   f['b']='h';   f['c']='e';
    f['d']='s';   f['e']='o';   f['f']='c';
    f['g']='v';   f['h']='x';   f['i']='d';
    f['j']='u';   f['k']='i';   f['l']='g';
    f['m']='l';   f['n']='b';   f['o']='k';
    f['p']='r';   f['q']='z';   f['r']='t';
    f['s']='n';   f['t']='w';   f['u']='j';
    f['v']='p';   f['w']='f';   f['x']='m';
    f['y']='a';   f['z']='q';   f[' ']=' ';
}

int main(){
    freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\test.txt","r",stdin);
    freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\ans.txt","w",stdout);
    init();
    int i,j,cs;
    cin>>cs;
    int n=0;
    gets(s);
    while(cs--){
        n++;
        gets(s);
        cout<<"Case "<<"#"<<n<<": ";
        for(i=0;s[i]!='\0';i++)
           printf("%c",f[s[i]]);
        cout<<endl;
    }
    return 0;
}
