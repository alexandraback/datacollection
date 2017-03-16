

from collections import defaultdict

no_cases = int(input())


for case_no in range(no_cases):
	number = input()
	freq = defaultdict(lambda : 0)

	for c in number:
		freq[c]+=1

	digitCount = [0]*10

	digitCount[0] = freq['Z'];

	freq['Z'] -= digitCount[0];
	freq['E'] -= digitCount[0];
	freq['R'] -= digitCount[0];
	freq['O'] -= digitCount[0];

	digitCount[6] = freq['X'];

	freq['S'] -= digitCount[6];
	freq['I'] -= digitCount[6];
	freq['X'] -= digitCount[6];

	digitCount[2] = freq['W'];

	freq['T'] -= digitCount[2];
	freq['W'] -= digitCount[2];
	freq['O'] -= digitCount[2];

	digitCount[8] = freq['G'];

	freq['E'] -= digitCount[8];
	freq['I'] -= digitCount[8];
	freq['G'] -= digitCount[8];
	freq['H'] -= digitCount[8];
	freq['T'] -= digitCount[8];

	digitCount[7]  = freq['S'];

	freq['S'] -= digitCount[7];
	freq['E'] -= digitCount[7];
	freq['V'] -= digitCount[7];
	freq['E'] -= digitCount[7];
	freq['N'] -= digitCount[7];

	digitCount[5] = freq['V']

	freq['F'] -= digitCount[5];
	freq['I'] -= digitCount[5];
	freq['V'] -= digitCount[5];
	freq['E'] -= digitCount[5];

	digitCount[4] = freq['F']

	freq['F'] -= digitCount[4];
	freq['O'] -= digitCount[4];
	freq['U'] -= digitCount[4];
	freq['R'] -= digitCount[4];

	digitCount[9] = freq['I']

	freq['N'] -= digitCount[9];
	freq['I'] -= digitCount[9];
	freq['N'] -= digitCount[9];
	freq['E'] -= digitCount[9];

	digitCount[3] = freq['H']

	freq['T'] -= digitCount[3];
	freq['H'] -= digitCount[3];
	freq['R'] -= digitCount[3];
	freq['E'] -= digitCount[3];
	freq['E'] -= digitCount[3];

	digitCount[1] = freq['O']

	freq['O'] -= digitCount[1]
	freq['N'] -= digitCount[1]
	freq['E'] -= digitCount[1]

	actual_number = ""

	for digit in range(10):
		actual_number += str(digit)*digitCount[digit]

	print("Case #{}: {}".format(case_no+1,actual_number))

