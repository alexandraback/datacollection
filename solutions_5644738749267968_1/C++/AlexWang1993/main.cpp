//
//  main.cpp
//  DeceitfulWar
//
//  Created by Alex Wang on 4/11/2014.
//  Copyright (c) 2014 Alex Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(float a,float b){
    return a<b;
}
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<float> a,b;
        for (int i=0;i<n;i++){
            float x;
            cin>>x;
            a.push_back(x);
        }
        for (int i=0;i<n;i++){
            float x;
            cin>>x;
            b.push_back(x);
        }
        sort(a.begin(),a.end(),compare);
        sort(b.begin(),b.end(),compare);
        cout<<"Case #"<<i+1<<": ";
        {
            vector<float> a1(a),b1(b);
            int ans=0;
            for (int i=0;i<a1.size();i++){
                if (a1[i]<b1[0]){
                    b1.pop_back();
                } else {
                    b1.erase(b1.begin());
                    ans++;
                }
            }
            cout<<ans<<" ";
        }
        {
            vector<float> a1(a),b1(b);
            int ans=0;
            for (int i=0;i<a1.size();i++){
                bool fl=false;
                int j;
                for (j=0;j<b1.size();j++){
                    if (b1[j]>a1[i]){
                        fl=true;
                        break;
                    }
                }
                if (fl){
                    b1.erase(b1.begin()+j);
                } else {
                    b1.erase(b1.begin());
                    ans++;
                }
        }
            cout<<ans<<endl;}
    }
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}

