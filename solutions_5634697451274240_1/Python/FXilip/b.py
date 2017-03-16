#with open("B-small-attempt0.in") as f:
with open("B-large.in") as f:
	dat = f.read().splitlines()

def flip(pck):
	pck = pck.replace("-",'|').replace("+",'-').replace("|",'+')
	return pck[::-1]
	

n = int(dat[0])
out = []
for i in range(1,n+1):
	pcks = dat[i][::-1]
	nl = pcks.__len__()
	
	ni = 0
	ind = pcks.find('-')
	while ind !=-1:
		ni += 1
		
		#flip first
		ii = nl-1
		while pcks[ii] == "+":
			ii -= 1
		if ii != nl-1:
			ni += 1
			pcks = pcks[:ii] + "-"*(nl-ii)	

		pcks = pcks[:ind] + flip(pcks[ind:])
		ind = pcks.find('-',ind)
	
	res = "Case #"+str(i)+": "+str(ni)

	print(res)
	out.append(res)

assert out.__len__() == n
of = open("out.txt","w")
of.write("\n".join(out))
of.close()



