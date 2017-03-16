#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char S[2100];
string numb[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int letters[10]['Z'+1];
int qtd['Z'+1];
string ans;

bool find(int n){
    if(n == 10){
        for(char ch='A'; ch<='Z'; ch++){
            if(qtd[ch]) return false;
        }
        
        return true;
    }
    
    int q = 3000;
    
    for(char ch='A'; ch<='Z'; ch++){
        if(letters[n][ch]){
            q = min(q, qtd[ch]/letters[n][ch]);
        }
    }
        
    for(int i=0; i<=q; i++){
        for(char ch='A'; ch<='Z'; ch++){
            qtd[ch] -= i*letters[n][ch];
        }
        
        if(find(n+1)){
            for(int j=0; j<i; j++) ans += (char)(n+'0');
            return true;
        }
        
        for(char ch='A'; ch<='Z'; ch++){
            qtd[ch] += i*letters[n][ch];
        }
    }
    
    return false;
}

int main(){
    memset(letters, 0, sizeof letters);
    
    for(int n=0; n<10; n++){
        for(int i=0; i<numb[n].size(); i++){
            letters[n][numb[n][i]]++;
        }
    }
    
    int T, tc = 0;
    scanf("%d", &T);
    
    while(T--){
        scanf("%s", S);
        
        memset(qtd, 0, sizeof qtd);
        
        for(int i=0; S[i]!='\0'; i++){
            qtd[S[i]]++;
        }
        
        ans = "";
        find(0);
        printf("Case #%d: ", ++tc);
        
        for(int i=ans.size()-1; i>=0; i--) printf("%c", ans[i]);
        printf("\n");
    }
}
