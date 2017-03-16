#include <stdio.h>
#include <stdlib.h>

int findMove(int* arr,int st,int end,int val)
{
    if(st >= end) return 0; // pass
    if(val == 1) return 999999999;
    // try add mote
    val += (val-1);
    // eat all
    for(int i = st;i <= end;i++)
    {
        if(val > arr[st])
        {
            val += arr[st];
            st++;
        }
        else
        {
            break;
        }
    }
    return findMove(arr,st,end,val) + 1;
}

int min(int a,int b) { return a<b?a:b; }

int main()
{
    int t,tt;
    scanf("%d",&tt);
    for(t = 0;t < tt;t++)
    {
        printf("Case #%d: ",t+1);
        // find ans
        int start,n;
        scanf("%d %d",&start,&n);
        int arr[n];
        int *counting = (int*)calloc(sizeof(int),1000001);
        // first , try to eat all
        for(int i =0;i < n;i++)
        {
            int ind;
            scanf("%d",&ind);
            counting[ind]++;
        }
        // eat all
        int arrInd = 0;
        for(int i = 0;i < 1000001;++i)
        {
            while(counting[i] > 0)
            {
                counting[i]--;
                arr[arrInd++] = i;
            }
        }
        arrInd = 0;
        int left = n;
        while(left > 0 && start > arr[arrInd])
        {
            start += arr[arrInd];
            left--;
            arrInd++;
        }
        int ans = 99999999;
        if(left > 0) {
        // try to remove the highest
        for(int i = arrInd;i <= n;i++)
        {
            ans = min(ans,findMove(arr,arrInd,i,start) + (n-i));
            //printf("<%d> %d - %d ( -%d ) = %d\n",start,arrInd,i,n-i,findMove(arr,arrInd,i,start));
        }
        }
        else
        {
            ans = 0;
        }

        printf("%d\n",ans);

        //while(arr[arrInd])




    }
}
