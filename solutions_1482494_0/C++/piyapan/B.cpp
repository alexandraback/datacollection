#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

struct Level
{
 int i, a, b;
};

bool cmp1Star(const Level &a, const Level &b)
{
 if(a.a != b.a)
  return a.a > b.a;
 else
  return a.b < b.b;
}

bool cmp2Star(const Level &a, const Level &b)
{
 return a.b > b.b;
}

int main()
{
 int i, T, N, j, myCount, myStar;
 bool *got1Star, success;
 Level l;
 vector<Level> oneStar, twoStar;

 cin >> T;
 for(i=0;i<T;i++)
 {
  cin >> N;
  got1Star = new bool[N];
  myCount = 0;
  myStar = 0;
  success = true;

  for(j=0;j<N;j++)
  {
   got1Star[j] = false;

   cin >> l.a >> l.b;
   l.i = j;

   oneStar.push_back(l);
   twoStar.push_back(l);
  }

  sort(oneStar.begin(), oneStar.end(), cmp1Star);
  sort(twoStar.begin(), twoStar.end(), cmp2Star);

  while(!twoStar.empty())
  {
   //printf("myStar %d\n", myStar, twoStar.back().b);
   if(myStar >= twoStar.back().b)
   {
//    printf("choos 2star %d\n", twoStar.back().i);

    if(got1Star[twoStar.back().i])
     myStar++;
    else
    {
     myStar+=2;
     got1Star[twoStar.back().i] = true;
    }

    myCount++;
    twoStar.pop_back();
   }
   else
   {
    while(!oneStar.empty() && got1Star[oneStar.back().i])
     oneStar.pop_back();

//printf("choos 1star %d\n", oneStar.back().i);
    if(oneStar.empty() || myStar < oneStar.back().a)
    {
     success = false;
     break;
    }

    got1Star[oneStar.back().i] = true;
    myStar++;
    myCount++;
    oneStar.pop_back();
   }
  }

  printf("Case #%d: ", i+1);
  if(!success)
   printf("Too Bad\n");
  else
   printf("%d\n", myCount);

  oneStar.clear();
  twoStar.clear();
  delete[] got1Star;
 }
}
