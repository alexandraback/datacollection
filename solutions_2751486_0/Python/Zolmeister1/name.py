fin = open('name.in')
cases = int(fin.readline())
fout = open('name.out','w')

def pp(case, out):
    ss= "Case #%d: %s\n" % (case+1, out)
    print ss,
    fout.write(ss)

cons='bcdfghjklmnpqrstvwxyz'
def consonants(s,n):
    cnt=0
    for i in s:
        if i in cons:
            cnt+=1
            if cnt==n:
                return True
        else:
            cnt=0
    return False

for case in xrange(cases):
    name, s = fin.readline().split(' ')
    n = int(s)
    cnt=0
    for start in xrange(len(name)):
        for end in xrange(start,len(name)+1):
            if consonants(name[start:end],n):
                cnt+=1
    pp(case,cnt)