global strlist
global maxused
global maxstr

strlist = ["aaaa","aaaa","aaa","aaaa"]
maxused = []
maxstr = []

def B(str,used):
	global strlist
	global maxused
	global maxstr

	last = str[len(str)-1]

	for i in range(len(strlist)):
		if (i not in used) and (strlist[i][0] == last):
			newused = used[:]
			newused.append(i)
			B(str+strlist[i],newused)

	if len(used) > len(maxused):
		maxused = used[:]
		maxstr = []
		maxstr.append(str)
	elif set(used) == set(maxused):
		maxstr.append(str)


def find():
	global maxused
	global maxstr
	countlist=[]
	while (len(strlist)>0):
		maxused = []
		maxstr = []
		for i in range(len(strlist)):
			B(strlist[i],[i])
		countlist.append(len(maxstr))
		offset = 0
		maxused.sort()
		for x in maxused:
			del strlist[x-offset]
			offset += 1
		a = set(''.join(maxstr))
		b = set(''.join(strlist))
		if (len(a&b) > 0):
			return 0
		
	n = len(countlist)
	ans = 1
	for i in range(n):
		ans = ans * (i+1) % 1000000007
	for x in countlist:
		ans = ans * x % 1000000007

	return ans


def main():
	global strlist
	fin = open("B-small-attempt2.in")
	fout = open("out.txt","w")

	cases = int(fin.readline())
	for case in range(cases):
		print case
		N = fin.readline()
		strlist = fin.readline().split()
		fout.write("Case #"+str(case+1)+": "+str(find())+"\n")

	fin.close()
	fout.close()
main()
