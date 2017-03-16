#include <iostream>
#include <cstdio>
using namespace std;
char keys[10] , target[10];
int sum, max_repetitions, words;

void count_repetitions(char state[],int n,int target_len){
    int k, rep = 0;
    //cout<<"counting rep for: "<<state<<endl;
    //cout<<"len: "<<n<<endl;
    for(int i=0;i<n;i++){
        k = 0;
        for(int j=i;j<n && k<target_len;j++,k++){ 
            if(state[j]!=target[k]) break;
        }
        if(k==target_len){
            ++rep;
        }
    }

    if(rep > max_repetitions) max_repetitions = rep;
    //cout<<"rep: "<<rep<<endl;
    sum+= rep;
}

void backtrack(char state[],int k,int n,int op,int word_length){
    if(k+1==n){
        count_repetitions(state, n, word_length);               
        ++words;
    } else {
        ++k;
        for(int i=0;i<op;++i){
            state[k] = keys[i];
            backtrack(state, k, n, op,word_length);
        }
    }
}

int main(){
    char state[10];
    int T, K,L,S,counter = 1;
    double ans;
    cin>>T;
    while(T--){
        sum = words = max_repetitions = 0;
        cin>>K>>L>>S;
        cin>>keys>>target;
        backtrack(state, -1, S, K, L);
        //cout<<"max_rep: "<<max_repetitions<<" words: "<<words<<" sum: "<<sum<<endl;
        ans = double(max_repetitions*words-sum)/words;
        printf("Case #%d: %lf\n",counter++,ans);
    }
    return 0;
}
