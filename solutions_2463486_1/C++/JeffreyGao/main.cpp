#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
int smallerorEqual(string first,string second)
{
	if(first.size()<second.size())
		return -1;
	else if(first.size()>second.size())
		return false;
	else
		return strcmp(first.c_str(),second.c_str());
}
string add(string a, string b)//算两个字符串的加法，如“123456” + “111111” = “234567”；
{
	if(a == "")
		return b;
	else if(b == "")
		return a;

	if(a.length() < b.length())
	{
		string temp = a; 
		a = b;
		b = temp;
	}

	string answer(100000, '0');//这个字符串的长度决定了结果的长度，也就是说输出的结果不能超过100000位。

	int input = 0, i = 1, lengtha = a.length(), lengthb = b.length();

	answer[0] = 's';

	while(lengthb)
	{
		answer[i] = (a[--lengtha] + b[--lengthb] - 96 + input) % 10 + 48;
		input = (a[lengtha] + b[lengthb] - 96 + input) >= 10 ? 1 : 0;

		i++;
	}


	int te = lengtha ;
	if(lengtha > 0)
	{
		while(true)
		{
			a[--lengtha] += input;

			input = 0;
			if(a[lengtha] > '9')
			{
				a[lengtha] = '0';
				input = 1;
			}

			if(lengtha  < 1)
			{ 
				if(input == 1)
				{
					a = '1' + a ;
					te++;
				}
				break;
			}
		}

		while(te)
			answer[i++] = a[--te];

	}
	else if(input == 1)
		answer[i++] = '1';


	answer[i] = 's';

	int t = answer.find('s', 1) - 1, t1 = 0;
	char tt;

	string s  = answer.substr(1, t );
	t--;
	while(t1 <= t/2 )
	{
		tt = s[t1];
		s[t1] = s[t - t1];
		s[t - t1] = tt;

		t1++;
	}

	return s;

}
string num2str(double number)
{	
	string numstr;
	while(number!=0)
	{
		double remain=floor(number/10);
		double digit=number-remain*10;
		number=remain;
		string singleData=" ";
		singleData[0]='0'+digit;
		numstr=numstr+singleData;
	}
	return numstr;
}
string multiplication(string a)//算字符串的平方，如“123456”的平方为“15241383936”；
{
	string answer = "";
	long in = 0, temp = 0;
	int flagl = a.length() - 1, flagr = flagl, times = 2 * flagl + 1, i = 0;
	while(times--)
	{
		while(2 * i < flagr - flagl)
		{
			temp += (a[flagl + i] - 48) * (a[flagr - i] - 48);
			i++;
		}
		temp = 2 * temp + in;
		if(2 * i == flagr - flagl)
			temp += (a[flagl + i] - 48) * (a[flagl + i] - 48);

		answer += temp % 10 + 48;
		in = temp / 10;

		flagl = --flagl < 0 ? flagr--, 0 : flagl;
		temp = i = 0;
	}
	if(in > 0)
		while(in)
		{
			answer += in % 10 + 48;
			in /= 10;
		}

		int t1 = 0, t2 = answer.length() - 1, t3 = t2 / 2;
		char tt;
		while(t1 <= t3 )
		{
			tt = answer[t1];
			answer[t1] = answer[t2 - t1];
			answer[t2 - t1] = tt;

			t1++;
		}

		return answer;

}
bool judgePalindrome(string number)
{
	for(int index=0;index<floor(double(number.size())/2);index++)
	{
		if(number[index]!=number[number.size()-1-index])
			return false;
	}
	return true;
}
string palindromeGenerator(string number,int digits)
{
	string result;
	if(digits%2==1)
	{
		for(int times=1;times<=(digits-1)/2;times++)
		{
			number=number+"0";
		}
		result=number;
		for(int times=1;times<=(digits-1)/2;times++)
		{
			result[result.size()-times]=result[times-1];
		}
	}
	else
	{
		for(int times=1;times<=digits/2;times++)
		{
			number=number+"0";
		}
		result=number;		
		for(int times=1;times<=digits/2;times++)
		{
			result[result.size()-times]=result[times-1];
		}
	}
	return result;
}
string nextNum(string number,bool valid)
{
	string numstring=number;
	if(valid==true)
	{
		numstring=number;
		numstring[numstring.size()-1]++;
	}
	else
	{
		int notZeroIndex=-1;
		bool notlastend=false;
		for(int index=numstring.size()-1;index>=0;index--)
		{
			if(numstring[index]!='0')
			{
				if(notlastend==true)
				{
					notZeroIndex=index;
					break;
				}
				else
				{
					notlastend=true;
				}
			}
			if(numstring[index]=='0')
			{
				if(notlastend==true)	
				{
					notZeroIndex=index;
					break;
				}
			}
		}
		if(notZeroIndex==-1)
			return "-1";
		else	
		{
			numstring[notZeroIndex]++;
			for(int index=notZeroIndex+1;index<numstring.size();index++)
				numstring[index]='0';
		}
	}
	return numstring;
}
void main()
{
	vector<string> finalvec;
	ofstream out("largeoutput.txt",ios::out);
	for(int index=1;index<=14;index++)
	{
		string toJudgeRoot="1";
		for(int innerindex=1;innerindex<=floor(((double)index+1)/2)-1;innerindex++)
			toJudgeRoot=toJudgeRoot+"0";
		string toJudgeData;
		while(1)
		{
			toJudgeData=palindromeGenerator(toJudgeRoot,index);
			string powData=multiplication(toJudgeData);
			if(judgePalindrome(powData))	
			{
				finalvec.push_back(powData);
				toJudgeRoot=nextNum(toJudgeRoot,true);
			}
			else
			{
				toJudgeRoot=nextNum(toJudgeRoot,false);
			}
			if(toJudgeRoot=="-1")
				break;
		}
	}
	ifstream in("C-large-1 (1).in",ios::in);
	int times;
	in>>times;
	for(int index=1;index<=times;index++)
	{
		string first,second;
		in>>first>>second;
		int firstIndex=finalvec.size()-1,secondIndex=finalvec.size()-1;
		for(int index=0;index<finalvec.size()-1;index++)
		{
			if(smallerorEqual(finalvec[index],first)<=0&&smallerorEqual(finalvec[index+1],first)>=0)	
			{
				if(strcmp(finalvec[index].c_str(),first.c_str())==0)
					firstIndex=index-1;
				else if(strcmp(finalvec[index].c_str(),first.c_str())==0)
					firstIndex=index;
				else
					firstIndex=index;
				break;
			}
		}
		for(int index=0;index<finalvec.size()-1;index++)
		{
			if(smallerorEqual(finalvec[index],second)<=0&&smallerorEqual(finalvec[index+1],second)>=0)	
			{
				if(strcmp(finalvec[index].c_str(),second.c_str())==0)
					secondIndex=index;
				else if(strcmp(finalvec[index+1].c_str(),second.c_str())==0)
					secondIndex=index+1;
				else
					secondIndex=index;
				break;
			}
		}	
		out<<"Case #"<<index<<": "<<secondIndex-firstIndex<<endl;
	}
}