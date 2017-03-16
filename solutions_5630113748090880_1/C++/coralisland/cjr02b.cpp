#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<set>
#include<vector>

using namespace std;

int main()
{

    freopen("0in.txt","r",stdin);
    freopen("0out.txt","w",stdout);
    int i,j,k,l,t,n,num;

    int arr[2509];
    scanf("%d",&t);

    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%d",&n);
        set<int> myset;
        set<int>::iterator it;

        memset(arr,0,sizeof(arr));

        for(i=1;i<=2*n-1;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&num);
                arr[num]++;
                myset.insert(num);

            }

        }

        vector<int>vec;

        for (it=myset.begin(); it!=myset.end(); ++it)
        {
            if(arr[*it]%2==1)
            {
                vec.push_back(*it);
            }
        }

        int len;
        len=vec.size();

        printf("Case #%d: ",kk1);

        for(i=0;i<len;i++)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;








    }


}
