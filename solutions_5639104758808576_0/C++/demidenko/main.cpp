#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
#include <unistd.h>
#include <wait.h>
using namespace std;
typedef long long ll;
const int __limitofthreads = 4;
vector<pid_t> __ids;
char __str[256];

const int N = 1e6+6;



void solve(int test){
    /*+++start read data+++*/
    
    int n;
    string s;
    cin>>n>>s;
    
    /*---end read data---*/
    if(__ids.size()>=__limitofthreads) wait(0);
    pid_t __id = fork();
    if(__id>0){
        __ids.push_back(__id);
        return ;
    }else{
        sprintf(__str, "thread%d.out", test);
        freopen(__str,"w",stdout);
    }
    /*+++start solution and write output+++*/
    
    int add = 0;
    int c = 0;
    for(int i=0;i<=n;++i){
        if(c<i){
            int x = i-c;
            add+=x;
            c+=x;
        }
        c+=s[i]-'0';
    }
    
    cout<<"Case #"<<test<<": ";
    cout<<add<<endl;
    
    /*---end solution---*/
    sprintf(__str, "test #%d ok.%c", test,10);
    cerr<<__str;
    exit(0);
}

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        solve(i);
    }
    
    /*combining outputs*/
    for(pid_t __id : __ids) waitpid(__id,0,0);
    int __bufsize = 1<<16;
    char *__buf = new char[__bufsize];
    for(int i=1;i<=t;++i){
        sprintf(__str, "thread%d.out", i);
        FILE *f = fopen(__str, "r");
        while(fgets(__buf, __bufsize, f)) printf("%s",__buf);
        fclose(f);
        remove(__str);
    }
    
    return 0;
}
