#include<bits/stdc++.h>
#define SWAP(x,y,t) t=x,x=y,y=t
using namespace std;


// 1 1
// -1 2
// i 3
// j 4
// k 5
// -i 6
// -j 7
//-k 8

long long  mul(long long  a, long long  b)
{
    if(a == 1)
    return b;
    else if(a == 2)
    {
        if(b == 1)
        return 2;
        if(b == 2)
        return 1;
        if(b == 3)
        return 6;
        if(b == 4)
        return 7;
        if(b == 5)
        return 8;
        if(b == 6)
        return 3;
        if(b == 7)
        return 4;
        if(b == 8)
        return 5;
    }
    else if(a == 3)
    {
        if(b == 1)
        return 3;
        if(b == 2)
        return 6;
        if(b == 3)
        return 2;
        if(b == 4)
        return 5;
        if(b == 5)
        return 7;
        if(b == 6)
        return 1;
        if(b == 7)
        return 8;
        if(b == 8)
        return 4;
    }
    if(a == 4)
    {
        if(b == 1)
        return 4;
        if(b == 2)
        return 7;
        if(b == 3)
        return 8;
        if(b == 4)
        return 2;
        if(b == 5)
        return 3;
        if(b == 6)
        return 5;
        if(b == 7)
        return 1;
        if(b == 8)
        return 6;
    }
    else if(a == 5)
    {
        if(b == 1)
        return 5;
        if(b == 2)
        return 8;
        if(b == 3)
        return 4;
        if(b == 4)
        return 6;
        if(b == 5)
        return 2;
        if(b == 6)
        return 7;
        if(b == 7)
        return 3;
        if(b == 8)
        return 1;
    }
    else if(a == 6)
    {
        if(b == 1)
        return 6;
        if(b == 2)
        return 3;
        if(b == 3)
        return 1;
        if(b == 4)
        return 8;
        if(b == 5)
        return 4;
        if(b == 6)
        return 2;
        if(b == 7)
        return 5;
        if(b == 8)
        return 7;
    }
    else if(a == 7)
    {
        if(b == 1)
        return 7;
        if(b == 2)
        return 4;
        if(b == 3)
        return 5;
        if(b == 4)
        return 1;
        if(b == 5)
        return 6;
        if(b == 6)
        return 8;
        if(b == 7)
        return 2;
        if(b == 8)
        return 3;
    }
    else if(a == 8)
    {
        if(b == 1)
        return 8;
        if(b == 2)
        return 5;
        if(b == 3)
        return 7;
        if(b == 4)
        return 3;
        if(b == 5)
        return 1;
        if(b == 6)
        return 4;
        if(b == 7)
        return 3;
        if(b == 8)
        return 2;
    }
}


int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    long long  t;
    cin>>t;
    long long  k = 1;
    //cout<<t<<endl;
    while(t--)
    {
        cout<<"Case #"<<k<<": ";
        k++;
        long long  flag = 0;
        long long  l,x;
        cin>>l>>x;
        vector<long long > v;
        for(long long  i=0;i<l;i++)
        {
            char ch;
            cin>>ch;
            if(ch == 'i')
            v.push_back(3);
            else if(ch == 'j')
            v.push_back(4);
            else
            v.push_back(5);
        }
        long long ind = 0;
        long long maxind = l*x;
        long long  val = 1;
        for(long long  i=0;i<l;i++)
        {
            val = mul(val,v[i]);
        }
        long long r = x%4;
        long long val11 = 1;
        for(long long i=0;i<r;i++)
        {
            val11 = mul(val11,val);
        }
        //cout<<"val: "<<val<<endl;
        //cout<<"val11: "<<val11<<endl;
        if(val11 == 2)
        {
            long long  val = 1;
            long long ind;
            for(ind = 0;ind<(min(4*l,maxind));ind++)
            {
                if(val == 3)
                {
                    break;
                }
                val = mul(val,v[ind%l]);
            }
            //cout<<"val: "<<val<<endl;
            //cout<<"ind: "<<ind<<endl;
            if(val == 3)
            {
                long long  no = (ind/l);
                long long  no2 = no + 4;
                long long  ind2 = min(maxind,(no2+1)*l);
                val = 1;
                ind2--;
                long long  ff = 1;
                if(v[ind2%l] != 5)
                {
                    ff = 2;
                    for(;ind2 >= ind;ind2--)
                    {
                        if(val == 8)
                        break;
                        val = mul(val,v[ind2%l]);
                    }
                }
                else val = 5;
                //cout<<"vallllll: "<<val<<endl;
                if(val == 8 || ff == 1)
                {
                    //cout<<"ind2: "<<ind2<<endl;
                    if(ind2-ind >= 1)
                    flag = 1;
                }
            }
        }
        if(flag == 1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}
