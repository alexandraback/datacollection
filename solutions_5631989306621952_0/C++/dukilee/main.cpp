#include <bits/stdc++.h>

using namespace std;

void solvre(string s){
    deque<char> de;
    int tam = s.length();

    de.push_back(s[0]);
    for(int i = 1; i<tam; i++){
        if(de.front()<=s[i]){
            de.push_front(s[i]);
        }else{
            de.push_back(s[i]);
        }
    }
    while(!de.empty()){
        printf("%c", de.front());
        de.pop_front();
    }
    printf("\n");

}

int main(){
    int n;
    string s;

    cin>>n;
    for(int i = 1; i<=n; i++){
        printf("Case #%d: ", i);
        cin>>s;
        solvre(s);
    }
}
