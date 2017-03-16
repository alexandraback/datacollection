#include<cstdio>
#include<iostream>

using namespace std;

bool check(__int64 num)
{
	char s[128];
	int i, len;
	sprintf(s, "%I64d", num);
	len = strlen(s);
	for(i = 0; i < len-1-i; i ++)
	{
		if(s[i] != s[len-1-i])return false;
	}
	//cout << num << endl;
	return true;
}

__int64 list[10000];
int size;

void init()
{
	__int64 i, j;
	list[size++] = 0;
	for(i = 1; i <= 10000000; i ++)
	{
		if(check(i))
		{
			j = i*i;
			if(check(j))
			list[size++] = j;
		}
	}
	/*
	for(i = 1; i < size; i ++)
	{
		cout << list[i] << " ";
	}*/
}

int GetIndex(int num, bool Upper)
{
	int left, right, mid;
	int Ret = size;
	left = 0; right = size-1;
	while(left <= right)
	{
		mid = (left + right)>>1;
		if(num > list[mid])
		{
			left = mid+1;
		}
		if(num <= list[mid])
		{
			Ret <?= mid-1;
			right = mid-1;
		}
	}
	
	if(Upper)
	{
		if(num == list[Ret+1])Ret ++;
	}
	
	return Ret;
}

int main()
{
	init();
	int T;
	scanf("%d", &T);
	
	int Case;
	for(Case = 1;  Case <= T; Case ++)
	{
		__int64 A, B;
		cin >> A >> B;
		//cout << GetIndex(B, true) << " " << GetIndex(A, false) << endl;
		int Ans = GetIndex(B, true) - GetIndex(A, false);
		printf("Case #%d: %d\n", Case, Ans);
	}
	
	return 0;
}
