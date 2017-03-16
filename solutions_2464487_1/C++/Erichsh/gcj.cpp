#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double pi = acos(-1.0);

//非负数比较
bool Less(string &x, string &y){	return x.size()<y.size() || x.size()==y.size()&&x<y;	}

//非负数除前导0
void Head_zero_remove(string &x)
{
	if(x[0]!='0')	return ;
	x.erase(0,x.find_first_not_of('0'));
	if(x.empty())	x="0";
}

//非负数相加
string Add(string x, string y)
{
	if(x.size()<y.size())	x.swap(y);						//x的长度<y的长度
	y.insert(y.begin(), x.size()-y.size(), '0');			//y补0对齐
	string sum(x.size(),-1);									//初始大小，x.size()
	int carry=0;
	for(int i=x.size()-1; i>=0; i--)
		if((carry+=x[i]+y[i]-96)>9)	sum[i]=char(carry-10+48), carry=1;
		else		sum[i]=char(carry+48), carry=0;
	if(carry)	return '1'+sum;
	else	return sum;
}

//非负数想减，结果可能为负
string Minus(string x, string y)
{
	bool neg=0;						//结果为负标记
	if(Less(x,y))		x.swap(y),neg=1;
	y.insert(y.begin(), x.size()-y.size(), '0');		//y补0对齐
	string diff(x.size(),-1);								//差（绝对值）
	int carry=0;					//借位标记
	for(int i=x.size()-1; i>=0; i--)
		if(x[i]>=y[i]+carry)	diff[i]=x[i]-y[i]-carry+'0', carry=0;
		else					diff[i]=x[i]+10-y[i]-carry+'0', carry=1;
	Head_zero_remove(diff);
	if(neg)		return '-'+diff;
	else		return diff;
}

//非负高精度乘低精度
string Multiply(string s, int a)
{
	if(s=="0" || a==0)		return "0";
	string prod(s.size(),-1);				//先申请s.size()位
	int carry=0;
	for(int i=s.size()-1; i>=0; i--)	carry+=(s[i]-'0')*a, prod[i]=carry%10+'0', carry/=10;
	while(carry)	prod.insert(prod.begin(),carry%10+'0'), carry/=10;
	return prod;
}

//非负高精度乘高精度
string Multiply(string x, string y)
{
	string prod="0";
	for(int i=y.size()-1; i>=0; i--)
	{
		string p_sum= Multiply(x,y[i]-'0');
		if(p_sum!="0")	p_sum.insert(p_sum.end(), y.size()-1-i, '0');
		prod = Add(prod, p_sum);
	}
	return prod;
}

//非负高精度除以低精度（除数不为0）
string Divide(string x, int y, int &remainder)
{
	string quotient(x.size(),0);
	remainder=0;
	for(int i=0; i<x.size(); i++)
		remainder=remainder*10+x[i]-'0', quotient[i]=remainder/y+'0', remainder%=y;
	Head_zero_remove(quotient);
	return quotient;			//remainder则为所求的余数
}

//非负高精度除以高精度（除数不为0）
string Divide(string x, string y, string &remainder)
{
	string quotient(x.size(),'0');
	remainder="";				//初始为空格，每次下移一个字符
	for(int i=0; i<x.size(); i++)
	{
		remainder+=x[i];
		while(!Less(remainder,y))	remainder=Minus(remainder,y),quotient[i]++;		//余数>除数，则余数减除数，商加1
	}
	Head_zero_remove(quotient);			
	return quotient;			//remainder为余数
}

//非负高精度的低精度幂
string Power(string s, int a)
{
	string power="1";
	while(a)	power=(a&1)?Multiply(power,s):power, a>>=1, s=Multiply(s,s);
	return power;
}

//非负高精度开平方
string Sqrt(string s)
{
	string ret((s.size()+1)>>1, -1);
	string res=s.substr(0,2-(s.size()&1)), div="0";		//res奇位取前1，偶位取前2， div占一位置
	for(int i=0; i<ret.size(); i++)
		for(int quot=9; ;quot--)
		{
			div[div.size()-1]=quot+'0';				//末尾试商，由9到0
			string p_prod=Multiply(div, quot);
			if(!Less(res,p_prod))
			{
				ret[i]=quot+'0';					//将结果追加！
				div=Multiply(ret.substr(0,i+1),20);		
				res=Minus(res, p_prod);
			
				string nxt2=s.substr(((i+1)<<1)-(s.size()&1),2);
				if(res=="0")	res=nxt2;		//取后2位
				else	res+=nxt2;				//下移2位，追加；即res = res*100+next2
				break;
			}
		}
	return ret;				//此时res即为余数
}

//**************以下是负数支持*******************************************

//取相反数（允许负数）
string Neg(string s)
{
	if(s[0]=='-')		return s.substr(1,s.size()-1);
	if(s=="0")			return s;
	return '-'+s;
}

//加法（允许负数）
string SAdd(string x, string y)
{
	if(x[0]=='-'&&y[0]=='-')	return Neg(Add(Neg(x),Neg(y)));
	if(x[0]=='-')				return Minus(y,Neg(x));
	if(y[0]=='-')				return Minus(x,Neg(y));
	return Add(x,y);
}

//减法（允许负数）
string SMinus(string x, string y)
{
	if(x[0]=='-'&&y[0]=='-')	return Minus(Neg(y),Neg(x));
	if(x[0]=='-')				return Neg(Add(Neg(x),y));
	if(y[0]=='-')				return Add(x,Neg(y));
	return Minus(x,y);
}

//高精度乘低精度（允许负数）
string SMultiply(string s, int a)
{
	if(s[0]=='-'&&a<0)			return Multiply(Neg(s),-a);
	if(s[0]=='-')				return Neg(Multiply(Neg(s),a));
	if(a<0)						return Neg(Multiply(s,-a));
	return Multiply(s,a);
}

//高精度乘高精度（允许负数）
string SMultiply(string x, string y)
{
	if(x[0]=='-'&&y[0]=='-')	return Multiply(Neg(x),Neg(y));
	if(x[0]=='-')				return Neg(Multiply(Neg(x),y));
	if(y[0]=='-')				return Neg(Multiply(x,Neg(y)));
	return Multiply(x,y);
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;		scanf("%d", &tc);
	for (int T = 1; T <= tc; T++)
	{
		//double r, t;	scanf("%lf%lf", &r, &t);
		//double a = 2, b = -1.0 + 2 * r, c = - t; //cout << b << endl;
		//double n = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
		////double n = - b / (2.0 * a) + sqrt( (b / a) * (b / a) / 4 - c / a);
		////double n = sqrt((r/2) * (r/2) + t/2 - r/4) - (r/2 - 1/4);
		//int ans = floor(n);
		////printf("%lf, %lf, %lf, %lf\n",a, b, c, n);
		//printf("Case #%d: %d\n", T, ans);

		string r, t;	cin >> r >> t;
		string a = "2", b = SAdd("-1", Multiply("2", r)), c = Neg(t);
		int tem1;
		string ans1 = Divide(b, 4, tem1);
		if (tem1 == 0)
			ans1 = Neg(ans1);
		else
			ans1 = Neg(Add(ans1, "1"));

		string tem2 = SMinus(Multiply(b, b), SMultiply("4", SMultiply(a, c)));

		//cout << tem2;
		int tem;
		string root = Divide(tem2, 16, tem);
		//cout << " " << "16" << " " << root << endl << endl << endl;;
		string ans2 = Sqrt(root);
		string ans = SAdd(ans1, ans2);
		//cout << a << " " << b << " " << c << " "  << " "<< tem << " " <<ans <<" " <<  root << " " <<endl;
		//cout << ans1 << " " << ans2 <<" " << ans << endl;

		while (1)
		{
			string newans = Add(ans, "1");
			string newtem = SAdd(c, SAdd(SMultiply(b, newans), SMultiply(a, SMultiply(newans, newans))));
			//cout << "while: " << newans << " " << newtem << endl;
			if (newtem[0] == '-' || newtem[0] == '0')	ans = newans;
			else	break;
		}
		cout << "Case #" << T << ": " << ans << endl;

	}
}