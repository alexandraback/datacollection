#include<iostream>
#include<fstream>
using namespace std;

int data[20],temp[21];
ofstream outfile("output.txt");
bool flag;

int qsort(int l, int r)
{
	int x=l,y=r,p=data[l];
	int temp=data[l];
	while (x<y)
	{
		while ((data[y]>=p)&&(x<y)) y--;
		data[x]=data[y];
		while ((data[x]<=p)&&(x<y)) x++;
		data[y]=data[x];
	}
	data[y]=temp;
	if (l<y-1) qsort(l,y-1);
	if (x+1<r) qsort(x+1,r);
	return 0;
}

void print(int a[],int i, int j)
{
	for (int p=0;p<=i;p++)
		outfile<<a[p]<<' ';
	outfile<<endl;
	for (int p=i+1;p<=j;p++)
		outfile<<a[p]<<' ';
	outfile<<endl;
}

bool check(int a[])
{
	int b[20];
	b[0]=a[0];
	for (int i=1;i<20;i++)
		b[i]=b[i-1]+a[i];
	for (int i=0;i<19;i++)
		for (int j=0;(j<20-i);j++)
		{
			if (b[i]==b[j]-b[i]) 
			{
				print(a,i,j);
				return true;
			}
		}
	return false;
}

void Recursion(int a[], int n, int k)
{
	if (flag) return;
    if (k == 0)
	{
       if(check(a)) flag=true;
	}
    else
    {
        int temp;
        for (int i=0; i<k; i++) //穷举，依次让第k个元素与前面的元素交换
        {
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
           
            Recursion(a, n, k-1); //递归生成k-1个元素的全排列
           
            temp = a[i]; //再换回来
            a[i] = a[k];
            a[k] = temp;
        }
    }
}

int main()
{
	ifstream infile("input.txt");
	int t,n;
	long sum=0;
	infile>>t;
	for (int i=0;i<t;i++)
	{
		outfile<<"Case #"<<i+1<<": "<<endl;
		infile>>n;
		for (int j=0;j<n;j++)
		{
			infile>>data[j];
			sum+=data[j];
		}
		qsort(0,19);
		int low=0, high=19;
		for (int j=n-1;j>0;j--)
			if (data[j]>sum/2) low++;
		flag=false;
		Recursion(data,n,n-1);
	}




	infile.close();
	outfile.close();
	return 0;
}