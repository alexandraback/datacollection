#include <iostream>
#include <cstring>
#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>

#define PII pair<int,int>
using namespace std;

int a, b;

int main(){
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        cin >> a >> b;
        
        set< PII > k;
        unsigned long long int sol = 0;
        for (int n=a; n<=b; n++){
            vector<int> shift;
            
            {
                char s[10];
                memset(s,0,sizeof s);
                sprintf(s, "%d", n);
                int nsize = strlen(s);
                
                for (int p=0; p<nsize; p++){
                    int number = 0;
                    
                    for (int diff=0; diff<nsize; diff++){
                        number = 10*number + (s[ (p+diff) % nsize] - '0');
                    }
                    
                    if ( a <= number && number <= b && k.find(PII(n,number)) == k.end() 
                         && n < number )
                    {
                        k.insert( PII( min(n,number), max(n,number) ) );
                        sol++;
                    }
                }
            }
            
        }
        cout << sol << endl;
    }
    return 0;
}