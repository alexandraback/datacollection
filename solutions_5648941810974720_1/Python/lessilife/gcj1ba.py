import numpy,re

numbers=["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
a=[]
for i in xrange(ord('A'),ord('Z')+1):
    temp=[]
    for j in xrange(len(numbers)):
        temp+=[len(re.findall(chr(i),numbers[j]))]
    temp+=[0]
    a+=[temp]
a=numpy.array(a)

t=input()
for ti in xrange(t):
    s=raw_input()
    b=[]
    for i in xrange(ord('A'),ord('Z')+1):
        b+=[len(re.findall(chr(i),s))]
    b=numpy.array(b)
    x=numpy.linalg.lstsq(a,b)
    answer=""
    for i in xrange(10):
        if x[0][i]>0.5:
            for j in xrange(int(round(x[0][i]))):
                answer+=str(i)
    print("Case #%d: %s"%(ti+1,answer))
