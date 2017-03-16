__author__ = 'jeff'

base = "A-small-attempt0"
f = open(base +'.in','r')
fout = open(base +'.out','w')

def is_consonant(c):
    if( c=='a' ): return 0
    if( c=='e' ): return 0
    if( c=='i' ): return 0
    if( c=='o' ): return 0
    if( c=='u' ): return 0
    return 1

num = int(f.readline())
for case in range(1,num+1):
    [word,n] = f.readline()[0:-1].split(' ')
    cons = list(map(is_consonant, word))
    n = int(n)
    prefix = "Case #" + str(case) + ": "
    accum = []
    for st in range(0,len(cons) - n+1):
        if( sum(cons[st:st+n]) >= n):
            accum.append(st)
    total=0
    for i in range(0,len(cons)):
        for j in range(i+n,len(cons)+1):
            #print(word[i:j], list(filter(lambda x: i<= x and j>=x+n, accum)))
            if( len(list(filter(lambda x: i<= x and j>=x+n, accum)))>0):
                total += 1
    out='Case #{0}: {1}\n'.format(case,total)
    print(word,out)
    fout.write(out)

fout.close()
f.close()



