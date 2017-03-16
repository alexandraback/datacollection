#num of cases??
num_testcases = int(raw_input());

inputs = [];
replace_char = 'yhesocvxduiglbkrztnwjpfmaq';

# get test cases strings
for i in range(0, num_testcases):
	input = raw_input();
	inputs.append(input);


for i in range(0, num_testcases):
	print "Case #%d:" % (i+1),
	output = ""
	for c in inputs[i]:
		if c == ' ':
			output = output + c
		else:
			output = output + replace_char[ord(c) - 97]
	print output
