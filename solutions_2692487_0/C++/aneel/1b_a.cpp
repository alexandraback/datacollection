#include <iostream>
#include <algorithm>
using namespace std;

int howMany(int a, int b, int &v) {
//        cout<<a<<" ";
    int count1 = 0;
    while(a <= b) {
        a += a-1;
        ++count1;

    }
    v = a;
    return count1;
}

int arr[1000002];

int main() {
    int t,a,n;
    
    cin>>t;
    for(int ti = 1; ti <= t; ++ti)
    {
        cin>>a>>n;
        
//        cout<<endl;
        for(int i = 0; i < n; ++i)
        {
            cin>>arr[i];
//            cout<<arr[i]<<" ";
        }
//        cout<<endl;
//        cout<<a<<endl;
        sort(arr,arr+n);
        
        int min0=n, min1 = 0, count1;
        int sum = 0, temp;
        
        if(a == 1) min0 = n;
        else 
        for(int i = 0; i < n; ++i)
        {
            if(a <= arr[i]) 
            {
                if((count1 = howMany(a,arr[i],temp)) < n - i) 
                {
                    a=temp+arr[i];
                    min1 += count1;
                }
                else {
                    break;
                }
            }
            else {
                a += arr[i];
            }
            if(min0 > min1+n-i-1) min0 = min1+n-i-1;
        }
        
        cout<<"Case #"<<ti<<": "<<min0<<endl;
    }    
    return 0;
}
