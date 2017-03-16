/*=============================================================================
#     FileName: gcj_r2bb.cpp
#         Desc: 
#       Author: zhangc
#        Email: sirnodin@gmail.com
#     HomePage: 
#      Version: 0.0.1
#     CreateOn: 2014-05-04 00:38:25
#   LastChange: 2014-05-04 00:59:56
#      History:
=============================================================================*/
#include <iostream>
using namespace std;
size_t TEST_CASES;
int A,B,K;
long long ans;
void solve()
{
    ans=0;
    cout<<ans<<endl;
}
void solveSlow()
{
    ans=0;
    for(int i=0;i<A;++i)for(int j=0;j<B;++j)
    {
        if((i&j)<K)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    cin>>TEST_CASES;
    for(size_t CASE=0;CASE<TEST_CASES;++CASE)
    {
        cin>>A>>B>>K;
        printf("Case #%ld: ",CASE+1);
        solveSlow();
    }
    return 0;
}
