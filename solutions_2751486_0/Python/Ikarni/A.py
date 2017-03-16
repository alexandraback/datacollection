# Python version 2.7
import sys
     
def oneCase(inputFile):
    r = inputFile.readline().split(' ')
    s = r[0]; n = int(r[1])
    x = 0; y=0; start=0; end=len(s)
    for i,c in enumerate(s):
        if c in "aeiou": x=0
        else: x+=1
        if x>=n: 
            y+= (i+1)-n-start + end-(i+1) + 1 + ((i+1)-n-start)*(end-(i+1))
            start = i-(n-2)
            #print y,start,i
    return str(y)

def main(f = None):
    inputFile = sys.stdin if f==None else open(f)
    cases = int(inputFile.readline())
    for i in range(cases):
        print "Case #" + str(i+1) + ": " + oneCase(inputFile) 

#main("A-test.in")
main()