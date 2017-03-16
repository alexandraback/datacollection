#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<algorithm>

using namespace std;

#define max_size				100
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define F(i,a,b)				for(int i=a;i<=b;i++)


/*							find,count,equal,search
(int *) find (starting_address,last_address,element)				int *pos=find(a,a+4,5);
(int *) find_if (starting_address,last_address,function_name)			int *pos=find_if(a,a+4,isodd);returns the address of d 1st odd ele in a
(int *) find_end (starting_address,last_address, match1, match1+3)		Find last subsequence in range
(int *) find_end (starting_address,last_address, match1, match1+3,function_name)
(int *) find_first_of (starting_address,last_address, match1, match1+3)		Find (first match) element from set in range
(int *) adjacent_find (starting_address,last_address)				Find (first adjacent) equal adjacent elements in range
int = (int) count (myints, myints+8, value)					Count appearances of value in range
int = (int) count_if (starting_address,last_address,function_name)		Return number of elements in range satisfying condition
(1 or 0)equal (starting_address,last_address, myints)				Test whether the elements in two ranges are equal
(int *) search (starting_address,last_address, match1, match1+4);		Find subsequence in range returns first address where match occurs
it = search_n (starting_address,last_address, 2, 30)				Find succession of equal values in range 2 30's in succession(1st occure)
*/

/*					copy,swap,replace,fill,remove,unique,reverse,rotate,partition
copy ( myints, myints+7, myvector.begin() )					Copy range of elements
swap(x,y)									Exchange values of two objects
replace (myvector.begin(), myvector.end(), 20, 99)				Replace value in range replace 20 with 99
replace_if (myvector.begin(), myvector.end(), function_name, 99)		Replace values in range 
fill (myvector.begin(),myvector.begin()+4,5)					Fill range with value
fill_n (myvector.begin(),4,20)							Fill sequence with value
pend = remove (pbegin, pend, 20);						Remove value from range
pend = remove_if (pbegin, pend, IsOdd);						Remove elements from range
remove_copy (myints,myints+8,myvector.begin(),20)				Copy range removing value		
remove_copy_if (myints,myints+9,myvector.begin(),IsOdd)				Copy range removing values
it = unique (myvector.begin(), myvector.end());					Remove consecutive duplicates in range
it=unique_copy (myints,myints+9,myvector.begin())				Copy range removing duplicates
reverse(myvector.begin(),myvector.end())					Reverse range 
reverse_copy (myints, myints+9, myvector.begin())				Copy range reversed
rotate(myvector.begin(),middle,myvector.end());					Rotate elements in range (element in middle becomes 1st element )
rotate_copy(myints,myints+3,myints+7,myvector.begin())				Copy rotated range
bound = stable_partition (myvector.begin(), myvector.end(), IsOdd)		Partition range in two-stable ordering(bound has address wer partit 											occurs first address to partiton contains ele that satisfy function)
*/

/*								sort,nth_element
sort (myvector.begin(), myvector.begin()+4);					Sort elements in range( ascending order)
sort (myvector.begin()+4, myvector.end(), myfunction);	
stable_sort									equivalent elements are not swapped
partial_sort (myvector.begin(), myvector.begin()+5, myvector.end())		Partially Sort elements in range (start to start+5 remaining wil b asis)
partial_sort (myvector.begin(), myvector.begin()+5, myvector.end(),function)
partial_sort_copy (myints, myints+9, myvector.begin(), myvector.end())		Copy and partially sort range
partial_sort_copy (myints, myints+9, myvector.begin(), myvector.end(), myfunction)	
nth_element (myvector.begin(), myvector.begin()+5, myvector.end());		Sort element in range(lft side of 5th ele wil all b less rhs wil b high)
*/

/*								binary_search
low=lower_bound (v.begin(), v.end(), 20);					Return address to1st ele which does not compare less than value.(sorted)
up= upper_bound (v.begin(), v.end(), 20);					Return address to first ele which compares greater than value.(sorted)
binary_search (v.begin(), v.end(), 3)						returns true or false (sorted array required)
*/

/*							merge,includes,union,intersection,difference
merge (first,first+5,second,second+5,v.begin())					Combines the elements in the sorted ranges [first1,last1) and 											[first2,last2), into a new range beginning at result with its elements 											sorted
includes(container,container+10,continent,continent+4)				True if every element in the range [first2,last2) is contained in the 											range [first1,last1), false otherwise.
includes(container,container+10,continent,continent+4, myfunction)
it=set_union (first, first+5, second, second+5, v.begin())			Constructs a sorted range beginning in the location pointed by result 											with the set union of the two sorted ranges [first1,last1) and 											[first2,last2) as content.
it=set_intersection (first, first+5, second, second+5, v.begin())		Constructs a sorted range beginning in the location pointed by result 											with the set intersection of the two sorted ranges [first1,last1) and 											[first2,last2) as content.
it=set_difference (first, first+5, second, second+5, v.begin())			Constructs a sorted range beginning in the location pointed by result 											with the set difference of range [first1,last1) with respect to 										[first2,last2) as content
it=set_symmetric_difference (first, first+5, second, second+5, v.begin())	Constructs a sorted range beginning in the location pointed by result 											with the set symmetric difference of the two sorted ranges 											[first1,last1) and [first2,last2) as content.
*/

/*								min,max,permutation
min(a,b)									Returns the lesser of a and b. If both are equivalent, a is returned.
max(a,b)									Returns the greater of a and b. If both are equivalent, a is returned.
min_element(myints,myints+7)							Returns an iterator pointing to the element with the smallest value in 											the range [first,last).
max_element(myints,myints+7)							Returns an iterator pointing to the element with the largest value in 											the range [first,last)
lexicographical_compare(first,first+5,second,second+9)				Returns true if range [first1,last1) compares lexicographically less 											than the range [first2,last2) (dictionary order A<a)
next_permutation (myints,myints+3)						True if the function could rearrange the object as a lexicographicaly 											greater permutation. Otherwise, the function returns false to indicate 											that the arrangement is not greater than the previous, but the lowest 											possible (sorted in ascending order).
prev_permutation (myints,myints+3)						True if the function could rearrange the object as a lexicographicaly 											smaller permutation. Otherwise, the function returns false to indicate 											that the arrangement is not smaller than the previous, but the largest 											possible (sorted in descending order).(sort and reverse)
*/

class A
{
public:
int N,M,m[60][60];
int tem[55],flag;
void input();
void rec(int);
void output();

};

void A::rec(int h)
{
F(i,1,N){
if(m[h][i]==1)
{tem[i]++;
rec(i);
}}
}

void A::input()
{
int temp;
flag=0;
F(k,1,55)
F(l,1,55)
m[k][l]=0;
cin>>N;
F(i,1,N)
{
cin>>M;
F(j,1,M)
{
cin>>temp;
m[i][temp]++;
}
}

F(jk,1,N)
tem[jk]=0;
int cnt;
int pt=1;
while(pt<=N)
{
	cnt=(int)count(m[pt]+1,m[pt]+N+1,1);
	if(cnt<=1)
	{pt++;continue;}
	else
	{
	for(int h=1;h<=N;h++)
		{
		if(m[pt][h]==1)
			{
			tem[h]++;
			rec(h);
			}
		}
	F(imp,1,N)
	{
		if(tem[imp]>1)
		{flag=1;break;}
	}
	if(flag)break;
	F(km,1,N)
	tem[km]=0;
	}
	pt++;
}
}

void A::output()
{
if(flag)
cout<<"Yes\n";
else
cout<<"No\n";
}





int main()
{
	A obj[max_size];
	int T;
	cin>>T;
	char ch=getchar();
	if(ch=='\n')
	{
		for(int i=0;i<T;i++)
		obj[i].input();
		for(int i=0;i<T;i++)
		{
			cout<<"Case #"<<(i+1)<<": ";
			obj[i].output();
		}
	}
	return 0;
}
