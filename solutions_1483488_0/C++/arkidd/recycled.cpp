#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<set>
using namespace std;

int tc, i, j, k, l;
int a, b, temp;

int ans;

string s, t;
set<int> used;


int main(void){
    freopen("recycled.in", "r", stdin);
    freopen("recycled.out", "w", stdout);
    
    scanf("%d\n", &tc);
    for (i = 1; i <= tc; i++){
        scanf("%d %d", &a, &b);
        
        ans = 0;
        for (j = a; j <= b; j++){
            s = "";
            temp = j;
            while (temp > 0){
                s += (char)((temp%10)+'0');
                temp/=10;
            }
            reverse(s.begin(), s.end());
            
            used.clear();
            for (k = 1; k < s.length(); k++){
                t = "";
                t = s.substr(k,s.length()-k);
                t += s.substr(0,k);
                
                temp = 0;
                for (l = 0; l < t.length(); l++)
                    temp = (temp*10)+(t[l]-'0');
                
                if (a < temp && temp <= b && j < temp){
                   if (used.count(temp) <= 0){
                      ans++;
                      used.insert(temp);
                   }
                }
            }
        }
        
        printf("Case #%d: %d\n", i, ans);
    }    
    
    fclose(stdin);
    fclose(stdout);
    return 0;   
}
    
