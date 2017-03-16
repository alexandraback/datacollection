import sys
sys.setrecursionlimit(9999999)
d = {'11':'1', '1i':'i', '1j':'j', '1k':'k', 'i1':'i',  'ii':'-1' ,  'ij':'k',  'ik':'-j', \
'j1':'j',  'ji':'-k' ,  'jj':'-1', 'jk':'i', 'k1':'k',  'ki':'j'  ,  'kj':'-i', 'kk':'-1' }

def evaluate(t1, t2):
	neg1, neg2 = t1.count('-') , t2.count('-')
	t1, t2 = t1.replace('-',''), t2.replace('-','')
	neg = neg1 + neg2
	key = t1 + t2
	res = d[key]
	if (neg % 2) == 1:
		if res[0] == '-':
			res = res[1:]
		else:
			res = '-' + res
	return res


def evaluate_substring(substr):
	res = substr[0]
	if res == 'i':
		flag_i = True
	flag_i, flag_ij = False, False
	for i in xrange(1, len(substr)):
		res = evaluate(res, substr[i])
		if res == 'i' and flag_i == False:
			flag_i = True
		if res == 'k' and flag_i == True:
			flag_ij = True
	if res == '-1' and flag_ij == True:
		return True
	return False



def main():
	file_name = 'C-small-attempt0.in'
	fh = open(file_name, 'rt')
	line = fh.readline()
	test_cases = int(line)
	result = ''
	for i in xrange(1, test_cases+ 1):
		line1 = fh.readline().replace('\n','') 
		line2 = fh.readline().replace('\n','')
		repeat = int(line1.split(' ')[1])
		string = str(line2) * repeat
		if len(string) < 3:
			result += 'Case #' + str(i) + ": NO\n"
			continue
		elif len(string) == 3:
			if string == 'ijk':
				result += 'Case #' + str(i ) + ": YES\n"
                        	continue
			else:
				result += 'Case #' + str(i ) + ": NO\n"
                        	continue
		eval_str = evaluate_substring(string)
		if eval_str == True:
			result += 'Case #' + str( i ) + ": YES\n"
		else:
			result += 'Case #' + str(i ) + ": NO\n"
	fh.close()
	f = open('MaryamDijk.out', 'w')
	f.write(result)
	f.close()

main()
