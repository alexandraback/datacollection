#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int sum;
int A, N;
int flag;
int arr[100];

int find(int a[100], int len){
    if(len == 0){
        arr[0] = 99999999;
        return 0;
    }
    int x = find(a, len-1);
    arr[len-1] = x+(N-len+1);
    if(flag)
        return x+1;
//    cout<<"the sum ans a is"<<sum<<" "<<a[len-1]<<endl;
    if(a[len-1] < sum){
        sum += a[len-1];
        return x;
    }
    else{
        int i=0;
        if(sum == 1){
            flag = true;
            return x+1;
        }
        while(sum <= a[len-1]){
            sum += (sum-1);
            i++;
        }
        if(i > N+1-len){
            flag = true;
            return x+1;
        }
        else{
            sum += a[len-1];
            return x+i;
        }
    }
}

int compare(const void *a, const void *b){
    int t = *(int *)a -*(int *)b;
    if(t<0)
        return -1;
    if(t>0)
        return 1;
    return 0;
}

void print(int a[100]){
    for(int i=0; i<N; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int min(int arr[100], int N){
    int min = 99999999;
    for(int i=0; i<N; i++){
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}

int main()
{
    int T, a[100], ans, ans2;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>A>>N;
        for(int j=0; j<N; j++){
            cin>>a[j];
        }
        qsort(a, N, sizeof(int), compare);
//        print(a);
        sum = A;
        flag = false;
        ans = find(a, N);
        ans2 = min(arr, N);
//        print(arr);
//        cout<<ans2<<" this is ans"<<endl;
        if(ans2<ans)
            ans = ans2;
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
    }
    return 0;
}

