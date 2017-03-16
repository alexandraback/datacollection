#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int T; cin >> T; 
    for(int t=0; t<T; ++t){
        int N, M; cin >> N >> M;
        vector<long long> a(N,0), A(N,0);
        for(int i=0; i<N;++i){
            long long x, y;
            cin >> x >> y;
            a[i]=x; A[i]=y;
        }
        vector<long long> b(M,0), B(M,0);
        for(int i=0; i<M;++i){
            long long x, y;
            cin >> x >> y;
            b[i]=x; B[i]=y;
        }


        queue<long long> q_a, q_a_r, q_b, q_b_r, q_s;
        q_a.push(0);
        q_a_r.push(0);
        q_b.push(0);
        q_b_r.push(0);
        q_s.push(0);
        long long ret=0;
        while(!q_a.empty()){
            long long a_i = q_a.front();
            long long a_rest = q_a_r.front();
            long long b_i = q_b.front();
            long long b_rest = q_b_r.front();
            long long sum = q_s.front();
            ret = max(sum, ret);
            q_a.pop();
            q_a_r.pop();
            q_b.pop();
            q_b_r.pop();
            q_s.pop();
            if(a_i >= N || b_i >= M)
                continue;

            if(A[a_i]==B[b_i]){
                long long m = min(a[a_i]-a_rest, b[b_i]-b_rest);
                long long A_i, A_rest, B_i, B_rest;
                if(a_rest + m ==a[a_i]){
                    A_i = a_i+1;
                    A_rest = 0;
                }else{
                    A_i = a_i;
                    A_rest = a_rest+m;
                }
                if(b_rest + m ==b[b_i]){
                    B_i = b_i+1;
                    B_rest = 0;
                }else{
                    B_i = b_i;
                    B_rest = b_rest+m;
                }
                q_a.push(A_i);
                q_a_r.push(A_rest);
                q_b.push(B_i);
                q_b_r.push(B_rest);
                q_s.push(sum+m);
                
            }else{
                q_a.push(a_i+1);
                q_a_r.push(0);
                q_b.push(b_i);
                q_b_r.push(b_rest);
                q_s.push(sum);

                q_a.push(a_i);
                q_a_r.push(a_rest);
                q_b.push(b_i+1);
                q_b_r.push(0);
                q_s.push(sum);
                
            }

        }
        cout << "Case #" << t+1 << ": "<< ret << endl;



    }
    return 0;

}
