#include <stdio.h>
#include <vector>
#include <math.h>
#include <queue>
#include <unordered_set>

int reverse(long a)
{
    long result = 0;
    while(a > 0)
    {
	result = result*10+(a%10);
	a /= 10;
    }
    return result;
}

class Number
{
public:
    long val;
    long dist;
    //long f;

    Number(long val, long dist)//, long f)
	:val(val), dist(dist)//, f(f)
    {
    }
};

class Comparator
{
public:
    Comparator()
    {
    }

    bool operator()(const Number& a, const Number& b)
    {
	return a.dist > b.dist;
    }
};

std::vector<long> solve(const std::vector<long>& N)
{
    int nbToFind = N.size();
    std::vector<long> answer(N.size());
    std::unordered_set<long> setN;
    for(int i = 0; i < N.size(); i++)
	setN.insert(N[i]);
    std::priority_queue<Number, std::vector<Number>, Comparator> dict;
    std::unordered_set<long> closeSet;
    dict.push(Number(1,1));//,N));
    closeSet.insert(1);
    while(true)
    {
	Number num = dict.top();
	if(setN.find(num.val) != setN.end())
	{
	    for(int i = 0; i < N.size(); i++)
	    {
		if(N[i] == num.val)
		{
		    answer[i] = num.dist;
		    nbToFind--;
		}
 	    }
	}
	if(nbToFind == 0)
	    return answer;
	dict.pop();
	Number a(num.val+1, num.dist+1);//, num.dist+1);//abs(N-(num.val+1)));//+num.dist+1);
	long reverseVal = reverse(num.val);
	Number b(reverseVal, num.dist+1);//, num.dist+1);//abs(N-reverseVal));//+num.dist+1);
	if(closeSet.find(a.val) == closeSet.end())
	{
	    dict.push(a);
	    closeSet.insert(a.val);
	}
	if(closeSet.find(b.val) == closeSet.end())
	{
	    dict.push(b);
	    closeSet.insert(b.val);
	}
    }
}

int main()
{
    int num;
    char line[1024];
    scanf("%d\n", &num);
    std::vector<long> N(num);
    for(int i = 0; i < num; i++)
	scanf("%ld", &N[i]);
    std::vector<long> answer = solve(N);
    for(int i = 0; i < num; i++)
        printf("Case #%d: %ld\n", i+1, answer[i]);
    return 0;
}
