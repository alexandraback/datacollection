
def search2(e, l):
	s = set(range(1, len(l) + 1))
	ret = 0
	count = 1
	curL = [e]
	cur = l[e-1]
	b = False
	while 1:
		if (len(curL) > 1 and cur == curL[-2]):
			ret = count 
			b = True
			break
		if cur == curL[0]:
			ret = count
			break
		if cur in s:
			s.remove(cur)
		else:
			break
		curL.append(cur)

		cur = l[cur-1]
		count += 1

	if b:
		for e in s:
			if l[e-1] == curL[-1]:
				ret += 1
				break

	print e, l, ret, curL, b, s
	return ret

def search(l):
	ret = 0

	for e in range(1, len(l) + 1):
		ret = max(ret, search2(e, l))

	return ret

def main():
    inpfile = open("C-small-attempt0.in", 'r')
    outfile = open('outputC_s.txt', 'w')
    casenum = int(inpfile.readline().strip())
    for case in range(1, casenum + 1):
        line = inpfile.readline().strip()
        line = inpfile.readline().strip()
        linelst = line.split()
        lst = [int(i) for i in linelst]
        print lst
        ret = search(lst)

        result = "Case #" + str(case) + ": " + str(ret) + "\n"
        print result
        outfile.write(result)
    inpfile.close()
    outfile.close()




if __name__ == "__main__":
	main()
    # print generateNum(35, 4)
    # print toBinary(6, 16)

    # gen_primes()

