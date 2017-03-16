import sys
translate={'y':'a','n':'b','f':'c','i':'d','c':'e','w':'f',
	   'l':'g','b':'h','k':'i','u':'j','o':'k','m':'l',
	   'x':'m','s':'n','e':'o','v':'p','z':'q','p':'r',
	   'd':'s','r':'t','j':'u','g':'v','t':'w','h':'x',
	   'a':'y','q':'z',' ':' '}
def main():
    input = open(sys.argv[1])
    output = open(sys.argv[2],'w')
    caseString=input.readline()
    if caseString[-1:]=='\n':
	caseString=caseString[:-1]
    numCases=int(caseString)
    for i in range(numCases):
	current=input.readline()
	if current[-1:]=='\n':
	    current=current[:-1]
        res="Case #"+str(i+1)+": "        
	for i in range(len(current)):
	    res+=translate[current[i]]
	res+="\n"
	output.write(res)
    output.close()
	
if __name__=='__main__':
    main()

def test(input, out):
    sys.argv.append(input)
    sys.argv.append(out)
    main()