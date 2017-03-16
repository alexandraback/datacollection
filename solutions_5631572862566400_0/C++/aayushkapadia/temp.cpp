#include<bits/stdc++.h>
using namespace std;
bool findIn(int *arr,vector<int> &list,int n,int *done)
{
  for(int i=0;i<n;i++)
  {
    if(arr[i]==list[0] || arr[i]==list[list.size()-1])
    {
      if(!done[i])
        return true;
    }
  }
  return false;
}
int countUpto(int *done,int *arr,int n,int curr1)
{
  int max2 = 1;
  for(int i=0;i<n;i++)
  {
    int answer=1;
    int curr = i;
    bool proper = 0;
    for(int j=0;j<=(n+5);j++)
    {
      if(curr==curr1)
      {
        proper=1;
        break;
      }
      else
      {
        if(done[curr]==1)
          break;
        answer++;
      }
      curr=arr[curr];
    }
    if(proper)
    {
      max2=max(max2,answer);
    }


  }
  return max2-1;
}
int main()
{
  int t;
  cin>>t;
  for(int gh=1;gh<=t;gh++)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      arr[i]--;
    }
    int max1 = 1;
    for(int i=0;i<n;i++)
    {
      int done[n];
      int ans = 1;
      memset(done,0,n*sizeof(int));
      done[i]=1;
      int curr = i;
      vector<int> list;
      list.push_back(i);
      while(1)
      {
        int temp = arr[curr];
        if(done[temp]==1)
        {
          //cout<<"Hi "<<temp<<endl;
          if(temp==i)
          {

                         break;
          }
          else
          {

                        //cout<<"H"<<" "<<temp<<endl;
                        if(list.size()<2)
                        {
                          ans=-1;
                          break;
                        }

            if(list[list.size()-2]==temp)
            {
              //cout<<"Hello"<<endl;
              bool val = findIn(arr,list,n,done);
              int tempAns=1,tempAns2=1;
              if(val==true)
                tempAns=ans+1;
              //cout<<"Val= "<<val;
              int count1 = countUpto(done,arr,n,list[list.size()-1]);
              //cout<<tempAns<<endl;
              tempAns2=ans+count1;
              ans=max(ans,tempAns);
              ans=max(ans,tempAns2);


            }
            else
              ans=-1;
            break;
          }

        }
        else
        {
          done[temp]=1;
          list.push_back(temp);
          curr=temp;
          ans++;

        }
      }
      //cout<<ans<<endl;
      max1 = max(max1,ans);
    }
    cout<<"Case #"<<gh<<": "<<max1<<endl;
  }
  return 0;
}
