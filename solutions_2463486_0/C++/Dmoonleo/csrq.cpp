#include<iostream>
using namespace std;

long long cheat[70];
long long cheat_square[70];

int main()
{
	cheat[0]=1;
	cheat_square[0]=1;
	cheat[1]=2;
	cheat_square[1]=4;
	cheat[2]=3;
	cheat_square[2]=9;
	cheat[3]=11;
	cheat_square[3]=121;
	cheat[4]=22;
	cheat_square[4]=484;
	cheat[5]=101;
	cheat_square[5]=10201;
	cheat[6]=111;
	cheat_square[6]=12321;
	cheat[7]=121;
	cheat_square[7]=14641;
	cheat[8]=202;
	cheat_square[8]=40804;
	cheat[9]=212;
	cheat_square[9]=44944;
	cheat[10]=1001;
	cheat_square[10]=1002001;
	cheat[11]=1111;
	cheat_square[11]=1234321;
	cheat[12]=2002;
	cheat_square[12]=4008004;
	cheat[13]=10001;
	cheat_square[13]=100020001;
	cheat[14]=10101;
	cheat_square[14]=102030201;
	cheat[15]=10201;
	cheat_square[15]=104060401;
	cheat[16]=11011;
	cheat_square[16]=121242121;
	cheat[17]=11111;
	cheat_square[17]=123454321;
	cheat[18]=11211;
	cheat_square[18]=125686521;
	cheat[19]=20002;
	cheat_square[19]=400080004;
	cheat[20]=20102;
	cheat_square[20]=404090404;
	cheat[21]=100001;
	cheat_square[21]=10000200001;
	cheat[22]=101101;
	cheat_square[22]=10221412201;
	cheat[23]=110011;
	cheat_square[23]=12102420121;
	cheat[24]=111111;
	cheat_square[24]=12345654321;
	cheat[25]=200002;
	cheat_square[25]=40000800004;
	cheat[26]=1000001;
	cheat_square[26]=1000002000001;
	cheat[27]=1001001;
	cheat_square[27]=1002003002001;
	cheat[28]=1002001;
	cheat_square[28]=1004006004001;
	cheat[29]=1010101;
	cheat_square[29]=1020304030201;
	cheat[30]=1011101;
	cheat_square[30]=1022325232201;
	cheat[31]=1012101;
	cheat_square[31]=1024348434201;
	cheat[32]=1100011;
	cheat_square[32]=1210024200121;
	cheat[33]=1101011;
	cheat_square[33]=1212225222121;
	cheat[34]=1102011;
	cheat_square[34]=1214428244121;
	cheat[35]=1110111;
	cheat_square[35]=1232346432321;
	cheat[36]=1111111;
	cheat_square[36]=1234567654321;
	cheat[37]=2000002;
	cheat_square[37]=4000008000004;
	cheat[38]=2001002;
	cheat_square[38]=4004009004004;
	cheat[39]=10000001;
	cheat_square[39]=100000020000001;
	cheat[40]=10011001;
	cheat_square[40]=100220141022001;
	cheat[41]=10100101;
	cheat_square[41]=102012040210201;
	cheat[42]=10111101;
	cheat_square[42]=102234363432201;
	cheat[43]=11000011;
	cheat_square[43]=121000242000121;
	cheat[44]=11011011;
	cheat_square[44]=121242363242121;
	cheat[45]=11100111;
	cheat_square[45]=123212464212321;
	cheat[46]=11111111;
	cheat_square[46]=123456787654321;
	cheat[47]=20000002;
	cheat_square[47]=400000080000004;
	cheat[48]=100000001;
	cheat_square[48]=10000000200000001;
	cheat[49]=100010001;
	cheat_square[49]=10002000300020001;
	cheat[50]=100020001;
	cheat_square[50]=10004000600040001;
	cheat[51]=100101001;
	cheat_square[51]=10020210401202001;
	cheat[52]=100111001;
	cheat_square[52]=10022212521222001;
	cheat[53]=100121001;
	cheat_square[53]=10024214841242001;
	cheat[54]=101000101;
	cheat_square[54]=10201020402010201;
	cheat[55]=101010101;
	cheat_square[55]=10203040504030201;
	cheat[56]=101020101;
	cheat_square[56]=10205060806050201;
	cheat[57]=101101101;
	cheat_square[57]=10221432623412201;
	cheat[58]=101111101;
	cheat_square[58]=10223454745432201;
	cheat[59]=110000011;
	cheat_square[59]=12100002420000121;
	cheat[60]=110010011;
	cheat_square[60]=12102202520220121;
	cheat[61]=110020011;
	cheat_square[61]=12104402820440121;
	cheat[62]=110101011;
	cheat_square[62]=12122232623222121;
	cheat[63]=110111011;
	cheat_square[63]=12124434743442121;
	cheat[64]=111000111;
	cheat_square[64]=12321024642012321;
	cheat[65]=111010111;
	cheat_square[65]=12323244744232321;
	cheat[66]=111101111;
	cheat_square[66]=12343456865434321;
	cheat[67]=111111111;
	cheat_square[67]=12345678987654321;
	cheat[68]=200000002;
	cheat_square[68]=40000000800000004;
	cheat[69]=200010002;
	cheat_square[69]=40004000900040004;

	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		long long a,b;
		cin >>a>>b;
		int pa,pb;
		for(int j=0;j<70;j++)
		{
			if(a<=cheat_square[j])
			{
				pa = j;
				break;
			}
		}

		for(int j=0;j<70;j++)
		{
			if(b<cheat_square[j])
			{
				pb = j;
				break;
			}
		}
		
		cout << "Case #"<<i+1<<": " << pb - pa<< endl;
	}
}
