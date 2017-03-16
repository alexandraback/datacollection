import sys

def nonsurptriplet(total):
	ave = int(total/3)
	rm = total - 3*ave
	if rm==0:
		return (ave, ave, ave)
	elif rm==1:
		return (ave, ave, ave+1)
	else:
		return (ave, ave+1, ave+1)

def surptriplet(total):
	ave = int(total/3)
	rm = total - 3*ave
	if rm==0 and ave>=1 and ave<=9:
		return (ave-1, ave, ave+1)
	elif rm==1 and ave>=1:
		return (ave-1, ave+1, ave+1)
	elif rm==2 and ave<=8:
		return (ave, ave, ave+2)
	else:
		return None

def main(argv):
	f = open(argv[0])
	count = int(f.readline().strip())
	for i in range(1, count+1):
		line = f.readline().strip()
		values = line.split(" ")
		n = int(values[0])
		maxsurp = int(values[1])
		p = int(values[2])
		scores = values[3:]
		surps = []
		surppass = 0
		nonsurppass = 0
		for score in scores:
			nonsurp = nonsurptriplet(int(score))
			surp = surptriplet(int(score))
			if max(nonsurp)>=p:
				nonsurppass += 1
			elif surp!=None and max(surp)>=p:
				surppass +=1
		count = nonsurppass + min(maxsurp, surppass)
		print "Case #"+str(i)+": "+ str(count)	
	f.close()


if __name__=="__main__":
	main(sys.argv[1:])
