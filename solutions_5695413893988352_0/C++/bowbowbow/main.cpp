#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <map>
using namespace std;

#define ull unsigned long long
int tmp = 0, len;
long long ans, ansA, ansB;

void back(string &a, string &b, int i, int s){
    char nowa = a[i], nowb = b[i];
    
    if(i == len){
        long long tmpA = stoll(a);
        long long tmpB = stoll(b);
        
        long long diff = abs(tmpA-tmpB);
        if(diff == ans){
            if(ansA > tmpA){
                ansB = tmpB;
                ansA = tmpA;
            }else if(ansA == tmpA){
                if(ansB > tmpB){
                    ansB = tmpB;
                    ansA = tmpA;
                }
            }
        }else if(diff < ans){
            ansA = tmpA;
            ansB = tmpB;
            ans = min(ans, diff);
        }
        return;
    }
    
    if(a[i] == '?' && b[i] == '?'){
        
        if(s == 1){
            
            a[i] = '0', b[i] = '9';
            back(a, b, i+1, 1);
            a[i] = nowa, b[i] = nowb;
            
        }else if(s == 0){
            
            a[i] = '1', b[i] = '0';
            back(a, b, i+1, 1);
            a[i] = nowa, b[i] = nowb;
            
            a[i] = '0', b[i] = '1';
            back(a, b, i+1, -1);
            a[i] = nowa, b[i] = nowb;
            
            a[i] = '0', b[i] = '0';
            back(a, b, i+1, 0);
            a[i] = nowa, b[i] = nowb;
            
        }else if(s == -1){
            
            a[i] = '9', b[i] = '0';
            back(a, b, i+1, -1);
            a[i] = nowa, b[i] = nowb;
            
        }
    }else if(a[i] == '?' && b[i] != '?'){
        
        if(s == 1){
            a[i] = '0';
            back(a, b, i+1, 1);
            a[i] = nowa;
            
        }else if(s == 0){
            
            a[i] = '0'+(b[i]-'0'+1)%10;
            back(a, b, i+1, 1);
            a[i] = nowa, b[i] = nowb;
            
            a[i] = b[i];
            back(a, b, i+1, 0);
            a[i] = nowa, b[i] = nowb;
            
            a[i] = '0'+(b[i]-'0'-1+10)%10;
            back(a, b, i+1, -1);
            a[i] = nowa, b[i] = nowb;
            
            
        }else if(s == -1){
    
            a[i] = '9';
            back(a, b, i+1, -1);
            a[i] = nowa; b[i] = nowb;
        }
        
    }else if(a[i] != '?' && b[i] == '?'){
        
        if(s == 1){
            b[i] = '9';
            back(a, b, i+1, 1);
            a[i] = nowa; b[i] = nowb;
            
        }else if(s == 0){
            
            b[i] = '0'+(a[i]-'0'+1)%10;
            back(a, b, i+1, 1);
            a[i] = nowa, b[i] = nowb;
            
            b[i] = a[i];
            back(a, b, i+1, 0);
            a[i] = nowa, b[i] = nowb;
            
            b[i] = '0'+(a[i]-'0'-1+10)%10;
            back(a, b, i+1, -1);
            a[i] = nowa, b[i] = nowb;
            
            
        }else if(s == -1){
            
            b[i] = '0';
            back(a, b, i+1, -1);
            a[i] = nowa; b[i] = nowb;
        }

        
    }else{
        
        if(s == 1){
            back(a, b, i+1, 1);
        }else if(s == 0){
            
            if(a[i] > b[i]){
                back(a, b, i+1, 1);
                
            }else if(a[i] == b[i]){
                back(a, b, i+1, 0);
                
            }else if(a[i] < b[i]){
                back(a, b, i+1, -1);
            }
            
        }else if(s == -1){
            back(a, b, i+1, -1);
        }
    }
}

int main() {
    freopen("/Users/clsrn1581/Desktop/codejam/B/B-small-attempt3.in", "r", stdin);
    freopen("/Users/clsrn1581/Desktop/codejam/B/B-small-attempt3.out", "w", stdout);
    
    int T;
    cin >> T;
    
    for(int t = 1; t <= T; t++){
        ans = ((long long )1 << 62);

        string A, B;
        cin >> A >> B;
        
        len = (int)A.length();
        
        back(A, B, 0, 0);
    
        printf("Case #%d: ", t);
        
        string strA = to_string(ansA);
        string strB = to_string(ansB);
        
        for(int i = 0 ; i < len - strA.size(); i++)
            cout << '0';
        cout << ansA << " ";
        
        for(int i = 0 ; i < len - strB.size(); i++)
            cout << '0';
        cout << ansB << endl;
    }
    return 0;
}
