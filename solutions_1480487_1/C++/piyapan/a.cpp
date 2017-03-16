#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

double calculate(int *score, int N, int scoreSum, const int i)
{
 vector<int> data, minus;
 int j, sum, sumeq, n;

 for(j=0;j<N;j++)
  if(j!=i)
   data.push_back(score[j]);

 if(data.size() == 1)
  if(data[0]-score[i]+scoreSum > 0)
   return (data[0]-score[i]+scoreSum)/(double)(2*scoreSum);
  else
   return 0;

 for(j=0;j<(int)data.size()-1;j++)
  minus.push_back(data[j+1]-data[j]);

 sum = minus[0];
 sumeq=sum;
 for(j=1;j<(int)minus.size();j++)
 {
  sum+=minus[j];
  sumeq+=sum;
 }

 n = data.size();
 return (n*(data[0]-score[i])+scoreSum+sumeq)/(double)(scoreSum*(n+1));
 /*
 if(n*(data[0]-score[i])+scoreSum+sumeq > 0)
  return (n*(data[0]-score[i])+scoreSum+sumeq)/(double)(scoreSum*(n+1));
 else
  return 0;
  */
}

double calAgain(int *score, int sum, int N,int i, vector<double> &caled)
{
 int *newSc = new int [N], j, count;

 count=0;
 for(j=0;j<N;j++)
  if(j!=i && caled[j] >= 0)
  {
   newSc[count] = score[j];
   count++;
  }

 newSc[count] = score[i];
 count++;


 double ans = calculate(newSc, count, sum, count-1);

 printf("%.6lf ", ans<0?0:ans*100);

 delete[] newSc;
}

//int main()
int op(int caseNum)
{
 int *score, sum, N, i, j;
 vector<double> cal;

 cin >> N;
 score = new int[N];

 sum=0;
 for(i=0;i<N;i++)
 {
  cin >> score[i];
  sum+=score[i];
 }

 //cout << "sum : " << sum << endl;
 cout << "Case #" << caseNum << ": ";
 for(i=0;i<N;i++)
  cal.push_back(calculate(score, N, sum, i));

 for(i=0;i<N;i++)
  calAgain(score, sum, N, i, cal);


 cout << endl;
 delete[] score;
}

int main()
{
 int N, i;

 cin >> N;
 for(i=0;i<N;i++)
  op(i+1);
}
