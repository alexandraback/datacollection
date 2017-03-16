#input_lines = open("tmp.in").read().splitlines()
input_lines = open("A-small-attempt2.in").read().splitlines()
#input_lines = open("A-large-attempt0.in").read().splitlines()
#input_lines = open("B-small-attempt0.in").read().splitlines()
#input_lines = open("B-large-attempt0.in").read().splitlines()
#input_lines = open("C-small-attempt0.in").read().splitlines()
#input_lines = open("C-large-attempt0.in").read().splitlines()
#input_lines = open("D-small-attempt0.in").read().splitlines()
#input_lines = open("D-large-attempt0.in").read().splitlines()

test_num = int(input_lines[0])

for i in range(test_num):
	r,c,w = map(int, input_lines[i+1].split())
	cnt = 0
	if c % w == 0:
		cnt = (c-w)/w + w
	else:
		cnt = c/w + w
	print "Case #" + str(i+1) + ": "+str(cnt)
