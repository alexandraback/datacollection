#include <iostream>

using namespace std;

#define debug 0
char face[2]={'+', '-'};

int find(string s, int dir, char sym){
    int ret=0;
    string str=s;
    if(dir<0)
        reverse(str.begin(), str.end());
    
    for(auto &c: str){
        if(c==sym)
            break;
        ret++;
    }
    return ret;
}

void flip(string *s, int start, int n){
#if debug
    cout<<"flip: "<<*s;
#endif
    reverse(s->begin()+start, s->begin()+n);
#if debug
    cout<<" reversed: "<<*s<<endl;
#endif
    for(int i = 0; i < n; i++){
        s->at(i)= s->at(i) == face[0] ? face[1] : face[0];
    }
#if debug
    cout<<"fliped: "<<*s<<endl;
#endif
}

void solve(string s){
    int f = 0;
    while(s.length()>0){
        int len=s.length();
        int firstn = find(s, -1, face[1]);
        if(firstn==s.length()){
            cout<<f<<endl;
            break;
        }
        s.resize(len-firstn);
#if debug
        cout<<"truncated: "<<s<<endl;
#endif
        int nextn = find(s, 0, face[1]);
#if debug
        cout<<"next n: "<<nextn<<endl;
#endif
        if(nextn>0){
            flip(&s, 0, nextn);
            f++;
        }
        flip(&s, 0, s.length());
        f++;
#if debug
        getchar();
#endif
    }
}

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        char S[102];
        scanf("%s", S);
        string str=S;
        cout<<"Case #"<<i+1<<": ";
        solve(str);
    }
    return 0;
}
