#include <bits/stdc++.h>
using namespace std;
int main()
{
	int flag, t, i, j, s1_digit[4], s2_digit[4], a, b, num1, num2, mindiff, diff, p[4], n1,n2, minN1,minN2;
	string s1, s2;
	int r1[5], r2[5];

	cin>>t;
	a=1;
	while(t--)
	{
		cin>>s1>>s2;

		minN1 = 1000;
		minN2 = 1000;
		mindiff = 1000;
		memset(r1, 0, 4*5);
		memset(r2, 0, 4*5);
		j=0;
		for(i=s1.length()-1; i>=0; i--){
			if(s1[i]=='?')
				s1_digit[j] = 11;
			else
				s1_digit[j] = s1[i]-'0';
			j++;
		}
		for(i=s1.length(); i<3; i++){
			s1_digit[i] = -1;
		}

		j=0;
		for(i=s2.length()-1; i>=0; i--){
			if(s2[i]=='?')
				s2_digit[j] = 11;
			else
				s2_digit[j] = s2[i]-'0';
			j++;
		}
		for(i=s2.length(); i<3; i++){
			s2_digit[i] = -1;
		}

	/*	cout<<s1<<" "<<s2<<endl;
		for(i=2; i>=0; i--)
			cout<<s1_digit[i]<<" ";
		cout<<endl;
*/
		for(num1=0; num1<pow(10, s1.length()); num1++){

			p[0] = num1%10;
			b = num1%100;
			p[1] = b/10;
			p[2] = num1/100;
			
			//cout<<p[2]<<p[1]<<p[0]<<endl;
			flag = 0;
			for(i=0; i<s1.length(); i++){
				//cout<<s1_digit[i]<<" ";

				if(s1_digit[i]==11)
					;
				else if(s1_digit[i] == p[i])
					;
				else
					flag=1;
			}
			//cout<<endl;


			if(flag==0)
			{
			//	cout<<"yes "<<num1<<endl;
				for(num2=0; num2<pow(10, s2.length()); num2++){

					p[0] = num2%10;
					b = num2%100;
					p[1] = b/10;
					p[2] = num2/100;
					flag = 0;
					for(i=0; i<s2.length(); i++){
						if(s2_digit[i]==11)
							;
						else if(s2_digit[i] == p[i])
							;
						else
							flag=1;
					}
					if(flag==0)
					{
					//	cout<<num2<<endl;
						diff = abs(num1-num2);

						if(diff<mindiff){
							minN1 = num1;
							minN2 = num2;
							mindiff = diff;
						}
						else if(diff==mindiff){
							if(num1<minN1)
								minN1=num1;
							else if(num1==minN1)
							{
								if(num2<minN2)
									minN2=num2;
							}
						}
					}
				}
			//	cout<<mindiff<<":  "<<minN1<<" "<<minN2<<endl;
			}

		}

		r1[0] = minN1%10;
		b = minN1%100;
		r1[1] = b/10;
		r1[2] = minN1/100;

		r2[0] = minN2%10;
		b = minN2%100;
		r2[1] = b/10;
		r2[2] = minN2/100;

		cout<<"Case #"<<a<<": ";
		for(i=s1.length()-1; i>=0; i--)
			cout<<r1[i];
		cout<<" ";
		for(i=s2.length()-1; i>=0; i--)
			cout<<r2[i];
		cout<<endl;
		a++;

	}
	return 0;
}