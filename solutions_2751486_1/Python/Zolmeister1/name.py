fin = open('name.in')
cases = int(fin.readline())
fout = open('name.out','w')

def pp(case, out):
    ss= "Case #%d: %s\n" % (case+1, out)
    print ss,
    fout.write(ss)

cons='bcdfghjklmnpqrstvwxyz'
vowels='aeiou'
def consonants(s,n):
    return False
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
    consonants=0
    used=[]
    found=0
    for i,letter in enumerate(name):
        if letter in vowels:
            consonants=0
        else:
            consonants+=1
            if consonants==n:
                cc = 0
                ind=i
                cnt+=max((i-n)*(len(name)-i-1),0)#max(i-n+1,0)
                cnt+=max(len(name)-i-1,0)
                cnt+=max(i-n+1,0)
                #cnt+=max(len(name)-i-1,0)
                cnt+=1
                found+=1
                consonants-=1
    cnt-=found-1
    """
    for start in xrange(len(name)):
        end=start
        while end <len(name)+1:
            
            end+=1
        for end in xrange(start,len(name)+1):
            pass
            if consonants(name[start:end],n):
                cnt+=1"""
    pp(case,cnt)