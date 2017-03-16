#include <iostream>
#include <cstdio>
using namespace std;

int t, n;
string a;
int last;

int main(){
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    
    for(int q=1; q<=t; q++){
        cin >> a >> n;    
        int l = a.size();
        
        long long wynik = 0;
        int ile = 0;
        last = 0;
        
        for(int i=0; i<l; i++){
            if(a[i] != 'a' && a[i] != 'o' && a[i] != 'e' && a[i] != 'i' && a[i] != 'u')
                ile++;
            else
                ile = 0;
            
            if(ile >= n){
                wynik += (l-i)*(i-n+2-last); 
                last = i-n+2;
            }
        }
        
        
        printf("Case #%d: %lld\n", q, wynik);
    }
    
    cin.ignore(2);
    return 0;    
}
