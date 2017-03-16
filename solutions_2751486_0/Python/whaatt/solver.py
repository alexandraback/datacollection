def numcons(wd):
	cons = 'bcdfghjklmnpqrstvwxyz'
	
	cnt = 0
	lng = 0
	
	for i in wd:
		if i in cons:
			cnt += 1
		else:
			if lng < cnt:
				lng = cnt
			cnt = 0
	
	if lng<cnt: lng=cnt
	
	return lng

def solve(case):
	case = case.split(' ')
	word = case[0]
	
	n = int(case[1])
	nval = 0
	
	for i in range(1, len(word)+1):
		for j in range(0,len(word)-i+1):
			if numcons(word[j:j+i]) >= n:
				nval += 1
	
	return str(nval)
	
file = open('A-small-attempt0.in','r')
lines = file.readlines()
for i in range(len(lines)):
	lines[i] = lines[i].strip()
file.close()

linesout = []
toout = ''
line = 1
while line < len(lines):
	toout = solve(lines[line])
	linesout.append('Case #' + str(len(linesout) + 1) + ': ' + toout + '\n')
	toout = ''
	line = line+1

linesout[-1] = linesout[-1][:-1]
file = open('out','w')
file.writelines(linesout)