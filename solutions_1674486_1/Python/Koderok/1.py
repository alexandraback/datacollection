import sys
sys.setrecursionlimit(100000)
def bfs(ls1,lst2,passed):
    passed = passed | ls1
    newSet=set([])
    for x in ls1:
        if(len(lst2[x-1] & passed)>0 or len(lst2[x-1] & newSet)>0):
            return True
        else:
            newSet = newSet | lst2[x-1]
    if(len(newSet)==0):
        return False
    else:
        return bfs(newSet,lst2,passed)
count = 1
infile = open('a')
outfile = open('b', 'w')   # write mode; creates the file
LL = int(infile.readline().split()[0])
for ll in xrange(LL):
    line = infile.readline()
    N = int(line.split()[0])
    lst = []
    flag=False
    for c in xrange(N):
        sl = infile.readline()
        l = map(int, sl.split())
        m = l[0]
        l = l[1:]
        lst = lst + [set(l)]
    outfile.write('Case #'+str(count)+': ')
    for xyz in xrange(len(lst)):
        if(bfs(set([xyz]),lst,set([]))):
            outfile.write('Yes')
            flag=True
            break
    if(flag==False):
        outfile.write('No')
    outfile.write('\n')
    count += 1
infile.close()                   # not strictly required; done automatically
outfile.close()
