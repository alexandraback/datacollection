#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cassert>
#include<cstring>

using namespace std;

///////////////NEXT HIGHER PALINDROME//////////////////

static int countDigits(int n)
{
	int c = 0;

	for(c=0; n > 0; c++, n /= 10)
		;
	return c;
}

static int makeMultiple(int what, int power)
{
	int c;

	for(c=1; power > 0; (c *= what), power--)
		;
	return c;
}

static int smallestPlalindromeLargerThanInteger(int n)
{
	n++;
	int c = countDigits(n);
	int mstens = makeMultiple(10, c-1);
	int lstens = 10;
	while(mstens >= lstens)
	{
		int postPart = n%lstens;
		if((n/mstens)%10 < (n%lstens)/(lstens/10))
		{
			int rem = (n/mstens)%10;
			n /= lstens;
			n++;
			n = n*lstens + rem*(lstens/10) + postPart%(lstens/10);
		}
		else if((n/mstens)%10 > (n%lstens)/(lstens/10))
		{
			int rem = (n/mstens)%10;
			n = n/lstens;
			n = n*lstens + rem*(lstens/10) + postPart%(lstens/10);
			mstens /= 10;
			lstens *= 10;
		}
		else
		{
			mstens /= 10;
			lstens *= 10;
		}
	}
	return n;
}

///////////////////////////////////////////////////////

#define TEST_CASES_SMALL 100
#define F_S_SMALL 1000

long FairAndSqNumbers[F_S_SMALL];
long count;

class inRange
{
public:
	int A;
	int B;
	int noOfFSNumbers;
};

inRange FSNUMS[TEST_CASES_SMALL];

bool isPalindrome(int x) {
  if (x < 0) return false;
  int divisor = 1;
  while (x / divisor >= 10) {
    divisor *= 10;
  }       
  while (x != 0) {
    int l = x / divisor;
    int r = x % 10;
    if (l != r) return false;
    x = (x % divisor) / 10;
    divisor /= 100;
  }
  return true;
}

void clearFSArray()
{
	memset(FSNUMS, 0, TEST_CASES_SMALL*sizeof(inRange));
}

void fairAndSquareSmall(int tcases)
{
	for(int i = 0; i < tcases; i++)
	{
		for(int j = 0; j< count; j++)
		{
			if((FairAndSqNumbers[j] >= FSNUMS[i].A) && (FairAndSqNumbers[j] <= FSNUMS[i].B))
				FSNUMS[i].noOfFSNumbers++;
			else if(FairAndSqNumbers[j] > FSNUMS[i].B)
				break;
		}
	}
}

void printFairAndSqCount(FILE *ofp, int tCases)
{
	assert(ofp);
	for(int i =0; i <tCases; i++)
		fprintf(ofp, "Case #%d: %d\n", i+1, FSNUMS[i].noOfFSNumbers);
	return;
}

void preprocessing()
{
	int upperLimit = (int)floor(sqrt((double)F_S_SMALL));
	count = 0;
	for(int i = 1; i <= upperLimit; i++)
	{
		if(isPalindrome(i) && isPalindrome(i*i) && ((i*i) <= F_S_SMALL))
			FairAndSqNumbers[count++] = i*i;
	}
}

int main()
{
	char *inFile = "C://InputOutput//FairAndSquare//C-small-attempt0.in";
	char *outFile = "C://InputOutput//FairAndSquare//sampleOutput.txt";
	
	FILE *ifp = fopen(inFile, "r");
	FILE *ofp = fopen(outFile, "w");
	assert(ifp);
	assert(ofp);

	int tcases=0;

	fscanf(ifp, "%d\n", &tcases);
	preprocessing();
	for(int i = 0; i < tcases; i++)
	{
		fscanf(ifp, "%d %d\n", &(FSNUMS[i].A), &(FSNUMS[i].B));
		FSNUMS[i].noOfFSNumbers = 0;
	}

	fairAndSquareSmall(tcases);
	printFairAndSqCount(ofp, tcases);

	return 0;
}