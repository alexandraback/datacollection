#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("in.txt");
    ofstream cout("out2.txt");
    int t;
    cin>>t;
    //cout<<t<<endl;
    int k = 1;
    while(t--)
    {

        cout<<"Case #"<<k<<": ";
        //cout<<"hi"<<endl;
        k++;
        int n;
        cin>>n;
        vector<int> arr;
        int mn1 = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
            if(temp > mn1)
            mn1 = temp;
        }

        int mn = INT_MAX;

        for(int i=1;i<=mn1;i++)
        {
            int c = 0;
            for(int j=0;j<arr.size();j++)
            {
                if(arr[j]%i == 0)
                {
                    c += (arr[j]/i - 1);
                }
                else
                {
                    c += (arr[j]/i);
                }
            }
            mn = min(c+i,mn);
        }
        cout<<mn<<endl;
    }
    return 0;
}


