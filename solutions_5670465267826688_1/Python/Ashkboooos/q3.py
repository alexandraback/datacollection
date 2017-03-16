import sys
sys.setrecursionlimit(9999999)
d = {'11':'1', '1i':'i', '1j':'j', '1k':'k', \
'i1':'i',  'ii':'-1' ,  'ij':'k',  'ik':'-j', \
'j1':'j',  'ji':'-k' ,  'jj':'-1', 'jk':'i', \
'k1':'k',  'ki':'j'  ,  'kj':'-i', 'kk':'-1' }

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

def evaluate_substring(substr, res, flag_i, flag_ij):
	#res = substr[0]
	if res == 'i':
		flag_i = True
	#flag_i, flag_ij = False, False
	for i in xrange( len(substr)):
		res = evaluate(res, substr[i])
		if res == 'i' and flag_i == False:
			flag_i = True
		if res == 'k' and flag_i == True:
			flag_ij = True
	'''
	if res == '-1' and flag_ij == True:
		return True
	return False
	'''
	return res, flag_i, flag_ij

def power(a, b):
	r = 1
	if b == 1 or a == '1':
		return a
	if a not in ['-1' , '1']:
		#r = d [(a + a) ] 
		r = evaluate(a, a)
		r = pow(int(r) , int(b/2))
		if (b %2 ) == 1:
			r = evaluate(str(r), a)
	else:
		if (b % 2) == 0:
			r = 1
		else:
			r = -1
	return str(r)

def evaluate_string(x, repeat):
	res, flag_i, flag_ij = '1', False, False
	res_x = ''
	for i in xrange(repeat):
		#print 'repeat = ' + str(i) + ' res = ' + res + ' flag_i ' + str(flag_i ) + ' flag_ij= ' + str(flag_ij)
		res, flag_i, flag_ij = evaluate_substring(x, res, flag_i, flag_ij)
		if i == 0:
			res_x = res
			p = power(res, repeat)
			#print ' p = ' + str(p)
			if p != '-1':
				return False
		if i > 100000:
			return False
		#print ' repeat = ' + str(i) + ' ' + str(flag_i) + ' ' + str(flag_ij)
		if flag_i == True and flag_ij == True:
			return True
	if res == '-1' and flag_ij == True:
		return True
        return False

def main():
	file_name = 'C-large.in'
	fh = open(file_name, 'rt')
	line = fh.readline()
	test_cases = int(line)
	result = ''
	for i in xrange(1, test_cases+ 1):
		#print str(i) 
		#print '~~~~~~~~~~~~~~'
		line1 = fh.readline().replace('\n','') 
		line2 = fh.readline().replace('\n','')
		repeat = int(line1.split(' ')[1])
		#string = str(line2) * repeat
		string = ''
		if len(line2) * repeat < 4:
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
		eval_str = evaluate_string(line2, repeat)
		if eval_str == True:
			result += 'Case #' + str( i ) + ": YES\n"
		else:
			result += 'Case #' + str(i ) + ": NO\n"
	print result	
	fh.close()
	f = open('q3.out', 'w')
	f.write(result)
	f.close()

main()
