#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
int result = INT_MAX;
string resS, resT;
int cal(string& s, string& t){
    int a=0, b=0;
    for(int i=0;i<s.length();i++){
        a*=10;
        b*=10;
        a+=(s[i]-'0');
        b+=(t[i]-'0');
    }
    return abs(a-b);
}
void DFS(string& s, string& t, int depth){
    if(depth==s.length()){
        int res = cal(s, t);
        //cout << s << ' ' << t << ' ' << res << endl;
        if(res<result){
            result=res;
            resS = s;
            resT = t;
        }
        return;
    }
    if(s[depth]!='?' && t[depth]!='?'){
        DFS(s, t, depth+1);
    }else if(s[depth]=='?' && t[depth]=='?'){
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                s[depth] = '0'+i;
                t[depth] = '0'+j;
                DFS(s, t, depth+1);
                s[depth] = '?';
                t[depth] = '?';
            }
            
        }
    }else if(s[depth]=='?' && t[depth]!='?'){
        for(int i=0;i<=9;i++){
            s[depth] = '0'+i;
            DFS(s, t, depth+1);
            s[depth] = '?';
        }
        
    }else{
        for(int i=0;i<=9;i++){
            t[depth]='0'+i;
            DFS(s, t, depth+1);
            t[depth]='?';
        }
        
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int k=0; k<t; k++)
    {
        string s;
        cin >> s;
        string t;
        cin >> t;
        DFS(s, t, 0);
        cout << "Case #" << k+1 << ": " << resS << " " << resT << endl;
        result = INT_MAX;
    }
    return 0;
}
