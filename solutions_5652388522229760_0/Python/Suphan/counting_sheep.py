f = open('A-small-attempt0.in')
fw = open('A-small.out', 'w')

cases = int(f.readline())
for case in range(cases):
    N = int(f.readline())
    if N == 0:
    	fw.write('Case #' + str(case + 1) + ': ' + 'INSOMNIA' + '\n')
    	continue

    currentN = N
    count = {}
    while True:
    	for digit in str(currentN):
    		count[digit] = 1
    	if len(count) == 10:
    		break
    	else:
    		currentN += N
    fw.write('Case #' + str(case + 1) + ': ' + str(currentN) + '\n')

fw.close()
f.close()
