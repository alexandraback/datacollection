#include <iostream>
#include <algorithm>

using namespace std;

main(){
  long long T;
  cin >> T;
  for(long long t=1;t<=T;t++){
    long long A, N;
    cin >> A >> N;
    long long data[100];
    for(long long i=0;i<N;i++) cin >> data[i];
    sort(data, data+N);
    long long ans = N;
    long long cnt = 0;
    if(!(A == 1 && data[0] >= 1)){
      for(long long i=0;i<N;i++){
        ans = min(ans, cnt + (N - i));
        if(data[i] >= A){
          while(data[i] >= A){
            cnt++;
            A += A - 1;
          }
          A += data[i];
        }else{
          A += data[i];
        }
        if(i == N - 1) ans = min(ans, cnt);
      }
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}
