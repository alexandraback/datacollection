import fileinput

N=-1
case=1

d={}

def filldict(l1,l2):
    for i in xrange(len(l1)):
        if not l1[i] in d:
            d[l1[i]]=l2[i]

def exclude():
    alph='abcdefghijklmnopqrstuvwxyz'
    for c in alph:
        if not c in d.values():
            print c

filldict(" "," ")
filldict("y qee","a zoo")
filldict("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand")
filldict("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities")
filldict("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up")
#filling missing letter
filldict("z","q")


for line in fileinput.input():
    if N<0:
        N=int(line)
    else:
        outline=''
        for c in line:
            if c!='\n':
                outline+=d[c]
        print 'Case #%i: %s'%(case,outline)
        case+=1
        if case>N:
            break
