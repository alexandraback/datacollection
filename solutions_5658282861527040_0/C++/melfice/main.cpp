#include <bits/stdc++.h>

using namespace std;

main()
 {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;

    for(int z=0;z<T;z++)
    {
        cout<<"Case #"<<z+1<<": ";
        int a,b,k;
        cin>>a>>b>>k;
        int sum=0;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                sum+=(i&j)<k;
        cout<<sum<<endl;
    }
}

