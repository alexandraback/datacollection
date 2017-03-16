#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream infile("A-small-attempt0.in",ios::in);
	ofstream outfile("A-small-attempt0.out",ios::out);
	int lines=0;
	char temp;
	while((temp=infile.get())!='\n')
		lines=lines*10+(temp-'0');
	int count=1;
	while(count<=lines)
	{
		unsigned long long num=0, denum=0,n_temp,d_temp,temp,temp1;
		temp = infile.get();
		while (temp != '/'){
			num = num * 10+(temp - '0');
			temp = infile.get();
		}
		temp = infile.get();
		while (temp != '\n' && temp != EOF){
			denum = denum * 10 + (temp - '0');
			temp = infile.get();
		}
		n_temp = num;
		d_temp = denum;
		while (n_temp != 0){
			temp = n_temp;
			n_temp = d_temp%n_temp;
			d_temp = temp;
		}
		num /= d_temp;
		denum /= d_temp;
		temp1 = denum;
		while (temp1 % 2 == 0)
			temp1 /= 2;
		if (temp1 != 1){
			outfile << "Case #" << count << ": impossible" << endl;
		}
		else{
			int gen = 1;
			while (2 * num < denum){
				gen++;
				num *= 2;
			}
			outfile << "Case #" << count << ": " << gen << endl;
		}
		count++;
	}
	system("pause");
	return 0;
}