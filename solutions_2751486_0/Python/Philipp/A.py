from math import *
def probA():
    f=open('input.txt','r')
    new=open('answer.txt','w')
    for tc in xrange(1, int(f.readline())+1):
        # Get input
        line1=f.readline()
        array=line1.split(" ")
        name=array[0]
        n=int(array[1])
        new.write('Case #%d: %d\n' % (tc, value(name, n)))


def value(name, n):
    count=0
    for start in range(0, len(name)-n+1):
        for end in range(start+n, len(name)+1):
            sub=name[start:end]
            num=test(sub)
            if num>=n:
                count+=1
    return count

def test(name):
    max=0
    cur=0
    for char in name:
        if char not in {'a','e','i','o','u'}:
            cur+=1
            if cur>max:
                max=cur
        else:
            cur=0
    return max
