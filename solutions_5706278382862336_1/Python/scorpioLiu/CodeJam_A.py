import sys

input_file = 'A-large.in'
output_file = 'A-large.out'

x = [2**i for i in range(32)]

def run(resolve):
	oldstdin = sys.stdin
	fi = open(input_file, 'r')
	fo = open(output_file, 'w')
	sys.stdin = fi
	fo.write(process_cases(resolve))
	sys.stdin = oldstdin

def process_cases(resolve):
	case_total_num = int(input())
	result = ''
	for i in range(case_total_num):
		res = 'Case #%d: %s' % (i + 1, resolve(i+1))
		print(res)
		result = '%s%s\n' % (result, res)
	return result

def resolve(case_num):
	s = input().strip()
	a, b = s.split('/')
	a = int(a)
	b = int(b)
	
	cnt = 0
	flag = False
	while b >= 1:
		print (a, b)
		if a == 1:
			if b not in x:
				return 'impossible'
		if a < b and not flag:
			cnt += 1
		b /= 2
		if int(b)!= b:
			return 'impossible'
		if a >= b:
			flag = True
		if a == b:
			return cnt
		b = int(b)
		if a > b:
			a -= b
	return cnt

if __name__ == '__main__':
	run(resolve)
		