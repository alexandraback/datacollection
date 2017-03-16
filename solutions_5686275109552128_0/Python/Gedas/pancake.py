name="B-small-attempt0"

def calc_steps(stackMax,data):
    return stackMax+sum([((x-1)//stackMax) for x in data])

def solve(data):
    return min([calc_steps(x,data) for x in range(1,max(data)+1)])


inFile=open(name+'.in','r')
outFile=open(name+'.out','w')
#Validation is considered out of scope for the exercise and will be willfully omitted
inFile.readline()

for n in xrange(1,101):
    if inFile.readline()=="": break
    initialSet=map(int,str.split(inFile.readline()))

    outFile.write("Case #"+str(n)+": "+str(solve(initialSet))+"\n")

inFile.close()
outFile.close()
print "Done."
