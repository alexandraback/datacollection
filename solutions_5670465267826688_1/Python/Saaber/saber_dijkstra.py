d = {'11':'1', '1i':'i', '1j':'j', '1k':'k', \
'i1':'i',  'ii':'-1' ,  'ij':'k',  'ik':'-j', \
'j1':'j',  'ji':'-k' ,  'jj':'-1', 'jk':'i', \
'k1':'k',  'ki':'j'  ,  'kj':'-i', 'kk':'-1' }

def evaluate(s1, s2):
	neg1, neg2 = s1.count('-') , s2.count('-')
	t1, t2 = s1.replace('-',''), s2.replace('-','')
	neg = neg1 + neg2
	key = t1 + t2
	res = d[key]
	if (neg % 2) == 1:
		if res[0] == '-':
			res = res[1:]
		else:
			res = '-' + res
	return res

def evaluate_substring(substr, result, flag_i, flag_ij):
	if result == 'i':
		flag_i = True
	for i in xrange( len(substr)):
		result = evaluate(result, substr[i])
		if result == 'i' and flag_i == False:
			flag_i = True
		if result == 'k' and flag_i == True:
			flag_ij = True
	return result, flag_i, flag_ij

def power(a, b):
	result = 1
	ijop = 1
	if b == 1 or a == '1':
		return a
	if a not in ['-1' , '1']:
		result = evaluate(a, a)
		result = pow(int(result) , int(b/2))
		if (b %2 ) == 1:
			result = evaluate(str(result), a)
	else:
		if (b % 2) == 0:
			result = 1
		else:
			result = -1
	ijop = -1
	return str(result)

def evaluate_string(x, repeat):
	res, flag_i, flag_ij = '1', False, False
	f_r = 1
	#first resylt null
	res_x = ''
	for i in xrange(repeat):
		res, flag_i, flag_ij = evaluate_substring(x, res, flag_i, flag_ij)
		if i == 0:
			res_x = res
			p = power(res, repeat)
			#print ' p = ' + str(p)
			if p != '-1':
				return False
		# for sure if it didn't find i and j, then it can't find it anymore
		if i > 100000:
			return False
		if flag_i == True and flag_ij == True:
			return True
	if res == '-1' and flag_ij == True:
		return True
        return False

def main():
	f_name = 'C-large.in.txt'
	fh = open(f_name, 'rt')
	line = fh.readline()
	test_cases = int(line)
	result = ''
	for i in xrange(1, test_cases+ 1):
		line1 = fh.readline().replace('\n','') 
		line2 = fh.readline().replace('\n','')
		repeat = int(line1.split(' ')[1])
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
	f = open('saber_dijkstra.out', 'w')
	f.write(result)
	f.close()

main()
