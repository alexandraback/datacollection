

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;


int T;

int Reverse(int x){
    vector<int> digits;
    
    while (x!=0){
        digits.push_back(x%10);
        x=x/10;
    }
    
    reverse(digits.begin(),digits.end());
    int res=0;
    int p=1;
    for (int i=0;i<digits.size();i++){
        res=res+p*digits[i];
        p=p*10;
    }
    
    return res;
    
    
}

int smallest_number_of_steps[1000005];

int main() {
    scanf("%d",&T);
    
    memset(smallest_number_of_steps, -1, sizeof(smallest_number_of_steps));
    
    smallest_number_of_steps[1]=1;
    
    queue<int> Q;
    Q.push(1);
    
    while (!Q.empty()){
        int x=Q.front(); Q.pop();
        if (x>1000000) break;
        if (smallest_number_of_steps[x+1]==-1){
            
            smallest_number_of_steps[x+1]=smallest_number_of_steps[x]+1;
            Q.push(x+1);
            
        }
        int r=Reverse(x);
        if (smallest_number_of_steps[r]==-1){
            smallest_number_of_steps[r]=smallest_number_of_steps[x]+1;
            Q.push(r);
        }
        
    }

    
    
    for (int case_n=1;case_n<=T;case_n++){
        int N;
        
        scanf("%d",&N);
        printf("Case #%d: %d\n",case_n,smallest_number_of_steps[N]);
        
        
        
    }

    return 0;
}
