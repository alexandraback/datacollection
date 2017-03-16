#include <iostream>
#include <set>

using namespace std;

// For we don't realize our faith in the prize
// Unless it's been somehow elusive

void doCase();

int main()
{
  int cases;
  cin >> cases;

  for(int c=0; c<cases; c++)
    {
      cout << "Case #" << c+1 << ": ";
      doCase();
    }
}

void doCase()
{
  int A,B;
  cin >> A >> B;
  int digits = 0;
  int tmp=A;

  while(tmp>0)
    {
      digits++;
      tmp/=10;
    }
  int mult=1;
  for(int i=0;i<digits-1;i++)
    {
      mult*=10;
    }
  int result=0;
  for(int i=A; i<=B; i++)
    {
      int newnum = i;
      set<int> done;
      for(int j=0; j<digits-1; j++)
	{
	  int last = newnum%10;
	  newnum = newnum/10 + mult*last;
	  if(last != 0 && newnum > i && newnum <= B && done.count(newnum) == 0)
	    {
	      done.insert(newnum);
	      result++;
	    }
	}
    }
  cout << result << endl;
}
