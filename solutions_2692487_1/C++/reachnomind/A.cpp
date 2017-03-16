
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        int A, N;
        cin>>A>>N;
        int M[N];
        for(int i=0; i<N; i++) {
            cin>>M[i];
        }
        sort(M, M+N);

        int ans[N];
        for(int i=0; i<N; i++) {
            ans[i] = 0;
            while(M[i] >= A && A > 1) {
                A += A-1;
                ans[i]++;
            }
            if(M[i] < A) {
                A += M[i];
            }

            if(i>0) {
                ans[i] += ans[i-1];
            }
        }

        int ani = N;
        for(int i=0; i<N; i++) {
            if(M[i] < A && ani > ans[i] + (N - 1 - i)) {
                ani = ans[i] + (N - 1 - i);
            }
        }
        cout<<"Case #"<<t<<": "<<ani<<endl;
    }

    return 0;
}

