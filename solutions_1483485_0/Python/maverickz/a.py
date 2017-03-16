import sys
def main():
	mapping={' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm','q':'z','z':'q','\n':'\n'}
	if(len(sys.argv))<2:
		print "usage : a file.in"
		return
	inp=open(sys.argv[1],"r")
	op=open("output.out","w")
	t=int(inp.readline())
	case=1
	while case<=t:
		inpline=inp.readline()
		opline=""
		i=0
		while(i<len(inpline)):
			opline+=mapping[inpline[i]]
			i+=1
		op.write("Case #"+str(case)+": "+opline)
		case+=1
		
if __name__=="__main__":
	main()
