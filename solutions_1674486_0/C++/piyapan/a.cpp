#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;

typedef list<int> myList;

bool breathFirst(myList *AList, int N,const int i)
{
 bool *found = new bool [N];
 int j, r;
 myList myQueue;
 myList::iterator it;

 //cout << "index " << i << endl;
 for(j=0;j<N;j++)
  found[j] = false;

 myQueue.push_back(i);
 found[i] = true;
 while(!myQueue.empty())
 {
  r = myQueue.front();
  myQueue.pop_front();

  if(AList[r].empty())
   continue;

  for(it=AList[r].begin();it!=AList[r].end();it++)
   if(found[*it])
   {
    return true;
   }
   else
   {
    found[*it] = true;
    myQueue.push_back(*it);
   }
 }

 return false;
}

bool findAns(myList *AList, int N)
{
 int i;

 for(i=0;i<N;i++)
  if(breathFirst(AList, N, i))
   return true;

 return false;
}

int op(int caseNum)
{
 myList *AList;
 int N, M, i, j, r;

 cin >> N;
 AList = new myList [N];

 for(i=0;i<N;i++)
 {
  cin >> M;

  for(j=0;j<M;j++)
  {
   cin >> r;
   AList[i].push_back(r-1);
  }
 }

 printf("Case #%d: %s\n", caseNum, findAns(AList, N)?"Yes":"No");

 delete[] AList;
}

int main()
{
 int i, N;

 cin >> N;
 for(i=0;i<N;i++)
  op(i+1);
}
