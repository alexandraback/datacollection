#include <cstdio>
#include <string>
#include <map>

using namespace std;

char str1[30], str2[30];
pair<string,string> topic[1100];
bool valid[1100];

int main(){
    int T, tc = 0;
    scanf("%d", &T);
    
    while(T--){
        int N;
        scanf("%d", &N);
            
        map<string, int> a, b;
            
        for(int i=0; i<N; i++){
            scanf("%s%s", str1, str2);
            topic[i] = make_pair(str1, str2);
            a[str1]++; b[str2]++;
            valid[i] = true;
        }
        
        int ans = 0;
        
        while(true){
            bool test = false;
            
            for(int i=0; i<N; i++){
                if(valid[i] and a[topic[i].first] > 1 and b[topic[i].second] > 1){
                    valid[i] = false;
                    a[topic[i].first]--;
                    b[topic[i].second]--;
                    ans++;
                    test = true;
                }
            }
            
            if(!test) break;
        }
        
        printf("Case #%d: %d\n", ++tc, ans);
    }
}
