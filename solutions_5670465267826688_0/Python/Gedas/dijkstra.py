name="C-small-attempt1"
mult_mat={'i':{'i':'-1','j':'k','k':'-j'},'j':{'i':'-k','j':'-1','k':'i'},'k':{'i':'j','j':'-i','k':'-1'},'1':{'i':'i','j':'j','k':'k'},
          '-i':{'i':'1','j':'-k','k':'j'},'-j':{'i':'k','j':'1','k':'-i'},'-k':{'i':'-j','j':'i','k':'1'},'-1':{'i':'-i','j':'-j','k':'-k'}}
for x in mult_mat.keys():
    mult_mat[x]['1']=x
for x in mult_mat:
    for y,z in mult_mat[x].items():
        mult_mat[x]["-"+y]=("-"+z).replace("--","")


##def mult(a,b):
##    return (a[:-1]+mult_mat[a[-1]][b]).replace("--","")

def mult(a,b):
    return mult_mat[a][b]

def letterGen(data,r):
    for i in xrange(min(r,16)):
        for j in data:
            yield j
    if r>16: b=reduce(mult,data)
    for i in xrange(max(0,r-16)):
        yield b

def solve(data,r):
    lG=letterGen(data,r)
    try:
        a=lG.next()
        while a!="i": a=mult(a,lG.next())
        a=lG.next()
        while a!="j": a=mult(a,lG.next())
        a=lG.next()
    except StopIteration: return False
    try:
        while True: a=mult(a,lG.next())
    except StopIteration:
        if a=="k": return True
        else: return False
    


inFile=open(name+'.in','r')
outFile=open(name+'.out','w')
#Validation is considered out of scope for the exercise and will be willfully omitted
inFile.readline()

for n in xrange(1,101):
    try:
        firstline=inFile.readline()[:-1].split()
    except IndexError: break
    if firstline==[]: break
    dataline=inFile.readline()[:-1]
    
    outFile.write("Case #"+str(n)+": "+("YES" if solve(dataline,int(firstline[1])) else "NO")+"\n")

inFile.close()
outFile.close()
print "Done."
