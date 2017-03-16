#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define INF 2000000000

using namespace std;
typedef long long ll;
set<ll> s;

ll build_number(vector<int> vec){
    ll ans = 0;
    for(int i=0;i<vec.size();i++){
        ans*=10;
        ans+=vec[i];
    }
    return ans;
}

ll get_biggest_perm(ll a){
    vector<int> vec;
    ll num = a;
    int digit;
    while(a>0){
        digit = a%10;
        a/= 10;
        vec.push_back(digit);
    }
    sort(vec.begin(), vec.end());
    
    a = 0;
    for(int i=vec.size()-1;i>=0;i--){
        a*= 10;
        a+= vec[i];
    }
    if(a<=num) return -1;

    return a;
}

ll get_big_enough_perm(ll a,ll b){
    vector<int> vec;
    ll num = a;
    int digit;
    while(a>0){
        digit = a%10;
        a/=10;
        vec.push_back(digit);
    }
    reverse(vec.begin(), vec.end());
    //sort(vec.begin(), vec.end());
    //ll temp_numb = build_number(vec);
    //if(s.count(temp_numb)>0) return -1;
    //s.insert(temp_numb);

    ll temp, last_good = -1;
    do{
        temp = build_number(vec);   
        if(temp > num && temp<=b){
            last_good = temp;
        }
    }while(next_permutation(vec.begin(), vec.end()));

    return last_good;
}

int get_len(ll a){
    int ans = 0;
    while(a>0){
        ans++;
        a/=10;
    }
    return ans;
}

ll dfs(ll num,ll N,int N_len,int path_count,int limit){
    if(num==N) return path_count;
    if(path_count >= limit) return INF;
    //cout<<num<<" - "<<path_count<<endl;

    int num_len = get_len(num);
    ll temp = num+1;

    if(N_len > num_len){
        num = get_biggest_perm(num);
    } else if(N_len == num_len){
        num = get_big_enough_perm(num,N);
    }
    if(-1==num) num = temp;
    return dfs(num,N,N_len,path_count+1,limit);
}

int main(){
    int T, ans;
    int num_len, N_len, counter = 1;
    ll N, num, temp;
    cin>>T;

    while(T--){
        cin>>N;
        N_len = get_len(N);

        num = 1;
        ans = 0;
        s.clear();
        int best_count = N;
        while(num!=N){
            ans++;
            temp = num+1;
     
            if(num < 12){
                num = temp;
                continue;
            }

            //cout<<"new "<<num<<endl;
            int path = dfs(num, N,N_len,ans,best_count);
            if(path < best_count){
                best_count = path;
            }
            num = temp;
            continue;
           

            num_len = get_len(num);

            if(N_len > num_len){
                num = get_biggest_perm(num);
                if(-1==num){
                    num = temp;
                }
            } else if(N_len == num_len) {
                num = get_big_enough_perm(num, N);
                if(-1==num){
                    num = temp;
                }
            }
        }
        cout<<"Case #"<<counter++<<": "<<best_count<<endl;   
    }
    return 0;
}
